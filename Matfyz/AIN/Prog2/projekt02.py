# 2. zadanie: RAM
# autor: Peter Kendra
# datum: 11.3.2024

class RAMError(Exception): pass


class Registers:
    def __init__(self, num_bytes, maximum):
        self._mem = []
        self._bytes = num_bytes
        self._max = maximum

    def get(self, address):
        if address >= len(self._mem):
            return 0
        return self._mem[address]

    def set(self, address, value):
        if address > self._max:
            return

        if address >= len(self._mem):
            for i in range(address - len(self._mem) + 1):
                self._mem.append(0)

        self._mem[address] = value % (256 ** self._bytes)

    def __repr__(self):
        return "reg: " + str(self._mem)[1:-1].replace(",", "")


class RAM:
    def __init__(self, program):
        self._pc = None
        self._output = None
        self._input = None
        self.reg = None
        self._program = program.split("\n")

        for i in range(len(self._program)):
            if "#" in self._program[i]:
                self._program[i] = self._program[i][:self._program[i].find("#")]
            self._program[i] = self._program[i].strip()

        while "" in self._program:
            self._program.remove("")

        for i in range(len(self._program)):
            self._program[i] = self._program[i].split()

    def __repr__(self):
        return repr(self.reg)

    def start(self, input='', num_bytes=2, maximum=1000):
        self._pc = 0
        self.reg = Registers(num_bytes, maximum)
        self._input = input.split()
        self._output = []

        while True:
            if self._pc >= len(self._program) or self._pc == -1:
                return self._output
            self._pc = self.instruction(self._pc, self._program[self._pc][0], *self._program[self._pc][1:])

    def instruction(self, pc, instr, *param):
        if instr == "const":
            if len(param) != 2:
                raise RAMError()
            self.reg.set(int(param[0]), int(param[1]))
            return pc + 1

        elif instr == "read":
            if len(param) != 1:
                raise RAMError()
            try:
                tmp = self._input[0]
                del self._input[0]
            except IndexError:
                raise RAMError()

            self.reg.set(int(param[0]), int(tmp))
            return pc + 1

        elif instr == "print":
            if len(param) != 1:
                raise RAMError()
            self._output.append(self.reg.get(int(param[0])))
            return pc + 1

        elif instr == "load":
            if len(param) != 2:
                raise RAMError()
            self.reg.set(int(param[0]), self.reg.get(self.reg.get(int(param[1]))))
            return pc + 1

        elif instr == "store":
            if len(param) != 2:
                raise RAMError()
            self.reg.set(self.reg.get(int(param[0])), self.reg.get(int(param[1])))
            return pc + 1

        elif instr == "add":
            if len(param) != 2:
                raise RAMError()
            self.reg.set(int(param[0]), self.reg.get(int(param[0])) + self.reg.get(int(param[1])))
            return pc + 1

        elif instr == "sub":
            if len(param) != 2:
                raise RAMError()
            self.reg.set(int(param[0]), self.reg.get(int(param[0])) - self.reg.get(int(param[1])))
            return pc + 1

        elif instr == "mul":
            if len(param) != 2:
                raise RAMError()
            self.reg.set(int(param[0]), self.reg.get(int(param[0])) * self.reg.get(int(param[1])))
            return pc + 1

        elif instr == "div":
            if len(param) != 2:
                raise RAMError()
            try:
                self.reg.set(int(param[0]), self.reg.get(int(param[0])) // self.reg.get(int(param[1])))
            except ZeroDivisionError:
                raise RAMError()
            return pc + 1

        elif instr == "jump":
            if len(param) != 1:
                raise RAMError()
            return int(param[0])

        elif instr == "jz":
            if len(param) != 2:
                raise RAMError()
            if self.reg.get(int(param[0])) == 0:
                return int(param[1])
            return pc + 1

        elif instr == "jnz":
            if len(param) != 2:
                raise RAMError()
            if self.reg.get(int(param[0])) != 0:
                return int(param[1])
            return pc + 1

        elif instr == "jl":
            if len(param) != 3:
                raise RAMError()
            if self.reg.get(int(param[0])) < self.reg.get(int(param[1])):
                return int(param[2])
            return pc + 1

        elif instr == "halt":
            return -1

        elif instr == "nop":
            return pc + 1


prog1 = """
    read 0
    read 1
    const 2 1
    jz 1 11
    sub 1 2
    add 3 0
    mul 3 0
    sub 1 2
    jnz 1 6
    print 3
    halt
    print 2
"""

prog2 = """
    const 0 9       # začiatok poľa             
    const 1 1       # konštanta 1               
    const 2 0       # veľkosť poľa              
    const 3 0       # súčet                     
    const 4 0       # priemer                   
    const 5 0       # počet nadpriemernych      
    add 6 0         # pom / prvok za poľom                      
    read 7          # čítanie zo vstupu         
    jz 7 14
    store 6 7
    add 2 1
    add 3 7
    add 6 1
    sub 8 8
    add 8 7         # kontrolný register pre delenie
    jnz 7 7
    print 2         # zapíš veľkosť poľa
    print 3         # zapíš súčet
    jz 8 21
    add 4 3
    div 4 2
    print 4         # zapíš priemer         21
    jz 2 32
    add 7 0         # aktuálny prvok
    load 8 7
    sub 8 1
    jl 8 4 28
    add 5 1
    add 7 1
    jl 7 6 24
    print 5         # zapíš väčšie 
    halt   
    print 2   
"""


if __name__ == '__main__':
    ram = RAM(prog2)
    print(ram.start('150 460 206 349 389 465 245 405 431 478 398 180 312 0', 2))
    print(ram)


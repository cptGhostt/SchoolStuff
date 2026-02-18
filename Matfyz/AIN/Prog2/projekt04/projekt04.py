# 4. zadanie: binarny subor
# autor: Peter Kendra
# datum: 29.03.2024

class LinkedList:
    class Student:
        def __init__(self, number, name, grades):
            self.number = number
            self.name = name
            self.grades = grades
            self.next = None

        def __repr__(self):
            return f'Student({self.number}, {self.name!r}, {self.grades})'

    def __init__(self):
        self.zac = self.kon = None
        self.poc = 0

    def read(self, file_name):
        with open(file_name, 'rb') as f:
            num = f.read(4)
            while num != b"":
                ln = f.read(1)
                name = f.read((int.from_bytes(ln, "little")))
                tmp = f.read(1)
                grades = []
                while int.from_bytes(tmp, "little") != 0:
                    grades.append(int.from_bytes(tmp, "little"))
                    tmp = f.read(1)

                tmp = self.Student(int.from_bytes(num, "little"), name.decode(), tuple(grades))
                if self.poc == 0:
                    self.zac = self.kon = tmp
                    self.poc += 1
                else:
                    self.kon.next = tmp
                    self.kon = tmp
                    self.poc += 1

                num = f.read(4)

    def write(self, file_name):
        with open(file_name, 'wb') as f:
            student = self.remove_min()
            while student is not None:
                f.write(student.number.to_bytes(4, "little"))
                f.write(len(student.name).to_bytes(1, "little"))
                f.write(bytes(student.name, "utf8"))
                for i in student.grades:
                    f.write(i.to_bytes(1, "little"))
                a = 0
                f.write(a.to_bytes(1, "little"))
                student = self.remove_min()

    def remove_min(self):
        if self.poc == 0:
            return None
        if self.poc == 1:
            tmp = self.zac
            self.zac = self.kon = None
            self.poc -= 1
            return tmp

        to_ret = zoz = self.zac

        while zoz is not None:
            if zoz.number < to_ret.number:
                to_ret = zoz
            zoz = zoz.next

        zoz = self.zac

        if to_ret != self.zac:
            while zoz.next != to_ret:
                zoz = zoz.next

        if to_ret == self.kon:
            zoz.next = None
            self.kon = zoz
            self.poc -= 1
        elif to_ret == self.zac:
            self.zac = self.zac.next
            self.poc -= 1
        else:
            zoz.next = zoz.next.next
            self.poc -= 1

        return to_ret

    def __getitem__(self, number):
        zoz = self.zac

        while  zoz is not None and zoz.number != number:
            zoz = zoz.next

        if zoz is None:
            return None

        grades = {1: 1, 2: 1.5, 3: 2,
                  4: 2.5, 5: 3, 6: 4}

        priemer = 0

        if len(zoz.grades) == 0:
            return zoz.name, priemer

        for i in zoz.grades:
            priemer += grades[i]

        return zoz.name, priemer/len(zoz.grades)

    def __len__(self):
        return self.poc


if __name__ == '__main__':
    zoz = LinkedList()
    zoz.read('subor1.dat')
    print('pocet =', len(zoz))
    p = zoz.zac
    while p:
        print(p)
        p = p.next
    print()
    for cislo in 74565, 87654321, 8765432:
        print(f'student[{cislo}] =', zoz[cislo])
    # for i in range(4):
    print('min =', zoz.remove_min())
    print('pocet po remove_min =', len(zoz))
    zoz.write('test.dat')
    print('pocet po write =', len(zoz))

# 6. zadanie: logo
# autor: Peter Kendra
# datum: 12.11.2023

def logo2python(meno_suboru, tab=4):
    with open(meno_suboru, "r", encoding="utf8") as logo:
        script = logo.read().strip()

    script = script.replace("\n", " ")
    script = script.replace("[", " [")
    script = script.replace("]", "] ")
    while script.find("  ") != -1:
        script = script.replace("  ", " ")
    script = script.strip()
    script = script.split(" ")

    # print(script)

    with open(meno_suboru[:-4] + ".py", "w", encoding="utf8") as file:
        print("import turtle", file=file)
        print("t = turtle.Turtle()", file=file)

        count = 0
        while len(script) != 0:
            print(" " * tab * count, end="", file=file)

            if script[0] == "fd":
                print("t.fd(", end="", file=file)
                script.pop(0)
                if script[0].find("]") != -1:
                    script[0] = script[0].replace("]", "")
                    count -= 1
                while len(script) > 1 and script[1] == "]":
                    script.pop(1)
                    count -= 1
                print(script[0] + ")", file=file)
                script.pop(0)
                if len(script) > 0 and script[0] == "]":
                    script.pop(0)
            elif script[0] == "rt":
                print("t.rt(", end="", file=file)
                script.pop(0)
                if script[0].find("]") != -1:
                    script[0] = script[0].replace("]", "")
                    count -= 1
                while len(script) > 1 and script[1] == "]":
                    script.pop(1)
                    count -= 1
                print(script[0] + ")", file=file)
                script.pop(0)
                if len(script) > 0 and script[0] == "]":
                    script.pop(0)
            elif script[0] == "lt":
                print("t.lt(", end="", file=file)
                script.pop(0)
                if script[0].find("]") != -1:
                    script[0] = script[0].replace("]", "")
                    count -= 1
                while len(script) > 1 and script[1] == "]":
                    script.pop(1)
                    count -= 1
                print(script[0] + ")", file=file)
                script.pop(0)
                if len(script) > 0 and script[0] == "]":
                    script.pop(0)
            elif script[0] == "pu" or script[0] == "pu]":
                if script[0] == "pu]" or script[1] == "]":
                    count -= 1
                print("t.pu()", file=file)
                script.pop(0)
                if len(script) > 0 and script[0] == "]":
                    script.pop(0)
            elif script[0] == "pd" or script[0] == "pd]":
                if script[0] == "pd]" or script[1] == "]":
                    count -= 1
                print("t.pd()", file=file)
                script.pop(0)
                if len(script) > 0 and script[0] == "]":
                    script.pop(0)
            elif script[0] == "setpw":
                print("t.pensize(", end="", file=file)
                script.pop(0)
                if script[0].find("]") != -1 or (len(script) > 1 and script[1] == "]"):
                    script[0] = script[0].replace("]", "")
                    count -= 1
                print(script[0] + ")", file=file)
                script.pop(0)
                if len(script) > 0 and script[0] == "]":
                    script.pop(0)
            elif script[0] == "setpc":
                print("t.pencolor(", end="", file=file)
                script.pop(0)
                if script[0].find("]") != -1 or (len(script) > 1 and script[1] == "]"):
                    script[0] = script[0].replace("]", "")
                    count -= 1
                tmp = script[0]
                script.pop(0)
                if tmp[0] == "'":
                    while tmp[len(tmp)-1] != "'":
                        if script[0].find("]") != -1 or (len(script) > 1 and script[1] == "]"):
                            script[0] = script[0].replace("]", "")
                            count -= 1
                        tmp += " " + script[0]
                        script.pop(0)
                elif tmp[0] == '"':
                    while tmp[len(tmp)-1] != '"':
                        if script[0].find("]") != -1 or (len(script) > 1 and script[1] == "]"):
                            script[0] = script[0].replace("]", "")
                            count -= 1
                        tmp += " " + script[0]
                        script.pop(0)
                tmp = tmp
                print(tmp+")", file=file)
                if len(script) > 0 and script[0] == "]":
                    script.pop(0)
            elif script[0] == "repeat":
                print("for repc in range(1, ", end="", file=file)
                script.pop(0)
                tmp = int(script[0]) + 1
                script.pop(0)
                print(str(tmp) + "):", file=file)
                if script[0] == "[]":
                    print(" " * tab * (count+1) + "pass", file=file)
                    script.pop(0)
                    continue
                count += 1
                script[0] = script[0].replace("[", "")
                if len(script) > 0 and script[0] == "":
                    script.pop(0)
            elif script[0] == "to":
                print("def ", end="", file=file)
                script.pop(0)
                print(script[0] + "():", file=file)
                script.pop(0)
                if script[0] == "[]":
                    print(" " * tab * (count+1) + "pass", file=file)
                    script.pop(0)
                    continue
                count += 1
                script[0] = script[0].replace("[", "")
                if len(script) > 0 and script[0] == "":
                    script.pop(0)
            else:
                if script[0].find("]") != -1:
                    script[0] = script[0].replace("]", "")
                    count -= 1
                while len(script) > 1 and script[1] == "]":
                    script.pop(1)
                    count -= 1
                print(script[0] + "()", file=file)
                script.pop(0)

        print("turtle.done()", file=file)


# logo2python("subor20.txt")

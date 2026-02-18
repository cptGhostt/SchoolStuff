# 4. zadanie: zarovnaj
# autor: Peter Kendra
# datum: 31.10.2023

def vypis(meno_suboru, sirka, zarovnat=True, slovo=""):
    odsek = ""
    to_print = ""

    with open(meno_suboru, "r", encoding="utf8") as file:
        riadok = file.readline()
        while riadok != "":
            if riadok == "\n":
                odsek = odsek.strip()
                if odsek == "":
                    riadok = file.readline()
                    continue
                while odsek.find("  ") != -1:
                    odsek = odsek.replace("  ", " ")

                odsek = odsek.split(" ")

                if slovo != "" and slovo not in odsek:
                    riadok = file.readline()
                    odsek = ""
                    continue

                while len(odsek) != 0:
                    if to_print == "":
                        to_print += odsek[0]
                        odsek.pop(0)

                    if len(odsek) == 0:
                        print(to_print)
                        to_print = ""
                        break

                    while len(to_print + " " + odsek[0]) <= sirka:
                        to_print += " " + odsek[0]
                        odsek.pop(0)
                        if len(odsek) == 0:
                            break

                    if to_print.find(" ") == -1 or len(to_print) > sirka or len(odsek) == 0 or not zarovnat:
                        print(to_print)
                        to_print = ""
                    else:
                        tmp = to_print.split(" ")
                        index = 0
                        while len(to_print) != sirka:
                            if index % len(tmp) == len(tmp) - 1:
                                index += 1
                                continue

                            tmp[index % len(tmp)] = tmp[index % len(tmp)] + " "
                            index += 1

                            to_print = tmp[0]
                            for i in range(1, len(tmp)):
                                to_print += " " + tmp[i]
                        print(to_print)
                        to_print = ""
                print()

                odsek = ""

            odsek += riadok.strip() + " "
            riadok = file.readline()

        if odsek != "":
            odsek = odsek.strip()
            if odsek.find(slovo) == -1:
                return
            while odsek.find("  ") != -1:
                odsek = odsek.replace("  ", " ")

            odsek = odsek.split(" ")

            while len(odsek) != 0:
                if to_print == "":
                    to_print += odsek[0]
                    odsek.pop(0)

                if len(odsek) == 0:
                    print(to_print)
                    break

                while len(to_print + " " + odsek[0]) <= sirka:
                    to_print += " " + odsek[0]
                    odsek.pop(0)
                    if len(odsek) == 0:
                        break

                if to_print.find(" ") == -1 or len(to_print) > sirka or len(odsek) == 0 or not zarovnat:
                    print(to_print)
                    to_print = ""
                else:
                    tmp = to_print.split(" ")
                    index = 0
                    while len(to_print) != sirka:
                        if index % len(tmp) == len(tmp) - 1:
                            index += 1
                            continue

                        tmp[index % len(tmp)] = tmp[index % len(tmp)] + " "
                        index += 1

                        to_print = tmp[0]
                        for i in range(1, len(tmp)):
                            to_print += " " + tmp[i]
                    print(to_print)
                    to_print = ""
            print()


vypis('subor3.txt', 3)

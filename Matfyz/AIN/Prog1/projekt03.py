# 3. zadanie: kalendár
# autor: Peter Kendra
# datum: 23.10.2023

def pocet_dni_v_mesiaci(mesiac, priestupny=False):
    tmp = mesiac[:3]
    if tmp == "jan" or tmp == "mar" or tmp == "maj" or tmp == "jul" or tmp == "aug" or tmp == "okt" or tmp == "dec":
        return 31
    elif tmp == "feb":
        if priestupny:
            return 29
        return 28
    return 30


def pocet_dni_medzi(datum1, datum2):
    datum1 = datum1[:3] + datum1[datum1.find("."):]
    datum2 = datum2[:3] + datum2[datum2.find("."):]
    if datum1 == datum2:
        return 0

    rok = "janfebmaraprmajjunjulaugsepoktnovdec"
    pocet = 0

    mesiac1 = rok.find(datum1[:3])
    mesiac2 = rok.find(datum2[:3])
    rok1 = int(datum1[4:])
    rok2 = int(datum2[4:])

    if mesiac1 != 0:
        if rok1 == rok2:
            while mesiac1 != mesiac2:
                if rok1 % 4 == 0 and mesiac1 == 3:
                    pocet += pocet_dni_v_mesiaci(rok[mesiac1:mesiac1 + 3], True)
                else:
                    pocet += pocet_dni_v_mesiaci(rok[mesiac1:mesiac1 + 3])

                mesiac1 += 3
            return pocet

        while mesiac1 != 0:
            if rok1%4 == 0 and mesiac1 == 3:
                pocet += pocet_dni_v_mesiaci(rok[mesiac1:mesiac1 + 3], True)
            else:
                pocet += pocet_dni_v_mesiaci(rok[mesiac1:mesiac1+3])

            if mesiac1 == 33:
                mesiac1 = 0
                rok1 += 1
            else:
                mesiac1 += 3

    while rok1 != rok2:
        if rok1 % 4 == 0:
            pocet += 366
        else:
            pocet += 365
        rok1 += 1

    while mesiac1 != mesiac2:
        if rok1 % 4 == 0 and mesiac1 == 3:
            pocet += pocet_dni_v_mesiaci(rok[mesiac1:mesiac1 + 3], True)
        else:
            pocet += pocet_dni_v_mesiaci(rok[mesiac1:mesiac1 + 3])

        mesiac1 += 3

    # index = rok.find(datum1[:3])
    # while datum1 != datum2:
    #     if datum1[:3] == "feb":
    #         if int(datum1[4:]) % 4 == 0:
    #             pocet += pocet_dni_v_mesiaci("feb", True)
    #         else:
    #             pocet += pocet_dni_v_mesiaci("feb")
    #         datum1 = datum1.replace("feb", "mar")
    #         index = 6
    #     elif datum1[:3] == "dec":
    #         pocet += pocet_dni_v_mesiaci("dec")
    #         datum1 = datum1.replace("dec", "jan")
    #         tmp = int(datum1[4:]) + 1
    #         datum1 = datum1.replace(datum1[4:], str(tmp))
    #         index = 0
    #     else:
    #         pocet += pocet_dni_v_mesiaci(datum1[:3])
    #         tmp = rok[index+3:index+6]
    #         index += 3
    #         datum1 = datum1.replace(datum1[:3], tmp)

    return pocet


def den_v_tyzdni(datum):
    offset = int(datum[:datum.find(".")])
    pocet = pocet_dni_medzi("jan.1901", datum[datum.find(".")+1:]) + offset
    tyzden = "ponutostrstvpiasobned"
    return tyzden[pocet%7*3:pocet%7*3+3]
    # if pocet % 7 == 0:
    #     return "pon"
    # elif pocet % 7 == 1:
    #     return "uto"
    # elif pocet % 7 == 2:
    #     return "str"
    # elif pocet % 7 == 3:
    #     return "stv"
    # elif pocet % 7 == 4:
    #     return "pia"
    # elif pocet % 7 == 5:
    #     return "sob"
    # else:
    #     return "ned"


def kalendar(datum):
    print("pon uto str stv pia sob ned")
    priestupny = False
    if int(datum[-4:]) % 4 == 0:
        priestupny = True
    pocet = pocet_dni_v_mesiaci(datum[:datum.find(".")], priestupny)
    den = den_v_tyzdni("1."+datum)
    tyzden = "ponutostrstvpiasobned"
    print(" "*(tyzden.find(den) // 3) * 4, end="")

    for i in range(1, pocet+1):
        if i < 10:
            if den == "ned":
                print(f"  {i}")
                den = "pon"
            else:
                print(f"  {i}", end=" ")
                den = tyzden[tyzden.find(den)+3:tyzden.find(den)+6]
        else:
            if den == "ned":
                print(f" {i}")
                den = "pon"
            else:
                print(f" {i}", end=" ")
                den = tyzden[tyzden.find(den)+3:tyzden.find(den)+6]


print(pocet_dni_v_mesiaci("feb"))
# print(pocet_dni_v_mesiaci("feb", True))
#
# print(pocet_dni_medzi('sep.2023', 'okt.2023'))
# print(pocet_dni_medzi('okt.2023', 'okt.2024'))
# print(pocet_dni_medzi('januar.1999', 'oktober.2023'))
#
# print(den_v_tyzdni('6.oktober.2023'))
# print(den_v_tyzdni('1.jan.1901'))
# print(den_v_tyzdni('23.jun.1912'))
#
# kalendar("oktober.2023")
# print()
# kalendar("maj.1945")

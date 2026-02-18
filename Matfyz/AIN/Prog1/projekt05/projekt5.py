# 5. zadanie: najcastejsie
# autor: Peter Kendra
# datum: 02.11.2023

tab = []


def citaj(meno_suboru):
    with open(meno_suboru, "r", encoding="utf8") as file:
        text = ""
        for riadok in file:
            text += riadok

        text = text.replace("\n", " ")
        while text.find("  ") != -1:
            text = text.replace("  ", " ")

        text = text.split(" ")

        tmp = []
        while len(text) != 0:
            if text[0] in tmp:
                tmp[tmp.index(text[0]) + 1] += 1
                text.pop(0)
            else:
                tmp.append(text[0])
                tmp.append(1)
                text.pop(0)

        while len(tmp) != 0:
            if tmp[0] != "":
                tab.append((tmp[0], tmp[1]))
            tmp.pop(0)
            tmp.pop(0)


def pocet_vyskytov(slovo):
    for dvojica in tab:
        if dvojica[0] == slovo:
            return dvojica[1]

    return 0


def najcastejsie():
    arr = []
    naj = 0

    for dvojica in tab:
        if dvojica[1] == naj:
            arr.append(dvojica[0])
        elif dvojica[1] > naj:
            arr.clear()
            naj = dvojica[1]
            arr.append(dvojica[0])

    return tuple(arr)


def s_poctom(n):
    arr = []
    for dvojica in tab:
        if dvojica[1] == n:
            arr.append(dvojica[0])

    return tuple(arr)


def najdlhsie():
    arr = []
    naj = 0

    for dvojica in tab:
        if len(dvojica[0]) == naj:
            arr.append(dvojica[0])
        elif len(dvojica[0]) > naj:
            arr.clear()
            naj = len(dvojica[0])
            arr.append(dvojica[0])

    return tuple(arr)


def najkratsie():
    arr = []
    naj = 1000

    for dvojica in tab:
        if len(dvojica[0]) == naj:
            arr.append(dvojica[0])
        elif len(dvojica[0]) < naj:
            arr.clear()
            naj = len(dvojica[0])
            arr.append(dvojica[0])

    return tuple(arr)


def s_dlzkou(n):
    arr = []
    for dvojica in tab:
        if len(dvojica[0]) == n:
            arr.append(dvojica[0])

    return tuple(arr)


if __name__ == '__main__':
    citaj('text1.txt')
    print('pocet vyskytov "the":', pocet_vyskytov('the'))
    print('najcastejsie:', najcastejsie())
    print('najdlhsie:', najdlhsie())
    print('najkratsie:', najkratsie())
    print('len s poctom 5:', s_poctom(5))
    print('len s poctom 10:', s_poctom(10))
    print('len s dlzkou 10:', s_dlzkou(10))
    print('pocet roznych slov =', len(tab))

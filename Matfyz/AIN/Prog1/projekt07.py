# 7. zadanie: zoznamy
# autor: Peter Kendra
# datum: 21.11.2023

def number_of_lists(zoznam):
    to_ret = 0

    if type(zoznam) is list:
        to_ret += 1

    for i in zoznam:
        if type(i) is list:
            to_ret += number_of_lists(i)

    return to_ret


def get_elements(zoznam):
    to_ret = []

    for i in zoznam:
        if type(i) is list:
            to_ret.extend(get_elements(i))
        else:
            to_ret.append(i)

    return tuple(to_ret)


def flat_list(zoznam):
    tmp = list(get_elements(zoznam))
    zoznam.clear()
    zoznam.extend(tmp)


def nested_replace(zoznam, hodnota1, hodnota2):
    to_ret = []

    for i in zoznam:
        if type(i) is list:
            if i == hodnota1:
                to_ret.append(hodnota2)
                continue
            to_ret.append([])
            to_ret[len(to_ret)-1].extend(nested_replace(i, hodnota1, hodnota2))
        else:
            if i == hodnota1:
                to_ret.append(hodnota2)
            else:
                to_ret.append(i)

    return to_ret


def change_values(zoznam:list, hodnota1, hodnota2):
    size = len(zoznam)

    for i in range(size):
        if type(zoznam[i]) is list:
            if zoznam[i] == hodnota1:
                zoznam.insert(i, hodnota2)
                zoznam.pop(i+1)
                continue
            change_values(zoznam[i], hodnota1, hodnota2)
        else:
            if zoznam[i] == hodnota1:
                zoznam.insert(i, hodnota2)
                zoznam.pop(i+1)

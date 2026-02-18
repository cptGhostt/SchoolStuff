to_print = []
used_numbers = {}
input_line = input()

while input_line != "0":
    name_part = ""
    number_part = "0"
    tmp = ""

    for i in input_line:
        if '0' <= i <= '9':
            number_part += i
        else:
            name_part += i
    number_part = int(number_part)

    if name_part in used_numbers.keys():
        if number_part in used_numbers[name_part][0]:
            used_numbers[name_part][0].add(used_numbers[name_part][1])
            if used_numbers[name_part][1] != 0:
                tmp = name_part + str(used_numbers[name_part][1])
            else:
                tmp = name_part
            while used_numbers[name_part][1] in used_numbers[name_part][0]:
                used_numbers[name_part][1] += 1
        else:
            if number_part != 0:
                tmp = name_part + str(number_part)
            else:
                tmp = name_part
            used_numbers[name_part][0].add(number_part)
            while used_numbers[name_part][1] in used_numbers[name_part][0]:
                used_numbers[name_part][1] += 1
    else:
        used_numbers[name_part] = [{number_part}, 0]
        if number_part == 0:
            used_numbers[name_part][1] += 1
        if number_part != 0:
            tmp = name_part + str(number_part)
        else:
            tmp = name_part

    to_print.append(tmp)
    input_line = input()

print(*to_print, sep='\n')

# 1. zadanie: retazec
# autor: Peter Kendra
# datum: 7.10.2023

text = input('?')
dlzka_retazca = 0
iny_retazec = ''

for i in reversed(text):
    iny_retazec += i
    dlzka_retazca += 1

print('dlzka =', dlzka_retazca)
print('prevrat =', iny_retazec)

for i in text:
    for j in text:
        print(j, end='')
        print(' * ', end='')
    print()

    for j in text:
        print('*', end='')
        print(f' {j} ', end='')
    print()

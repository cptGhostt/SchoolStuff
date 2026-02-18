def ity_riadok(meno_suboru, index):
    with open(meno_suboru) as subor:
        riadok = ""
        for i in range(index+1):
            riadok  = subor.readline()

        return riadok


print(ity_riadok("text3.txt", 3))
print(ity_riadok("text1.txt", 100))

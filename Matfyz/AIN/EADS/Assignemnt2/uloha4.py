n = int(input())
players = 2 ** n
skill_values = list(map(int, input().split()))
tournament = [skill_values]

winner = (-1, float('-inf'))
for i in range(n):
    next_round = []
    for j in range(0, len(tournament[i]), 2):
        match_winner = ((j, tournament[i][j]) if tournament[i][j] >= tournament[i][j + 1] else (j+1, tournament[i][j + 1]))
        next_round.append(match_winner[1])
        if match_winner[1] > winner[1]:
            winner = match_winner
    tournament.append(next_round)

# print(*tournament, sep='\n')
print(*winner)

k = int(input())
for i in range(k):
    adjustment = list(map(int, input().split()))
    tournament[0][adjustment[0]] += adjustment[1]

    next_index = 0
    index = adjustment[0]
    number_of_wins = 0
    printed = False
    for j in range(n):
        next_index = index // 2
        if index % 2 == 0:
            if tournament[j][index] >= tournament[j][index+1]:
                number_of_wins += 1
                tournament[j+1][next_index] = tournament[j][index]
            else:
                if not printed:
                    print(number_of_wins)
                    printed = True
                tournament[j + 1][next_index] = tournament[j][index+1]
        else:
            if tournament[j][index] > tournament[j][index - 1]:
                number_of_wins += 1
                tournament[j + 1][next_index] = tournament[j][index]
            else:
                if not printed:
                    print(number_of_wins)
                    printed = True
                tournament[j + 1][next_index] = tournament[j][index-1]
        index = next_index

    if not printed:
        print(number_of_wins)


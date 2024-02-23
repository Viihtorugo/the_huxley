def main ():
    n = int(input())

    students = {}
    
    for i in range(0, n):
        s = input()
        s = s.split('-')
        students.update({i: [int(s[0]), s[1], float(s[2])]})
    
    students = dict(sorted(students.items(), key=lambda item: [item[1][2], item[1][0], item[1][1]]))

    average = 0

    for student in students:
        value = students[student]
        average += value[2]
    
    average = average / n

    print('Alunos abaixo da media:')

    for student in students:
        value = students[student]
        if value[2] < average:
            print(f"Matricula: {value[0]} Nome: {value[1]} Nota: {value[2]}")

    print('Alunos iguais ou acima da media:')

    for student in students:
        value = students[student]
        if value[2] >= average:
            print(f"Matricula: {value[0]} Nome: {value[1]} Nota: {value[2]}")

    print(f"Media = {average:.2f}")


main()
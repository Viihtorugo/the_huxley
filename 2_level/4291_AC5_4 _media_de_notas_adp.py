def main():
    average = 0
    n = int(input())

    for i in range(0,n):
        num = float(input())
        average += num

    print(average/n)

main()
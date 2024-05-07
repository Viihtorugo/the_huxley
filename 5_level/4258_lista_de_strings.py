def main():
    string = input("Digite uma String de números: \n")
    numbers = string.split(" ")
    n = len(numbers)
    
    out = "O inverso dos números digitados é: "

    for i in range(n - 1, -1, -1):
        out += numbers[i]
        if i == 0:
            out += "."
        else:
            out += ", "
    
    print(out)

main()
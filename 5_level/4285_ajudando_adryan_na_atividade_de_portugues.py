def print_string(strings):
    rep = ""
    for i, str in enumerate(strings):
        if i + 1 != len(strings):
            rep += str + ", "
        else:
            rep += str + "."
    return rep

def main ():
    g = []
    p = []
    i = []
    r = []

    while True:
        str = input().lower()

        if str == "fim":
            break
        
        if len(str) >= 3:
            subString = str[-3:]

            if subString == "ndo":
                g.append(str)
            elif subString == "ido" or subString == "ado":
                p.append(str)
            else:
                subString = str[-2:]
                if subString == "er" or subString == "ir" or subString == "ar":
                    i.append(str)
                else:
                    r.append(str)
        elif len(str) == 2:
                if str == "er" or str == "ir" or str == "ar":
                    i.append(str)
                else:
                    r.append(str)
        else:
            r.append(str)

    if len(g) == 0 and len(i) == 0 and len(p) == 0 and len(r) == 0:
        print("Programa finalizado, você digitou apenas a palavra *fim*, desejando encerrar o programa.") 
    else:
        if len(g) > 0:
            print(f"As palavras que você digitou no gerúndio foram as seguintes: {print_string(g)}")
        else:
            print("Você não digitou nenhuma palavra no gerúndio!")
        if len(p) > 0:
            print(f"As palavras que você digitou estão no particípio: {print_string(p)}")
        else:
            print("Você não digitou nenhuma palavra no particípio!")
        if len(i) > 0:
            print(f"As palavras que você digitou no infinitivo são: {print_string(i)}")
        else:
            print("Você não digitou nenhuma palavra no infinitivo!")
        if len(r) > 0:
            print(f"As palavras que você digitou que não estão no gerúndio, particípio ou infinitivo e/são: {print_string(r)}")
        else:
            print("As palavras que você digitou estão enquadradas nas classes acima.")

main()
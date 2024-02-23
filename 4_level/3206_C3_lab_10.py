import math

def main ():
    angule = float(input())
    dist = float(input())

    res = dist/math.cos(math.radians(angule))

    print(res)

main()
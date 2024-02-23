def main():
    import sys
    sys.set_int_max_str_digits(0)

    n = int(input())
    result = str(1 << n)

    out = [result[i:i+50] for i in range(0, len(result), 50)]

    for num in out:
        print(num)

main()
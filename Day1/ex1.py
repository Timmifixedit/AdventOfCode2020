import sys
from functools import reduce


def find_n(numbers, start, depth, n_sum):
    for i in range(start, len(numbers)):
        if depth == 0 and n_sum + numbers[i] == 2020:
            return [numbers[i]]
        elif depth != 0:
            tmp_res = find_n(numbers, i + 1, depth - 1, n_sum + numbers[i])
            if tmp_res != -1:
                tmp_res.append(numbers[i])
                return tmp_res
    return -1


def main():
    if len(sys.argv) != 2:
        print("Please specify the path to the input file")

    file = sys.argv[1]
    numbers = []
    with open(file) as f:
        for num in f:
            n = int(num)
            numbers.append(n)

    res = find_n(numbers, 0, 1, 0)
    print(res)
    print(reduce(lambda x, y: x * y, res))
    res = find_n(numbers, 0, 2, 0)
    print(res)
    print(reduce(lambda x, y: x * y, res))


if __name__ == '__main__':
    main()

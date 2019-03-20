def countingValleys(s):
    count = 0
    prev = 0
    current = 0
    for move in s:
        if move == 'U':
            current += 1
            if current == 0 and prev < 0:
                count += 1
        else:
            current -= 1
        prev = current
    return count



if __name__ == '__main__':
    n = int(input())
    s = input()
    print(countingValleys(s))
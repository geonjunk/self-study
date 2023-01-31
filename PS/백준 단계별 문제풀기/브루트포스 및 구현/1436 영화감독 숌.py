n = int(input())
# 666 1666 2666... 10666 16660
now = 666
count = 0
while True:
    if "666" in str(now):
        count += 1
        if count == n:
            break

    now += 1
print(now)

n, r, c = map(int, input().split())

# r행 c열
# 4등분하고 재귀적으로 방문


def search(r, c, n):
    if n == 0:
        return 0
    if 0 <= r < pow(2, n-1) and 0 <= c < pow(2, n-1):
        return search(r, c, n-1)
    elif 0 <= r < pow(2, n-1) and c >= pow(2, n-1):
        return pow(2, n-1)*pow(2, n-1)+search(r, c-pow(2, n-1), n-1)
    elif r >= pow(2, n-1) and 0 <= c < pow(2, n-1):
        return pow(2, n-1)*pow(2, n-1)*2+search(r-pow(2, n-1), c, n-1)
    else:
        return pow(2, n-1)*pow(2, n-1)*3+search(r-pow(2, n-1), c-pow(2, n-1), n-1)


print(search(r, c, n))

# 범위 4등분 -> 위치 찾음 -> 해당 위치 범위의 탐색 순서 더함 -> 다시 쪼갬
# r행 c열을 바로 계산하는 방법?

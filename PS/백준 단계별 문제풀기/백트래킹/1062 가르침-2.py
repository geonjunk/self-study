- 풀이 2) 26개 알파벳 순회 → 단 조합이므로 이전 idx 달고 순회

    ```python
    import sys
    input=sys.stdin.readline
    n, k=map(int, input().split())
    # 단어의 갯수 n, 가르칠수 있는 글자수 k개
    words=[input().strip() for _ in range(n)]
    # a,n,t,i,c

    if k < 5:
        print(0)
    elif k == 26:
        print(n)
    else:
        visited=[False]*26
        visited[ord("a")-ord("a")]=True
        visited[ord("c")-ord("a")]=True
        visited[ord("n")-ord("a")]=True
        visited[ord("i")-ord("a")]=True
        visited[ord("t")-ord("a")]=True
        ans=-1

        def backtracking(count, idx):
            if count == k-5:
                calAnswer()
                return

            for i in range(idx, 26):
                if not visited[i]:
                    visited[i]=True
                    backtracking(count+1, i+1)
                    visited[i]=False

        def calAnswer():
            global ans
            tmp=0
            for w in words:
                tmp += 1
                for i in w:
                    if not visited[ord(i)-ord("a")]:
                        tmp -= 1
                        break
            ans=max(tmp, ans)
        backtracking(0, 0)
        print(ans)
    ```

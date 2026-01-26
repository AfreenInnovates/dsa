t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    ans = 0
    cnt = 1

    for i in range(1, n):
        if (a[i] % 2) == (a[i - 1] % 2):
            cnt += 1
        else:
            ans += cnt - 1
            cnt = 1

    ans += cnt - 1  # last block
    print(ans)

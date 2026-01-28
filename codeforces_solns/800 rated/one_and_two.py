t = int(input())

for _ in range(t):
    n=int(input())
    a=list(map(int, input().split()))

    total_twos =a.count(2)

    if total_twos%2!=0: # if odd number of twos, we won't have two parts of array with equal product
        print(-1)
        continue  

    need_twos = total_twos//2 # we need half of the number of twos, so that we can divide in two equal parts

    count = 0

    for i, num in enumerate(a):
        if num == 2:
            count += 1

        if count == need_twos:
            print(i + 1) 
            break


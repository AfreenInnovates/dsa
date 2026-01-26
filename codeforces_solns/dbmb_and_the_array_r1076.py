# we can only INCREASE the array sum by doing operations
# each operation adds exactly x to the total sum
# so if current sum already exceeds s, we can never fix it

# otherwise, we just need to check if we can reach s
# i.e., (s - current_sum) must be a multiple of x

t = int(input())
for _ in range(t):
    n, s, x = map(int, input().split())
    a = list(map(int, input().split()))
    
    total = sum(a)
    
    if total > s:
        print("NO")
    elif (s - total) % x == 0:
        print("YES")
    else:
        print("NO")

import math

def solve(cd, s):
    if cd == len(duration):
        return 0
    
    npega = solve(cd + 1, s)
    #print(duration[cd])
    if s - duration[cd] >= 0:
        pega = duration[cd] + solve(cd + 1, s - duration[cd])
        return max(pega, npega)
    
    return npega

while True:
    try:
        duration, space = [], 0
        duration = [int(x) for x in input().split()]
        space, duration = duration[0], duration[1::]
        res = solve(0, space)
        print(res)
    except EOFError:
        break

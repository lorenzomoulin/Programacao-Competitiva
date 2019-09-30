dp = [0, 1]
for i in range(2, 5002):
    dp += [dp[i - 1] + dp[i - 2]]
while True:
    try: 
        n = int(input())
        print('The Fibonacci number for %d is %d' % (n, dp[n]))
    except EOFError:
        break

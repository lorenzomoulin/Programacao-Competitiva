line = input ()
spl = line.split (' ')
n = int (spl[0])
m = int (spl[1])
h = int (spl[2])

line = input ()
spl = line.split (' ')
x = int (spl[0])
y = int (spl[1])
z = int (spl[2])

line = input ()
spl = line.split (' ')
p = int (spl[0])
q = int (spl[1])
r = int (spl[2])

print (((n*h*m*(m+1)*(2*m+1)*y*p//6)%(1000000007) + \
(n*(n+1)*h*m*(m+1)*x*p//4)%(1000000007) + \
(n*h*(h+1)*m*(m+1)*y*q//4)%(1000000007) + \
(n*(n+1)*h*(h+1)*m*x*q//4)%(1000000007) + \
(n*(n+1)*h*m*x*r//2)%(1000000007) + \
(n*h*m*(m+1)*y*r//2)%(1000000007) + \
(n*h*m*(m+1)*z*p//2)%(1000000007) + \
(n*h*(h+1)*m*z*q//2)%(1000000007) + \
(n*h*m*z*r)%(1000000007))%(1000000007))


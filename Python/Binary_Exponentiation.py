def power(x, y, p):
    res = 1
 
    while (y > 0):
        if ((y & 1) != 0):
            res = res * x
        y = y >> 1
        x = x * x
 
    return res % p
 
x = 2
y = 5
p = 13
print("Power is ", power(x, y, p))
import math

a = float(input("Unesi duzinu stranice jednakostranicnog trougla: "))
p = (a**2) * math.sqrt(3) / 4
p = round(p, 2)
print("Povrsina jednakostranicnog trougla duzine stranice:", a, " iznosi: ", p)



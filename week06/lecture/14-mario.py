from cs50 import get_int

while True:
    n = get_int("Height: ")
    if (n > 0):
        break # We've got the value we need

for _ in range(n):
    print("#")

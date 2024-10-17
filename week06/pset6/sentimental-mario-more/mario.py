from cs50 import get_int

while True:
    n = get_int("Height: ")
    if 1 <= n <= 8:
        break

for i in range(n, 0, -1):  # Começa de n e vai até 1
    spaces = n - i
    hashes = i

    print(" " * spaces, end="")
    print("#" * hashes)

from cs50 import get_int

while True:
    n = get_int("Height: ")
    if 1 <= n <= 8:
        break

for i in range(1, n + 1):
    spaces = n - i
    hashes = i

    print(" " * spaces, end="")
    print("#" * hashes)

for i in range(1, n + 1):  # De 1 a n
    print("#" * i)  # Imprime i hashes

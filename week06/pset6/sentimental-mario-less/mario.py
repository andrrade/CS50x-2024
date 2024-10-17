from cs50 import get_int


while True:
    n = get_int("Height: ")
    width = n + 1
    if (n > 0):
        break

for i in range(1, width):
    hashes = i + 1
    spaces = width - hashes

    print(" " * spaces, end="")
    print("#" * hashes)

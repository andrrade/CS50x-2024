from cs50 import get_int

while True:
    n = get_int("Height: ")
    if 1 <= n <= 8:
        break

for i in range(1, n + 1):
    # Para a primeira pirâmide (à esquerda)
    spaces = n - i  # Número de espaços à esquerda
    hashes = i      # Número de hashes

    # Imprime a primeira pirâmide com os espaços
    print(" " * spaces + "#" * hashes, end="  ")  # Adiciona 2 espaços entre as pirâmides

    # Para a segunda pirâmide (à direita)
    print("#" * i)  # Imprime a segunda pirâmide


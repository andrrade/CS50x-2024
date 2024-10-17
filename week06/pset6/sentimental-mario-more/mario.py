from cs50 import get_int

# Solicita a altura da pirâmide até que seja um valor entre 1 e 8
while True:
    n = get_int("Height: ")
    if 1 <= n <= 8:
        break

# Laço para gerar as linhas das pirâmides
for i in range(1, n + 1):
    spaces = n - i  # Calcula os espaços para alinhar à direita
    hashes = i  # Determina a quantidade de hashes

    # Imprime os espaços e a primeira pirâmide
    print(" " * spaces, end="")
    print("#" * hashes, end="  ")  # Adiciona dois espaços entre as pirâmides
    # Imprime a segunda pirâmide sem espaços à frente
    print("#" * hashes)

import csv
import sys


def main():
    # TODO: Verificar o uso da linha de comando
    if len(sys.argv) != 3:
        sys.exit()

    # TODO: Ler o arquivo do banco de dados em uma variável
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        data = list(reader)

    # TODO: Ler o arquivo da sequência de DNA em uma variável
    with open(sys.argv[2], "r") as file:
        seq = file.read()

    # TODO: Encontrar a correspondência mais longa de cada STR na sequência de DNA
    STR = []
    for i in range(1, len(reader.fieldnames)):
        STR.append(longest_match(seq, reader.fieldnames[i]))

    # TODO: Verificar o banco de dados em busca de perfis correspondentes
    for i in range(len(data)):
        matches = 0
        for j in range(1, len(reader.fieldnames)):
            if int(data[i][reader.fieldnames[j]]) == STR[j - 1]:
                matches += 1
            if matches == len(reader.fieldnames) - 1:
                print(data[i]['name'])
                return
    print("No match")


def longest_match(sequence, subsequence):
    # Retorna o comprimento da sequência mais longa de subsequência na sequência.

    # Inicializar variáveis
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Verificar cada caractere na sequência em busca do maior número de ocorrências consecutivas da subsequência
    for i in range(sequence_length):

        # Inicializar contagem de ocorrências consecutivas
        count = 0

        # Verificar por uma correspondência da subsequência em um "substring" (um subconjunto de caracteres) dentro da sequência
        # Se houver correspondência, mover o substring para a próxima correspondência potencial na sequência
        # Continuar movendo o substring e verificando por correspondências até que não haja mais correspondências consecutivas
        while True:

            # Ajustar início e fim do substring
            start = i + count * subsequence_length
            end = start + subsequence_length

            # Se houver uma correspondência no substring
            if sequence[start:end] == subsequence:
                count += 1

            # Se não houver correspondência no substring
            else:
                break

        # Atualizar o maior número de correspondências consecutivas encontrado
        longest_run = max(longest_run, count)

    # Após verificar as ocorrências em cada caractere da sequência, retornar a maior ocorrência encontrada
    return longest_run


main()

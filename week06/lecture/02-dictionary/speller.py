import time

# Define um conjunto global para armazenar as palavras do dicionário
words = set()

def check(word):
    """Verifica se uma palavra está no dicionário."""
    return word.lower() in words

def load(dictionary):
    """Carrega o dicionário a partir de um arquivo."""
    try:
        with open(dictionary, 'r') as file:
            words.update(file.read().splitlines())
        return True
    except FileNotFoundError:
        print(f"Could not load {dictionary}. File not found.")
        return False

def size():
    """Retorna o número de palavras no dicionário."""
    return len(words)

def unload():
    """Descarrega o dicionário (neste caso, apenas retorna True)."""
    return True

def calculate(start, end):
    """Calcula o tempo decorrido entre start e end."""
    return end - start

def main(dictionary_file, text_file):
    """Função principal que executa o verificador de ortografia."""
    # Carregar o dicionário
    if not load(dictionary_file):
        return

    # Variáveis para contagem e tempo
    misspellings = 0
    words_checked = 0
    time_check = 0.0
    word = ''

    # Tenta abrir o arquivo de texto
    try:
        with open(text_file, 'r') as file:
            # Ler e verificar cada caractere
            for c in file.read():
                # Permitir apenas caracteres alfabéticos e apóstrofos
                if c.isalpha() or (c == "'" and word):
                    word += c
                else:
                    if word:  # Se encontramos uma palavra
                        words_checked += 1
                        start_time = time.time()
                        if not check(word):  # Verifica a ortografia
                            print(word)  # Imprime palavras incorretas
                            misspellings += 1
                        end_time = time.time()
                        time_check += calculate(start_time, end_time)
                        word = ''  # Reinicia para a próxima palavra

            # Verifica se há uma palavra restante no final
            if word:
                words_checked += 1
                start_time = time.time()
                if not check(word):
                    print(word)
                    misspellings += 1
                end_time = time.time()
                time_check += calculate(start_time, end_time)

    except FileNotFoundError:
        print(f"Could not open {text_file}. File not found.")
        unload()
        return

    # Relatório final
    print(f"\nWORDS MISSPELLED: {misspellings}")
    print(f"WORDS IN DICTIONARY: {size()}")
    print(f"WORDS IN TEXT: {words_checked}")
    print(f"TIME IN CHECK: {time_check:.2f} seconds")

if __name__ == "__main__":
    DICTIONARY = "dictionaries/large.txt"  # Substitua pelo caminho correto
    TEXT = "texts/holmes.txt"  # Substitua pelo caminho correto
    main(DICTIONARY, TEXT)

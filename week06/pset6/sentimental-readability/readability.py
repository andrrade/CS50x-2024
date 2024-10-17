from cs50 import get_string  # Importa a função get_string da biblioteca CS50 para obter entrada do usuário


def count_letters(text):
    # Conta o número de letras no texto.
    count = 0  # Inicializa o contador de letras
    for char in text:  # Percorre cada caractere no texto
        if char.isalpha():  # Verifica se o caractere é uma letra
            count += 1  # Se for letra, incrementa o contador
    return count  # Retorna o total de letras contadas


def count_words(text):
    # Conta o número de palavras no texto.
    # Divide o texto por espaços em branco e filtra quaisquer strings vazias
    words = text.split()  # Divide o texto em palavras
    return len(words)  # Retorna o número total de palavras


def count_sentences(text):
    # Conta o número de sentenças no texto.
    count = 0  # Inicializa o contador de sentenças
    for char in text:  # Percorre cada caractere no texto
        if char in ['.', '!', '?']:  # Verifica se o caractere é um sinal de pontuação que indica o fim de uma sentença
            count += 1  # Se for, incrementa o contador de sentenças
    return count  # Retorna o total de sentenças contadas


def calculate_grade(letters, words, sentences):
    # Calcula o índice de Coleman-Liau.
    L = (letters / words) * 100  # Calcula a média de letras por 100 palavras
    S = (sentences / words) * 100  # Calcula a média de sentenças por 100 palavras
    index = 0.0588 * L - 0.296 * S - 15.8  # Aplica a fórmula do índice
    return round(index)  # Retorna o índice arredondado para o inteiro mais próximo


def main():
    text = get_string("Text: ")  # Obtém a entrada do usuário
    letters = count_letters(text)  # Conta o número de letras
    words = count_words(text)  # Conta o número de palavras
    sentences = count_sentences(text)  # Conta o número de sentenças

    # Calcula o nível de graduação com base nos contadores
    grade = calculate_grade(letters, words, sentences)

    # Saída do nível de graduação
    if grade < 1:  # Se o índice for menor que 1
        print("Before Grade 1")  # Imprime que é antes do grau 1
    elif grade >= 16:  # Se o índice for 16 ou mais
        print("Grade 16+")  # Imprime que é grau 16 ou mais
    else:  # Para índices entre 1 e 15
        print(f"Grade {grade}")  # Imprime o grau correspondente


if __name__ == "__main__":
    main()  # Executa a função principal

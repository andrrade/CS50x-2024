from cs50 import get_long

# Função para determinar o comprimento (número de dígitos) do cartão
def get_length(number):
    length = 0
    while number > 0:
        number //= 10  # Remove o último dígito
        length += 1  # Conta o número de dígitos
    return length

# Função para obter os primeiros dígitos do cartão
def first_numbers(number):
    while number >= 100:
        number //= 10  # Remove o último dígito
    return number  # Retorna os primeiros dígitos

# Função para identificar o tipo de cartão
def what_card(number):
    length = get_length(number)  # Obtém o comprimento do número do cartão
    firsts = first_numbers(number)  # Obtém os dois primeiros dígitos

    # Verifica o tipo de cartão com base no comprimento e nos primeiros dígitos
    if length == 15 and (firsts == 34 or firsts == 37):
        print("AMEX")
    elif length == 16 and (51 <= firsts <= 55):
        print("MASTERCARD")
    elif (length == 13 or length == 16) and (firsts // 10 == 4):
        print("VISA")
    else:
        print("INVALID")  # Caso nenhum tipo de cartão seja identificado

# Função para calcular a soma dos dígitos usando o algoritmo de Luhn
def get_sum(number):
    total_sum = 0  # Inicializa a soma
    toggle = False  # Flag para alternar a multiplicação

    while number > 0:
        digit = number % 10  # Armazena o último dígito de number
        number //= 10  # Remove o último dígito encontrado

        if toggle:  # Verifica se o dígito deve ser multiplicado
            digit *= 2  # Multiplica o dígito por 2
            if digit >= 10:
                # Se o número contiver 2 casas decimais, realiza a soma entre os dígitos
                digit = (digit % 10) + (digit // 10)

        total_sum += digit  # Adiciona o dígito (ou a soma dos dígitos) à soma total
        toggle = not toggle  # Alterna a flag para o próximo dígito

    return total_sum % 10 == 0  # Retorna True se a soma total for divisível por 10, caso contrário, False

def main():
    while True:
        number = get_long("Number: ")  # Solicita o número do cartão ao usuário
        if number >= 0:  # Verifica se o número é positivo
            break

    if get_sum(number):  # Verifica se o número é válido pelo algoritmo de Luhn
        what_card(number)  # Determina o tipo de cartão com base no número
    else:
        print("INVALID")  # Imprime "INVALID" se o número for inválido

main()

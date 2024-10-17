from cs50 import get_float

def how_much(cents, coin_type):
    return cents // coin_type  # Usar // para obter a parte inteira

def main():
    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break

    quarters = how_much(change, 25)
    change -= quarters * 25

    dimes = how_much(change, 10)
    change -= dimes * 10

    nickels = how_much(change, 5)
    change -= nickels * 5

    pennies = how_much(change, 1)
    change -= pennies

    total = quarters + dimes + nickels + pennies
    print(total)

main()

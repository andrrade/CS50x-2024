from cs50 import get_string
import math

def count(type, text):
    counter = 0
    length = len(text)

    for i in range(length):
        if type == 1 and text[i].isalpha():
            counter += 1
        elif type == 2 and (i == 0 or text[i - 1].isspace()):
            counter += 1
        elif type == 3 and (text[i] in ['.', '!', '?']):
            counter += 1

    if type == 2:
        counter += 1

    return counter

def Liau(letters, words, sentences):
    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)

def main():
    text = get_string("Text: ")
    letters = count(1, text)
    words = count(2, text)
    sentences = count(3, text)
    grade = Liau(letters, words, sentences)

    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

main()

from cs50 import get_string
import math

def count_letters(text):
    """Counts the number of letters in the text."""
    count = 0
    for char in text:
        if char.isalpha():  # Check if the character is a letter
            count += 1
    return count

def count_words(text):
    """Counts the number of words in the text."""
    # Split the text by whitespace and filter out any empty strings
    words = text.split()
    return len(words)

def count_sentences(text):
    """Counts the number of sentences in the text."""
    count = 0
    for char in text:
        if char in ['.', '!', '?']:  # Check for sentence-ending punctuation
            count += 1
    return count

def calculate_grade(letters, words, sentences):
    """Calculates the Coleman-Liau index."""
    L = (letters / words) * 100  # Average letters per 100 words
    S = (sentences / words) * 100  # Average sentences per 100 words
    index = 0.0588 * L - 0.296 * S - 15.8
    return round(index)  # Round to nearest integer

def main():
    text = get_string("Text: ")  # Get user input
    letters = count_letters(text)  # Count letters
    words = count_words(text)  # Count words
    sentences = count_sentences(text)  # Count sentences

    # Calculate the grade level
    grade = calculate_grade(letters, words, sentences)

    # Output the grade level
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")

if __name__ == "__main__":
    main()

import sys
import time
import os

# Default dictionary
DICTIONARY = "dictionaries/large.txt"

# Global set to store words
words = set()

def load(dictionary):
    """Load the dictionary into memory from a file."""
    try:
        with open(dictionary, 'r', encoding='utf-8') as file:
            # Read lines from the file and update the words set
            words.update(word.strip().lower() for word in file.readlines())
        return True
    except FileNotFoundError:
        print(f"Could not load {dictionary}.")
        return False

def check(word):
    """Check if the word is in the dictionary."""
    return word.lower() in words

def size():
    """Return the number of words in the dictionary."""
    return len(words)

def unload():
    """Unload the dictionary from memory."""
    words.clear()  # Clear the set of words to free memory
    return True

def main():
    # Check for correct number of args
    if len(sys.argv) != 2 and len(sys.argv) != 3:
        print("Usage: python speller.py [DICTIONARY] text")
        return 1

    # Determine dictionary to use
    dictionary = sys.argv[1] if len(sys.argv) == 3 else DICTIONARY

    # Load dictionary and time it
    start_load = time.time()
    loaded = load(dictionary)
    end_load = time.time()

    # Exit if dictionary not loaded
    if not loaded:
        return 1

    # Try to open text
    text = sys.argv[2] if len(sys.argv) == 3 else sys.argv[1]
    if not os.path.isfile(text):
        print(f"Could not open {text}.")
        unload()
        return 1

    # Prepare to report misspellings
    print("\nMISSPELLED WORDS\n")

    # Prepare to spell-check
    misspellings = 0
    words_in_text = 0

    try:
        with open(text, 'r', encoding='utf-8') as file:
            word = ''
            while True:
                c = file.read(1)
                if not c:  # End of file
                    break

                if c.isalpha() or (c == "'" and word):  # Allow alphabetical characters and apostrophes
                    word += c
                else:
                    if word:  # If a complete word is found
                        words_in_text += 1
                        if not check(word):
                            print(word)
                            misspellings += 1
                        word = ''  # Reset word

                    if c.isdigit():  # Ignore words with numbers
                        while c and c.isalnum():  # Consume alphanumeric string
                            c = file.read(1)
                        word = ''  # Reset word

    except UnicodeDecodeError:
        print(f"Error reading {text}. The file might not be in UTF-8 encoding.")
        unload()
        return 1

    # Determine dictionary's size
    dict_size = size()

    # Unload dictionary
    unloaded = unload()

    # Abort if dictionary not unloaded
    if not unloaded:
        print(f"Could not unload {dictionary}.")
        return 1

    # Report results
    print(f"\nWORDS MISSPELLED:     {misspellings}")
    print(f"WORDS IN DICTIONARY:  {dict_size}")
    print(f"WORDS IN TEXT:        {words_in_text}")
    print(f"TIME IN load:         {end_load - start_load:.2f} seconds")

    # Success
    return 0

if __name__ == "__main__":
    main()

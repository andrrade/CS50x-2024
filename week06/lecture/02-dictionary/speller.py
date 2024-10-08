import sys
import time
import os
import re
from dictionary import load, check, size, unload  # Importar as funções do dictionary.py

# Default dictionary
DICTIONARY = "dictionaries/large"

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
    total_time_check = 0

    try:
        with open(text, 'r', encoding='utf-8') as file:
            content = file.read()

            # Find all words in the text using regex
            words = re.findall(r"[a-zA-Z']+", content)  # Capture words with letters and apostrophes
            words_in_text = len(words)  # Count total words

            for word in words:
                # Time the check function
                start_check = time.time()
                if not check(word):
                    print(word)
                    misspellings += 1
                end_check = time.time()
                total_time_check += (end_check - start_check)

    except UnicodeDecodeError:
        print(f"Error reading {text}. The file might not be in UTF-8 encoding.")
        unload()
        return 1
    except Exception as e:
        print(f"An error occurred while reading {text}: {e}")
        unload()
        return 1

    # Determine dictionary's size and time it
    start_size = time.time()
    dict_size = size()
    end_size = time.time()

    # Unload dictionary and time it
    start_unload = time.time()
    unloaded = unload()
    end_unload = time.time()

    # Abort if dictionary not unloaded
    if not unloaded:
        print(f"Could not unload {dictionary}.")
        return 1

    # Calculate total time
    total_time = (end_load - start_load) + total_time_check + (end_size - start_size) + (end_unload - start_unload)

    # Report results
    print(f"\nWORDS MISSPELLED:     {misspellings}")
    print(f"WORDS IN DICTIONARY:  {dict_size}")
    print(f"WORDS IN TEXT:        {words_in_text}")
    print(f"TIME IN load:         {end_load - start_load:.2f} seconds")
    print(f"TIME IN check:        {total_time_check:.2f} seconds")
    print(f"TIME IN size:         {end_size - start_size:.2f} seconds")
    print(f"TIME IN unload:       {end_unload - start_unload:.2f} seconds")
    print(f"TOTAL TIME:           {total_time:.2f} seconds")

    # Success
    return 0

if __name__ == "__main__":
    main()

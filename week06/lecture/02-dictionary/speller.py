import sys
import time

# Importar funções do módulo dictionary
from dictionary import load, check, size, unload

# Default dictionary
DICTIONARY = "dictionaries/large.txt"

def calculate(start_time, end_time):
    """Calculate elapsed time in seconds."""
    return end_time - start_time

def main():
    # Check for correct number of args
    if len(sys.argv) not in (2, 3):
        print("Usage: python speller.py [DICTIONARY] text")
        return 1

    # Benchmarking variables
    time_load, time_check, time_size, time_unload = 0.0, 0.0, 0.0, 0.0

    # Determine dictionary to use
    dictionary = sys.argv[1] if len(sys.argv) == 3 else DICTIONARY

    # Load dictionary
    start_time = time.time()
    if not load(dictionary):
        print(f"Could not load {dictionary}.")
        return 1
    end_time = time.time()
    time_load = calculate(start_time, end_time)

    # Try to open text
    text = sys.argv[2] if len(sys.argv) == 3 else sys.argv[1]
    try:
        with open(text, 'r') as file:
            print("\nMISSPELLED WORDS\n")
            misspellings, words = 0, 0
            word = ''
            for c in file.read():
                # Allow only alphabetical characters and apostrophes
                if c.isalpha() or (c == "'" and word):
                    word += c
                else:
                    if word:
                        words += 1
                        start_time = time.time()
                        if not check(word):
                            print(word)
                            misspellings += 1
                        end_time = time.time()
                        time_check += calculate(start_time, end_time)
                        word = ''  # Reset for next word

            # Check for any error while reading
            if file.closed:
                print(f"Error reading {text}.")
                unload()
                return 1

    except FileNotFoundError:
        print(f"Could not open {text}.")
        unload()
        return 1

    # Determine dictionary's size
    start_time = time.time()
    n = size()
    end_time = time.time()
    time_size = calculate(start_time, end_time)

    # Unload dictionary
    start_time = time.time()
    unload()
    end_time = time.time()
    time_unload = calculate(start_time, end_time)

    # Report benchmarks
    print(f"\nWORDS MISSPELLED:     {misspellings}")
    print(f"WORDS IN DICTIONARY:  {n}")
    print(f"WORDS IN TEXT:        {words}")
    print(f"TIME IN load:         {time_load:.2f}")
    print(f"TIME IN check:        {time_check:.2f}")
    print(f"TIME IN size:         {time_size:.2f}")
    print(f"TIME IN unload:       {time_unload:.2f}")
    print(f"TIME IN TOTAL:        {time_load + time_check + time_size + time_unload:.2f}\n")

    return 0

# Run the program
if __name__ == "__main__":
    sys.exit(main())

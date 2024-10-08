words = set()

def load(dictionary):
    """Load the dictionary into memory from a file."""
    with open(dictionary, 'r', encoding='utf-8') as file:
        words.update(word.strip().lower() for word in file.readlines())
    return True

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


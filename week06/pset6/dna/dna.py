import csv
import sys


def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py <database> <sequence>")
        return

    # Read database file into a variable
    database_file = sys.argv[1]
    sequences_file = sys.argv[2]

    with open(database_file) as db_file:
        reader = csv.DictReader(db_file)
        database = list(reader)

    # Read DNA sequence file into a variable
    with open(sequences_file) 'r') as seq_file:
        dna_sequence = seq_file.read().strip()

    # Get list of STRs from the database
    str_names = reader.fieldnames[1:]

    # Find longest match of each STR in DNA sequence
    longest_matches = {}
    for str_name in str_names:
        longest_matches[str_name] = longest_match(dna_sequence, str_name)

    # Check database for matching profiles
    for profile in database:
        match_found = True
        for str_name in str_names:
            if int(profile[str_name]) != longest_matches[str_name]:
                match_found = False
                break
        if match_found:
            print(profile['name'])
            return

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

            # Avoid index out of range
            if end > sequence_length:
                break

        longest_run = max(longest_run, count)

    return longest_run


if __name__ == "__main__":
    main()

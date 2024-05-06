import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 2 and len(sys.argv) > 3:
        print("Oopsie you used the wrong number of arguments D: you should use two next time :3")
        return
    # # check to see if arg 0 is a csv file
    # if not sys.argv[0].endswith('.csv'):
    #     print("Oh no, that isn't a csv file :( that won't work can you fix that please?")
    #     return
    # # check to see if arg 1 is a txt file
    # if not sys.argv[1].endswith('.txt'):
    #     print("Oh no, that isn't a txt file :( that won't work can you fix that please?")
    #     return

    # TODO: Read database file into a variable
    rows = []
    with open(sys.argv[0]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    # TODO: Read DNA sequence file into a variable
    sequence = ''
    with open(sys.argv[1]) as file:
        sequence = sequence.join(file.readlines())

    # TODO: Find longest match of each STR in DNA sequence
    str1 = rows[0][2]
    print(str1)

    # TODO: Check database for matching profiles

    return


# Given entire DNA sequence and an STR (ACTG) as inputs, outputs the longest repitition
def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

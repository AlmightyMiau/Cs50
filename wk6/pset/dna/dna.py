import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 2 and len(sys.argv) > 3:
        print("Oopsie you used the wrong number of arguments D: you should use two next time :3")
        return

    # TODO: Read database file into a variable
    database = sys.argv[1]
    rows = []
    fields = []
    with open(database) as file:
        reader = csv.DictReader(file)
        fields = reader.fieldnames
        for row in reader:
            rows.append(row)

    # TODO: Read DNA sequence file into a variable
    text = sys.argv[2]
    sequence = ''
    with open(text) as file:
        sequence = sequence.join(file.readlines())

    # TODO: Find longest match of each STR in DNA sequence
    matches = []
    for field in fields:
        if field != 'name':
            matches.append(longest_match(sequence, field))
        else:
            matches.append('')

    # TODO: Check database for matching profiles
    for person in rows:
        counter = 1
        for i in range(len(fields)):
            if fields[i] != 'name':
                if int(person[fields[i]]) == matches[i]:
                    counter += 1
                else:
                    break
        if counter == len(fields):
            print(person['name'])
            return

    print('No match')
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

import csv, sys

# Open the CSV file
with open(sys.argv[1]) as csvfile:
    # Create a CSV reader object
    reader = csv.reader(csvfile)

    # Get the header (first line)
    header = next(reader)

    # Get the rest of the data
    data = list(reader)

# Print the header and data to verify
print("Header:", header)
print("Data:", data)

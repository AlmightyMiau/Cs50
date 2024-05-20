
# DOESN'T WORK BECAUSE WE DON'T HAVE FAVORITES.CSV



import csv

with open("favorites.csv") as file:
    reader = csv.DictReader(file)
    counts = {}

    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in sorted(counts, key=counts.get):
    print(favorite, ':', counts[favorite])


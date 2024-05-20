
# DOESN'T WORK BECAUSE WE DON'T HAVE FAVORITES.CSV



import csv

from collections import Counter

with open("favorites.csv") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")

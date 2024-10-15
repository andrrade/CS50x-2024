import csv

from collections import Counter

# file = open("favorites.csv", "r")
# # Do something with file
# close(file)

with open("favorites.csv", "r") as file: # "witg" means that the file will be automatically closed later
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        favorite = row["language"]
        counts[favorite] += 1

favorite = input("Favorite: ")
print(f"{favorite}: {counts[favorite]}")

    # counts = {} # or: dict()

    # for row in reader:
    #     favorite = row["language"]
    #     if favorite in counts:
    #         counts[favorite] += 1
    #     else:
    #         counts[favorite] = 1

# for favorite in sorted(counts, key=counts.get, reverse=True): # for something in that dictionary # get the value for that key
# for favorite, count in counts.most_common():
#     print(f"{favorite}: {count}")


#     # next(reader) # skip the header
#     # for row in reader:
#     #     print(row["language"])

#     scratch, c, python = 0, 0, 0

#     for row in reader:
#         favorite = row["language"]
#         if favorite == "Scratch":
#             scratch += 1
#         elif favorite == "C":
#             c += 1
#         elif favorite == "Python":
#             python += 1

# print(f"Scratch: {scratch}")
# print(f"C: {c}")
# print(f"Python: {python}")

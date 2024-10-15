import csv

# file = open("favorites.csv", "r")
# # Do something with file
# close(file)

with open("favorites.csv", "r") as file: # "witg" means that the file will be automatically closed later
    reader = csv.DictReader(file)
    # next(reader) # skip the header
    # for row in reader:
    #     print(row["language"])
    scratch, c, python = 0, 0, 0

    for row in reader:
        favorite = row["language"]
        if favorite == "Scratch":
            scratch += 1
        elif favorite == "C":
            c += 1
        elif favorite == "Python":
            python += 1

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")

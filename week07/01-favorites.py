import csv

# file = open("favorites.csv", "r")
# # Do something with file
# close(file)

with open("favorites.csv", "r") as file: # "witg" means that the file will be automatically closed later
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        print(row[1])

names = ["Carter", "David", "John"]

name = input("Name: ")

# for n in names:
#     if (name == n):
#         print("Found")
#         break
# else: # for lloops can have an else clause
#     print("Not found")

if name in names:
    print("Found")
else:
    print("Not found")

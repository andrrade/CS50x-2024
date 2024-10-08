s = input("Do you agree? [y/n]: ")

s = s.lower() # oop

# if (s == "Y") or (s == "y"):
#     print("Yes :)")
# elif (s == "N") or (s == "n"):
#     print("No :(")
# else:
#     print("Invalid Option :|")

if s in ["y", "yes"]:
    print("Yes :)")
elif n in ["n", "no"]:
    print("No :(")
else:
    print("Invalid :|")

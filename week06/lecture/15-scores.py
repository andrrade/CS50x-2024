from cs50 import get_int

scores = []
for _ in range(3):
    score = get_int("Score: ")
    scores.append(score)
    # or
    # scores += [score]

average = sum(scores) / len(scores)
print(f"Average: {average}")
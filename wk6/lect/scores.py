# scores = [72, 73, 33]
#
# avg = sum(scores) / len(scores)
# print("Average: ", avg)


from cs50 import get_int

scores = []
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)

avg = sum(scores) / len(scores)
print("Average: ", avg)

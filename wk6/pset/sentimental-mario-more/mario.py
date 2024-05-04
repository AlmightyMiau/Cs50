# import get_int
# get input using get_int
# make sure the input is between 1 and 8
# print the pyramids
# for i in range(input - 1):
    # print(" " * (input - i - 1), "#" * i + 1)

from cs50 import get_int

size = 0

# while size < 1 and size > 8:
size = get_int("Height: ")

for i in range(size - 1):
    print(" " * (size - i - 1), "#" * (i + 1), "", "#" * (i + 1), " " * (size - i - 1))


from cs50 import get_int


while True:
    size = get_int("Height: ")
    if size > 0 and size < 9:
        break

for i in range(size):
    print(' ' * (size - i - 1), end='')
    print("#" * (i + 1), end='')
    print("  ", end='')
    print("#" * (i + 1))


# import get_int
# get input using get_int
# make sure the input is between 1 and 8
# print the pyramids
# for i in range(input - 1):
# print(" " * (input - i - 1), "#" * i + 1)

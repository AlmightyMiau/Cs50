from cs50 import get_float

while True:
    cents = get_float("Chnage: ")
    if cents > 0:
        break

quarters = round((cents / 25), 2)
cents =

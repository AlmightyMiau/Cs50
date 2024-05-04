from cs50 import get_float

while True:
    cents = get_float("Change: ")
    if cents > 0:
        break

print(cents)

cents = round(cents, 2)
quarters = cents // 0.25
cents -= quarters * 0.25
cents = round(cents, 2)
print(cents)

cents = round(cents, 2)
dimes = cents // 0.10
cents -= dimes * 0.10
cents = round(cents, 2)
print(cents)

cents = round(cents, 2)
nickels = cents // 0.05
cents -= nickels * 0.05
cents = round(cents, 2)
print(cents)

cents = round(cents, 2)
pennies = cents // 0.01
cents -= pennies * 0.01
cents = round(cents, 2)
print(cents)

coins = quarters + dimes + nickels + pennies
print(int(coins))

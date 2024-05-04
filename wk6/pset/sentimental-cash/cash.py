from cs50 import get_float

while True:
    cents = get_float("Change: ")
    if cents > 0:
        break

quarters = cents // 0.25
cents -= quarters * 0.25

dimes = cents // 0.10
cents -= dimes * 0.10

nickels = cents // 0.05
cents -= nickels * 0.05

pennies = cents // 0.01
cents -= pennies * 0.01

coins = quarters + dimes + nickels + pennies
print(int(coins))

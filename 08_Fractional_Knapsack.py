
# Practical 8: Fractional Knapsack

# Read number of items
n = int(input("Enter number of items: "))

items = []

for i in range(n):
    profit = int(input("Enter profit: "))
    weight = int(input("Enter weight: "))

    # Calculate profit per unit weight
    ratio = profit / weight
    items.append((ratio, profit, weight))

capacity = int(input("Enter knapsack capacity: "))

# Sort items by profit/weight ratio in descending order
items.sort(reverse=True)

total_profit = 0

# Select items to maximize profit
for ratio, profit, weight in items:

    if capacity >= weight:
        # Take the complete item
        total_profit += profit
        capacity -= weight

    else:
        # Take only the required fraction
        total_profit += ratio * capacity
        capacity = 0
        break

print("Maximum Profit:", total_profit)

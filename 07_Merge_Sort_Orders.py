
# Practical 7: Merge Sort for Online Orders

# Merge two sorted lists
def merge(left, right):
    result = []
    i = j = 0

    # Compare delivery times and merge
    while i < len(left) and j < len(right):
        if left[i][1] <= right[j][1]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Add remaining orders
    result += left[i:]
    result += right[j:]

    return result


# Divide and sort the orders
def merge_sort(orders):
    if len(orders) <= 1:
        return orders

    mid = len(orders) // 2

    left = merge_sort(orders[:mid])
    right = merge_sort(orders[mid:])

    return merge(left, right)


# Main program
orders = []
n = int(input("Enter number of orders: "))

for i in range(n):
    order_id = input("Enter order ID: ")
    time = int(input("Enter delivery time: "))

    orders.append((order_id, time))

# Sort orders by delivery time
orders = merge_sort(orders)

print("\nOrders sorted by delivery time:")
for order in orders:
    print("Order ID:", order[0], "Delivery Time:", order[1])

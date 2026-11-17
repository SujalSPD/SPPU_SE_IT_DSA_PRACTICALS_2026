
# Practical 9: Naive String Matching

# Search pattern in text
def naive_search(text, pattern):
    n = len(text)
    m = len(pattern)
    positions = []

    # Check every possible starting position
    for i in range(n - m + 1):

        # Compare pattern with text
        if text[i:i + m] == pattern:
            positions.append(i)

    return positions


# Main program
text = input("Enter text: ")
pattern = input("Enter pattern: ")

result = naive_search(text, pattern)

if result:
    print("Pattern found at positions:", result)
else:
    print("Pattern not found")

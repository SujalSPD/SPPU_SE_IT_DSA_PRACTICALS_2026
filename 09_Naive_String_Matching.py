def naive_search(text, pattern):
    n = len(text)
    m = len(pattern)

    if m == 0:
        print("Pattern found at indices:", list(range(n + 1)))
        return

    found = False

    for i in range(n - m + 1):
        j = 0

        while j < m and text[i + j] == pattern[j]:
            j += 1

        if j == m:
            print("Pattern found at index:", i)
            found = True

    if not found:
        print("Pattern not found")

text = input("Enter text: ")
pattern = input("Enter pattern: ")

naive_search(text, pattern)

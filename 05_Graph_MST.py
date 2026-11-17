
# Practical 5: Minimum Spanning Tree using Prim's and Kruskal's

# Create graph using adjacency list
n = int(input("Enter number of vertices: "))
graph = [[] for i in range(n)]
edges = []

e = int(input("Enter number of edges: "))

for i in range(e):
    u, v, w = map(int, input("Enter source destination weight: ").split())
    graph[u].append((v, w))
    graph[v].append((u, w))
    edges.append((w, u, v))


# Prim's Algorithm
def prim():
    visited = [False] * n
    visited[0] = True
    cost = 0

    print("Prim's MST:")
    for i in range(n - 1):
        minimum = float('inf')
        for u in range(n):
            if visited[u]:
                for v, w in graph[u]:
                    # Select minimum edge to an unvisited vertex
                    if not visited[v] and w < minimum:
                        minimum = w
                        a, b = u, v

        if minimum == float('inf'):
            print("Graph is disconnected")
            return

        print(a, "-", b, ":", minimum)
        cost += minimum
        visited[b] = True

    print("Total Cost:", cost)


# Kruskal's Algorithm
def kruskal():
    parent = list(range(n))
    cost = 0

    # Find the parent of a vertex
    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]

    print("Kruskal's MST:")

    # Sort edges by weight
    for w, u, v in sorted(edges):
        a, b = find(u), find(v)

        # Add edge only if it does not form a cycle
        if a != b:
            parent[a] = b
            print(u, "-", v, ":", w)
            cost += w

    if len(set(find(i) for i in range(n))) > 1:
        print("Graph is disconnected")
    else:
        print("Total Cost:", cost)


# Main menu
while True:
    print("\n1. Prim's Algorithm")
    print("2. Kruskal's Algorithm")
    print("0. Exit")

    ch = int(input("Enter choice: "))

    if ch == 1:
        prim()
    elif ch == 2:
        kruskal()
    elif ch == 0:
        break
    else:
        print("Invalid choice")

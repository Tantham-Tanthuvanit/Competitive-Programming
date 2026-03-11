# DEPTH FIRST SEARCH

## INTUITION
- finding the order in how we can explore all the verticies
- think of it as exploring the graph
- if it hits a dead end it then retraces steps

> [!WARNING] DFS can have multiple valid orders for the same graph
> Always pick the vertex with the smaller value unless instructions say so otherwise

---

## IMPLIMENTATION
- pseudo code implimentation
    ```python
    def dfs(G,v):
        visit(v)
        for w in G.neighbors(v):
            dfs(G,w)
    ```
- same implimentation just with marking nodes
    ```python
    marked = [False] * G.size()
    def dfs(G, v):
        visit(v)
        marked[v] = True
        for w in G.neighbors(v):
            if not marked[w]:
                dfs(G,w)
    ```

---

## PREORDER DFS
- Output vertex as part of order as soon as it encounters a vertex

## POSTORDER DFS
- Only add vertecies as part of order when it reaches a dead end

---

# USE CASES
1. Cycle Detection
2. Finding Connected Components
3. Topological Sort
4. Maze Generation

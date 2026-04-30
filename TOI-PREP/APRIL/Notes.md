# APRIL NOTES

> [!NOTE] 16 APRIL 2026

### What I have learnt
dfs finnaly memorized and bfs almost memorized, cycle detection works by creating a newvector of intigers size n to store states of each node, with 1 being explored, 2 being completed and 0 no being explored. We go through dfs normally but this time we check if a neighboring node is at state 1, if so then return true which means we have found a cycle. if we have found a state 0 node then we know it has not been explored so we reccursively call dfs on it and make a statement to check if it returns true, if so then return true as well. if function returns true in the end then we know the graph it was exploring definately contains a cycle

## What to improve on
start memorizing cycles problems on directed AND undirected graphs

> [!NOTE] 20 APRIL 2026

### What I have learnt
learned and started memorizing kruskals algorithm [ FINALLY ] and started on the 2nd mst problem, Second mst differes to mst by exactly 1 edge so take an edge NOT in the mst and add it so that it creates a cylce, then remove the maxmimum weight edge in that cycle to get a new mst

## What to improve on
fully memorizing it

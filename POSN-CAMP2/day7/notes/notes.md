# DIVIDE AND CONQURE

> [!NOTE] DC template for most problems

``` cpp
prodecure dc {
    if base case then solve {
        solve
    }

    else {
        partition into l and r subproblems
        solve l
        solve r
        combine l and r solutions
    }
}
```

## USE CASES
- sorting
- modular exponentiation
- intiger multiplication
- matrix multiplication
- closest pair of points

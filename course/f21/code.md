## Problems
<!-- AUTO-GENERATED-CONTENT:START (TOC:collapse=true&collapseText="Click to expand") -->
<details>
<summary>Index</summary>

- [Rat in a Maze](#problem1)
- [Sudoku Puzzle](#problem2)

</details>
<!-- AUTO-GENERATED-CONTENT:END --> 

## Problem1
### Rat in a Maze
```cpp
bool isSafe( vector<vi> &maze, int i, int j, int n)
{
  return (i<n && j<n && maze[i][j]==1);
}

bool recur_Maze(vector<vi> &maze, int i, int j, vector<vi> &sol, int n)
{
  // Base Condition
  if( i==n-1 && j==n-1 ){
    sol[i][j]= 1; return true;
  }
  // Backtracking condition
  if( isSafe(maze, i,j, n) ){
    sol[i][j]=1;
    if( recur_Maze(maze, i+1,j, sol, n) || recur_Maze(maze, i, j+1, sol, n) )
      return true;
    sol[i][j]=0;
  }
  // current path is not good
  return false;
}
```
## Problem2
### Sudoku Puzzle
```cpp
```
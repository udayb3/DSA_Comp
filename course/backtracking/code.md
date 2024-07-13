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
bool isSafe( vector< vi> &grid, int i, int j, int val)
{
  int n= grid.size();
  // Checking in the current row\column
  for( int k=0;k<n;k++){
    if( grid[k][j]==val || grid[i][k]==val)
      return false;
  }

  // Finding the starting row index and column index of the grid
  int s=sqrt( n), rowst= i- (i%s), colst= j- (j%s);

  // Checking in the grid grid
  for(int i=0;i<s;i++){
    for(int j=0;j<s;j++){
      if( grid[ i+rowst ][j+colst]==val )
        return false;
    }
  }
  return true;
}

bool Sudoku( vector<vi> &grid, int n)
{
  int i=0,j=0; bool ch=false;
  for( i=0;i<n;i++){
    for( j=0;j<n;j++){
      if( grid[i][j]==0 ){
        ch=true;; break; 
      }
    }
    if(ch)
      break;
  }
  if(i==n && j==n)
    return true;

  for(int k=1;k<=n;k++){
  
    if( isSafe( grid, i,j,k ) ){
      grid[i][j]= k;
  
      if( Sudoku(grid, n) )
        return true;
  
      grid[i][j]=0;
    }    
  }
  return false;
}
```
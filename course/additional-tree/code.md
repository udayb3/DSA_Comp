## Problems

<!-- AUTO-GENERATED-CONTENT:START (TOC: collapse=true&collapseText="Click to expand") -->
<details>
<summary>Index</summary>

- [Building a Segment tree](#problem1)
- [Performing Range Queries](#problem2)
- [Updating the Segment tree](#problem3)
- [Updating value in Binary Indexed tree](#problem4)
</details>
<!-- AUTO-GENERATED-CONTENT:END -->

## Problem1
### Building a segment tree: take the size of tree as 4*n or 5*n, take it as upper bound 
```cpp
int BuildSegtree( vi &arr, int st, int en, vi &tree, int ind)
{
  // Base case
  if( st==en ){
    tree[ind]= arr[st];
    return arr[st];
  }

  // Recurrence relation
  int md= st+ (en-st)/2;
  int lt= 2*ind+1, rt= 2*ind +2;
  tree[lt]= BuildSegtree( arr, st, md, tree, 2*ind+1 ); tree[rt]= BuildSegtree( arr, md+1, en, tree, 2*ind + 2);
  tree[ind]= tree[lt]+tree[rt];
  return tree[ind];
}
```
## Problem2
### Performing Range Queries
```cpp
int getOperation(vi &tree, int qus, int que, int cqs, int cqe, int ind)
{
  // base condition: When the user range is not in our range or when the user range is totally inside
  if( cqe<qus || cqs>que )
    return 0; // Can be 1 depending upon operation
  if( qus<=cqs && que>=cqe )
    return tree[ind];

  // jab overlap kar rahe hai
  int md= cqs + (cqe-cqs)/2;
  return getOperation(tree, qus, que, cqs, md, 2*ind+1) + getOperation( tree, qus, que, md+1, cqe, 2*ind+2);
}
```
## Problem3
### Updating the Segment Tree 
```cpp
void updateSegtree(vi &tree, int st, int en, int ky, int val, int ind)
{
  // Base case
  if(ky<st || ky>en)
    return;
  
  tree[ind]=tree[ind]+val;

  if( en>st ){
    int md= st + (en-st)/2;
    updateSegtree(tree, st, md, ky, val, 2*ind+1 );
    updateSegtree(tree, md+1, en, ky, val, 2*ind+2);
  } 
}
```
## Problem4
### Updating value in Binary Indexed tree
```cpp
void update(vi &arr, int n, vi &tree, int val, int ind)
{
  int dif= val-arr[ind]; arr[ind]=val;
  ind+= 1;
  while(ind<n+1){
    // updating the index in the tree as we go down in the tree
    tree[ind]+= dif; ind+= ind&(0-ind);
  }
}
```
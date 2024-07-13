## Searching in a BST[normal]: O( h )
```cpp
bool searchBST(tnode *root, int val)
{
  while(root!=NULL){
    if(root->dt > val)
      root= root->lt;
    else if(root->dt < val)
      root= root->rt;
    else
      return true;
  }
  return false;
}
```

## Insertion in a BST[normal]: O( h )
### One way here is to write the simple recursive approach with O( h ) space overhead. The bottom approach is iterative and better.
```cpp
tnode *InsertBST(tnode *root, ll val)
{
  tnode *t1= new tnode(val);
  tnode *par=NULL, *cur= root;
  while(cur!=NULL){

    par= cur;
    if(cur->dt > val)
      cur= cur->lt;
    else if(cur->dt<val)
      cur=cur->rt;
    else
      return root;
  }

  if(par==NULL)
    return t1;

  if(par->dt < val)
    par->rt= t1;
  else
    par->lt= t1;
  
  return root;
}
```

## Deletion in a BST[normal]: O( h )
### For the case when target node has both children, we have replaced the target node with its inorder successor
```cpp
tnode *minValue(tnode *nd)
{
  tnode *cur; cur= nd;
  while( cur->lt!=NULL){
    cur= cur->lt;
  }
  return cur;
}

tnode *removeBST( tnode *root, ll val)
{
  if(root==NULL)
    return root;

  if(root->dt > val)
    root->lt= removeBST(root->lt, val);
  else if(root->dt < val)
    root->rt- removeBST(root->rt, val);
  else{
    // Case for when the node has 1/0 children
    if( root->lt==NULL){
      tnode *t1= root->rt;
      free(root);
      return t1;
    }
    else if(root->rt==NULL){
      tnode *t1= root->lt;
      free(root);
      return t1;
    }

    // Case for when the node has 2 children
    tnode *t1= minValue( root->rt );
    root->dt= t1->dt;
    root->rt= removeBST( root->rt, t1->dt );
  }
  return root;
}
```
## Finding floor of a given number in a BST
```cpp
tnode *floorBST(tnode *root, ll val)
{
  tnode *ans= NULL, *cur=root;
  while(cur!=NULL ){

    if(cur->dt == val)
      return cur;
    else if(cur->dt > val)
      cur= cur->lt;
    else{
      ans= cur;
      cur= cur->rt;
    }
  }
  return ans;
}
```

## Checking if a Binary tree is BST or not
```cpp
int prev=INT_MIN;
bool isBST( tnode *root)
{
  if(root == NULL)  return true;

  if(isBST(root->lt)== false) return false;

  if(root->dt >= prev)  return false;
  prev= root->dt;
  return isBST(root->dt);
}
```

## Vertical Traversal of Binary tree
```cpp
```
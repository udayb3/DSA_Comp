## Traversals:

### In-order(left->root->right)
### Pre-order(root->left->right)
### Post-order(left->right->root)
### Level-wise traversal
```cpp
void Level(tnode *root)
{
  if(root==NULL){
    return;
  }
  queue<tnode *> qu; qu.push(root);

  while(!qu.empty()){
  
    tnode *t1= qu.front();
    cout << t1->dt;
  
    qu.pop();
    if(t1->lt!=NULL)
      qu.push(t1->lt);
    if(t1->rt!=NULL)
      qu.push(t1->rt);
  }
}
```
## Print nodes with distance k from root
```cpp
void rootdisk(tnode *root, int k)
{
  if(root==NULL)
    return;
  if(k==0)
    cout << root->dt << " ";
  rootdisk(root->lt, k-1);
  rootdisk(root->rt, k-1);
}
```
## Level-wise traversal with a indication for new level
```cpp
void Levelind(tnode *root)
{
  if(root==NULL)
    return;

  queue<tnode *> qu; qu.push(root);
  while(!qu.empty()){
    int sz= qu.size();
    for(int i=0;i<sz;i++){
      tnode *t1= qu.front();  qu.pop();
      cout << t1->dt << " ";
      
      if((t1->lt)!=NULL)
        qu.push(t1->lt);
      if((t1->rt)!=NULL)
        qu.push(t1->rt);
    }
    cout << "\n";
  }
}
```
## Searching for a node in the Binary tree
```cpp
tnode *searchVal(tnode *root, ll val)
{
  queue<tnode *> qu;  qu.push(root);
  while( !qu.empty()){
    tnode *t1= qu.front(); qu.pop();
    if(t1->dt==val)
      return t1;
    
    if(t1->lt!=NULL)
      qu.push(t1->lt);
    if(t1->rt!=NULL)
      qu.push(t1->rt);
  }
  return NULL;
}
```
## Delete node[By replacing it with the deepest rightmost node]
```cpp
void delNode(tnode *root, ll val)
{
  tnode *elm;
  while(searchVal(root, val) != NULL){

    elm= searchVal(root, val);
  
    // Doing level order traversal until last node
    struct tnode* t1; queue<tnode *> q; q.push(root); 
    while(!q.empty())
    { 
      t1 = q.front(); 
      q.pop();
      if(t1->lt!=NULL)
        q.push(t1->lt);
      if (t1->rt!=NULL) 
        q.push(t1->rt); 
    }
    
    ll t2=elm->dt; elm->dt= t1->dt; t1->dt= t2; elm=t1; 
    q.push(root);
 
    while(!q.empty()) 
    { 
      t1 = q.front(); q.pop();
 
      if(t1->rt!=NULL){
        if(t1->rt==elm){
          t1->rt= NULL; free(elm); break;
        }
        else
          q.push(t1->rt);
      }
      if (t1->lt!=NULL){
        if(t1->lt==elm){
          t1->lt= NULL; free(elm); break;
        }
        else{
          q.push( t1->lt );
        }
      } 
    }
  }
}
```
## Print left view of Binary tree[logic is to find the first element of each level]
```cpp
```
## Check if the Binary tree is balance/not
```cpp
```
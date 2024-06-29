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
## Path finding algorithm for a node of tree: Time com.:O(n), Space com.:O(h)
```cpp
bool PathFind(tnode *root, vector<ll> &st, ll val)
{
  if(root==NULL)
    return false;

  st.push_back( root->dt );
  if(root->dt==val)
    return true;

  if( (root->lt!=NULL && PathFind(root->lt, st, val)) || (root->rt!=NULL && PathFind(root->rt, st, val)) ){
    return true;
  }

  st.pop_back();
  return false;
}
```
## Finding Lowest common ancestor
```cpp
ll LCA(tnode *root, ll val1, ll val2)
{
  vl path1, path2;
  bool ch1= PathFind(root, path1, val1), ch2= PathFind(root, path2, val2);
  if(!ch1 || !ch2){
    return -1;
  }
  int sz1= path1.size(), sz2= path2.size(); ll ans;
  for(int i=0;i<min(sz1,sz2);i++){
    if(path1[i] == path2[i])
      ans= path1[i];
    else
      break;
  }
  return ans;
}
```
## Find height of Binary tree
```cpp

ll find_height(tnode *root)
{
  if(root==NULL)
    return 0;

  queue<tnode *> qu;  qu.push(root); ll ans=0;
  while(!qu.empty()){
    int sz= qu.size(); ans++;
    for(int i=0;i<sz;i++){
      tnode *t1= qu.front(); qu.pop();
      if(t1->lt!=NULL)
        qu.push(t1->lt);
      if(t1->rt!=NULL)
        qu.push(t1->rt);
    }
  }
  return ans;
}
```
## Find Diameter of the binary tree 
```cpp
ll findDiameter(tnode *root)
{
  // Base Condition
  if(root==NULL)
    return 0;

  // recursive relation
  ll lng= find_height(root->lt) + find_height(root->rt) + 1;
  return max( lng, max( findDiameter(root->lt), findDiameter(root->rt)) );
}
```
## Showing the top view[logic here is that right child takes ordering +1 and left child takes ordering-1 ]
```cpp
void topView(tnode *root, vl &ans)
{
  if(root==NULL)
    return;
  map<ll,ll> mp1;
  queue< pair<tnode *, int>> qu;  qu.push( MP(root, 0) );

  while(!qu.empty()){
    int sz= qu.size();
    for(int i=0;i<sz;i++){
      pair<tnode *, int> t1= qu.front(); qu.pop();
      if( mp1.find(t1.sec)==mp1.end() )
          mp1[t1.sec]= (t1.fir)->dt;
      
      if((t1.fir)->lt!=NULL){
        qu.push( MP( (t1.fir)->lt, t1.sec -1) );
      }
      if( (t1.fir)->rt!=NULL){
        qu.push(  MP( (t1.fir)->rt, t1.sec +1) );
      }
    }
  }

  for(auto it=mp1.begin();it!=mp1.end();it++){
    ans.PB(it->sec);
  }
}
```
## Check if the Binary tree is balance/not
```cpp
int Balance(tnode *root)
{
  // Base condition
  if(root==NULL)
    return 0;
  // Checking if the left and right sub-tree are balanced and if yes, then getting their height in the same recursive call
  int lth= Balance(root->lt);
  if(lth==-1){return -1;}
  int rth= Balance(root->rt);
  if(rth==-1){return -1;}

  // checking if tree rooted at current node is balanced or not
  if( abs(lth-rth)>1 )
    return -1;
  else
    return max(lth, rth)+1;
}
```
## Generate binary tree from inorder and preorder traversal[using hashing]
```cpp
void Preprocess(umll &mp, vl &ino)
{
  for(int i=0;i<ino.size();i++){
    mp[ ino[i] ]= i;
  }
}

int indpre=0;
tnode *ConstructTree(umll &ino , vl &pre, int ist, int ien )
{
  // Checking if the size of the partition is less than 1
  if(ist>ien)
    return NULL;
  tnode *root= new tnode( pre[indpre]); indpre++;

  // using unordered map to find out the position of value from preorder array
  int ind= ino[root->dt];
  root->lt= ConstructTree(ino, pre, ist, ind-1);
  root->rt= ConstructTree(ino, pre, ind+1, ien);
  return root;
}
```
## Burning the Binary tree
```cpp
```
## Serialization & Deserialisation[using levelwise-traversals]
```cpp
```
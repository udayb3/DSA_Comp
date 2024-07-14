## Problems
<!-- AUTO-GENERATED-CONTENT: START (TOC:collapse:true&collapseText="Click to expand") -->
<details>
<summary>Index</summary>

- [Structue of trie node](#problem1)
- [Insertion in Trie](#problem2)
- [Search in Trie](#problem3)
- [Deletion in Trie](#problem4)

</details>
<!-- AUTO-GENERATED-CONTENT: END -->

## Problem1
### Structure of Trie node and initialisation
```cpp
struct trien{
  trien * next[alpha_size];
  bool isEnd;
  trien()
  {
    isEnd=false; 
    for(int i=0;i<alpha_size;i++)
      next[i]= NULL;
  }

};
```

## Problem2
### Insertion in Trie
```cpp
void inserttrien( trien *root, string key)
{
  trien *st= root; int sz= SZ(key);

  for( int i=0;i<sz;i++){
    int ind= key[i]-'a';
    if( st->next[ind] ==NULL )
      st->next[ind]=  trien();

    st= st->next[ind];
  }
  st->isEnd= true;
}
```

## Problem3
### Search in trie
```cpp
bool searchtrien( trien *root, string key)
{
  trien *st= root; int sz= SZ( key );
  for(int i=0;i<sz;i++){
    
    int ind= key[i]-'a';
    if( st->next[ind]==NULL)
      return false;
    
    st= st->next[ind];
  }
  if( st!=NULL || st->isEnd==true )
    return true;
  else
    return false;
}
```

## Problem4
### Removal in trie
```cpp
bool isEmpty( trien *root){

  // Checking if all its next node are null
  for(int i=0;i<alpha_size;i++){
    if( root->next[i]!=NULL )
      return true;
  }
  return false;
}
trien *removetrien( trien *root , string key, int depth )
{
  // When root is NULL
  if(root==NULL)
    return NULL;

  // when depth is equal to size of key
  if( depth== key.size() ){
    // if this is the end of string then make it false;
    if( root->isEnd )
      root->isEnd=false;
    
    // if it has no children then delete this node
    if( isEmpty(root) ){
      free(root); root= NULL;
    }
  return root;
  }

  // Proceeding to the next node if the depth has not reached the length of key
  int ind= key[depth]-'a';
  root->next[ind]= removetrien(root->next[ind], key, depth + 1);

  // if it has no next node now
  if( isEmpty(root) ){
    free(root); root=NULL;
  }
  return root;
}```
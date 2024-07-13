## Implementing Stack using queue
```cpp
struct mstack
{
  queue<int> ent, bck;
  mstack(){

  }
  int top(){
    return q1.front();
  }
  int size(){
    return q1.size();
  }
  void pop(){
    q1.pop();
  }
  void inssert(int v)
  {
    
    while(!ent.empty()){
      bck.push_back(ent.top());
      ent.pop();
    }
    ent.push_back(v);
    while(!bck.empty()){
      ent.push_back(bck.top());
      bck.pop();
    }
  }
}
```

## Generating number using the given digits
```cpp
vstr Gennum(set<string> arr, int n)
{
  queue<string> qu;
  for(auto it=arr.begin(); it!=arr.end(); it++){
    qu.push(*it);
  }
  vstr ans;
  while(n--){
    string p= qu.front();
    ans.push_back( p );
    for(auto it=arr.begin(); it!=arr.end(); it++){
      string q= *it;
      string t= qu.front();
      qu.push(t+q );
    }
    qu.pop();
  }
  return ans;
}
```
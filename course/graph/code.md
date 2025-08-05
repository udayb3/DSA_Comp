## Breadth-first traversal of graph
#### In Fully-Connected graph
```cpp
void GrBFT(vvl &gr, vl &ans, int st, vb &vis)
{
  
  queue<int> qu; qu.push(st); vis[st]=true;
  while( !qu.empty() ){
    ll fr= qu.front(); ans.PB(fr); 
    qu.pop(); 
    vis[fr]=true;

    for(auto a:gr[fr]){
      if(!vis[a])
      { qu.push(a); vis[a]=true;}
    }
  }
}
```
#### In Dis-connected graph
```cpp
void dGrBFT(vvl &gr, vl &ans, int st)
{
  vector<bool> vis(n,false);
  for(int i=0;i<gr.size();i++){
    if(vis[i]==false)
      GrBFT(gr, ans, i,vis );
  }
}
```
## Depth-first traversal of graph
#### In Fully-Connected graph
```cpp
void GrDFT(vvl &adl, vl &ans, int st, vb &vis)
{
  stack<int> st1; st1.push(st); vis[st]=true;
  while( !st1.empty() )
  {
    ll cur= st1.top(); st1.pop();
    ans.PB(cur);
    for( auto neigh:adl[cur] ){
      if( !vis[neigh] ){
        st1.push( neigh ); vis[neigh]= true;
      }
    }
  }
}
```
#### In Dis-connected graph
```cpp
void dGrDFT(vvl &adj, vl &ans, int st)
{
  vector<bool> vis(n,false);
  for(int i=0;i<adj.size();i++){
    if( vis[i]==false)
      GrDFT(adj, ans, st, vis);
  }
}
```
## Detecting cycle in the graph
#### In Undirected Graph
```cpp
bool util(vvl &adj, vb &vis, int st, int par)
{
  vis[st]= true;
  stack< pair<int, int> > st1; st1.push( MP(st,par) );
  
  while( !st1.empty() ){
    auto cur= st1.top(); st1.pop();

    for( auto neigh:adj[cur.fir] ){
      if( !vis[neigh] ){
        st1.push( MP(neigh, cur.fir) ); vis[neigh]= true;
      }
      else if( neigh!= cur.sec )
        return true;
    }
  }
  return false;
}

bool isCycle(vvl &adj)
{
  vb vis(adj.size(), false);
  for(int i=0;i<adj.size();i++){
    if(vis[i]==false){
      if( util(adj, vis, i, -1) )
        return true;
    }
  }
  return false;
}
```
#### For Directed graph
```cpp
bool ICDutil(int u, vvl &adj, vb &vis, vb &visst)
{
  vis[u]= true; visst[u]= true;
  for(auto v:adj[u] ){
    if( !vis[v] && ICDutil(v, adj, vis, visst) )
      return true;
    else if( visst[v]== true )
      return true;
  }
  visst[u]= false;
  return false;
}

bool IsCycleDg( vvl &adj)
{
  int nv= adj.size();
  vb vis(nv, false), visst(nv, false);
  for(int i=0;i<nv;i++){
    if(vis[i]==false && ICDutil(i, adj, vis, visst) )
      return true;
  }
  return false;
}
```
## Printing vertices after sorting them topologically[ Kahn's Algorithm ]
```cpp
void TopSort( vvl &adj, vi &ans)
{
  int nv= adj.size();
  
  // Storing the indegree of each vertex
  vi indeg(nv, 0);
  for( int u=0;u<nv;u++ ){
    for( auto v: adj[u] ){
      indeg[v]++;
    }
  }

  // Create a queue and add all vertices with in-degree 0 to it
  queue<int> qu;
  for(int i=0;i<nv;i++){
    if( indeg[i]==0 ){
      qu.push( i );
    }
  }

  // take out the top vertex and update the in-degree of its adjacent
  while( !qu.empty() ){
    int u= qu.front(); qu.pop();
    ans.PB(u);

    for( auto v:adj[u] ){
      indeg[v]--;
      if(indeg[v]==0)
        qu.push(v);
    }
  }
}
```
## Djikstra's Single Source Shortest Path algorithm
```cpp
void Djikstra( vector< vector< pll> > &adj, int v, int src, vi &dis )
{
  priority_queue< pii, vector<pii>, greater<pii> > pq;
  pq.push( MP(0, src) ); dis[src]=0;
  while( !pq.empty() ){
    int cur= pq.top().sec;  pq.pop();
    for( auto neg: adj[cur] ){
      int x= neg.fir, wei= neg.sec;
      if( dis[x] > dis[cur]+ wei){
        dis[x]= dis[cur]+wei; pq.push(MP( dis[x], x ));
      }
    }
  }
}
```
## Djikstra's Shortest Path algorithm for all vertices
### Djikstra's algorithm with finding ways and shortest distance from src to all indices
  - Time Complexity: O( E*log V )
    -  adj	stores the vector for ( neighbour , wt( i , neighbour) ) for the ith vertex for all i
	  - ways	number of ways from src vertex to ith index  for all i
    - dis	distance of src to ith vertex for all i

```cpp
long long usage( vector< vector< pair<int,int> > > &adj, int v, int src  )	{
	vt<ll> dis(v, LLONG_MAX );

	priority_queue< pll, vt<pll>, greater<pll> > pq;
	pq.push( make_pair(0, src) ); dis[src]=0;

	vector<ll> ways(v, 0); 
	ways[src]= 1;

	while( !pq.empty() ){
  	auto [ wt, u ] = pq.top();  pq.pop();
  	if ( wt > dis[u] )  continue;
  
  	for( auto neg: adj[u] ){
    	ll x= neg.fir, wei= neg.sec;
    
    	if( dis[x] > dis[u]+ wei ){
      	dis[x]= dis[u]+wei; 
      	ways[x]= ways[u];
      	pq.push( { dis[x], x } );
    	} else if( dis[x] == dis[u]+ wei ) {
      	ways[x]= ( ways[x]+ ways[u] ) % MOD;
    	}
  	}
	}
	return ways[v-1];
}

```
## Single-source shortest path algorithm: Bellman-ford algotrithm
```cpp
bool Bellmanford(vector<vpii> &adj, vi &dis, int src)
{
  int nv= adj.size();
  dis[src]= 0;

  // The time complexity of the below loop is still O(V*E)
  for(int i=0;i<nv-1;i++){
    
    for( int j=0; j<nv;j++){
      for(auto v: adj[j] ){
        if( dis[v.first] > dis[j] + v.second )
          dis[v.first]= dis[j] + v.second;
      }
    }
  }

  // Checking for negative weight cycles
  for( int j=0; j<nv;j++){
      for(auto v: adj[j] ){
        if( dis[v.first] > dis[j] + v.second )
          return false;
      }
    }
  return true;
}
```
## Prim's minimum spanning tree algorithm
```cpp
int minVer(vi &val, vb &mst)
{
  int pos=-1, mn=INT_MAX;
  for(int i=0;i<val.size();i++){
    if( !mst[i] && val[i]<mn){
      mn= val[i]; pos=i;
    }
  }
  return pos;
}

void Prim(vi &par, vector<vi> &gr)
{

  vi val(gr.size(),INT_MAX);
  vb mst(gr.size(), false);
  int nv= gr.size(); 

  val[0]=0; par[0]= -1; mst[0]=true;
  for(int e1=0;e1<nv;e1++){

    int u= minVer(val, mst);
    mst[u]=true;
    for(int v=0;v<nv;v++){
      if(gr[u][v] && !mst[v] && gr[u][v]<val[v] ){
        par[v]= u; val[v]= gr[u][v];
      }
    }
  }
}
```
## Finding Cut points in a graph
```cpp
void CutUtil(int u, vector<vector<ll>> &adj, vector<int> &par, vector<int> &disc, vector<int> &low, vector<bool> &vis, vector<bool> &cut)
{
  static int tim= 0;
  int nchild= 0;
  tim++;
  
  vis[u]= true;  disc[u]= tim; low[u]= tim;
  for(auto i= adj[u].begin(); i!= adj[u].end(); i++){
    int val= *i;
    if( !vis[val] ){
      nchild++;
      par[val]= u;

      CutUtil(val, adj, par, disc, low, vis, cut);

      low[u]= min( low[u], low[val] );

      if( par[u]==-1 && nchild>1)
        cut[u]=true;
      
      if( par[u]!=-1 && low[u]>=disc[u]){
        cut[u]=true;
      }
    }
    else if(val != par[u])
      low[u]= min( low[u], disc[val] );
  }
}
void CutVertex(vvl &adj)
{
  int nv= adj.size();
  vector<int> par(nv,-1), low(nv, INT_MAX), disc(nv, INT_MAX); vector<bool> vis(nv,false), cut(nv,false);

  for(int i=0;i<nv;i++){
    if( !vis[i] ){
      CutUtil(i, adj, par, disc, low, vis, cut);
    }
  }
  for(int i=0;i<nv;i++){
    if( cut[i]==true )
      cout << i << " ";
  }
}
```
## Finding SCC in a directed graph: _Kosaraju's algorithm_
```cpp
```

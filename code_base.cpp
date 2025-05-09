#include<bits/stdc++.h>
using namespace std;
/*
// separating a sentence into a vector of string using string stream 
inline static vector<string> toStringVec(string& s){
    // s is stored in the string stream object
    stringstream ss(s);
    vector<string> ans; string w;
    // reading word one by one
    while (ss>>w)
        ans.push_back(w);
    ss.clear();
    return ans;
}
// Tower of Hanoi: Printing the steps
	void ToH(ll n, vpi &vc, int st, int mid, int en)
	{
	  if(n)
	  {
	    ToH(n-1, vc, st,en,mid);
	    vc.push_back( make_pair(st,en) );
	    ToH(n-1, vc, mid, st, en);
	  }
	  return ;
	}
int height(struct Node* node) {
    if (node == NULL) 
        return 0;

    return node->height;
}

int getBalanceFactor(struct Node* node) {
    if (node == NULL) 
        return 0;
        
    return height(node->left) - height(node->right);
}

struct Node* leftRotate(struct Node* root) {
    struct Node* newMid = root->right;
    struct Node* temp = newMid->left;

    newMid->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    return newMid;
}

struct Node* rightRotate(struct Node* root) {
    struct Node* newMid = root->left;
    struct Node* temp = newMid->right;

    newMid->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newMid->height = max(height(newMid->left), height(newMid->right)) + 1;

    return newMid;
}

struct Node* successorInorder(struct Node* root) {
    struct Node* curr = root;
    while (curr && curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (!root) 
        return root;

    if (data < root->data) 
        root->left = deleteNode(root->left, data);
        
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
        
    else {
        if (root->left == NULL && root->right == NULL) 
            return NULL;
        else if (root->left == NULL) 
            return root->right;
        else if (root->right == NULL) 
            return root->left;
        

        struct Node* successor = successorInorder(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }

    if (!root) 
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalanceFactor(root);

    if (balance <= 1 && balance >= -1)
        return root;

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0) 
        return leftRotate(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
}

 PRINTS 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.first << "," << p.second << ')';
}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v){
    os; string sep; for (const T &x : v) os << sep << x, sep = " "; return os;
}
  
SQUARE ROOT:
  long long int SQRT(long long int st,long long int en,long long int n)
  {
    long long int mid=(st+en)/2;
    if(mid*mid==n)
      return mid;
    else if(mid*mid>n)
      SQRT(st,mid,n);
    else
      SQRT(mid+1,en,n);
  }
HCF-Taking the presumption that p<=q
QUICK SORT:
  void swap(int *a,int *b)
  {
  int p=*a,q=*b;
  *a=q; *b=p;
  }
  void qsort(int arr[],int st,int en)
  {
    int index=en-1; int pos=st; 
    for(int i=st;i<en-1;i++)
    {
      if(arr[index]>=arr[i])
      {  swap(arr+i,arr+pos); pos++; }
    }
    swap(arr+pos,arr+index);
    if(st<pos-1)
      qsort(arr,st,pos);
    if(pos+2<en)
      qsort(arr,pos+1,en);
  }
TWO POINTER APPROACH
  eop=False; int i=0,j=8;
  while(!eop)
  {
    if(arr[i]+arr[j]<11)
      i+=1;
    else if(arr[i]+arr[j]==11)
      break;
    else
      j-=1;
  }
// A Perfect example of dp. It can also be used in Partitioning of sets.
int perfectSum(int arr[], int n, int sum){
        const int mod=1e9+7;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= arr[i]; --j) {
                dp[j] += dp[j - arr[i]];
                dp[j] %= mod;
            }
        }
    return dp[sum];
    }

vector<vector<int> > fourSum(vector<int> &arr, int k){
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        set <vector<int>> s;
        for(int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int start=j+1;
                int end=n-1;
                while(start<end){
                    int sum=arr[i]+arr[j]+arr[start]+arr[end];
                    if(sum==k){
                        s.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    }
                    else if(sum>k){
                        end--;
                    }
                    else{
                        start++;
                    }
                }
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }

// Finding the lowest common ancestor
Node* lowest_common_ancestor(Node* root , int a , int b)
    {
        if(root == NULL || root->data == a || root->data == b)
        return root;
        
        Node* left = lowest_common_ancestor(root->left , a , b);
        Node* right = lowest_common_ancestor(root->right , a , b);
        
        if(left == NULL )
        return right;
        
        else if(right == NULL )
        return left;
        
        else return root;
    }
// Heap Sort

void swap(long long int *p,long long int *q){
	*p+=*q;	*q=*p-*q; *p-=*q;
}

void MaxHeapify(vtll vec,int q)
{
	int temp=q,sz=vec.size(),l=-1,r=-1,lar=q;
	if(q*2<=sz-1)
		l=q*2;
	if(q*2+1<=sz-1)
		r=q*2-1;
	
	if(l!=-1)
		lar=vec[temp]>vec[l]?temp:l;
	if(r!=-1)
		lar=vec[lar]>vec[r]?lar:r;
	
	if(lar!=q){
		swap(&vec[lar],&vec[q]);
		MaxHeapify(vec,lar);
	}
}
void BuildHeap(vtll vect, int n)
{
	int sz=((n-1)/2)+1;
	while(sz--)
	{
		MaxHeapify(vect,sz);
	}
}
void Hpsort(vtll arr)
{
	int k=1,siz=arr.size();
	BuildHeap(arr,siz);
	while(k<siz)
	{
		
	}

}

template<typename T>
T solve()
{
	int n=10;	vector <int> arr(10,0);
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
}

int main(void)
{
	int tst=1;	cin >> tst;
	while(tst--)
	{
		solve<void>();
	}
}

// Algorithm for finding number of swaps required where ans is the number of swaps and vec  is the in-order traversal of the tree.
void Merge(int i,int j) {
        if(i>=j)return;
        
        int mid=i+(j-i)/2;
        Merge(i,mid);
        Merge(mid+1,j);
        
        int k=mid+1, start=i;
        while(i<k and k<=j) {
            if(vec[i] <= vec[k])i++;
            else {
                vec+=mid-i+1;
                k++;
            }
        }
       sort(vec.begin() + start, vec.begin() + j + 1);
    }
*/

// Sorting the linked list using quick sort
// struct Node* part(struct Node* st, struct Node* en) {
//         Node *t1 = st, *t2= st;
//         while(t1!=en){
//             if(t1->data<st->data) swap(t1->data, t2->next->data), t2 = t2->next;
//             t1 = t1->next;
//         }
//         swap(t2->data, st->data);
//         return t2;
//     }
//     void mysort(struct Node* st, struct Node* en) {
//         if(st!=NULL && st != en)
//         {
//             Node* divi = part(st, en);
//             mysort(st, divi);
//             mysort(divi->next, en);
//         }
//     }
//     struct Node* quickSort(struct Node* head) {
//         mysort(head, NULL);
//         return head;
//     }


// GRAPH

	// Djikstra's algorithm with finding ways and shortest distance from src to all indices
	
	// Time: O( E*log V )

	// :adj	stores the vector for ( neighbour , wt( i , neighbour) ) for the ith vertex for all i
	// :ways	number of ways from src vertex to ith index  for all i
	// :dis	distance of src to ith vertex for all i

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

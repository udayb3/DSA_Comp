/*
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
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vvll vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define mii map<int, int>
#define mis map<int,string>
#define msi map<string,int>
#define si set<int>
#define sll set<long long>
#define sc set<char>

 FUNCTIONS 
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
define for(i,n) for(int i=0;i<n;i++)

 PRINTS 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.first << "," << p.second << ')';
}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v){
    os; string sep; for (const T &x : v) os << sep << x, sep = " "; return os;
}

DECLARATION:


ALGORITHMS
BINARY SEARCH:

  
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
QUESTIONS:
  CODEFORCES: Hammon Odyssey    Rudolf and the other competition   Help Oppenheimer
  CODECHEF: XOR problem
	Four element sum problem gfg
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
// Heap Sort
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vti; 
typedef vector<long long> vtll;
typedef pair <long long,long long> prll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long,long long>> vpll;


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
*/
### separating a sentence into a vector of string using string stream 
```cpp
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
```
### AVL tree
```cpp
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
```
### Complex typenames, can be used as macros
```cpp
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p){
    return os << '(' << p.first << "," << p.second << ')';
}
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v){
    os; string sep; for (const T &x : v) os << sep << x, sep = " "; return os;
}
```
### A Good example of dp. It can also be used in Partitioning of sets.
```cpp
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
```

### Finding the lowest common ancestor
```cpp
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
```
### Algorithm for finding number of swaps required where ans is the number of swaps and vec  is the in-order traversal of the tree.
```cpp
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
```
### Sorting the linked list using quick sort
```cpp
struct Node* part(struct Node* st, struct Node* en) {
        Node *t1 = st, *t2= st;
        while(t1!=en){
            if(t1->data<st->data) swap(t1->data, t2->next->data), t2 = t2->next;
            t1 = t1->next;
        }
        swap(t2->data, st->data);
        return t2;
    }
    void mysort(struct Node* st, struct Node* en) {
        if(st!=NULL && st != en)
        {
            Node* divi = part(st, en);
            mysort(st, divi);
            mysort(divi->next, en);
        }
    }
    struct Node* quickSort(struct Node* head) {
        mysort(head, NULL);
        return head;
    }
```
### Rolling hash + binary search implementation of Longest pallindromic substring
```cpp
unordered_map<char, int> charToInt;
int currVal = 1;
class Hasher{
    queue<char> q;
    long long hash;
    int mod;
    int MAX;
    int size;
public:
    Hasher(int MAX){
        size = 0;
        hash = 0;
        mod = 1e9 + 7;
        this -> MAX = MAX;
    }
    int get_hash(){
        return hash;
    }
    int char_to_int(char c){
        if(charToInt.find(c) == charToInt.end()){
            charToInt[c] = currVal++;
        }
        return charToInt[c];
    }
    void insert_back(char c){
        q.push(c);
        int val = char_to_int(c);
        hash = add(hash, mul(val, xyp(MAX, size)));
        size++;
    }
    void pop_front(){
        char c = q.front();
        q.pop();
        int val = char_to_int(c);
        hash = sub(hash, val);
        hash = div(hash, MAX);
        size--;
    }
    int add(int x, int y){
        return (x + y) % mod;
    }
    int sub(int x, int y){
        return (1LL * x - y + mod) % mod;
    }
    int mul(int x, int y){
        return (1LL * x * y) % mod;
    }
    int div(int x, int y){
        return (1LL * x * inv_mod(y)) % mod;
    }
    // x power y mod p 
    int xyp(int x, int y){
        if(y == 0) return 1;
        if(y == 1) return x;
        if(y & 1){
            long long temp = xyp(x, y - 1);
            return (temp * x) % mod;
        }
        long long temp = xyp(x, y >> 1);
        return (temp * temp) % mod;
    }
    int inv_mod(int x){
        return xyp(x, mod - 2);
    }
};

vector<int> forward, backward;
string rev;
int distChar;
void calc_hash(int& len, string& s, vector<int>& v){
    Hasher forHash(distChar);
    for(int i = 0; i < len; i++){
        forHash.insert_back(s[i]);
    }
    v.push_back(forHash.get_hash());
    for(int i = len; i < s.size(); i++){
        forHash.pop_front();
        forHash.insert_back(s[i]);
        v.push_back(forHash.get_hash());
    }
}
bool check(int len, string& s){
    forward.clear();
    backward.clear();
    calc_hash(len, s, forward);
    calc_hash(len, rev, backward);
    reverse(backward.begin(), backward.end());
    for(int i = 0; i < backward.size(); i++){
        if(backward[i] == forward[i]) return true;
    }
    return false;
}
string longestPalindrome(string s) {
    if(s.size() == 0) return s;
    if(s.size() == 1) return s;
    unordered_set<char> uSet;
    for(int i = 0; i < s.size(); i++){
        uSet.insert(s[i]);
    }
    distChar = uSet.size();
    rev = s;
    reverse(rev.begin(), rev.end());
    int low = 1, high = s.size() / 2;
    int maxx = 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(2 * mid, s)){
            low = mid + 1;
            maxx = max(maxx, 2 * mid);
        }
        else{
            high = mid - 1;
        }
    }
    low = 1, high = (s.size() + s.size() % 2) / 2;
    while(low <= high){
        int mid = (low + high) / 2;
        if(check(2 * mid - 1, s)){
            low = mid + 1;
            maxx = max(maxx, 2 * mid - 1);
        }
        else{
            high = mid - 1;
        }
    }
    forward.clear();
    backward.clear();
    calc_hash(maxx, s, forward);
    calc_hash(maxx, rev, backward);
    reverse(backward.begin(), backward.end());
    int idx;
    for(int i = 0; i < backward.size(); i++){
        if(forward[i] == backward[i]){
            idx = maxx - 1 + i;
            break;
        }
    }
    string ret = "";
    for(int i = idx; ret.size() < maxx; i--){
        ret += s[i];
    }
    return ret;
}
```
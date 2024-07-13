## Basic structure for Doubly Linked list
```cpp
struct node{
  long long data;
  node *prev;
  node *next;
  node(long long val, struct node *pre){
    data=val;
    next= NULL; prev= pre;
  }
};

node* inssert(node *cur, long long val)
{
  node *t1=new node(val, cur);
  if(cur!=NULL){
    t1->next= cur->next;
    cur->next= t1;
  }
  return t1;
}

node* remove(node *cur)
{
  node *t1= cur->prev, *t2= cur->next;
  if(t1==NULL){
    free(cur); return t2;
  }
  else{
    t1->next= t2; free(cur); return t2;
  }
}
```
## Implementation Circular Linked list[Note that head is the 0th element]
```cpp

struct cnode
{
  long long data;
  struct cnode *next;
  struct cnode *prev;
  cnode(long long val, struct cnode *pre){
    data= val;
    next= NULL;
    prev= pre;
  }
};

cnode* inssert(long long val, cnode *prev, cnode *head)
{
  cnode *temp= new cnode(val, prev);
  if(head==NULL){
    temp->next= temp;  temp->prev=temp;
  }
  else{
    prev->next->prev= temp; temp->next= prev->next; temp->prev= prev; prev->next= temp; 
  }
  return temp;
}

cnode *remove(cnode *tar, cnode *head)
{
  if(head->next==head)
  {
    free(head);
    return NULL;
  }
  else{
      cnode *t1, *t2, *ans; t1= tar->prev; t2= tar->next;
      t1->next= tar->next;
      t2->prev= tar->prev;
      if( tar==head )
        ans= t2;
      else
        ans= head;
      // free(tar);
      return ans;
  }
}

void TraverseCircular(cnode *head)
{
  cnode *curr= head; bool ch=true;
  while(ch || curr!=head){
    cout << curr->data << " ";
    curr= curr->next;
    ch= false;
  }
}

cnode *removekthNode(cnode *head, int k)
{
  cnode *cur= head; k++;
  while(k--){
    cur= cur->next;
  }
  return remove(cur, head);
}
```

## Traversing Circular Linked list
```cpp
void TraverseCircular(cnode *head)
{
  cnode *curr= head; bool ch=true;
  while(ch || curr!=head){
    cout << curr->data << " ";
    curr= curr->next;
    ch= false;
  }
}
```
## Reversing a Linked list
```cpp
node *reverse(node *cur, node *prev)
{
  if(cur==NULL)
    return prev;
  node *nxt= cur->next; cur->next= prev;
  return reverse(nxt, cur);
}
```
## Removing Duplicates
```cpp
void removeDuplicates(node *hd)
{
  node *cur=hd, *t1;
  while(cur!=NULL){
    if(cur->next != NULL && cur->data == cur->next->data){
      t1= cur->next; cur->next= cur->next->next; free(t1);
    }
    else{
      cur= cur->next;
    }
  }
}
```
## Reversing linked list in groups
```cpp
node* ReverseKGroup(node *head, int k)
{
  node *cur=head, *pre= NULL, *lst1= head, *nxt, *lst2, *ans; bool ch=true;
  while(cur!=NULL)
  {
    int i=0;
    while(cur!=NULL && i<k)
    {
      nxt= cur->next;
      cur->next= pre;
      pre=cur;
      cur= nxt;
      i++;
    }
    if(ch){ans= pre; ch=false; lst2=cur;}
    else{
      lst1->next= pre; lst1=lst2;
    }
    pre= NULL; 
  }
  return ans;
}
```
## Cloning a linked list with next and secondary pointer
```cpp
node * Clone(node *head)
{
  if(head==NULL)
    return NULL;

  node *cur=head, *t1, *ans;
  while(cur!=NULL)
  {
    t1= cur->next;
    cur->next= new node( cur->data);
    cur=cur->next; cur->next= t1; cur=cur->next;
  }
  t1= head;
  while(t1!=NULL)
  {
    cur= t1->next; cur->ran= (t1->ran)->next; t1= cur->next;
  }
  t1= head; bool ch=true;
  while(t1!=NULL)
  {
    cur= t1->next; t1->next= cur->next; t1= t1->next; 
    if(t1!=NULL)
      cur->next= t1->next;
    if(ch){  ans= cur; ch=false; }
  }
  return ans;
}
```
## Merge 2 sorted linked list
```cpp
```
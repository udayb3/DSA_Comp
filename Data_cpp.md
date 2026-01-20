<!-- AUTO-GENERATED-CONTENT:START (TOC:collapse=true&collapseText="Click to expand") -->
<details>
<summary>Index</summary>

- [Headers](#headers)
- [Variables](#variables)
- [Structures](#structures)
  - [ARRAY](#array)
  - [ITERATORS:](#iterators)
  - [VECTORS:](#vectors)
  - [STRINGS:](#strings)
  - [PAIR](#pair)
  - [STACK:](#stack)
- [Algorithms](#algorithms)
  - [Sorting Algorithms:](#sorting-algorithms)
- [Sieve of eratosthenes:](#sieve-of-eratosthenes)
- [Types](#types)

</details>
<!-- AUTO-GENERATED-CONTENT:END -->

### Headers
  - `<iostream.h>`        : Header file for basic input and output.
  - `<vector.h>`          : Header file containing the vector data structure.
  - `<bits/stdc++.h>`     : It is a general header file which contains most of the tools required.
  - `using namespace std;`: It is a fundamental way of telling from where the header files come from.

### Variables

- They are nothing but containers to store data.

| Available Data types | Size(Bits)  |
| --- | --- |
| int | 32 |
| char  | 8 |    
| long long int | 64 |
| bool  | 8 |
| short int | 16 |
|float  | 32 |
| double  | 64 |   

### Structures

#### ARRAY
- It is a data structure to store a specific type of data.
- Comlpexity:
  - ACCESS: O(1)
  - DISPLAYING: O(n)

#### ITERATORS:
- It is used to a particular memory adress of the containers.
- Methods:
  - `.begin()`         : It returns the beginning position of the container.
  - `.end()`           : It returns the after-ending position of the container.
  - `.advance(it,pos)` : It increments the value of the iterator till argument is same as the given number.
  - `.next(), .prev()` : They return a new iterator which points to the index with the increment and decrement in index.  

#### VECTORS:  
- It is a linear data structure. They are commonly used to input data as in arrays.
- They posses advantage over arrays as they are dynamic in nature.       
- Complexity:
  - ACCESS         = O(1)
  - DISPLAYING     = O(n)
  - ADDITION       = O(n)
- OPERATIONS:
  - `.push_back(a)`: It inserts an element a at the end of vector.
  - `.pop_back()`    : It deletes the last element. It does not returns anything.
  - `.size()`        : It returns the total number of elements in the vector.
  - `.clear()`       : It clears the vector v.
  - `.resize(n)`     : It resizes the vector to the size of n.
  - `.begin()`       : Returns Iterator to the starting element
  - `.end()`         : Returns Iterator to the ending element
  - `.empty()`       : It returns 1 if the size of the vector is 0.

#### STRINGS:
- It stores the words or sentences.
- When we used the cin function to take input, if it encounters spacebar given by user it will end execution.
- The above is the reason as to why we use `getline(cin,(string name))`. It will ensure that all the spaces and everything will come in string.
- FUNCTIONS:
  - `.length()`                    : It returns the length of string.
  - `.size()`                      : It returns length.
  - `.clear()`                     : It erases all the characters from string.
  - `s1.append(s2)`                : It appends s2 with s1.
  - `s1.append(s2 , start , end )` : It appends s2 from index start to end.
  - `reverse(s.begin() ,s.end() )` : It reverses the string.
  - `s.substring(i,n)`             : It returns the part of string from i to n.
  - `s1.find(s2)`             : It finds the first instance of s2 in s1 and returns the starting character.
  - `s1.rfind(s2)`                 : It returns the last instance of s2 in s1.
  - `s1.compare(s2)`               : It compares the strings s1 and s2 lexicographically.
  
#### PAIR
- SYNTAX:
```cpp
pair <data_type1,data_type2> pair_name(value1,value2) eg. pair<int,string> p;
pair_name={value1,value2}
```
- ACCESS:
      pair_name.first   pair_name.second
- COMPARISION: ==, !=, >=, <= checks both the first and second values in the order from first to second.
- If pair is not initialized, it stores default values. Default value of int, double is 0, char is NULL.
  
#### STACK: 
- It is general data structure which follows the principle of FIFO.
- SYNTAX:
  stack  <data_type> variable_name
    SOME functions which we use in stack are:
      empty(), size(), top(), push(), pop() 
      time complexity= O(1).
    IMPLEMENTATION:
      There is a stack algorithm stored already in cpp. All the functions are named as per given above.
  
  QUEUE:
    It is also a general data structure but unlike stack, it  follows the principle of LIFO.
    SYNTAX:
      queue<data_type> variable_name
    Some functions which we use in queue:
      front(), back(), push(), pop(), size(), empty(), 

  DQUEUE: doubly ended queue
    It is a similar structure to queue but it can add and remove the elements from both side.
    Another benefit which we have in dequeue is that we can iterate over all the elements without removing the elements which we cannot do in stack and queue.
    SYNTAX: 
      dequeue<data_type> variable_name
    Some functions which we use in dqueue:
      push_front(x) push_back(x)  pop_front() pop_back()  front() back()  size()  empty()

  MATRICES:
    It is an arrangement of rows and columns. In the most simplest way it is a 2-D array.
  
  SETS:
    SYNTAX:
      set<data_type> val; val={3,2,1,5};
    PROPERTIES:
      STORING ORDER:  The set stores elements in sorted order.  char values are stored in the order of ascii values.
      VALUE CHARACTERISTIC: All the elements have a unique index.
      INSERT FUNTION: The set stores values in O(nlog n) complexity. The syntax is as follows:
        a.insert(value);
        begin(), end(), - O(1)
      If we do not want output in a order which is not sorted, we can store the values in unordered sets.
      The only difference is that unordered set does not store in sorted manner.
        unordered set<data_type> variable_name
    
  MULTI_SETS:
    They are associative containers with the only difference being that multiple elements can have same values.
    SYNTAX: 
      multiset <data_type> variable_name

  MAPS:
    They are a type of associative containers. 
    Values are keys to  maps. keys are like indices but they are not necessarily numbers, like dictionary in python.
    Maps store key-value pairs in increasing order of the keys, lexicographically in the case of strings.
    They are implemented red-black binary trees.
    Time-complexity of searching an element is O(log n).
    DECLARATION:
      map <data_type of key,data_type of value>map_name;
      The line below can store the keys of map in decreasing order.
      map<int,int, greater<int>>map_name;
    Data types can be of any type.
    Once we have assigned the key, we can not change the value.
    Traversal:
      We need an iterator to traverse in the map.
    
  UNORDERED MAPS:
    There is no certain order. 
    They are implemented using hash tables.
    The time complexity of finding an element is O(1).

1. TIME COMPLEXITY

  It does not give exact time taken by your program to run.
  There are sites in which we can measure time taken to run by our program.
  We can also use the <time.h> header file in c and <ctime.h> in cpp.
  The time taken also depends from machine to machine, from site to site.

  >SOME NOTATIONS
    Big O notation:
      It expresses the worst case time complexity.
      The syntax is:
        O(f(n)) where n is the input.

  >Some tips for approximation:
    When the function you found has addition of different parts, it will be easy to ignore the lower part. 

  >Best case and worst case:
    Best Case: 
      It can be described as the case for which the algorithm takes the least amount of time.
    Worst Case:
      It can be described as the case for which the algorithm takes the most amount of time.
    
    We usually take worst case for comparision or to decide the algorithm.
    
  >Some common time complexities:
    Mathemathical formulas: O(n)
		Binary search         :	O(log n)
		Prime factorisation   : O(n^1/2)
		Linear Search         : O(n)
		Sorting               : Selection sort/Bubble sort=O(n^2), Merge sort/Quick sort =O(n*log n)
		Iterating subsets     : O(2^n)
		Iterating permutations: O(n!)

### Algorithms
#### Sorting Algorithms:
- There are different type of sorting algorithms:- Bubble sort( O(n^2) ), Merge sort( O(n*log n) ), Quick sort( O(n*log n)), Selection sort, Insertion sort,
- There are in-built library function in cpp to sort which, most probably, works on merge sort.
- In cpp, sorting works on the algorithm of Introsort-a hybrid of Merge sort, Quick sort and Insertion sort. 
```cpp
sort(arr,arr+n)- It sorts array in ascending order.
sort(vec.begin(),vec.end()): It sorts the vector in ascending order.
sort(arr+a,arr+b): It sorts an array from (a+1)st to (b+1)st position.
```  

### Sieve of eratosthenes: 
- This algorithm is used to find the prime numbers upto a certain limit.
  Complexity: O(n*(log n)*log(log n))
SIEVE:
    Origin: Eratosthenes of Cyrene
    It helps in finding the prime number upto a certain number.
    Algorithm:
      we list all the numbers from 2 to n.
      then we remove all the multiples of 2.
      then the number which is next i.e. 3, we remove all the multiples of 3.
      The above step is done until we reach our given limit of n.

  Euler totient function:
    It is also known as phi function phi(n).
    It counts the number of integers b/w 1 to n inclusive which are co-prime of n.

  Two pointer approach:
    Two different variables which point to two different to two different indexes. 
    We can use it in the following cases:
      When we want to find to two elements with a specific sum.
      When we want to merge two arrays.

  Prefix sum array:
      ps[i]=arr[i]+ps[i-1];
  Frequency arrays:
    The frequency array of an array contain the number of times the element comes in the array.

### Types

  Greedy Algorithms:
    They are a type of problem where solution is derived from intuition and proved later on.
	Brute Force:
		Brute force is an approach which involves going through all possible cases and selecting whichever one is most favourable.
		Usually there will not be given such problems with higher values of n.

SOME SPECIFIC COMMANDS:
  count << fixed << std::setprecision(x) << ans; == It will print the answer with x digits of decimal.

Sources:
  Geeks for geeks
  CSES problemsheet
  USACO

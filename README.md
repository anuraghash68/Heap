# Heap Build.
**Insertion, deletion and getMin and getMax operation in heap.**

1.*Creating a Class with name heap.*
 - Declaring the class variable of vector<int>v as array will be used to implement the heap
  - We will create boolean variable with name meanHeap to check what user wants at compile time a min heap or max heap
   -Then we will will creater compare function for checking what type of heap we wanted to buid.
    Here is the code part of it.
   ```
  vector<int>v;
    bool minHeap;
    bool compare(int a, int b)
    {
        if(minHeap)
            return a<b;
        else
            return a>b;
    }
  ```
 2.* Let's Create a constructor of Heap,where we pass a bool type to perform min or max heap at compile time.*
   - Setting the minHeap variable of boolean type and blocking the first index of vector because we will consider it 1 based indexing
  Here is the code part of it.
 ```
 public:
    explicit Heap(bool type = true)
    {
        minHeap = type;
        v.push_back(-1);
    }
 ```
3.*Let's create a push function for inseting a new data into heap.*
  - We always insert a new element into the last of positon of a vector.
    - Then we will start comparing the inserted element index with parents by `i/2` where i is the children index.
      - For left childrent the index will be `2*i` and for right child `2*i+1`.
       - Now we have found the index of parent then will compare data according to min heap or max heap and we swap the data.
        - Now, we will update our current child index and parent index by dividing 2.
         - So, we always comparing with parent element at each statement so pushing a element into a heap will take `log(n)` time.
   Here is the code...carefully understand it.
 
    ```
    void push(int data)
    {
      v.push_back(data);
      int index = v.size()-1;
      int parent = index/2;

      while(index > 1 && compare(v[index], v[parent]))
      {
          swap(v[index], v[parent]);
          index = parent;
          parent = parent/2;
      }

    }
    ```
4.*Let's create a function for checking wether a heap is empty or not.*
  - We just have to check the vector size is 1 or not? because we had reserved the first index.
  Here is the code for it...
  ```
   bool isEmpty()
    {
        return v.size() == 1;
    }
  ```
5.*Let's create a function for finding the topmost element of heap.*
 - we just have to return the first index,here first index will be `one` not `zero` because 0th index was blocked.
 Here is the code for it...
 ```
  int top()
    {
        return v[1];
    }
 ```
6.*Now, most important part comes, poping an element from the heap*
  - In deletion, first we swap the first element with last element then we will delete the last element by poping from vector.
    - Now we have to perform heapify opertion so that the next max or min element comes at the top.
    - We always perform heapify operation from the first index.
     - We calculate the children of first index `2*i` and `2*i+1`.
      - then we will compare the index, left and right child value whoever is minimum(for minheap) between them we will swap them.
       - the we will again call for next index to perform heapify by recursive method.
       Here is the code for it `understant it very carefully`.
       ```
       void heapify(int i)
    {
        int left = 2*i;
        int right = 2*i + 1;
        int minIndex = i;

        if(left < v.size() && compare(v[left], v[i]))
            minIndex = left;
        if(right < v.size() && compare(v[right], v[minIndex]))
            minIndex = right;

        if(minIndex != i)
        {
            swap(v[i], v[minIndex]);
            heapify(minIndex);
        }
    }
    ```
7.*Here come the inside the main function code*.
```

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Heap h(false);
    h.push(20);
    h.push(3);
    h.push(6);
    h.push(0);
    h.push(1);
    h.push(15);

    //cout << h.top() << endl;
    while (!h.isEmpty()){
        cout << h.top() << endl;
        h.pop();
    }

    return 0;
}
```

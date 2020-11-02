//  Life Should be Great Rather than Long --> Dr. B.R Ambedkar.
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define endl '\n'
const int MAX = 1e6;
unsigned long long fac[310000];

using namespace std;

unsigned long long power(unsigned long long x, int y){
    unsigned long long res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

unsigned long long modInverse(unsigned long long n){
    return power(n, MOD - 2);
}
unsigned long long nCr(unsigned long long n, int r){
    if (n < r)
        return 0;
    if (r == 0)
        return 1;




    return (fac[n] * modInverse(fac[r]) % MOD* modInverse(fac[n - r]) % MOD)% MOD;
}/*
fac[0] = 1;
for (int i = 1; i <= 310000; i++)
fac[i] = (fac[i - 1] * i) % MOD; */
// Sieve based approach to pre-
// calculate all divisors of number
void seive(vector<int>&v, int n){
    v.push_back(n);
    for(int i=2;i*i<=n;i++){
        if(n%i==0) {
            v.push_back(i);
            if(i!=n/i) v.push_back(n/i);

        }
    }
}

class Heap
{
    vector<int>v;
    bool minHeap;
    bool compare(int a, int b)
    {
        if(minHeap)
            return a<b;
        else
            return a>b;
    }
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
public:
    explicit Heap(bool type = true)
    {
        minHeap = type;
        v.push_back(-1);
    }
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
    bool isEmpty()
    {
        return v.size() == 1;
    }
    int top()
    {
        return v[1];
    }
    void pop()
    {
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        heapify(1);
    }

};

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


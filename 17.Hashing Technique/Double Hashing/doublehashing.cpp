// cpp program to implement Collision Resolving technique - "Double Hashing"
#include<iostream>

using namespace std;

// class for HashTable
class HashTable
{
public:
    int *HT;
    int size;

    HashTable(int size);
    ~HashTable();

    int hashFunction1(int key);     // h1(x) -> Basic Hash Function

    int PrimeNumberR();     // R -> prime number less than and nearest to size of hash table
    int hashFunction2(int key);     // h2(x) -> Used by the DoubleHashing function below

    int DoubleHash(int key);
    
    void Insert(int key);

    bool search(int key);
    // int Delete(int key);     // In Double Hashing, delete function is avoided.Because, we need to shift after deleting elements to make the deleted free to be occupied
};

// implementing the above functions of the class
HashTable :: HashTable(int size)
{
    this->size = size;

    HT = new int[this->size];

    // initializing all the values in the hash table to 0
    for(int i=0;i<this->size;i++)
        HT[i] = 0;
}

// function to implement the destructor for HashTable
HashTable :: ~HashTable()
{   
    delete [] HT;
}

// function to implement hash function -> h1(x) -> (Basic Hash Function)
int HashTable :: hashFunction1(int key)
{
    return key%this->size;  // here, 10 - because, size of hashtable = 10
}

// function to find R -> prime number less than and nearest to size of hash table
int HashTable :: PrimeNumberR()
{
    int R;      // R -> prime number less than and nearest to size of hash table

    int i;

    return 7;
}

// function to implement hash function -> h2(x) -> (Modified Hash Function)
int HashTable :: hashFunction2(int key)
{
    int R = PrimeNumberR();

    return R - (key % R);
}

// function to perform Double Hashing -> if collision occurs  // Double Hashing -> uses h1(x) and h2(x)
int HashTable :: DoubleHash(int key)
{
    int hashIndex1 = hashFunction1(key);
    int hashIndex2 = hashFunction2(key);

    int i = 0;

    while(HT[(hashIndex1+i*hashIndex2)%this->size] != 0)
        i++;

    return (hashIndex1+i*hashIndex2)%this->size;
}

// function to perform insertion into a hashtable
void HashTable :: Insert(int key)
{
    int hashIndex = hashFunction1(key);      // hashFunction returns the hashcode (or) hashvalue for a key

    if(HT[hashIndex] != 0)      // if collision occurs, use "DoubleHashing" - Collision Resolution Technique
        hashIndex = DoubleHash(key);
    
    HT[hashIndex] = key;
}

// function to perform searching in a hash table in double hashing
bool HashTable :: search(int key)
{
    int hashIndex1 = hashFunction1(key);  // hashFunction returns the hashcode (or) hashvalue for a key
    int hashIndex2 = hashFunction2(key);

    int i = 0;

    while(HT[(hashIndex1+i*hashIndex2)%this->size] != key && HT[(hashIndex1+i*hashIndex2)%this->size] != 0)
        i++;

    if(HT[(hashIndex1+i*hashIndex2)%this->size] == 0)
        return false;
    else    
        return true;
}

int main()
{
    HashTable H(10);

    H.Insert(5);
    H.Insert(15);
    H.Insert(25);
    H.Insert(35);
    H.Insert(95);

    if(H.search(95))
        cout<<"key found"<<endl;
    else
        cout<<"key not found"<<endl;
}
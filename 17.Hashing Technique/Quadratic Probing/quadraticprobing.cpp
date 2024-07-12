// cpp program to implement Collision Resolving technique - "Quadratic Probing" - Here, Probe moves quadratically (i*i)
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

    int hashFunction(int key);

    int QuadraticProbe(int key);     // Quadratic Probe - helper function for Insert to find the free space in Hashtable if collision occurs using Quadratic Probing
    void Insert(int key);

    bool search(int key);
    // int Delete(int key);     // In Quadratic Probing, delete function is avoided.Because, we need to shift after deleting elements to make the deleted free to be occupied
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

// function to implement hash function
int HashTable :: hashFunction(int key)
{
    return key%this->size;  // here, 10 - because, size of hashtable = 10
}

// function to perform Quadratic Probing -> // Quadratic Probe - helper function for Insert to find the free space in Hashtable if collision occurs using Quadratic Probing
int HashTable :: QuadraticProbe(int key)
{
    int i, hashIndex;

    hashIndex = hashFunction(key);

    i = 0;

    while(HT[(hashIndex+i*i)%this->size] != 0)    
        i++;
    
    return (hashIndex+i*i)%this->size;
}

// function to perform insertion into a hashtable
void HashTable :: Insert(int key)
{
    int hashIndex = hashFunction(key);      // hashFunction returns the hashcode (or) hashvalue for a key

    if(HT[hashIndex] != 0)      // if collision occurs, use "Quadratic Probing" - Collision Resolution Technique
        hashIndex = QuadraticProbe(key);
    
    HT[hashIndex] = key;
}

bool HashTable :: search(int key)
{
    int hashIndex = hashFunction(key);  // hashFunction returns the hashcode (or) hashvalue for a key

    int i = 0;

    while(HT[(hashIndex+i*i)%this->size] != key && HT[(hashIndex+i*i)%this->size] != 0)
        i++;

    if(HT[(hashIndex+(i*i))%this->size] == 0)
        return false;
    else    
        return true;
}

int main()
{
    HashTable H(10);

    H.Insert(10);
    H.Insert(21);
    H.Insert(34);
    H.Insert(31);

    if(H.search(0))
        cout<<"key found"<<endl;
    else
        cout<<"key not found"<<endl;
}
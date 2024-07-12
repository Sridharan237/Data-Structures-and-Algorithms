// cpp program to implement Collision Resolving technique - "Separate Chaining"
#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// class for HashTable
class HashTable
{
public:
    Node **HT;
    int size;

    HashTable(int size);
    ~HashTable();

    int hashFunction(int key);

    void sortedInsert(int key);
    bool search(int key);
    int Delete(int key);
};

// implementing the above functions of the class
HashTable :: HashTable(int size)
{
    this->size = size;

    HT = new Node*[this->size];

    // initializing all the values in the hash table to nullptr
    for(int i=0;i<this->size;i++)
        HT[i] = nullptr;
}

// function to implement the destructor for HashTable
HashTable :: ~HashTable()
{
    Node *p;

    int i;

    for(i=0;i<this->size;i++)
    {
        p = HT[i];

        while(HT[i] != nullptr)
        {
            HT[i] = HT[i]->next;

            delete p;

            p = HT[i];
        }
    }
    
    delete [] HT;
}

// function to implement hash function
int HashTable :: hashFunction(int key)
{
    return key%this->size;  // here, 10 - because, size of hashtable = 10
}

// function to implement the sorted insert in a linked list of hashtable
void HashTable :: sortedInsert(int key)
{
    Node *p, *q;    // q - tail pointer

    // creating a new node
    Node *t = new Node;

    // initializing a new node
    t->data = key;
    t->next = nullptr;

    int hashIndex = hashFunction(key);

    p = HT[hashIndex];

    if(HT[hashIndex] == nullptr)
        HT[hashIndex] = t;
    else
    {
        while(p != nullptr && t->data > p->data)
        {
            q = p;

            p = p->next;
        }

        q->next = t;
        t->next = p;
    }
}

bool HashTable :: search(int key)
{
    int hashIndex = hashFunction(key);  // hashFunction returns the hashcode for a key

    Node *p = HT[hashIndex];

    while(p != nullptr)
    {
        if(p->data == key)
            return true;
        p = p->next;
    } 

    return false;
}

// function to perform deletion from HT (Hash Table)
int HashTable :: Delete(int key)
{
    Node *p, *q;    // q - tail pointer

    int x = -1;

    int hashIndex = hashFunction(key);  // hashFunction returns the hashcode for a key

    p = HT[hashIndex];

    if(p->data == key && p->next == nullptr)
    {
        x = p->data;

        delete HT[hashIndex];

        HT[hashIndex] = nullptr;
    }
    else
    {
        while(p != nullptr)
        {
            if(p->data == key)
            {
                x = p->data;

                q->next = p->next;

                delete p; 
            }
            else
            {
                q = p;

                p = p->next;
            }
        }
    }

    return x;
}

int main()
{
    HashTable H(10);

    H.sortedInsert(10);
    H.sortedInsert(21);
    H.sortedInsert(34);
    H.sortedInsert(31);
    H.sortedInsert(58);

    if(H.search(10))
        cout<<"key found"<<endl;
    else
        cout<<"key not found"<<endl;

    cout<<"Deleted Element : "<<H.Delete(10)<<endl;

    if(H.search(10))
        cout<<"key found"<<endl;
    else
        cout<<"key not found"<<endl;
}
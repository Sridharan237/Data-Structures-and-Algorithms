// cpp program to create a heap of 'n' elements and delete 'n' elements from heap (- performing heap sort)
// here, heap - Max heap - "Binary heap"
#include<iostream>

using namespace std;

// function to swap 2 values in their addresses
void swap(int *num1, int*num2)
{
    int temp = *num1;

    *num1 = *num2;
    *num2 = temp;
}

// function to insert one value into heap
void Insert(int H[], int n)     // n - index of the element in 'H' array needs to be get inserted into the heap part of 'H' array
{   // function to insert element at index 'n' to heap
    int i, temp;

    i = n, temp = H[n];

    while(i>1 && temp > H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }

    H[i] = temp;
}

// function to delete root value from heap
int Delete(int H[], int n)  // n - is the size of heap
{
    int i, j, x;

    i = 1, j = 2*i;     // j - left child of i

    x = H[1];   // x - root element to be deleted
    H[1] = H[n];

    H[n] = x;

    while(j <= n-1)
    {
        if(j < n-1 && H[j+1] > H[j])
            j = j + 1;
        
        if(H[i] < H[j])
        {
            swap(&H[i], &H[j]);

            i = j;
            j = 2*i;
        }
        else
            break;
    }

    return x;   // x - deleted root element in heap
}

// function to create a heap of 'n' elements
int* createHeap(int H[], int n)
{
    int i = 0;

    // inserting elements from index 2 to n into heap
    for(i=2;i<=n;i++)
        Insert(H, i);
    
    return H;
}

// function to perform Heap Sort in a Heap
int* HeapSort(int H[], int n)
{
    int i = 0;

    H = createHeap(H, n);

    for(i=n;i>1;i--)
        Delete(H, i);

    return H;
}

// function to display a heap
void Display(int H[], int n)
{
    int i = 0;

    for(i=1;i<=n;i++)
        cout<<H[i]<<" ";
    
    cout<<endl;
}

int main()
{
    // int H[] = {0, 25, 30, 50, 40, 60, 15, 10, 5};   // H - heap && 0 - dummy value for that 0 index
    
    int n;
    
    cout<<"Enter the size of the Heap : ";
    cin>>n;
    
    int *H = new int[n+1];
    
    H[0] = 0;   // index 0 - will contain 0 as dummy value we don't use that

    for(int i=1;i<n+1;i++)
        cin>>H[i];

    // Insert(H, 2);   // function to insert element at index 2 to heap
    
    H = HeapSort(H, n);

    Display(H, n);
}
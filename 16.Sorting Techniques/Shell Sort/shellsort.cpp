// cpp program to implement Shell Sort
#include<iostream>

using namespace std;

// function to perform Shell Sort
void shellSort(int A[], int n)
{
    int i, j, temp, gap;

    for(gap=n/2;gap>=1;gap/=2)      // successive division of gap
    {
        for(i=gap;i<n;i++)
        {
            temp = A[i];

            j = i - gap;

            while(j >= 0 && A[j] > temp)
            {
                A[j+gap] = A[j];

                j=j-gap; 
            }

            A[j+gap] = temp;
        }
    }
}

int main()
{
    int A[] = {10, 5, 3, 2, 9}, n = 5;

    shellSort(A, n);

    for(int i=0;i<n;i++)    // for displaying the array elements
        cout<<A[i]<<" ";
}
//program to finding duplicates in a string ---> 3)using bits 
#include<iostream>

using namespace std;

void duplicateByte(char A[])          //function for finding duplicates in a string using bitwise operator - & - bitwise AND , | - bitwise OR
{
    int H = 0, x = 0;                      // H - 4 bytes (or) 32 bits only 26 bits are useful to perform the finding duplicate operation
    
    for(int i=0;A[i]!='\0';i++)
    {
        x = 1;
        x = x<<(A[i] - 97);

        if((x&H)>0)                //  performing ANDing (or) masking
        {
            cout<<"Duplicate character is \'"<<A[i]<<"\'"<<endl;
        }
        else
        {
            H = x|H;               // performing ORing (or) merging
        }
    }

}

int main() 
{
    char str1[] = "sridharan";

    duplicateByte(str1);
}
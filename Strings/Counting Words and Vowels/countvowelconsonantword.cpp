//program to find to count the No. of vowels and consonants and words in a string (or) a sentence
#include <iostream>

using namespace std;

void countVowelConsonant(char string[])          //function for counting vowels and consonants
{
    int Vcount = 0, Ccount = 0;

    for(int i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')                  // condition for finding uppercase 65-90
           Vcount++;
        else if(string[i] >= 65 && string[i] <= 'z' || string[i] >= 'A' && string[i] <= 'Z')
           Ccount++;
    }
    
    cout<<"Vowel : "<<Vcount<<endl;
    cout<<"Consonant : "<<Ccount<<endl;
}

int wordCount(char string[])          //function for counting number of words in a string (or) a sentence
{
    int word = 0;                     // Here, word is for counting spaces in the string

    for(int i=0;string[i]!='\0';i++)         //   '\0' -> null character
    {
        if(string[i] == ' ' && string[i-1] != ' ')         
           word++;
    }

    return (word+1);
}

int main() 
{
    char str1[] = "WELCOME";
    char str2[] = "hello this is my     house";
    
    countVowelConsonant(str1);
    cout<<"No. of words in the string : "<<wordCount(str2)<<endl;
    
}
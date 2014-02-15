/*      Code witten by Eric/Maxow234/ItsEric            *
*           Published under WTFPL license               *
*            https://github.com/ItsEric                 *
*                                                       *
* This programm will encode the string "toEncrypt" with *
* the key (an int) given in command line parameter. To  *
*   execute it comile it then type ./caesar.c [key].    *
*The programm is a C implementation of the Caesar cipher*
*             more info about the cipher:               *   
*     http://en.wikipedia.org/wiki/Caesar_cipher        */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int encrypt( int cap, int charToEncrypt, int key );

int main(int argc, char*argv[])
{

if (argc != 2)
{ 
printf("You should only have one argument!\n");
return 1; 
}
else if (atoi(argv[1]) <= 0)
{ return 0; }
else
{
char cryptedChar ;

char*toEncrypt = "ENTER YOUR STRING HERE !!!" ; // I don't know how to use pointers and so scanf yet. This line will be edited later

if (toEncrypt != NULL)
{
    for ( int i = 0, n = strlen(toEncrypt); i < n ; i++) // n takes every value of the string
    {
        if ( toEncrypt[i] >= 'A' && toEncrypt[i] <= 'Z' )
        {
            cryptedChar = encrypt (1, toEncrypt[i], atoi(argv[1])) ; // tell the programm it's a CAPITALIZED letter, we send the letter and the key to encrypt()
            printf("%c", cryptedChar);
        }
        else if ( toEncrypt[i] >= 'a' && toEncrypt[i] <= 'z' )
        {
            cryptedChar = encrypt (0, toEncrypt[i], atoi(argv[1])) ; 
            printf("%c", cryptedChar);
        }
        else
        {
            printf("%c", toEncrypt[i]); // One do not touch non alphabetical char
        }
    }
    printf("\n");
}
else
{
    return 2;
}
}
}

int encrypt( int cap, int charToEncrypt, int key )
{
char newChar = 0 ;
if (cap == 1) // CAPITALIZED letter
{
    newChar = ((charToEncrypt - 'A' + key)%26) + 'A' ;
}
else if (cap == 0) //  non capitalized letter
{
    newChar = ((charToEncrypt - 'a' + key)%26) + 'a' ;
}
return newChar;
}

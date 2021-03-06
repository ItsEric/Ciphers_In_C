/*      Code witten by Eric/Maxow234/ItsEric            *
*           Published under WTFPL license               *
*            https://github.com/ItsEric                 *
*                                                       *
* This program will encode the string "toEncrypt" with  *
* the key (an int) given in command line parameter. To  *
*   execute it comile it then type ./caesar.c [key].    *
*The program is a C implementation of the Caesar cipher.*
*             More info about the cipher:               *   
*     http://en.wikipedia.org/wiki/Caesar_cipher        */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int encrypt( int cap, int charToEncrypt, int key );

int main(int argc, char*argv[])
{
    int i;
    int n;
    char*toEncrypt = "ENTER YOUR STRING HERE !!!" ; // I don't know how to use pointers and so scanf yet. This line will be edited later
    char cryptedChar ;

    if (argc != 2)
    { 
        printf("You should only have one argument!\n");
        return 1; 
    }
    if (atoi(argv[1]) <= 0)
        return 0;

    if (toEncrypt == NULL)
        return 2;
    
    else // (toEncrypt =! NULL)
    {
    
       for ( i = 0, n = strlen(toEncrypt); i < n ; i++) // n takes every value of the string
       {
            if ( isupper(toEncrypt[i]) )
            {
                cryptedChar = encrypt (1, toEncrypt[i], atoi(argv[1])) ; // tell the programm it's a CAPITALIZED letter, we send the letter and the key to encrypt()
                printf("%c", cryptedChar);
            }
            else if ( islower(toEncrypt[i]) )
            {
                cryptedChar = encrypt (0, toEncrypt[i], atoi(argv[1])) ; 
                printf("%c", cryptedChar);
            }
            else
            {
                printf("%c", toEncrypt[i]); // One do not touch non alphabetical chars
            }
        }
        printf("\n");
    }

}

int encrypt( int cap, int charToEncrypt, int key )
{
    char newChar;
    char genre == ( cap ) ? 'A' : 'a';

    newChar = ((charToEncrypt - genre + key)%26) + genre ;
    return newChar;
}

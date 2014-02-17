/********************************************************
*       Code witten by Eric/Maxow234/ItsEric            *
*           Published under WTFPL license               *
*            https://github.com/ItsEric                 *
*                                                       *
*   This program will brute force any string give in    *
*command line parameter. It will try every possible key.*
*                                                       *
*       To execute it, compile it then type :           * 
*               ./caesar.c [Your string]                *
*The program is a C bruteforce of the Caesar cipher     *
*             more info about the cipher:               *   
*     http://en.wikipedia.org/wiki/Caesar_cipher        *
*********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int encrypt( int cap, int charToEncrypt, int key );

int main(int argc, char*argv[])
{
    int i, n, k, j;
    char cryptedChar ;

    if (argc == 1)
    { 
        printf("You must enter the text you want to bruteforce as command line arguments !\n");
        return 1; 
    }

    else 
    {
        // loop for evey possible key
        for (i = 0 ; i <= 25 ; i++)
        {
            // to align all the strings 
            if (i < 10)
            printf("KEY #%i: ", i);
            else 
            printf("KEY #%i:", i);
            
            // loop for every word (one word is one argv[] from 1 to argc)
            for (j = 1; j < argc ; j++)
            {
                char*toEncrypt = argv[j];
                
                // loop for every character of every argv[] (of every key)
                for ( k = 0, n = strlen(toEncrypt); k < n ; k++) // k takes every value of the word
                {
                    // Tell the program if the char is capitalized or not, then we send the letter and the key, i, to encrypt() 
                    if ( isupper(toEncrypt[k]) )
                    {
                        cryptedChar = encrypt (1, toEncrypt[k], i) ; 
                        printf("%c", cryptedChar);
                    }
                    else if ( islower(toEncrypt[k]) )
                    {
                        cryptedChar = encrypt (0, toEncrypt[k], i) ; 
                        printf("%c", cryptedChar);
                    }
                    else
                    {
                        printf("%c", toEncrypt[k]); // One do not touch non alphabetical chars
                    }
                    
                 }
                 printf(" "); // One space at the end of every word
            }

        printf("\n"); // One new line for each key
        }
    }
}

int encrypt( int cap, int charToEncrypt, int key )
{
    char newChar;
    char genre = ( cap ) ? 'A' : 'a';
    // minus genre so 'A' or 'a' = 0 and modulo 26 to "wrap" around the alphabet.
    newChar = ((charToEncrypt - genre + key)%26) + genre ;
    return newChar;
}

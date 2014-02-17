/*********************************************************
*          Code witten by Eric/Maxow234/ItsEric         *
*              Published under WTFPL license             *
*                https://github.com/ItsEric              *
*                                                        *
* This program will encode the string "toEncrypt" using  *
*       a keyword given in command line parameter.       *
*                                                        *
* To execute it comile it then type ./vigenere.c [code]. *
*                                                        *
*   This program is a C implementation of the Vigenere   *
*                                                 cipher.*
*            More info about this cipher:                *   
*   http://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher    *
*                                                        * 
* WARNING: This code is quite, the power of the ctupe.h  *
* library is not fully used and the code can be globally *
* optimized in a lot of ways. However it should compile  *
*                     and run properly.                  * 
**********************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int encrypt(int cap, int charToEncrypt, int key);

int main(int argc, char*argv[])
{
    char*toEncrypt = "ENTER YOUR STRING HERE !!!" ; // I don't know how to use pointers and so scanf yet. This line will be edited later
    char*code = argv[1];
    char cryptedChar;
    int i = 0, n = 0, nonAlpha = 0;
 
 // We check if there is enough command line arguments sent   
    if (argc != 2)
    { 
        printf("You should only have one argument!\n");
        return 1; 
    }

    else
    {
         // Now we check if "argv[1]" aka "code" is only made of alphabetical characters
        for ( i = 0, n = strlen(code); i < n ; i++)
        {
            if ( isalpha(code[i]) == 0 )
            {    
                printf("The keyword must be only made of letter !\n");
                return 1;
            }
        }


        if (toEncrypt != NULL)
        {
            // n takes every value of the string
            for ( i = 0, n = strlen(toEncrypt); i < n ; i++) 
            {
            // tell the programm if it's a CAPITALIZED letter, a "normal" letter or an non alphabetical character that we don't want to encrypt 
            // I used toupper(code[i-nonAlpha]) so I won't have to check later is the code[i-nonAlpha] is bewteen 'a' and 'z' or 'A' and 'Z' in the ASCII table
                if ( isupper(toEncrypt[i]) )
                {
                    cryptedChar = encrypt (1, toEncrypt[i], toupper(code[(i-nonAlpha) % strlen(code)])) ; 
                    printf("%c", cryptedChar);
                }
                else if ( islower(toEncrypt[i]) )
                {
                    cryptedChar = encrypt (0, toEncrypt[i], toupper(code[(i-nonAlpha) % strlen(code)])) ; 
                    printf("%c", cryptedChar);
                }
                else
                {
                    // One do not touch non alphabetical chars
                    printf("%c", toEncrypt[i]);
                    // So the counter for the code wrapping won't increment when it is a non alphabetical char see lines 64 andd 69
                    nonAlpha++; 
                }
            }
            printf("\n");
        }
    else
            return 2;
    }
}

int encrypt(int cap, int charToEncrypt, int key)
{
    
    char newChar = 0 ;
    // CAPITALIZED letter
    if (cap == 1) 
    {
        //printf("Key is: %c the char ton encrypt is %c, the sum of the two minus A and a is %d with the modulo %d +A %c\n", key, charToEncrypt, (charToEncrypt - 'A') + (key - 'a'), ((charToEncrypt - 'A') + (key - 'a'))%26, (((charToEncrypt - 'A') + (key - 'a'))%26)+'A');  
        newChar = (((charToEncrypt - 'A') + (key - 'A') ) % 26) + 'A' ;
    }
    // non capitalized letter
    else if (cap == 0) 
    {
        newChar = (((charToEncrypt - 'a') + (key - 'A') ) % 26) + 'a' ;
    }
    return newChar;
}

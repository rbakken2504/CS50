#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHA 26
#define END 122
#define END_CAPITAL 90


// declaring functions to be defined later
string Encoder(string code, string message, int k);
int GetK(char code);

int main(int argc, string argv[])
{
    // check to see if user entered 1 and only 1 argument   
    if (argc != 2 || argv <= 0)
    {
        printf("Pass me only 1 argument!\n");
        return 1;
    }
    
    string code = argv[1];
    string message;
    // check to see if user entered only letters as argument
    for(int i = 0, n = strlen(code); i < n; i++)
    {
        if (isalpha(code[i]) == false)
        {
            printf("Wrong\n");
            return 1;
        }
    }
    int k = 0;
    message = GetString();
    // passing codeword, message, and k to the Encoder method.
    string encoded = Encoder(code, message, k);
    printf("%s\n", encoded);
}

string Encoder(string code, string message, int k)
{
    string cipher = message;
    // x variable to be used to "skip" non alpha input.
    int x = 0;
    // iterating through message to be encoded and shifting k places        
    for(int i = 0, n = strlen(message); i < n ; i++)
    {
        if (isalpha(message[i])) 
        {
            // if codeword length is greater than message length, no adjustments will be needed.
            if (strlen(code) >= strlen(message))
            { 
                k = GetK(code[x]);
            }
            // if codeword length is greater than message length, adjustments will be needed.
            if (strlen(code) < strlen(message))
            {
                if (i >= strlen(code))
                {
                    // modulus will loop from the last letter, to the first
                    int temp = x % strlen(code);
                    k = GetK(code[temp]);
                }
                else
                {
                    k = GetK(code[x]);
                }
            }
        }  
        if (isspace(message[i]) || isdigit(message[i] ) || ispunct(message[i]))
        {
            // outputs non-letter input as originally inputted
            cipher[i] = message[i];
            // decrements x, so the codeword isn't used on non-letter input.
            x = x - 1;
        }
        // k adjustment to "wrap" back to the start of alphabet
        else if (k > END - message[i] && islower(message[i]))
        {
            int j = k - ALPHA;
            cipher[i] = (message[i] + j);
        }
        else if (k > END_CAPITAL - message[i] && isupper(message[i]))
        {
            int j = k - ALPHA;
            cipher[i] = (message[i] + j);
        }
        else
        {
            cipher[i] = (message[i] + k);
        }
        // increments x along with i, except in cases where a non-letter input exists.
        x++;
    }
    return cipher;
}

int GetK(char code)
{
    switch (code)
    {
        case 'A' :
        case 'a' :
            return 0;
            break;
        case 'B' :
        case 'b' :
            return 1;
            break;
        case 'C' :
        case 'c' :
            return 2;
            break;
        case 'D' :
        case 'd' :
            return 3;
            break;
        case 'E' :
        case 'e' :
            return 4;
            break;
        case 'F' :
        case 'f' :
            return 5;
            break;
        case 'G' :
        case 'g' :
            return 6;
            break;
        case 'H' :
        case 'h' :
            return 7;
            break;
        case 'I' :
        case 'i' :
            return 8;
            break;
        case 'J' :
        case 'j' :
            return 9;
            break;
        case 'K' :
        case 'k' :
            return 10;
            break;
        case 'L' :
        case 'l' :
            return 11;
            break;
        case 'M' :
        case 'm' :
            return 12;
            break;
        case 'N' :
        case 'n' :
            return 13;
            break;
        case 'O' :
        case 'o' :
            return 14;
            break;
        case 'P' :
        case 'p' :
            return 15;
            break;
        case 'Q' :
        case 'q' :
            return 16;
            break;
        case 'R' :
        case 'r' :
            return 17;
            break;
        case 'S' :
        case 's' :
            return 18;
            break;
        case 'T' :
        case 't' :
            return 19;
            break;
        case 'U' :
        case 'u' :
            return 20;
            break;
        case 'V' :
        case 'v' :
            return 21;
            break;
        case 'W' :
        case 'w' :
            return 22;
            break;
        case 'X' :
        case 'x' :
            return 23;
            break;
        case 'Y' :
        case 'y' :
            return 24;
            break;
        case 'Z' :
        case 'z' :
            return 25;
            break;
        default:
            return 0;
    }
}


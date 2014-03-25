#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHA 26
#define END 122

string Encoder(string message, int k);

int main(int argc, string argv[])
{   
    if (argc != 2 || argv <= 0)
    {
        printf("Pass me only 1 argument!\n");
        return 1;
    }
    
    string message;
    int k = atoi(argv[1]) % ALPHA;
    message = GetString();
    string encoded = Encoder(message, k);
    printf("%s\n", encoded);
    
}

string Encoder(string message, int k)
{
    string cipher = message;
    //iterating through message to be encoded and shifting k places
    for(int i = 0, n = strlen(message); i < n ; i++)
    {        
        if (isspace(message[i]) || isdigit(message[i] ) || ispunct(message[i]))
        {
            cipher[i] = message[i];
        }
        // k adjustment to "wrap" back to the start of alphabet
        else if (k > END - message[i])
        {
            int j = k - ALPHA;
            cipher[i] = (message[i] + j);
        }
        else
        {
            cipher[i] = (message[i] + k);
        }
    }
    return cipher;
}





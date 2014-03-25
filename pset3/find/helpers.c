/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    bool found = false;
    int i = (n - 1) / 2;
    int count = 0;
    int upperBound = n;
    int lowerBound = 0;
    int max = (int) log(n) / log(2);
    while ( found != true && i <= n - 1 && i >= 0 )
    {
        if (values[i] == value)
        {
            found = true;
        }
        else if ( count > max)
        {
            break;
        }
        else if (values[i] > value)
        {
            upperBound = i - 1;
            i = (i + lowerBound) / 2;
            if ( i == 1 )
            {
                i = 0;
            }
            count++;
        }
        else if (values[i] < value)
        {
            lowerBound = i + 1;
            i = (i + upperBound) / 2;
            if ( i == n - 2 )
            {
                i = n - 1;
            }
            count++;
        }
        
    }
    return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int count = 0, temp = 0;
    do
    {
       count = 0;
       for(int i = 0, j = n - 1; i < j; i++)
       {
           temp = values[i];
            if (temp > values [i + 1])
            {
                values[i] = values[i+1];
                values[i+1] = temp;
                count++;
            }
       }
                
    }
    while ( count != 0 );
    return;
}

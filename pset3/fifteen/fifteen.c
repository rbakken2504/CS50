/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

#define EMPTY 9999

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int d;

// prototypes
void clear(void);
void greet(void);
void init(int d, int board[MAX][MAX]);
void draw(int d, int board[MAX][MAX]);
bool move(int tile, int board[MAX][MAX], int d);
bool won(int board[MAX][MAX], int d);
void save(void);
void complete(int tile, int board[MAX][MAX],int d);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < MIN || d > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init(d, board);

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw(d, board);

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won(board, d))
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile, board, d))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }
        else if (move(tile, board, d))
        {
            complete(tile, board, d);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(int d, int board[MAX][MAX])
{
    int k = d * d - 1;
    if (k % 2 == 0)
    {
        for(int i = 0; i < d; i++)
        {
            
            for(int j = 0; j < d; j++, k--)
            {   
                if( i == d - 1 && j == d - 1)
                {
                    board[i][j] = EMPTY;
                }
                else
                {         
                    board[i][j] = k;
                }            
            }
        }
    }
    else
    {
        for(int i = 0; i < d; i++)
        {
            for(int j = 0; j < d; j++, k--)
            {
                if( i == d - 1 && j == d - 1)
                {
                    board[i][j] = EMPTY;
                }
                else if ( j == d - 2 && i == d - 1)
                {
                    board[i][j] = k + 1;
                    board[i][j-1] = k;
                }
                else
                {            
                    board[i][j] = k;
                }            
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(int d, int board[MAX][MAX])
{
    for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                if ( board[i][j] == EMPTY )
                {
                    if ( j == 0 )
                    {
                        printf(" _  ");
                    }
                    else if ( j == d - 1)
                    {
                        printf("_");
                    }
                    else
                    {
                        printf("_  ");
                    }
                }
                else if ( board[i][j] > 10)
                {
                    printf("%d ", board[i][j]);
                }
                else if ( board[i][j] <= 10 && j == 0 )
                {
                    printf(" %d  ", board[i][j]);
                }
                else
                {
                    printf("%d  ", board[i][j]);
                }
            }
            printf("\n");
        }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */

bool move(int tile, int board[MAX][MAX], int d)
{
    for(int i = 0; i < d; i++)
    {
        for( int j = 0; j < d; j++)
        {
            if ( board[i][j] == tile )
            {
                for( int k = 0; k < d; k++)
                {
                    for( int l = 0; l < d; l++)
                    {
                        if (board[k][l] == EMPTY)
                        {
                            if((k == i + 1 || k == i - 1) && l == j)
                            {
                                board[k][l] = tile;
                                board[i][j] = EMPTY;
                                return true;
                                break;
                            }
                            else if((l == j + 1 || l == j - 1) && k == i)
                            {
                                board[k][l] = tile;
                                board[i][j] = EMPTY;
                                return true;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return false; 
}

void complete(int tile, int board[MAX][MAX],int d)
{
    for(int i = 0; i < d; i++)
    {
        for( int j = 0; j < d; j++)
        {
            if ( board[i][j] == tile )
            {
                for( int k = 0; k < d; k++)
                {
                    for( int l = 0; l < d; l++)
                    {
                        if (board[k][l] == EMPTY)
                        {
                            if((k == i + 1 || k == i - 1) && l == j)
                            {
                                board[k][l] = tile;
                                board[i][j] = EMPTY;
                                k = d;
                                j = d;
                                i = d;
                                break;
                                
                            }
                            else if((l == j + 1 || l == j - 1) && k == i)
                            {
                                board[k][l] = tile;
                                board[i][j] = EMPTY;
                                k = d;
                                j = d;
                                i = d;
                                break;
                            }
                        }
                    }
                }
            }
        }
    } 
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(int board[MAX][MAX], int d)
{
    int check = 1, count = 0;
    bool win = false;
    for (int i = 0; i < d; i++)
    {
        for ( int j = 0; j < d && check <= d * d - 1 ; j++, check++)
        {
            if(board[i][j] == check)
            {
                count++;
            }
            else
            {
                i = d;
                break;
            }
        }
    }
    if ( count == d * d - 1)
    {
        win = true;
    }
    return win;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < d; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < d; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < d - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < d - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}

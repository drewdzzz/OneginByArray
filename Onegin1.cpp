#include <stdio.h>
#include <assert.h>
#include <math.h>
#define INPUTFILE_NAME  "onegin.txt"
#define OUTPUTFILE_NAME "oneginOut.txt"
#define SIZE         50
#define STRING_LIMIT 50
//#define DEBUG

void readInput ( FILE* fp, char poem[SIZE][STRING_LIMIT], int* sizeofpoem );
void bubbleSort ( char poem [SIZE][STRING_LIMIT], int arraySize );
void mySwap (char mySwappingArray[SIZE][STRING_LIMIT], int a, int b);
int main ()
{
    FILE* fp;
    if ( !(fp = fopen ( INPUTFILE_NAME, "r")) )
    {
        printf ("Input file is not open");
        return 1;
    }
    int sizeofpoem = STRING_LIMIT;
    char poem[SIZE][STRING_LIMIT];
    readInput ( fp, poem, &sizeofpoem );

    #ifdef DEBUG
    printf ("Reading complete!\n");
            for ( int i = 0; i < sizeofpoem; i++)
            puts(poem[i]);
    #endif

    bubbleSort ( poem, sizeofpoem);
    #ifdef DEBUG
    printf ("Poem Sorted!");
    #endif
    fclose(fp);
    if ( !(fp = fopen ( OUTPUTFILE_NAME, "w")) )
    {
        printf ("Output file is not open");
        return 1;
    }
    for (int i = 0; i < sizeofpoem; i++)
            fputs ( poem[i], fp);

    return 0;
}

void readInput ( FILE* fp, char inputArray[SIZE][STRING_LIMIT], int* sizeofpoem)
{
    assert (isfinite(*sizeofpoem));
    assert (!feof(fp));


    for (int i = 0; i < *sizeofpoem; i++)
        if (!feof (fp))
            fgets ( inputArray[i], SIZE, fp);
        else
        {
            *sizeofpoem = i;
            return;
        }
}


void bubbleSort( char poem [SIZE][STRING_LIMIT], int arraySize)
{
    assert ( poem != NULL );
    assert ( isfinite (arraySize) );
    int strcmp (char*, char*);
    void mySwap ( char [SIZE][STRING_LIMIT], int, int);
    for (int i = 0; i < arraySize; i++)
        for (int j = i; j < arraySize; j++)
            if ( strcmp ( poem[i], poem[j]) > 0 )
            {
                mySwap (poem, i, j);
                #ifdef DEBUG
                    printf("SWAPPED!\n");
                #endif
            }
}

int strcmp ( char* string1, char* string2 )
{
    assert ( string1 != NULL );
    assert ( string2 != NULL );
    #ifdef DEBUG
        printf ("IS COMPARING...\n");
    #endif
    int i = 0;
    while ( string1[i] != '\0' && string2[i] != '\0' )
    {
        if ( string1[i] >= 'A' && string1[i] <= 'Z' ) string1[i] += ('a' - 'A');
        if ( string2[i] >= 'A' && string2[i] <= 'Z' ) string2[i] += ('a' - 'A');
        if ( string1[i] != string2[i] ) return string1[i] - string2[i];
        i++;
    }

    return string1[i] - string2[i];
}

void mySwap (char mySwappingArray[SIZE][STRING_LIMIT], int a, int b)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (mySwappingArray != NULL);
    #ifdef DEBUG
        printf("IS mySwapPING...\n");
    #endif
    for (int i = 0; i < SIZE; i++)
    {
        char temp = mySwappingArray[a][i];
        mySwappingArray[a][i] = mySwappingArray[b][i];
        mySwappingArray[b][i] = temp;
    }
}


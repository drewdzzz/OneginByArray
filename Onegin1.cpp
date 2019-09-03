#include <stdio.h>
#include <assert.h>
#include <math.h>
#define INPUTFILE_NAME  "onegin.txt"
#define OUTPUTFILE_NAME "oneginOut.txt"
#define SIZE         50
#define STRING_LIMIT 50
//#define DEBUG

//void quickSort ( char poem[SIZE][STRING_LIMIT], int left, int right)
/*{
    assert ( poem != NULL );
    assert ( isfinite (left) );
    assert ( isfinite (right));
    assert ( left >= 0 && left < STRING_LIMIT);
    assert ( right >= 0 && right < STRING_LIMIT);

    int strcmp (char*, char*);
    void mySwap ( char [SIZE][STRING_LIMIT], int, int);

    char* mid = poem[ (left + right) / 2];
    int l = left;
    int r = right;
    while ( right > left )
    {
        while ( strcmp (poem[left], mid) < 0 )   left++;
        while ( strcmp (poem[right], mid) > 0 ) right--;
        if (left < right) mySwap ( poem, left, right);
        left++;
        right--;
    }
    if ( l < right ) quickSort( poem, l, right);
    if ( r > left  ) quickSort( poem, left, r);
}
*/
//{----------------------------------------------------------------------------
//!
//! @brief Функция позволяет поместить поэму в массив
//!
//! @param fp поток, из которого осуществляется ввод
//!
//! @param poem двумерный массив типа char, в который будет осуществляться ввод
//!
//! @param *sizeofpoem параметр, в который передаётся размер кол-во строк (ограничивается константой STRING_LIMIT)
//!
//! @par как юзать:
//! @code
//! readInput ( fp, poem, &sizeofpoem);
//! @endcode
//}----------------------------------------------------------------------------

void readInput ( FILE* fp, char poem[SIZE][STRING_LIMIT], int* sizeofpoem );

//{----------------------------------------------------------------------------
//!
//! @brief An usual BubbleSort:)
//!
//! @param poem double-dimensional array that will be sorted
//!
//! @param arraySize size of sorted array
//}----------------------------------------------------------------------------

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
    //quickSort ( poem, 0, sizeofpoem-1);
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
                    printf("mySwapPED!\n");
                #endif
            }
}




//{----------------------------------------------------------------------------
//! @brief Компоратор строк (понижает регистры)
//!
//! @return Возвращает разницу кодов между первыми попавшимися разными символами строк (0 если равны, >0 если a>b, <0 если a<b)
//!
//!
//!
//!
//}----------------------------------------------------------------------------

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


//{----------------------------------------------------------------------------
//!
//! @brief Функция меняется местами два элемента в массиве char
//!
//! @param array массив, в котором меняются элементы
//! @param a индекс первого элемента
//! @param b индекс второго элемента
//!
//}----------------------------------------------------------------------------

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


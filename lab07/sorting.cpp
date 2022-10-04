using namespace std;       // sets up some standard names for things
#include <iostream>        // This is  library containing input-output functions
#include <iomanip>   // this is required to use "setprecision" 
#include <fstream>
#define _USE_MATH_DEFINES  // tells the compiler to define math constants (like pi) for you
#include <cmath>
#include <cstdio>     // for the  useful old C-standard stuff 
#include <cstdlib>  
#include <stdlib.h>	// for calling

int int_sorter( const void *first_arg, const void *second_arg )
{
    int first = *(int*)first_arg;
    int second = *(int*)second_arg;
    if ( first < second )
    {
        return -1;
    }
    else if ( first == second )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    int array[10];
    int i;
    /* fill array */
    for ( i = 0; i < 10; ++i )
    {
        array[ i ] = 10 - i;
    }
    qsort( array, 10 , sizeof( int ), int_sorter );
    for ( i = 0; i < 10; ++i )
    {
        printf ( "%d\n" ,array[ i ] );
    }
}

#include <stdio.h>
#include <string.h>

int max (int a, int b)
{
  if ( a > b )
    return a;
  else
    return b;
}

double max (double a, double b)
{
  if ( a > b )
    return a;
  else
    return b;
}

char* max (char* a, char * b)
{
  if ( strcmp (a, b) > 0 )
    return a;
  else
    return b;
}

int max (int a[], int length)
{
 int i;

 int m = a[0];

 for ( i = 0 ; i < length ; i++ )
   if ( m < a[i] )
     m = a[i];

 return m;
}

int main (int argc, char** argv)
{
  printf ("L1: The larger integer value is: %d\n",
             max (3, 5 ) );

  printf ("L2: The larger string value is: %s\n",
             max ( "hello", "goodbye" ) );

  printf ("L3: The larger double value is: %f\n",
             max ( 8.211 , 3.14159 ) );

  int arr[10] = { 32, 24, 65, 12, 98, 84, 43, 72, 59, 4};
  int size = 10; 
  printf ("L4: The larget array value is: %d\n",
             max ( arr, size ) );

  return 1;
}


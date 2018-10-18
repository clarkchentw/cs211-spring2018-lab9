#include "MyDate.h"

#include <cstdio>


// attempt to change the date instance using a Pass-By-Value parameter
void changeDatePBV (MyDate d)
{
  d.setMonth ( 12 );
  d.setDay ( 25 );
}

// attempt to change the date instance using a Pass-By-ADDRESS parameter
void changeDatePBA (MyDate *d)
{
  d->setMonth ( 12 );
  d->setDay ( 25 );
}

// This function uses the C++ TRUE Pass-by-Reference parameter syntax
// attempt to change the date instance using a Pass-By-REFERENCE parameter
void changeDatePBR (MyDate &d)
{
  d.setMonth ( 12 );  // no referencing or dereferencing required!
  d.setDay ( 25 );
}

int main (int argc, char** argv)
{
 char buffer[100];   // buffer of size 100 to print dates

 // create a new instance of the MyDate class
 MyDate d; //  the default constructor is called 
 printf ("Default date: %s\n", d.toStr(buffer) );

 MyDate d2; //  the default constructor is called
 d2.setMonth ( 10 );
 d2.setDay ( 31 );
 d2.setYear ( 17 );
 printf ("Happy Halloween: %s\n", d2.toStr(buffer) );

 // create an instance of MyDate using the constructor with
 //   three parameters
 /* Delete this line to test code for Q2
 MyDate d3 ( 12, 6, 17 );
 printf ("Last day for CS 211: %s\n", d3.toStr(buffer) ); 
 *  Delete this line to test code for Q2 */

 // Why do CS majors get Halloween and Christmas confused?
 d2.setMonth ( 10 );
 d2.setDay ( 31 );
 d2.setYear ( 17 );
 printf ("Happy Halloween: %s\n", d2.toStr(buffer) );
 changeDatePBV (d2); 
 printf ("PBV Attempt - Merry Christmas?: %s\n", d2.toStr(buffer) );
  
 d2.setMonth ( 10 );
 d2.setDay ( 31 );
 d2.setYear ( 17 );
 printf ("Happy Halloween: %s\n", d2.toStr(buffer) );
 changeDatePBA (&d2); 
 printf ("PBA Attempt - Merry Christmas?: %s\n", d2.toStr(buffer) );
  
 d2.setMonth ( 10 );
 d2.setDay ( 31 );
 d2.setYear ( 17 );
 printf ("Happy Halloween: %s\n", d2.toStr(buffer) );
 changeDatePBR (d2); 
 printf ("PBR Attempt - Merry Christmas?: %s\n", d2.toStr(buffer) );
  
 return 1;
} 

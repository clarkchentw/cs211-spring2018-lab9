#include <cstdio>

class MyDate
{
 private:
   int month;
   int day;
   int year;

 public:

   // This class does not have any real constructors (yet)
   MyDate ()
   {
	month = 1;
	day = 1;
	year = 2001;
   }

   MyDate (int inputMonth, int inputDay, int inputYear)
   {
	setMonth(inputMonth);
	setDay(inputDay);
	setYear(inputYear);
   }


   void setMonth ( int m )
   {
    if ( m >= 1 && m <= 12 )
      month = m;
    else
      month = 1;
   }

   void setDay ( int d )
   {
    static int MaxDayCount[] = {0, 31, 28, 31, 30, 31, 30,
      31, 31, 30, 31, 30, 31 };

    if ( month >= 1 && month <= 12 && d >= 1 &&
         d <= MaxDayCount[month] )
      day = d;
    else
      day = 1;
   }

   void setYear ( int y )
   {
     if ( y >= 0 && y <= 99 )
       year = 2000 + y;
     else
       year = y;
   }

   // note this is unsafe since length of buf is never verified
   char* toStr (char* buf)
   {
     static char* Months[] = { "NoMonth", 
        "January",   "February", "March",    "April", 
        "May",       "June",     "July",     "August", 
        "September", "October",  "November", "December" };

     // for MDY format
     sprintf ( buf, "%s %d, %d", Months[month], day, year );

     // for mm/DD/YYYY format
     //sprintf ( buf, "%02d/%02d/%d", month, day, year);

     return buf;
   }

};

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
// /* Delete this line to test code for Q2
 MyDate d3 ( 12, 6, 17 );
 printf ("Last day for CS 211: %s\n", d3.toStr(buffer) ); 
// *  Delete this line to test code for Q2 */

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

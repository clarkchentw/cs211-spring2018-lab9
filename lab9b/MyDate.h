// File: MyDate.h   built from the lab9a.cpp file

#include <cstdio>

class MyDate
{
 private:
   //  The Data Members for the class
   int month;
   int day;
   int year;

 public:

   // prototypes for all the Methods in the class
   MyDate();
   void setMonth ( int m );
   void setDay ( int d );
   void setYear ( int y );
   char* toStr (char* buf);
};

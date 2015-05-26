#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include "Header.h"

using namespace std;

int main()
{int w;
Pharmacy a;
 while(1)
 {

cout<<endl;
   cout<<"1. Open the data file\n";
   cout<<"2. Create the data file\n";
   cout<<"3. Display data file to the screen\n";
   cout<<"4. Add records in the data file\n";
   cout<<"5. Remove records from the data file\n";
   cout<<"6. Edit records in the data file\n";
   cout<<"7. Search records in the data file\n";
   cout<<"8. Sorting\n";
   cout<<"9. Save data to a file\n";
   cout<<"0. Exit\n"<<endl;
   cout <<"Enter the number of line in the menu: ";     cin>>w;
  switch(w)
  {case 1:a.reading();break;
   case 2:a.create();break;
   case 3:a.output();getch();break;
   case 4:a.adding();break;
   case 5:a.del();break;
   case 6:a.correct();break;
   case 7:a.find();getch();break;
   case 8:a.sorting();break;
   case 9:a.record();break;
   case 0:exit(0);
   default:cout<<"Error";getch();  } }}

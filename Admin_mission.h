#ifndef ADMIN_MISSION_H_INCLUDED
#define ADMIN_MISSION_H_INCLUDED
#include<string>
#include<iostream>
#include<fstream>
#include"Login.h"
#include <cstdlib>
#include"search.h"
using namespace std;
class Admin_mission{
private:

   string filename;

public:
   //void Show_Book();///
    string Select_cat();///
    void Users_feedback();
    void Add_Book();///
    void User_Request();///
     Login read;
void Manage_Borrow_system();
void check_string (int &choies);
void isTrue(int &num, int range);

};
string Admin_mission::Select_cat(){
    string name;
    int category;
    cout<<"Please Choose From This Menu:"<<endl;
cout<<"1>>Computer Science\n2>>Cooking\n3>>Economics\n4>>Philosophy\n5>>Science"<<endl;
cin>>category;
isTrue(category,5);
check_string(category);
  switch(category){
case 1:
filename="Book_computer science.txt";
break;
case 2:
filename="Book_cooking.txt";
break;
case 3:
    filename="Book_economic.txt";
    break;
case 4:
    filename="Book_philosophy.txt";
    break;
case 5:
   filename="Book_science.txt";
    break;
default:
    cout<<"Invalid Input"<<endl;
exit(0);
}///END SWITCH CASE
return filename;
}
////////////////////////
/*void Admin_mission::Show_Book(){
string file;
file=Select_cat();
read.Readfile(file.c_str());
}*/
/////////////////////////////////
void Admin_mission::Manage_Borrow_system(){
cout<<"Welcome TO Borrowing System Manegment"<<endl;
cout<<"Borrowed Books Are"<<endl;
read.Readfile("borrow_data.TXT");
}
/////////////////////////////////////////////
void Admin_mission::User_Request(){
cout<<"U Are Going To See User Reguest For New Book..\Please Add Them As soon As."<<endl;
read.Readfile("User_Request.txt");
}
////////////////////////////////////////////////
void Admin_mission::Add_Book(){
string file,Title,Author_name;
double Book_price;int publish_year;
cout<<"Welcome To Add Book Section\nBe Carefull When Adding New Books"<<endl;
file=Select_cat();
ofstream writefile;
		writefile.open(file, ios :: app);
        cout<<"Enter the title of the book : "<<endl;
		cin>>Title;
		cout<<"Enter the author name of the book : "<<endl;;
		cin>>Author_name;
		cout<<"Enter the price of the book : "<<endl;
		cin>>Book_price;
		cout<<"Enter the year of the book : "<<endl;
		cin>>publish_year;

		writefile<<Title<<"\t"<<Author_name<<"\t"<<Book_price<<"\t"<<publish_year<<endl;
       /*search se(file);
        se.createBook(Title, Author_name, publish_year, Book_price);*/  //if you deleted the comment stars you have to change the fun.called createBook in search class to public or protected
cout<<Title<<" Added Sucssfully."<<endl;
		writefile.close();
}
/////////////////////////////////////
void Admin_mission::Users_feedback(){
cout<<"You Now Will See Users FeedBack please Treat with interest"<<endl;

read.Readfile("User_Feedback.txt");

}
/////////////////////////////
void Admin_mission::check_string (int &choies){
 while (cin.fail())
    {
        cin.clear(); // clear input buffer to restore cin to a usable state
        cin.ignore(INT_MAX,'\n'); // ignore last input
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> choies;
    }//end while
	}//end methoed
////////////////////////////////////
void Admin_mission::isTrue(int &num, int range)
{
    while((num<=0)||(num>range))
    {
        cout<<"please enter a number from 1 to "<<range<<endl;
        cin>>num;
    }
}
#endif // ADMIN_MISSION_H_INCLUDED

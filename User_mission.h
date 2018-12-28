#ifndef USER_MISSION_H_INCLUDED
#define USER_MISSION_H_INCLUDED
#include<string>
#include<iostream>
#include<fstream>
#include"Login.h"
#include "search.h"
#include"Admin_mission.h"
#include <cstdlib>
//
using namespace std;
class User_mission{
public :
void search_for(string);
void Required_book(string,string);
//void buy_book();
//void borrow_book();
void send_feedback(string);

Admin_mission admin_mission;
ofstream writefile;

};
void User_mission::search_for(string Book_name){
    string filename;
filename=admin_mission.Select_cat();
search cat(filename);
cat.searchBook(Book_name);
}
void User_mission::Required_book(string required_book,string user_name){
    string phone_num;
writefile.open("User_Request.txt",ios::app);
cout<<"Please Enter Phone Number That We Can Call You:-"<<endl;
cin>>phone_num;
writefile<<"User Name::"<<user_name<<endl;
writefile<<"Book Name::"<<required_book<<endl;
writefile<<"Phone Number::"<<phone_num<<endl;
writefile.close();
}
void User_mission::send_feedback(string username){
    char feedback[256];
cout<<"Please Enter Your Rate\nPress tab Buttun Then Enter When You finish"<<endl;
	cin.getline(feedback,100,'\t');
	writefile.open("User_Feedback.txt",ios::app);
writefile<<"User Name::"<<username<<endl;
writefile<<"FeedBack::"<<feedback<<endl;
writefile.close();
}
#endif // USER_MISSION_H_INCLUDED


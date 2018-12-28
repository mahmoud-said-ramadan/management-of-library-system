#include<iostream>
#include<string>
#include<fstream>
#include "Login.h"
#include "Admin_mission.h"
#include "User_mission.h"
#include "Borrow.h"
#include"buybook.h"
#include <cstdlib>
using namespace std;

int main(){
///START DECLARING VARIABLES
int    User_or_admin_choice,User_log_reg,Read_Terms,Admin_choice,cat_choice,User_choics,borrow_or_return;
bool   Admin_is_log=false,User_is_log=false;
string AdminUserName,AdminPassword,User_user_name,User_Password,RegUserName,RegPassword1,RegPassword2,book_name,required_book,
       borrowed_cat,borrowed_notreal,borrowed_bookname;


//////////////////////////////////
///START INIIALIZING OBJECTS
Login login;
Admin_mission Admin_work;
User_mission user_mission;

borrow b;
//////////////////////////////////

///START OF PROG
cout<<"Welcome To Our Amazing Library System,We Hope You Enjoy With Us:"<<endl;
 int otherEmail;
do{
cout<<"Are U An Admin Or User \n1-Admin\n2-User"<<endl;
    cin>>User_or_admin_choice;
    Admin_work.isTrue(User_or_admin_choice, 2);
    Admin_work.check_string(User_or_admin_choice);

if(User_or_admin_choice==1){
  do{
   cout<<"Please Enter Your User Name"<<endl;
   cin>>AdminUserName;
   cout<<"Please Enter Your PassWord"<<endl;
   cin>>AdminPassword;
  }while(login.Is_Loged(AdminUserName,AdminPassword,"Admin.txt")==false);

if(login.Is_Loged(AdminUserName,AdminPassword,"Admin.txt")){Admin_is_log=true;}
}///END User_or_admin_choice==1

else if(User_or_admin_choice==2){
    cout<<"Welcome..Do You Want To LogIn Or Register\n1>>Login\n2>>Register-NEW USER-)"<<endl;
    cin>>User_log_reg;
    Admin_work.isTrue(User_log_reg, 2);
    if(User_log_reg==1){
        do{
   cout<<"Please Enter Your User Name"<<endl;
   cin>>User_user_name;
   cout<<"Please Enter Your PassWord"<<endl;
   cin>>User_Password;
  }while(login.Is_Loged(User_user_name,User_Password,"User.txt")==false);

  if(login.Is_Loged(User_user_name,User_Password,"User.txt")==true){User_is_log=true;}
    }///END OF lOGIN
else if(User_log_reg==2){
     cout<<"You Now Are Going TO Register As A New User..."<<endl;
     cout<<"1-Read Registrition Terms For Our Library\n 2-Continue Without Reading Terms"<<endl;
     cin>>Read_Terms;
          Admin_work.check_string(Read_Terms);
          Admin_work.isTrue(Read_Terms, 2);
     if(Read_Terms==1)                              {
            cout<<"===================="<<endl;
            login.Readfile("Registration Terms.txt");}
            cout<<"===================="<<endl;

    cout<<"Please Enter User Name That You Want To Use In Your New Account"<<endl;
    cin>>RegUserName;
    cout<<"Please Enter Password"<<endl;
    cin>>RegPassword1;
    cout<<"Please Confirm Password Again"<<endl;
    cin>>RegPassword2;
    login.Registertion(RegUserName,RegPassword1,RegPassword2,"User.txt");
    cout<<"Registration Complete Sucssessfully"<<endl;
    User_is_log=true;}
}///END User_or_admin_choice==2
////////////////////////////////////////////////////End Login And Registeratiom ///
if(Admin_is_log){
 cout<<"Welcome "<<AdminUserName<<endl;
 int admenAgain;
do{
 cout<<"1>>Show Book\n2>>Manage Borrowing System\n3>>See Users Request For Books\n4>>see Users Comment\n5>>Add New Books"<<endl;
cin>>Admin_choice;
     Admin_work.check_string(Admin_choice);
     Admin_work.isTrue(Admin_choice, 5);

 if(Admin_choice==1){ /*Admin_work.Show_Book();*/  //show books from files
    search se(Admin_work.Select_cat());
    se.display();                                //show books from the list
 }///show Book
 else if(Admin_choice==2){Admin_work.Manage_Borrow_system();}
 else if(Admin_choice==3){Admin_work.User_Request();}///See Users Request For New Book
 else if(Admin_choice==4){Admin_work.Users_feedback();}///user feedback
 else if(Admin_choice==5){Admin_work.Add_Book();}

 cout<<"if U want to do other options as an admen enter -1-\n If U Don't Want Press Any Other Number"<<endl;
cin>>admenAgain;
     Admin_work.check_string(admenAgain);
}while(admenAgain==1);

}///END OF ADMIN IS LOGED
///////////////////////////////////////////////////////
if(User_is_log){
cout<<"Welcome "<<User_user_name<<endl;
    int userAgain;
do{
cout<<"1>>Search For Book\n2>>Ask For New Book\n3>>Buy Book\n4>>Borrow Book||Return Book\n5>>Rate Our Library "<<endl;
     cin>>User_choics;
     Admin_work.check_string(User_choics);
     Admin_work.isTrue(User_choics, 5);

if(User_choics==1){///search
        cout<<"Please Enter The Name Of The Book"<<endl;
        cin>>book_name;
        user_mission.search_for(book_name);
}
else if(User_choics==2){///Ask For Book
    cout<<"We Will Respond to Your Request As Soon As We Can"<<endl;
    cout<<"Please Enter The Name OF THe Book"<<endl;
    cin>>required_book;
    user_mission.Required_book(required_book,User_user_name);
}
else if(User_choics==3){///Buy New Book
    cout<<"Buying Isn't finished"<<endl;
}
else if(User_choics==4){///Borrow
  cout<<"Welcome To Borrowing,Return Department"<<endl;
  cout<<"Please Select Category That Do U Want To Interact with"<<endl;
  borrowed_cat=Admin_work.Select_cat();
  if(borrowed_cat=="Book_computer science.txt"){borrowed_notreal="computer science.txt";}
  else if(borrowed_cat=="Book_cooking.txt")    {borrowed_notreal="cooking.txt";}
  else if(borrowed_cat=="Book_economic.txt")   {borrowed_notreal="economic.txt";}
  else if(borrowed_cat=="Book_philosophy.txt") {borrowed_notreal="philosophy.txt";}
  else if(borrowed_cat=="Book_science.txt")    {borrowed_notreal="science.txt";}
  else{cout<<"Invalid Input"<<endl;exit(0);}
cout<<"Do U Want to Borrow or return\n1>>Borrow\n2>>Return"<<endl;
   cin>>borrow_or_return;
if(borrow_or_return==1){
  cout<<"Enter The Name Of The Book"<<endl;
  cin>>borrowed_bookname;
b.borrowing(borrowed_bookname,borrowed_cat,borrowed_notreal);
  cout<<"Borrowing Done Sucssfully"<<endl;}
else if(borrow_or_return==2){
  cout<<"Enter The Name Of The Book That U Will Return"<<endl;
  cin>>borrowed_bookname;
b.return_book(borrowed_bookname,borrowed_cat,borrowed_notreal);
}

}

else if(User_choics==5){
    cout<<"we Are happy That U Will Rate Us"<<endl;
    user_mission.send_feedback(User_user_name);
}
cout<<"if U want to do other options as a user enter \"1\" "<<endl;
 cin>>userAgain;
     Admin_work.check_string(userAgain);

}while(userAgain==1);
}///END USER IS LOGED
cout<<"if U want to Enter with Another E-Mail enter \"1\" "<<endl;
cin>>otherEmail;
Admin_work.check_string(otherEmail);
Admin_is_log=false;
User_is_log=false;
}while(otherEmail==1);
////STAY AWAY//////////////////////////////////
cout<<"We Hope That U Had a Nice Expriance With Us,\nEnjoy Reading...\nGood Bye"<<endl;
return 0;
}

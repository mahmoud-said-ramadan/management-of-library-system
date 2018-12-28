#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include<string>
#include<fstream>
#include<list>
using namespace std;
class Login{
private:
    string line;
    int choice;
    ///
    string word;
    list<string>loglist;
    list<string>::iterator it=loglist.begin();
public:
   // bool Is_Loged(string,string,string );
    void Registertion(string,string,string,string);
    void Readfile(string);
    void read(ifstream &file);
    bool Is_Loged(string,string,string);

};
bool Login::Is_Loged(string username,string password,string filename){
ifstream File;
File.open(filename.c_str());
	while (getline(File, word))
	{
		loglist.push_back(word);
	}
	File.close();
    bool access = false;
	for (it = loglist.begin(); it != loglist.end(); it++) {
		if (username == *it) {
			it++;
		if(password== *it) {
			access = true;
		}
		}
	}
if (access==false){
    cout<<"SomeThing Went Wrong!! \n*User Name Or Password Are Wrong"<<endl;
   cout<<"Make Sure That Your User Name And Password Are Correct"<<endl;
	return access;
}
}


///////////////////////////////////
void Login::Registertion(string username,string password1,string password2,string filename ){
ofstream writefile;
writefile.open(filename.c_str(),ios::app);
if(writefile.is_open())
cout<<"Are U Sure That u Want To Use- " <<username<<" -As a User Name "<<endl;
   cout<<" 1-Yes \n 2-No \n Enter 1 Or 2"<<endl;
  cin>>choice;
   if(choice==1){writefile<<username<<endl;}
   else if(choice==2){cout<<"Enter The User Name That U Want"<<endl;
   cin>>username;
   writefile<<username<<endl;
   }

while(password1!=password2){
 cout<<"Two PAssword Arent The same!"<<endl;
 cout<<"Please Enter Password"<<endl;
    cin>>password1;
    cout<<"Please Confirm Password Again"<<endl;
    cin>>password2;
}
writefile<<password1<<endl;
writefile.close();
}

///////////////////////////////////////////////////
void Login::Readfile(string filename){
ifstream readfile;
readfile.open(filename.c_str());
if(readfile.is_open()){
    while(getline(readfile,line)){
        cout<<line<<endl;
    }
    readfile.close();
}
else{cout<<"Error While Opening "<<filename<<endl;
}
}
#endif // LOGIN_H_INCLUDED

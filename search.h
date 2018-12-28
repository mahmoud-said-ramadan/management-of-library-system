#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
#include <fstream>

struct Book                //to create a Book
{
 string name, author;//data
 double price;       //data
 int year;           //data
 Book *next;         //pointer of the Book
};
class search
{
    private:
		Book *head, *tail;    //pointer in the first and other in the end
		string name,author;
		int year;
		double price;
		void print(Book *add );           //fun. to print the books
        void readFile(string FileName);           //fun. to read the data from the file to the data structure (list)
		public:
		search(string FileName);                  //constructor
		void display();                          //fun. to display the data from the data structure (list)
        void searchBook(string b);               //fun. to search in the data structure (list)
        void createBook(string n, string a, int y, double p);  //fun to create a Book

};
search::search(string FileName)   //the constructor
		{
			head=NULL;
			tail=NULL;
			readFile(FileName.c_str()); //fun.Book
		}
void search::readFile(string FileName)
{
        ifstream file(FileName);
            if(file.is_open())
              {
                  while(file >> name >> author >> price >> year)
                  {
                    createBook(name,author,year,price); //fun.
                 }
                    file.close();
              }
              else
              cout<<"the file isn't here"<<endl;
    }
void search::createBook(string n, string a, int y, double p)
		{
			Book *add=new Book;    //object from the struct Book
			add->name=n;
			add->author=a;
			add->year=y;
			add->price=p;
			add->next=NULL;
			if(head==NULL)   //if the pointer was empty
			{
				head=add;
				tail=add;
				add=NULL;
			}
			else
			{
				tail->next=add;
				tail=add;
				add=NULL;
			}
		}

void search::display()
		{
			Book *add=new Book;
			add=head;
			while(add!=NULL)
			{
				print(add); //fun.
				add=add->next;
			}
		}
void search::searchBook(string b)
		{
            Book *add=new Book;
            add=head;
            bool y=false;
			while(add!=NULL)
			{
			     if(b==add->name)
                        {
                            print(add);//fun.
				            y=true;
				            break;
                        }
                add=add->next;

             }
                  if(!y)
                    cout<<b<<"\" isn't available now!,We Are Sorry \n You can Ask The Admin To bring it soon to library\""<<endl;
        }
void search::print(Book *add )
    {
            cout<<"the name of the book is: "<<add->name<<"\n";
            cout<<"the author is: "<<add->author<<"\n";
            cout<<"has published in: "<<add->year<<"\n";
            cout<<"the price is: "<<add->price<<"\n";
            cout<<endl;
    }


#endif // SEARCH_H_INCLUDED

#ifndef BUYBOOK_H_INCLUDED
#define BUYBOOK_H_INCLUDED


#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
class buyBook{
public:
	/*
void removeLibraryBook(string Bname,string booksSold,string bookWanted) {
	string    line, line2;
	ifstream  books(bookWanted.c_str());//books is object from ifstream
	ofstream  Nbook("Nbooks.TXT");// name of book that has sold
	ifstream  data(booksSold.c_str());// data is object from ifstrream
	ofstream  Ndata("Ndata.TXT"); // name of book that sold
	fstream   sold_book_data("sold_book_data.TXT", ios::app);
	fstream   buying_book("buying_book.TXT", ios::app);
	while (getline(books, line)) {
		getline(data, line2);
		if (line == Bname) {
			sold_book_data << line2 << endl;
			buying_book << line << endl;
		}
		else if (line != Bname) {
			Ndata << line2 << endl;
			Nbook << line << endl;
		}
	}
	data.close();
	Ndata.close();
	sold_book_data.close();
	books.close();
	Nbook.close();
	buying_book.close();
	remove(booksSold.c_str());
	rename("Ndata.txt", booksSold.c_str());
	remove(bookWanted.c_str());
	rename("Nbooks.txt", bookWanted.c_str());
	remove ("Nbooks.TXT");
}
/////////////
void return_book(string BookName,string booksSold,string bookWanted) { ///relfile*->data file //ntrelfile*->name of book wanted
	string line, line2;
	ifstream Buying_data("sold_book_data.TXT");
	ifstream Buying_book("buying_book.TXT");
	ofstream books(booksSold.c_str(), ios::app);
	ofstream data(booksSold.c_str(), ios::app);
	ofstream  Nbuying_data("Ndata.TXT");
	ofstream  Nbuying_book("Nbook.TXT");
	while (getline(Buying_book, line)) {
		getline(Buying_data, line2);
		if (line == BookName) {
			data << line2 << endl;
			books << line << endl;
		}
		else if (line != BookName) {
			Nbuying_data << line2 << endl;
			Nbuying_book << line << endl;
		}
	}
	data.close();
	//sold_book_data.close();
	Buying_book.close();
	books.close();
	Nbuying_book.close();
	Buying_book.close();
	remove("buying_book.TXT");
	rename("Ndata.txt", "sold_book_data.TXT");
	remove("buying_book.TXT");
	rename("Nbooks.txt", "buying_book.TXT");


}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
sing namespace std;
struct node{
string name ;
string author;
double price;
int year;
node *next;

};
class Buying{
private:
    node *head,*tail;
    string name ,author;

    void creatnode(string Name,string Author,double Price,int Year);
    void readFile(string book);
    void readPricesFromFile(double PRICE);

    public:
        double price;
        Buying(string BookWanted); ///the constructor
        double PriceReminder(double usrMoney,double PRICE);

        void RemoveBookWanted(string BookWanted,node *head);





};
void Buying::creatnode(string NAME,string AUTHOR ,double PRICE,int YEAR){
node*add=new node;
add->name=NAME;
add->author=AUTHOR;
add->price=PRICE;
add->year=YEAR;
add->next=nullptr;
if (head ==nullptr){
    head=add;
    tail=add;
    add=nullptr;
}
else{
    tail->next=add;
    tail=add;
    add=nullptr;


}}
Buying::Buying(string BookWanted){
    head=nullptr;
    tail=nullptr;

}
void Buying::RemoveBookWanted(string BookWanted,node *head){
		{
		node *k,*q;
		q=head; //let q the start pointer to creat a list
		k=head->next;
		if (q-> name ==BookWanted){ // if the book which wanted to buy in the first in the list
		   // head k;
		    delete (q);
		}
		else{ // we will use the loop to find the book,s wanted
		while(k->name!=BookWanted){
		    k=k->next;
		    q=q->next;
		    if (k->next =nullptr){ // suppose that we found the book in the end of the list which the pointer  will be null
		        q->next =nullptr;
		        delete (k);

		    }
		    else{ // unless all the contion of the above ,of course it will be between in the front and the last of the list so let the pointer of k which point in a position = the pointer of q which  will point in the same position then delete (k)book wanted from the list
		        q->next=k->next;
		        delete (k);
		    }
		}
		return &head;
		}
		}
}
Buying::Buying(string BookWanted){
head=nullptr;
tail=nullptr;
readFile(bookWanted.c_str());
readPricesFromFile(double PricesBook.c_str());

}
void Buying::readFile(String BookWanted){//

    ifstream object1("Book_computer science.txt");
    if (object1.is_open()){
        while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }
    else {
        object1.open("Book_cooking.txt");
        while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }}
    object1.close();

    istream object2("Book_cooking,txt");
    if (object2.is_open()){
            while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }
    else {
        object2.open("Book_cooking.txt");
        while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }}
    }
    object2.close();

    ifstream object3("Book_economic.txt");

     if (object.is_open()){
            while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }
    else {
        object3.open("Book_cooking.txt");
        while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }}
    }
    object3.close();

    ifstream object4("Book_philosophy.txt");
    if (object4.is_open()){
            while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }
    else {
        object4.open("Book_cooking.txt");
        while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }}
    }
    object4.close();

    ifstream object5 ("Book_science.txt");
     if (object5.is_open()){
            while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }
    else {
        object5.open("Book_science.txt");
        while (name>>year>>author>>price){
        creatnode(name ,auther,price,year);
    }}
    }
object5.close();
    }
}
void Buying::readPricesFromFile(double PRICE){
ifstream object1 ("Book_science.txt");
     if (object1.is_open()){
            while (object1>>price){

    }
    else {
        object1.open("Book_science.txt");
        while (object1>>price){

    }}
}
ifstream object2 ("Book_science.txt");
     if (object2.is_open()){
            while (object2>>price){

    }
    else {
        object2.open("Book_science.txt");
        while (object2>>price){

    }}
}ifstream object3 ("Book_science.txt");
     if (object3.is_open()){
            while (object3>>price){

    }
    else {
        object3.open("Book_science.txt");
        while (object3>>price){

    }}
}ifstream object4 ("Book_science.txt");
     if (object4.is_open()){
            while (object4>>price){

    }
    else {
        object4.open("Book_science.txt");
        while (object4>>price){

    }}
}ifstream object5 ("Book_science.txt");
     if (object5.is_open()){
            while (object5>>price){

    }
    else {
        object5.open("Book_science.txt");
        while (object5>>price){

    }}
object1.close();
object2.close();
object3.close();
object4.close();
object5.close();
}



    double Buying::PriceReminder(double usrMoney,double PRICE){
           if (usrMoney==PRICE)
		cout >> "there is no reminder";
		else if (usrMoney>PRICE)
		    double r=usrMoney-PRICE;
		    else

		    return r;


    }


}

*/
};

#endif // BUYBOOK_H_INCLUDED

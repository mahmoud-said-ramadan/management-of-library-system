#ifndef BORROW_H_INCLUDED
#define BORROW_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
class borrow{
public:
void borrowing(string Bname,string relfile,string notrelfile) {
	string line, line2;
	ifstream books(notrelfile.c_str());
	ofstream  Nbook("Nbooks.TXT");
	ifstream data(relfile.c_str());
	ofstream  Ndata("Ndata.TXT");
	fstream borrow_data("borrow_data.TXT", ios::app);
	fstream borrow_book("borrow_book.TXT", ios::app);
	while (getline(books, line)) {
		getline(data, line2);
		if (line == Bname) {
			borrow_data << line2 << endl;
			borrow_book << line << endl;
		}
		else if (line != Bname) {
			Ndata << line2 << endl;
			Nbook << line << endl;
		}
	}
	data.close();
	Ndata.close();
	borrow_data.close();
	books.close();
	Nbook.close();
	borrow_book.close();
	remove(relfile.c_str());
	rename("Ndata.txt", relfile.c_str());
	remove(notrelfile.c_str());
	rename("Nbooks.txt", notrelfile.c_str());
	remove ("Nbooks.TXT");


}
/////////////
void return_book(string BookName,string relfile,string notrelfile) {
	string line, line2;
	ifstream borrow_data("borrow_data.TXT");
	ifstream borrow_book("borrow_book.TXT");
	ofstream books(notrelfile.c_str(), ios::app);
	ofstream data(relfile.c_str(), ios::app);
	ofstream  Nborrow_data("Ndata.TXT");
	ofstream  Nborrow_book("Nbook.TXT");
	while (getline(borrow_book, line)) {
		getline(borrow_data, line2);
		if (line == BookName) {
			data << line2 << endl;
			books << line << endl;
		}
		else if (line != BookName) {
			Nborrow_data << line2 << endl;
			Nborrow_book << line << endl;
		}
	}
	data.close();
	Nborrow_data.close();
	borrow_data.close();
	books.close();
	Nborrow_book.close();
	borrow_book.close();
	remove("borrow_data.TXT");
	rename("Ndata.txt", "borrow_data.TXT");
	remove("borrow_book.TXT");
	rename("Nbooks.txt", "borrow_book.TXT");


}



};

#endif // BORROW_H_INCLUDED

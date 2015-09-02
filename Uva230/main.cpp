/*
	UvaOJ 230
	Emerald
	Sat 9 May 2015
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book { // the book
public :
	string title, author; // the book's title and author
	bool returned, borrowed;
	Book( string t, string a ) {
		title = t;
		author = a;
		returned = borrowed = false; // false, not be borrowed
	}
	Book() {
		returned = borrowed = false; // false, not be borrowed
	}
};

vector <Book> list;

bool cmpa( Book a, Book b ) {
	return a.author < b.author;
}

bool cmpt( Book a, Book b ) {
	return a.title < b.title;
}

void Borrow() {
	string title;
	getline( cin, title );
	std::vector<Book> :: iterator it;
	for( it = list.begin(); it != list.end(); it++ ) {
		if( it->title == title ) {
			it -> borrowed = true;
		}
	}
}

void Return() {
	string title;
	getline( cin, title );
	std::vector<Book> :: iterator it;
	for( it = list.begin(); it != list.end(); it++ ) {
		if( it->title == title ) {
			it -> returned = true;
		}
	}

}

void Shelve() {
	for( int i=0, j; i<list.size(); i++ ) {
		if( list[i].returned ) {
			for( j = i - 1; j >= 0; j -- ) {
				if( list[j].borrowed == false ) {
					break;
				}
			}
			if( j==-1 ) {
				printf( "Put %s first\n", list[i].title.c_str() );
			} else {
				printf( "Put %s after %s\n", list[i].title.c_str(), list[j].title.c_str() );
			}
			list[i].borrowed = list[i].returned = false;
		}
	}
	printf("END\n");
}

int main() {
	string line;
	while( getline( cin, line ) && line!="END" ) {
		list.push_back( Book( line.substr( 0, line.find_last_of( '\"' ) + 1 ),
			line.substr( line.find_last_of('\"')+1 ) ) );
	} // substr the string
	stable_sort( list.begin(), list.end(), cmpt );
	stable_sort( list.begin(), list.end(), cmpa );

	string op;
	while( cin >> op ) {
		if( op == "BORROW" ) {
			cin.get();
			Borrow();
		} else if( op == "RETURN" ) {
			cin.get();
			Return();
		} else if( op == "SHELVE" ) {
			cin.get();
			Shelve();
		}
	}
	return 0;
}
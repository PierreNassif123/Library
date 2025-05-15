#include <iostream>
#include <string>
using namespace std;

int maxbooks = 100;
int bookid[100];
string booktitles[100];
string bookauthors[100];
bool isborrowed[100];
int bookcount = 0;

void addbook() {
    int id;
    string title, author;

    cout << "enter the id, title,and author " << endl;
    if (bookcount < maxbooks) {
        cin >> id >> title >> author;

        bookid[bookcount] = id;
        booktitles[bookcount] = title;
        bookauthors[bookcount] = author;
        isborrowed[bookcount] = false; 
        bookcount++;
    }
    else {
        cout << "library is full" << endl;
    }
}

void display() {
    for (int i = 0; i < bookcount; i++) {
        cout << "id: " << bookid[i] << endl;
        cout << "title: " << booktitles[i] << endl;
        cout << "author: " << bookauthors[i] << endl;
        cout << "status: " << (isborrowed[i] ? "not available" : "available") << endl;
    }
}

void borrowed() {
    int id;
    cout << "enter the id of the book you want to borrow " << endl;
    cin >> id;

    bool found = false;
    for (int i = 0; i < bookcount; i++) {
        if (bookid[i] == id) {
            found = true;
            if (!isborrowed[i]) {
                cout << "you borrowed this book" << endl;
                isborrowed[i] = true;
            }
            else {
                cout << "this book is already borrowed" << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "book not found in the library" << endl;
    }
}

void returnbook() {
    int id;
    cout << "enter the id of the book you want to return: " << endl;
    cin >> id;

    bool found = false;
    for (int i = 0; i < bookcount; i++) {
        if (bookid[i] == id) {
            found = true;
            if (isborrowed[i]) {
                cout << "you returned the book" << endl;
                isborrowed[i] = false;
            }
            else {
                cout << "this book is already available" << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "book not found in the library" << endl;
    }
}

int exitprog() {
    return 0;
}

void pragramoutput(){
    int choice = 0;
    while (choice != 5) {
        cin >> choice;
        switch (choice)
        {
        case 1: 
            addbook();
            break;
        case 2:
            display();
            break;
        case 3: 
            borrowed();
            break;
        case 4: 
            returnbook();
            break;
        case 5: 
            exitprog();
            break;

        default:
            cout << "enter a valid number" << endl;
            cin >> choice;
            break;
        }
    }


}

int main() {
    
    cout << "enter 1 if u want to add a book" << endl;
    cout << "enter 2 if u want to display all books" << endl;
    cout << "enter 3 if u want to borrow a book" << endl;
    cout << "enter 4 if u want to return a book" << endl;
    cout << "enter 5 if u want to exit the program" << endl;
    pragramoutput();
}
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Library {
private:
    
    map<string, int> books;

public:
    
    void addBook(const string &bookName, int quantity) {
        books[bookName] += quantity;  
        cout << "Added " << quantity << " copies of '" << bookName << "' to the library." << endl;
    }

    
    void displayBooks() {
        cout << "\nAvailable Books in Library:" << endl;
        if (books.empty()) {
            cout << "No books available in the library." << endl;
            return;
        }
        for (const auto &book : books) {
            cout << "'" << book.first << "' - " << book.second << " copies available" << endl;
        }
    }

    
    void issueBook(const string &bookName) {
        if (books.find(bookName) != books.end() && books[bookName] > 0) {
            books[bookName]--;
            cout << "You have successfully issued '" << bookName << "'." << endl;
        } else {
            cout << "Sorry, '" << bookName << "' is not available or out of stock." << endl;
        }
    }

    
    void returnBook(const string &bookName) {
        if (books.find(bookName) != books.end()) {
            books[bookName]++;
            cout << "'" << bookName << "' has been successfully returned." << endl;
        } else {
            cout << "'" << bookName << "' does not exist in the library system." << endl;
        }
    }
};


int main() {
    Library library;
    int choice;
    string bookName;
    int quantity;

    while (true) {
        
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) {
            case 1:
                cout << "Enter book name: ";
                cin.ignore();  
                getline(cin, bookName);
                cout << "Enter quantity of books: ";
                cin >> quantity;
                library.addBook(bookName, quantity);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter book name to issue: ";
                cin.ignore();
                getline(cin, bookName);
                library.issueBook(bookName);
                break;
            case 4:
                cout << "Enter book name to return: ";
                cin.ignore();
                getline(cin, bookName);
                library.returnBook(bookName);
                break;
            case 5:
                cout << "Exiting Library Management System." << endl;
                return 0;  
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


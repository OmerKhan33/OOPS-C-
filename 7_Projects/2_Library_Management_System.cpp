#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm> // Required for std::find

using namespace std;

// Base class for Users
class User {
protected:
    string name;
    string id;
public:
    User(string n, string i) : name(n), id(i) {}
    
    // Virtual function to display user information
    virtual void display() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    
    virtual ~User() {}
};

// Derived class for Members
class Member : public User {
public:
    vector<string> borrowedBooks;  // Stores borrowed books

    Member(string n, string i) : User(n, i) {}
    
    // Function to borrow a book
    void borrowBook(const string& book) {
        borrowedBooks.push_back(book);
    }
    
    // Function to return a borrowed book
    void returnBook(const string& book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
        }
    }
    
    // Overridden display function to include borrowed books
    void display() const override {
        User::display();
        cout << "Borrowed Books: ";
        for (const auto& book : borrowedBooks) {
            cout << book << " ";
        }
        cout << endl;
    }
};

// Derived class for Librarians
class Librarian : public User {
public:
    Librarian(string n, string i) : User(n, i) {}
    
    // Overridden display function to indicate librarian role
    void display() const override {
        User::display();
        cout << "Role: Librarian" << endl;
    }
};

// Book class representing each book in the library
class Book {
private:
    string title;
    string author;
    bool isAvailable;  // Book availability status

public:
    Book(string t, string a, bool avail = true) : title(t), author(a), isAvailable(avail) {}

    // Set availability of the book
    void setAvailability(bool avail) {
        isAvailable = avail;
    }
    
    // Get the availability status of the book
    bool getAvailability() const {
        return isAvailable;
    }
    
    // Get the title of the book
    string getTitle() const {
        return title;
    }
    
    // Display book details
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

// Library class managing a collection of books
class Library {
public:
    vector<Book> books;  // Vector storing all books

    // Add a new book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }
    
    // Display all books in the library
    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }
    
    // Borrow a book from the library if available
    bool borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title && book.getAvailability()) {
                book.setAvailability(false);
                return true;
            }
        }
        return false;
    }
    
    // Return a borrowed book to the library
    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.setAvailability(true);
                break;
            }
        }
    }
};

// Function to save library data to a file
void saveLibraryData(const Library& library, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& book : library.books) {
            outFile << book.getTitle() << "," << book.getAvailability() << endl;
        }
        outFile.close();
    }
}

// Function to load library data from a file
void loadLibraryData(Library& library, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string title, author, line;
        bool isAvailable;
        while (getline(inFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find_last_of(',');
            title = line.substr(0, pos1);
            author = line.substr(pos1 + 1, pos2 - pos1 - 1);
            isAvailable = line.substr(pos2 + 1) == "1";
            library.addBook(Book(title, author, isAvailable));
        }
        inFile.close();
    }
}

int main() {
    Library library;
    loadLibraryData(library, "library_data.txt");

    Librarian librarian("Alice", "L001");
    Member member("Bob", "M001");

    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    cout << "Library Inventory:" << endl;
    library.displayBooks();
    cout << endl;

    cout << "Librarian Info:" << endl;
    librarian.display();
    cout << endl;

    cout << "Member Info:" << endl;
    member.display();
    cout << endl;

    cout << "Attempting to borrow '1984': " << (library.borrowBook("1984") ? "Success" : "Failed") << endl;
    member.borrowBook("1984");
    member.display();
    cout << endl;

    cout << "Returning '1984': " << endl;
    library.returnBook("1984");
    member.returnBook("1984");
    member.display();
    cout << endl;

    saveLibraryData(library, "library_data.txt");

    return 0;
}

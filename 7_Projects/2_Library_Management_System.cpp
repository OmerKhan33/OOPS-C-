#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Base class for Users
class User {
protected:
    string name;
    string id;
public:
    User(string n, string i) : name(n), id(i) {}
    virtual void display() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    virtual ~User() {}
};

// Derived class for Members
class Member : public User {
public:
    vector<string> borrowedBooks;
public:
    Member(string n, string i) : User(n, i) {}
    void borrowBook(const string& book) {
        borrowedBooks.push_back(book);
    }
    void returnBook(const string& book) {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
        }
    }
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
    void display() const override {
        User::display();
        cout << "Role: Librarian" << endl;
    }
};

class Book {
public:
    string title;
    string author;
    bool isAvailable;
public:
    Book(string t, string a, bool avail = true) : title(t), author(a), isAvailable(avail) {}

    void setAvailability(bool avail) {
        isAvailable = avail;
    }
    bool getAvailability() const {
        return isAvailable;
    }
    string getTitle() const {
        return title;
    }
    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Library {
public:
    vector<Book> books;
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }
    void displayBooks() const {
        for (const auto& book : books) {
            book.display();
        }
    }
    bool borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title && book.getAvailability()) {
                book.setAvailability(false);
                return true;
            }
        }
        return false;
    }
    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.setAvailability(true);
                break;
            }
        }
    }
};

void saveLibraryData(const Library& library, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        // Save books data
        // Note: This is simplified, for real use you'd serialize more information
        for (const auto& book : library.books) {
            outFile << book.getTitle() << "," << book.getAuthor() << "," << book.getAvailability() << endl;
        }
        outFile.close();
    }
}

void loadLibraryData(Library& library, const string& filename) {
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string title, author;
        bool isAvailable;
        string line;
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

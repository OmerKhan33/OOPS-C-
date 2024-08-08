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
private:
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
private:
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
private:
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

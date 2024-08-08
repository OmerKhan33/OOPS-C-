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

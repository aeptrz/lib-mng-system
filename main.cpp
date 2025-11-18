#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

// =========================
// main - Simple menu
// =========================
int main() {
    Library library;

    // Preload some sample data
    library.addBook(Book("Clean Code", "Robert C. Martin", "1111", 2008));
    library.addBook(Book("The Pragmatic Programmer", "Andrew Hunt", "2222", 1999));
    library.addBook(Book("Design Patterns", "Gamma et al.", "3333", 1994));

    library.addCD(CD("Thriller", "Michael Jackson", "100000000001", 1982));
    library.addCD(CD("Abbey Road", "The Beatles", "100000000002", 1969));

    library.addMember(Member("Alice", "M01", 3));
    library.addMember(Member("Bob", "M02", 5));

    int option;
    do {
        cout << "===== Library Menu =====" << endl;
        cout << "1. List books" << endl;
        cout << "2. List members" << endl;
        cout << "3. List CDs" << endl;
        cout << "4. List all loans" << endl;
        cout << "5. List active loans" << endl;
        cout << "6. Borrow a book" << endl;
        cout << "7. Return a book" << endl;
        cout << "8. Borrow a CD" << endl;
        cout << "9. Return a CD" << endl;
        cout << "10. Remove a book" << endl;
        cout << "11. Remove a member" << endl;
        cout << "12. Remove a CD" << endl;
        cout << "13. Search a book" << endl;
        cout << "14. Search a CD" << endl;
        cout << "0. Exit" << endl;
        cout << "Select option: ";
        cin >> option;

        if (option == 1) {
            library.listBooks();
        }
        else if (option == 2) {
            library.listMembers();
        }
        else if (option == 3) {
            library.listCDs();
        }
        else if (option == 4) {
            library.listLoans(false);
        }
        else if (option == 5) {
            library.listLoans(true);
        }
        else if (option == 6) {
            string memberId, isbn, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Book ISBN: ";
            cin >> isbn;
            cout << "Borrow date (YYYY-MM-DD): ";
            cin >> date;
            library.borrowBook(memberId, isbn, date);
            cout << endl;
        }
        else if (option == 7) {
            string memberId, isbn, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "Book ISBN: ";
            cin >> isbn;
            cout << "Return date (YYYY-MM-DD): ";
            cin >> date;
            library.returnBook(memberId, isbn, date);
            cout << endl;
        }
        else if (option == 8) {
            string memberId, upc, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "CD UPC: ";
            cin >> upc;
            cout << "Borrow date (YYYY-MM-DD): ";
            cin >> date;
            library.borrowCD(memberId, upc, date);
            cout << endl;
        }
        else if (option == 9) {
            string memberId, upc, date;
            cout << "Member ID: ";
            cin >> memberId;
            cout << "CD UPC: ";
            cin >> upc;
            cout << "Return date (YYYY-MM-DD): ";
            cin >> date;
            library.returnCD(memberId, upc, date);
            cout << endl;
        }
        else if (option == 10) {
            string isbn;
            cout << "Book ISBN to remove: ";
            cin >> isbn;
            library.removeBook(isbn);
            cout << endl;
        }
        else if (option == 11) {
            string memberId;
            cout << "Member ID to remove: ";
            cin >> memberId;
            library.removeMember(memberId);
            cout << endl;
        }
        else if (option == 12) {
            string upc;
            cout << "CD UPC to remove: ";
            cin >> upc;
            library.removeCD(upc);
            cout << endl;
        }
        else if (option == 13) {
            string query;
            cout << "Enter book title or ISBN: ";
            cin.ignore();
            getline(cin, query);
            Book* book = library.searchBook(query);
            if (book) {
                cout << "Book found:" << endl;
                book->printInfo();
            } else {
                cout << "Book not found." << endl;
            }
            cout << endl;
        }
        else if (option == 14) {
            string query;
            cout << "Enter CD title or UPC: ";
            cin.ignore();
            getline(cin, query);
            CD* cd = library.searchCD(query);
            if (cd) {
                cout << "CD found:" << endl;
                cd->printInfo();
            } else {
                cout << "CD not found." << endl;
            }
            cout << endl;
        }
    } while (option != 0);

    cout << "Goodbye!" << endl;
    return 0;
}
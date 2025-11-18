#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "Member.h"
#include "Loan.h"
#include "CD.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Member> members;
    vector<Loan> loans;
    vector<CD> cds;

    Book* findBook(const string& isbn);
    Member* findMember(const string& memberId);
    CD* findCD(const string& upc);
    int countActiveLoansForMember(const string& memberId) const;
    bool isBookAvailable(const string& isbn) const;
    bool isCDAvailable(const string& upc) const;
    Loan* findActiveLoan(const string& memberId, const string& isbn);
    Loan* findActiveCDLoan(const string& memberId, const string& upc);

public:
    void addBook(const Book& book);
    void addMember(const Member& member);
    void addCD(const CD& cd);
    void listBooks() const;
    void listMembers() const;
    void listCDs() const;
    void listLoans(bool onlyActive = false) const;
    bool borrowBook(const string& memberId, const string& isbn, const string& borrowDate);
    bool returnBook(const string& memberId, const string& isbn, const string& returnDate);
    bool borrowCD(const string& memberId, const string& upc, const string& borrowDate);
    bool returnCD(const string& memberId, const string& upc, const string& returnDate);
    void removeBook(const string& isbn);
    void removeMember(const string& memberId);
    void removeCD(const string& upc);
    Book* searchBook(const string& query);
    CD* searchCD(const string& query);
};

#endif // LIBRARY_H
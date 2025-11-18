#include "Library.h"
#include <iostream>

Book* Library::findBook(const string& isbn) {
    for (auto& book : books) {
        if (book.getIsbn() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

Member* Library::findMember(const string& memberId) {
    for (auto& member : members) {
        if (member.getId() == memberId) {
            return &member;
        }
    }
    return nullptr;
}

CD* Library::findCD(const string& upc) {
    for (auto& cd : cds) {
        if (cd.getUpc() == upc) {
            return &cd;
        }
    }
    return nullptr;
}

int Library::countActiveLoansForMember(const string& memberId) const {
    int count = 0;
    for (const auto& loan : loans) {
        if (loan.getMemberId() == memberId && loan.isActive()) {
            count++;
        }
    }
    return count;
}

bool Library::isBookAvailable(const string& isbn) const {
    for (const auto& loan : loans) {
        if (loan.getIsbn() == isbn && loan.isActive()) {
            return false;
        }
    }
    return true;
}

bool Library::isCDAvailable(const string& upc) const {
    for (const auto& loan : loans) {
        if (loan.getIsbn() == upc && loan.isActive()) {
            return false;
        }
    }
    return true;
}

Loan* Library::findActiveLoan(const string& memberId, const string& isbn) {
    for (auto& loan : loans) {
        if (loan.getMemberId() == memberId &&
            loan.getIsbn() == isbn &&
            loan.isActive()) {
            return &loan;
        }
    }
    return nullptr;
}

Loan* Library::findActiveCDLoan(const string& memberId, const string& upc) {
    for (auto& loan : loans) {
        if (loan.getMemberId() == memberId &&
            loan.getIsbn() == upc &&
            loan.isActive()) {
            return &loan;
        }
    }
    return nullptr;
}

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::addMember(const Member& member) {
    members.push_back(member);
}

void Library::addCD(const CD& cd) {
    cds.push_back(cd);
}

void Library::listBooks() const {
    cout << "=== Books in library ===" << endl;
    for (const auto& book : books) {
        book.printInfo();
    }
    cout << endl;
}

void Library::listMembers() const {
    cout << "=== Members ===" << endl;
    for (const auto& member : members) {
        member.printInfo();
    }
    cout << endl;
}

void Library::listCDs() const {
    cout << "=== CDs in library ===" << endl;
    for (const auto& cd : cds) {
        cd.printInfo();
    }
    cout << endl;
}

void Library::listLoans(bool onlyActive) const {
    cout << (onlyActive ? "=== Active loans ===" : "=== All loans ===") << endl;
    for (const auto& loan : loans) {
        if (onlyActive && !loan.isActive()) {
            continue;
        }
        loan.printInfo();
    }
    cout << endl;
}

bool Library::borrowBook(const string& memberId, const string& isbn, const string& borrowDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    Book* book = findBook(isbn);
    if (!book) {
        cout << "Book not found." << endl;
        return false;
    }

    if (!isBookAvailable(isbn)) {
        cout << "Book is currently not available." << endl;
        return false;
    }

    int activeLoans = countActiveLoansForMember(memberId);
    if (activeLoans >= member->getMaxBooks()) {
        cout << "Member has reached the maximum number of active loans." << endl;
        return false;
    }

    loans.push_back(Loan(isbn, memberId, borrowDate));
    cout << "Book borrowed successfully." << endl;
    return true;
}

bool Library::returnBook(const string& memberId, const string& isbn, const string& returnDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    Book* book = findBook(isbn);
    if (!book) {
        cout << "Book not found." << endl;
        return false;
    }

    Loan* loan = findActiveLoan(memberId, isbn);
    if (!loan) {
        cout << "No active loan found for this member and book." << endl;
        return false;
    }

    loan->setReturnDate(returnDate);
    cout << "Book returned successfully." << endl;
    return true;
}

bool Library::borrowCD(const string& memberId, const string& upc, const string& borrowDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    CD* cd = findCD(upc);
    if (!cd) {
        cout << "CD not found." << endl;
        return false;
    }

    if (!isCDAvailable(upc)) {
        cout << "CD is currently not available." << endl;
        return false;
    }

    int activeLoans = countActiveLoansForMember(memberId);
    if (activeLoans >= member->getMaxBooks()) {
        cout << "Member has reached the maximum number of active loans." << endl;
        return false;
    }

    loans.push_back(Loan(upc, memberId, borrowDate));
    cout << "CD borrowed successfully." << endl;
    return true;
}

bool Library::returnCD(const string& memberId, const string& upc, const string& returnDate) {
    Member* member = findMember(memberId);
    if (!member) {
        cout << "Member not found." << endl;
        return false;
    }

    CD* cd = findCD(upc);
    if (!cd) {
        cout << "CD not found." << endl;
        return false;
    }

    Loan* loan = findActiveCDLoan(memberId, upc);
    if (!loan) {
        cout << "No active loan found for this member and CD." << endl;
        return false;
    }

    loan->setReturnDate(returnDate);
    cout << "CD returned successfully." << endl;
    return true;
}

void Library::removeBook(const string& isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getIsbn() == isbn) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Library::removeMember(const string& memberId) {
    for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getId() == memberId) {
            members.erase(it);
            cout << "Member removed successfully." << endl;
            return;
        }
    }
    cout << "Member not found." << endl;
}

void Library::removeCD(const string& upc) {
    for (auto it = cds.begin(); it != cds.end(); ++it) {
        if (it->getUpc() == upc) {
            cds.erase(it);
            cout << "CD removed successfully." << endl;
            return;
        }
    }
    cout << "CD not found." << endl;
}

Book* Library::searchBook(const string& query) {
    for (auto& book : books) {
        if (book.getIsbn() == query) {
            return &book;
        }
    }
    for (auto& book : books) {
        if (book.getTitle() == query) {
            return &book;
        }
    }
    return nullptr;
}

CD* Library::searchCD(const string& query) {
    for (auto& cd : cds) {
        if (cd.getUpc() == query) {
            return &cd;
        }
    }
    for (auto& cd : cds) {
        if (cd.getTitle() == query) {
            return &cd;
        }
    }
    return nullptr;
}
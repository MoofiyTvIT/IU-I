

#include "../std_lib_facilities.h"
#include "BookChrono.h"

#ifndef MYLIB_H
#define MYLIB_H

namespace Mylib {

using Chrono::Date;

class Invalid_ISBN { };  // to throw in case ISBN is not valid

class Book {
public:
    Book(string isbn, string title, string author, Date copyright);

    // modifying function members
    void check_out() { co = true; }
    void check_in() { co = false; }

    // non-modifying function members
    const string& isbn() const { return id; }
    const string& title() const { return tit; }
    const string& author() const { return auth; }
    const Date& copyright() const { return cright; }
    const bool checked_out() const { return co; }
private:
    string id;
    string tit;
    string auth;
    Date cright;
    bool co;
};

// helper functions

bool is_isbn(const string& isbn);
void print(ostream& os, const Book& book);

} // namespace Mylib

#endif

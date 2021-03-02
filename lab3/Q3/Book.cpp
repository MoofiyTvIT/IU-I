
#include "../std_lib_facilities.h"
#include "BookChrono.h"
#include "BookMylib.h"

using Chrono::Date;
using Chrono::Month;
using Mylib::Book;

int main()
try
{
    // Test Mylib::is_isbn() function
    string s{};
    string isbn{};

    isbn = "2342-2342-2344-A";
    s = Mylib::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "04-6502-656-7";
    s = Mylib::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "aoiefoawinefna";
    s = Mylib::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "2342-2342-2344-AAA";
    s = Mylib::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "2342-2342--A";
    s = Mylib::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    isbn = "-2345/234-23-23-2";
    s = Mylib::is_isbn(isbn) ? "" : "not ";
    cout << isbn << " is " << s << "a valid ISBN\n";
    cout << '\n';

    // Test Book class
    Book book{"04-6502-656-7", "Gödel, Escher, Bach: An Eternal Golden Braid",
              "Douglas Richard Hofstadter", Date{1999, Month::feb, 5}};
    Mylib::print(cout, book);
    book = Book{"07-5640-474-6", "The Name of the Wind", "Patrick Rothfuss",
                Date{2008, Month::apr, 1}};
    book.check_out();
    Mylib::print(cout, book);
    book = Book{"16-8050-127-5",
                "Practical Vim: Edit at the Speed of Thought, 2nd Edition",
                "Drew Neil", Date{2015, Month::nov, 7}};
    book.check_out();
    book.check_in();
    Mylib::print(cout, book);
    try {
        book = Book{"???", "Necronomicon", "Abdul Alhazred",
                    Date{768, Month::jan, 1}};
    }
    catch(Mylib::Invalid_ISBN& e) {
        cerr << "Invalid ISBN!\n";
    }

    return 0;
}
catch(Chrono::Date::Invalid& e)
{
    cerr << "Invalid date!\n";
    return 1;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 2;
}
catch(...)
{
    cerr << "Unknown exception!\n";
    return 3;
}


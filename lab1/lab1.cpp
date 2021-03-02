#include <iostream>
#include <vector>
#include "lab1/Lab1.h"


using namespace std;

//int main() {
//
//    while (true)
//    daysConverter();
//    return 0;
//}







void staticLocal() {
    static int i = 0; // local static variable
    i++;
    cout << "i = " << i << endl;
    cout << "i = " << &i << endl;
}

void staticLocal2() {
    static int i = 0; // local static variable
    i++;
    cout << "i = " << i << endl;
    cout << "i = " << &i << endl;
}


void printSize() {
    cout << "Size of int : " << sizeof(int) << " bytes" << endl;
    cout << "Size of short int : " << sizeof(short int) << " bytes" << endl;
    cout << "Size of long int : " << sizeof(long int) << " bytes" << endl;
    cout << "Size of signed long int : " << sizeof(signed long int) << " bytes" << endl;
    cout << "Size of unsigned long int : " << sizeof(unsigned long int) << " bytes" << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" << endl;
    cout << "Size of char : " << sizeof(char) << " byte" << endl;
    cout << "Size of float : " << sizeof(float) << " bytes" << endl;
    cout << "Size of double : " << sizeof(double) << " bytes" << endl;
}

void swapNumbers(int a, int b) {
    cout << "The two numbers  are: " << a << " , " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "\nAfter swapping The numbers are : " << a << " , " << b << endl;
}


void daysConverter() {
    int static days, y, m, d;
    cout << "last time you Converted  " << days << " days to " << endl;
    cout << "Years : " << y << "\nMonths : " << m << "\nDays : " << d << endl;
    cout << "Enter number of days you want to convert : ";
    cin >> days;
    y = days / 365;
    days = days % 365;
    m = days / 30;
    d = days % 30;
    cout << "Years : " << y << "\nMonths : " << m << "\nDays : " << d << endl;
    cout << "______________ " << endl;
}











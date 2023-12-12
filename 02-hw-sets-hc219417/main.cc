/**
 * @file: main.cc
 * @author: Hannah Culver
 * @date: September 18, 2022
 * @brief: main program to test myset class
 */

#include <iostream>
#include "myset.h"

using namespace std;

int main(){

    cout << "************************" << endl;
    cout << "TESTING SET CLASS" << endl;
    cout << "************************" << endl;
       
    cout << "========================" << endl;
    cout << "Default Constructor:" << endl;
    cout << "------------------------" << endl;

    MySet a;
    cout << a.size() << endl; //should be 0
    cout << a.toString() << endl; //should be "{}"

    cout << "========================" << endl;  
    cout << "adding a single element at a time & toString:" << endl;
    cout << "------------------------" << endl;

    MySet b;
    b = b + 10; //add an element to s
    cout << b.size() << endl; //should be 1
    cout << b.toString() << endl; //should be "{10}"

	b = b + 20;
	b = b + 10;
    cout << b.size() << endl; //should be 2
    cout << b.toString() << endl; //should be "{10, 20}"

    b = b + 30;
    b = b + 30;
    b = b + 5;
    cout << b.toString() << endl; //should be "{5, 10, 20, 30}"

    cout << "========================" << endl;
    cout << "removing a single element at a time & toString:" << endl;
    cout << "------------------------" << endl;

    MySet c;
    c = c + 10; //add an element to s
    c = c - 10;
    cout << c.toString() << endl; //should be "{}"

	c = c + 20;
	c = c + 10;
    cout << c.toString() << endl; //should be "{10, 20}"

    c = c + 30;
    c = c + 30;
    c = c + 5;
    cout << c.toString() << endl; //should be "{5, 10, 20, 30}"
    
    c = c - 5; //remove the first element
    c = c - 30; // remove the last element
    cout << c.toString() << endl; //should be "{10, 20}"

    cout << "========================" << endl;
    cout << "Set Membership:" << endl;
    cout << "------------------------" << endl;

    MySet d;
    cout << (10 ^ d) << endl; // false

    d = d + 10;
    cout << (10 ^ d) << endl; // true

    d = d + 20;
    d = d + 30;

    cout << (30 ^ d) << endl; // true
    cout << (40 ^ d) << endl; // false

    cout << "========================" << endl;
    cout << "Set Union:" << endl;
    cout << "------------------------" << endl;

    MySet e;
    e = e + 20;
    e = e + 10;
    e = e + 30;
    e = e + 40;

    MySet e2;
    e2 = e2 + 10;
    e2 = e2 + 50;
    e2 = e2 + 30;
    e2 = e2 + 60;

    MySet e3;
    e3 = e + e2;
    cout << e3.toString() << endl; //should be "{10, 20, 30, 40, 50, 60}"

    cout << "========================" << endl;
    cout << "Set Intersection:" << endl;
    cout << "------------------------" << endl;

    MySet f;
    f = f + 20;
    f = f + 10;
    f = f + 30;
    f = f + 40;

    MySet f2;
    f2 = f2 + 10;
    f2 = f2 + 50;
    f2 = f2 + 30;
    f2 = f2 + 60;

    MySet f3;
    f3 = f * f2;
    cout << f3.toString() << endl; //should be "{10, 30}"
    
    cout << "========================" << endl;
    cout << "Set Difference:" << endl;
    cout << "------------------------" << endl;

    MySet g;
    g = g + 20;
    g = g + 10;
    g = g + 30;
    g = g + 40;

    MySet g2;
    g2 = g2 + 10;
    g2 = g2 + 50;
    g2 = g2 + 30;
    g2 = g2 + 60;

    MySet g3;
    g3 = g - g2;
    cout << g3.toString() << endl; //should be "{20, 40}"
    g3 = g2 - g;
    cout << g3.toString() << endl; //should be "{50, 60}"

    MySet g4;
    g4 = g4 - g;
    cout << g4.toString() << endl; //should be "{}"
    g4 = g - g4;
    cout << g4.toString() << endl; //should be "{10, 20, 30, 40}"

    cout << "========================" << endl;
    cout << "Set Subset:" << endl;
    cout << "------------------------" << endl;

    MySet h;
    h = h + 20;
    h = h + 10;
    h = h + 30;
    h = h + 40;

    MySet h2;
    h2 = h2 + 10;
    h2 = h2 + 40;
    h2 = h2 + 30;
    h2 = h2 + 20;
    h2 = h2 + 50;

    cout << (h <= h2) << endl; // true
    cout << (h2 <= h) << endl; // false

    MySet h3;
    cout << (h3 <= h) << endl; // true
    cout << (h <= h3) << endl; // false

    cout << "========================" << endl;
    cout << "Set Superset:" << endl;
    cout << "------------------------" << endl;

    MySet i;
    i = i + 20;
    i = i + 10;
    i = i + 30;
    i = i + 40;

    MySet i2;
    i2 = i2 + 10;
    i2 = i2 + 40;
    i2 = i2 + 30;
    i2 = i2 + 20;
    i2 = i2 + 50;

    cout << (i2 >= i) << endl; // true
    cout << (i >= i2) << endl; // false

    MySet i3;
    cout << (i >= i3) << endl; // true
    cout << (i3 >= i) << endl; // false

    cout << "========================" << endl;
    cout << "Set Equal:" << endl;
    cout << "------------------------" << endl;

    MySet j;
    j = j + 20;
    j = j + 10;
    j = j + 30;
    j = j + 40;

    MySet j2;
    j2 = j2 + 10;
    j2 = j2 + 40;
    j2 = j2 + 30;
    j2 = j2 + 20;
    j2 = j2 + 50;

    cout << (j2 == j) << endl; // false

    MySet j3;
    j3 = j3 + 10;
    j3 = j3 + 40;
    j3 = j3 + 30;
    j3 = j3 + 20;

    cout << (j >= j3) << endl; // true

    MySet j4;
    cout << (j == j4) << endl; // false
    cout << (j4 == j) << endl; // false

    MySet j5, j6;
    cout << (j5 == j6) << endl; // true

    j5 = j5 + 10;
    j6 = j6 + 10;
    cout << (j5 == j6) << endl; // true

    cout << "========================" << endl;
    cout << "Set Clear:" << endl;
    cout << "------------------------" << endl;

    MySet k;
    k = k + 20;
    k = k + 10;
    k = k + 30;
    k = k + 40;
    cout << k.size() << endl; //should be 4

    k.clear();
    cout << k.size() << endl; //should be 0
    cout << k.toString() << endl; //should be "{}"

    cout << "========================" << endl;

    return 0;
}
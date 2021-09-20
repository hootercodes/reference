/*
Title: test_points2.cc
Purpose: To make sure everything implemeneted in points2.h runs without errors.
Description: Main program with two test functions that test points2.h
Modifications: none
To run:
make clean 
make all 
./test_points2
*/
#include <points2.h>

#include <array>
#include <iostream>
#include <string>
using namespace std;

// Place stand-alone function in unnamed namespace.
namespace {
void TestPart1() {
    Points2<int> a, b;  // Two empty Points2 are created.
    cout << a.size() << " " << b.size() << endl; // yields 0 0.
    const array<int, 2> a_point2{{7, 10}};
    Points2<int> d{a_point2};  // A Points2 containing (7, 10) should be created.
    cout << d;  // Should just print (7, 10).
    cout << "Enter a sequence of points (integer)" << endl;
    a.ReadPoints2(); // User enters a set of points in the form:
                     // 3 7 4 3 2 1 10
                     // 3 specifies number of points. Points are the pairs
                     // (7, 4) (3, 2) and (1, 10).
    cout << "Output1: " << endl;
    cout << a;  // Output should be what user entered.
    cout << "Enter a sequence of points (integer)" << endl;
    b.ReadPoints2();  // Enter another sequence.
    cout << "Output2: " << endl;
    cout << b;
    Points2<int> c{a};  // Calls copy constructor for c.
    cout << "After copy constructor1 c{a}: " << endl;
    cout << c;
    cout << a;
    a = b;  // Should call the copy assignment operator for a.
    cout << "After assignment a = b" << endl;
    cout << a;
    Points2<int> e = move(c);  // Move constructor for d.
    cout << "After e = move(c) " << endl;
    cout << e;
    cout << c; // c is not empty (null) - able to use if necessary but not really needed.
    cout << "After a = move(e) " << endl;
    a = move(e);  // Move assignment operator for a.
    cout << a;
    cout << e; // e is not null unlike when using move-constructor
}

void TestPart2() {
    Points2<double> a, b;
    cout << "Enter a sequence of points (double)" << endl;
    a.ReadPoints2();  // User provides input for Points2 a.
    cout << a;
    cout << "Enter a sequence of points (double)" << endl;
    b.ReadPoints2();  // User provides input for Points2 b.
    cout << b << endl;
    cout << "Result of a + b" << endl;
    cout << a + b << endl;
    Points2<double> d = a + b;
    cout << "Result of d = a + b" << endl;
    cout << d;
    cout << "Second element in a: " << endl;
    cout << a[1][0] << ", " << a[1][1] << endl;  // Should print the 2nd element.
}

}  // namespace

int main(int argc, char **argv) {
  TestPart1();
  TestPart2();
  return 0;
}

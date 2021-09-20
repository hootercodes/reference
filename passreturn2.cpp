#include <iostream>
using namespace std;
class Student {
public:
   int stuId;
   int stuAge;
   string stuName;
   /* In this function we are returning the
    * Student object.
    */
   Student input(int n, int a, string s){
      Student obj;
      obj.stuId = n;
      obj.stuAge = a;
      obj.stuName = s;
      return obj;
   }
   /* In this function we are passing object
    * as an argument.
    */
   void disp(Student obj){
      cout<<"Name: "<<obj.stuName<<endl;
      cout<<"Id: "<<obj.stuId<<endl;
      cout<<"Age: "<<obj.stuAge<<endl;
   }
};
int main() {
   Student s;
   s = s.input(1001, 29, "Negan");
   s.disp(s);
   return 0;
}
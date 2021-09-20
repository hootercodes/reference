#include <iostream>
using namespace std;
class AbstractionExample{
private:
   /* By making these data members private, I have
    * hidden them from outside world.
    * These data members are not accessible outside
    * the class. The only way to set and get their
    * values is through the public functions.
    */
   int num;
   char ch;

public:
   void setMyValues(int n, char c) {
      num = n; ch = c;
   }
   void getMyValues() {
      cout<<"Numbers is: "<<num<< endl;
      cout<<"Char is: "<<ch<<endl;
   }
};
int main(){
   AbstractionExample obj;
   obj.setMyValues(100, 'X');
   obj.getMyValues();
   return 0;
}
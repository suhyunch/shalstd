#include <iostream>
using namespace std;

class Complex{
     int Im;
     int Re;

public:
     Complex(int _Im=0, int _Re=0): Im(_Im), Re(_Re) {}



     Complex operator+(const Complex &y){
          return Complex(Im+y.Im, Re+y.Re);
     }
     void print(){
          if(Im!=0)cout << Im;
          if(Im!=0 && Re!=0) cout<<"+"<<Re<<"i"<<endl;
          else if(Im==0 && Re!=0)cout<<Re<<"i"<<endl;
          if(Im==0 && Re==0) cout << Im<<endl;
          return;
     }
};
int main(){
     Complex a;
     a.print();
     Complex b(0,2);
     b.print();
     Complex c(1,2);
     c.print();
     Complex d(1,0);
     d.print();
     return 0;
}

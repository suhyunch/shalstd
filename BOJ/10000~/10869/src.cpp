//https://www.acmicpc.net/problem/10869
#include <iostream>
using namespace std;

class oper{
    int a, b;

    public :
    void input(){
        cin >> a >> b;
    }
    void operation(){
        cout<< a+b << endl;
        cout << a-b << endl;
        cout << a*b << endl;
        cout << a/b << endl;
        cout << a%b << endl;
    }

};
int main(){
    oper AB;
    AB.input();
    AB.operation();
}

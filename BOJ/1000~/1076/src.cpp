//https://www.acmicpc.net/problem/1076
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct res{
     string color;
     int value;
     long long int digit;
};

res table[10];

void maketable(){
     table[0].color="black";  table[0].value=0;   table[0].digit=1;
     table[1].color="brown";  table[1].value=1;   table[1].digit=10;
     table[2].color="red";    table[2].value=2;   table[2].digit=100;
     table[3].color="orange"; table[3].value=3;   table[3].digit=1000;
     table[4].color="yellow"; table[4].value=4;   table[4].digit=10000;
     table[5].color="green";  table[5].value=5;   table[5].digit=100000;
     table[6].color="blue";   table[6].value=6;   table[6].digit=1000000;
     table[7].color="violet"; table[7].value=7;   table[7].digit=10000000;
     table[8].color="grey";   table[8].value=8;   table[8].digit=100000000;
     table[9].color="white";  table[9].value=9;   table[9].digit=1000000000;
     return;
}

int main(){
     maketable();
     string color;
     long long int ans=0;
     cin >> color;
     for(int i=0; i<10; i++){
           if(table[i].color==color) {
                ans=table[i].value;
                break;
           }
     }
     ans*=10;
     cin >> color;
     for(int i=0; i<10; i++){
           if(table[i].color==color) {
                ans+=table[i].value;
                break;
           }
     }
     cin >> color;
     for(int i=0; i<10; i++){
           if(table[i].color==color) {
                ans*=table[i].digit;
                break;
           }
     }
     cout << ans;
     return 0;
}

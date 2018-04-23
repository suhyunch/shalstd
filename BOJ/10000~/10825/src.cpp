//https://www.acmicpc.net/problem/10825
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

struct stu{
public:
     string name;
     int kor;
     int eng;
     int math;
};

bool cmp(stu a, stu b){
     if(a.kor>b.kor) return true;
     if(a.kor==b.kor){
          if(a.eng < b.eng) return true;
          if(a.eng==b.eng){
               if(a.math>b.math) return true;
               if(a.math==b.math) {
                    if(a.name.compare(b.name)<0) return true;
               }
          }
     }
     return false;
}

int main(){
     int n;
     scanf("%d",&n);
     vector<stu> v;
     for(int i=0; i<n; i++){
          stu a;
          cin >> a.name;
          scanf("%d %d %d", &a.kor, &a.eng, &a.math);
          v.push_back(a);
     }
     sort(v.begin(), v.end(), cmp);

     for(int i=0; i<n; i++) cout << v[i].name <<"\n";
     return 0;
}

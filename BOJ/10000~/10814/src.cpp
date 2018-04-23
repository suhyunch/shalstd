//https://www.acmicpc.net/problem/10814
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct cus{
     int age;
     int idx;
     char *name[20];
};

bool cmp(cus a, cus b){
     if(a.age < b.age) return true;
     if(a.age==b.age){
          return a.idx<b.idx;
     }
     return false;
}

int main(){
     int n;
     scanf("%d",&n);

     vector<cus> v;
     for(int i=0; i<n; i++){
          cus c;
          scanf("%d %s", &c.age, c.name);
          c.idx=i;
          v.push_back(c);
     }
     sort(v.begin(), v.end(), cmp);

     for(int i=0; i<n; i++){
          printf("%d %s\n",v[i].age, v[i].name);
     }

     return 0;
}

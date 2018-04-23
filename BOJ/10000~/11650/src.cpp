//https://www.acmicpc.net/problem/11650
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct xy{
     int x;
     int y;
};

bool cmp(xy a, xy b){
     if(a.x < b.x) return true;
     else if(a.x==b.x) return a.y<b.y;
     else return false;
}
int main(){
     int n;
     scanf("%d",&n);

     vector<xy> v;
     for(int i=0; i<n; i++){
          xy a;
          scanf("%d %d",&a.x, &a.y);
          v.push_back(a);
     }
     sort(v.begin(), v.end(), cmp);

     for(int i=0; i<n; i++){
          printf("%d %d\n", v[i].x, v[i].y);
     }
     return 0;
}

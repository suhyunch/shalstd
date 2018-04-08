//https://www.acmicpc.net/problem/1546
#include <iostream>
#include <vector>
using namespace std;

int main(){
     vector<float> score;

     int N;
     cin >> N;
     int mx=0;

     for(int i=0; i<N; i++){
          int tmp;
          cin >> tmp;
          mx=mx<tmp? tmp : mx;
          score.push_back(tmp);
     }

     float sum=0;
     for(int i=0; i<N; i++){
          score[i]=score[i]*100/mx;
          sum+=score[i];
     }
     cout<<fixed;
     cout.precision(2);
     cout << sum/N;
}

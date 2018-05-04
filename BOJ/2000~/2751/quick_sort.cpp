//https://www.acmicpc.net/problem/2751
#include <iostream>
using namespace std;

int arr[1000001];
int n;
void swap(int a, int b){
     int tmp=arr[a];
     arr[a]=arr[b];
     arr[b]=tmp;
     return;
}
int partition(int low, int high){
     int pivotidx=low+(high-low)/2;
     int pivotval=arr[pivotidx];
     swap(pivotidx, high);//pivot을 오른쪽으로 보내줌
     int stridx=low;
     for(int i=low; i<high; i++){
          if(arr[i]<pivotval){
               swap(i, stridx);
               stridx+=1;
          }
     }
     swap(stridx, high);
     return stridx;
}
void quick_sort(int low,int high){
     if(low<high){
          int pivot=partition(low, high);
          quick_sort(low, pivot-1);
          quick_sort(pivot+1, high);
     }
     return;
}
int main(){
     //int n;
     /*첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
      둘째 줄부터 N개의 줄에는 숫자가 주어진다.
       이 수는 절대값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.*/
     cin >>n;

     for(int i=0; i<n; i++)
          cin >> arr[i];

     quick_sort(0,n-1);

     for(int i=0; i<n; i++){
          cout << arr[i]<<'\n';
     }
     return 0;
}

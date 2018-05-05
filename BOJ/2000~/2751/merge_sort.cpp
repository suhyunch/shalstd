//https://www.acmicpc.net/problem/2751
#include <iostream>
using namespace std;

int arr[1000001];
int n;

void partition(int left, int right){
     if(left==right) return;
     else if(left+1==right){
          //한 칸 차이 일 때,  정렬
          if(arr[left]>arr[right]){
               int tmp=arr[left];
               arr[left]=arr[right];
               arr[right]=tmp;
          }
          return;
     }
     int mid=(left+right)/2;
     partition(left, mid);
     partition(mid+1, right);
     //분할
     int *sortedarr = new int[right-left+1];
     //자료형 *(배열 이름) = new 자료형[size];

     int leftidx=left;
     int rightidx=mid+1;
     int sortedidx=0;

     while(leftidx<=mid && rightidx<=right){
          if(arr[leftidx]<arr[rightidx]){
               sortedarr[sortedidx++]=arr[leftidx++];
          }
          else{
               sortedarr[sortedidx++]=arr[rightidx++];
          }
     }
     while(leftidx<=mid){
          sortedarr[sortedidx++]=arr[leftidx++];
     }
     while(rightidx<=right){
          sortedarr[sortedidx++]=arr[rightidx++];
     }

     for(int i=left; i<=right;i++){
          arr[i]=sortedarr[i-left];
     }
     delete[] sortedarr;

     return;
}
int main(){
     cin >> n;

     if(n==1) {
          int a;
          cin >> a;
          cout << a;
          return 0;
     }
     else {
          for(int i=0; i<n; i++) cin>> arr[i];
          partition(0, n-1);
     }

     for(int i=0; i<n; i++){
          cout << arr[i] <<'\n';
     }
     return 0;
}

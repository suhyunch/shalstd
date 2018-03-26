/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

int num[12];
int op[4]; // +, -, *, /
int mn, mx;
int N;
void solve(int depth, int res);
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

          cin >> N;

          for(int i=0; i<4; i++) cin >> op[i];
          for(int i=0; i<N; i++) cin >> num[i];

          mn= 100000000 ;
          mx=-100000000;
          solve(0, num[0]);

          cout << mx << " " << mn << endl;
          cout << "#" << test_case << " " << mx-mn <<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void solve(int depth, int res){
     if(depth==N-1){
          if(res<mn) mn=res;
          if(res>mx) mx=res;
          cout << res << endl;
          return;
     }

     for(int i=0; i<4; i++){
          if(op[i]>0){
               op[i]--;
               int tmp;
               if(i==0) tmp=res+num[depth+1];
               if(i==1) tmp=res-num[depth+1];
               if(i==2) tmp=res*num[depth+1];
               if(i==3) tmp=res/num[depth+1];
               solve(depth+1, tmp);
               op[i]++;
          }
     }
}

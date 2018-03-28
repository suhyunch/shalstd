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

int K;
bool magnet[4][8];
int idx[4];
void input();
void solve();

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
          for(int i=0; i<4; i++) idx[i]=0;
		input();
          //하나의 자석이 1 칸 회전될 때, 붙어 있는 자석은
          //서로 붙어 있는 날의 자성과 다를 경우에만 인력에 의해 반대 방향으로 1 칸 회전된다.
          solve();
          int score=0;

          if(magnet[0][idx[0]]) score+=1;
          if(magnet[1][idx[1]]) score+=2;
          if(magnet[2][idx[2]]) score+=4;
          if(magnet[3][idx[3]]) score+=8;
          cout << "#" << test_case << " " << score << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void input(){
     cin >> K;

     for(int i=0; i<4; i++){
          for(int j=0 ;j<8; j++){
              cin >> magnet[i][j];
          }
     }
     return;
}

void solve(){

     while(K-->0){
          int dir, sel;
          int idx_tmp[4];
          cin >> sel >> dir;
          //dir 1은 시계, -1은 반시계
          int dir_tmp=dir;
          //선택한 자석의 오른쪽 회전
          bool chk=0;
          if(dir==1)
               idx_tmp[sel-1]= idx[sel-1]==0 ? 7 : idx[sel-1]-1;
          else
               idx_tmp[sel-1]= idx[sel-1]==7 ? 0 : idx[sel-1]+1;
          for(int i=sel-1; i<3; i++){
               if(chk){
                    idx_tmp[i+1]=idx[i+1];
                    continue;
               }
               //magnet[i][2]와 magnet[i+1][6]확인
               int l=idx[i]+2 > 7 ?  idx[i]-6: idx[i]+2;
               int r=idx[i+1]+6 > 7 ?  idx[i+1]-2: idx[i+1]+6;
               if(magnet[i][l]!=magnet[i+1][r]){
                    if(dir_tmp==-1) {
                         dir_tmp=1;
                         idx_tmp[i+1]= idx[i+1]==0 ? 7 : idx[i+1]-1;
                    }
                    else {
                         dir_tmp=-1;
                         idx_tmp[i+1]= idx[i+1]==7 ? 0 : idx[i+1]+1;
                    }
               }
               else {
                    chk=1;
                    idx_tmp[i+1]=idx[i+1];
               }
          }
          //선택한 자석의 왼쪽 회전
          dir_tmp=dir;
          chk=0;
          for(int i=sel-1; i>0; i--){
               if(chk){
                    idx_tmp[i-1]=idx[i-1];
                    continue;
               }
               //magnet[i][6]와 magnet[i-1][2]확인
               int l=idx[i-1]+2 > 7 ?  idx[i-1]-6: idx[i-1]+2;
               int r=idx[i]+6 > 7 ?  idx[i]-2: idx[i]+6;
               if(magnet[i-1][l]!=magnet[i][r]){
                    if(dir_tmp==-1) {
                         dir_tmp=1;
                         idx_tmp[i-1]= idx[i-1]==0 ? 7 : idx[i-1]-1;
                    }
                    else {
                         dir_tmp=-1;
                         idx_tmp[i-1]= idx[i-1]==7 ? 0 : idx[i-1]+1;
                    }
               }
               else {
                    chk=1;
                    idx_tmp[i-1]=idx[i-1];
               }
          }
          for(int i=0; i<4; i++){
               idx[i]=idx_tmp[i];
          }
     }
     return;
}

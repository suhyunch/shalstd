#include<iostream>
using namespace std;
//–2,147,483,648 ~ 2,147,483,647 int 범위

int num[1000010];
int N, P;
int cnt;

void dfs(int now, int depth, long long int sum){
     if(sum/depth >= P) cnt++;
     if(now+1<N && now+1>0) dfs(now+1, depth+1, sum+num[now+1]);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
          cnt=0;
          cin >> N >> P;
          for(int i=0; i<N; i++) cin >> num[i];

          for(int i=0; i<N; i++) dfs(i, 1, num[i]);

          cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

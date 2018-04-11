#include<iostream>

using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
			long long int N;
        	cin>> N;

        	long long int S1, S2, S3;

        	S1=N*(N+1)/2;
        	S2=N*N;
        	S3=S2+N;

        	cout << "#"<<test_case <<" " <<S1 <<  " " <<S2 << " " <<S3 <<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

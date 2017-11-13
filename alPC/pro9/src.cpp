#include <cstdio>
using namespace std;

int abs(int a, int b) { return (a-b)>(b-a)? (a-b):(b-a); }
bool chk[3000];

int main()
{
	int n;
	char line[3001];
	while (scanf("%d", &n)==1)
	{
		bool jolly=1;
		for(int i=0; i<=n; i++) chk[i]=0;
		int x1, x2,diff;
		scanf("%d", &x1);
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &x2);
			diff=abs(x1,x2);
			if(chk[diff]||diff<=0||diff>=n) { jolly=0;break;}
			chk[diff]=1;
			x1=x2;
		}

		gets(line);
		puts(jolly? "Jolly" : "Not jolly");
	}
}

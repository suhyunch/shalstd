#include <iostream>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        int N;
        cin >> N;
        char farm[49];
        int sum=0;
        int cnt=0;

        for(int j=0; j<N/2;j++)
        {
            cin >> farm;
            for(int k=0; k<N; k++)
               if(k>=(N/2-j) && k<=(N/2+j))
                    sum +=(farm[k]-'0');
        }
        for(int j=N/2; j<N;j++)
        {
            cin >> farm;
            for(int k=cnt; k<N-cnt; k++)
                    sum +=(farm[k]-'0');
            cnt++;
        }

        cout << "#" << i << " " << sum << endl;
    }
   // system("pause");
}

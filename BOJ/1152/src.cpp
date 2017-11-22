#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str, '\n');
    int l=str.size();
    int cnt=0;
    int cnt_w=0;
    bool chk=0;
    for(int i=0; i<l; i++)
    {
        if(str[i] !=' ' && !chk)
        {
          cnt++;
          chk=1;
        }
        else if(str[i]==' ')
        {
          chk=0;
        }

    }
    cout << cnt;
}

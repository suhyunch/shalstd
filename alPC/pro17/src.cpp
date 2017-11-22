#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const  char * lines [4] ={"`1234567890-=`","QWERTYUIOP[]\\","ASDFGHJKL;","ZXCVBNM,./"};
int main()
{

  string str;
  bool cnt=0;
  while (1)
  {
    getline(cin, str, '\n');
    fflush(stdin);
    if(str.empty()){ return 0;}

    int l=str.size();
    for(int i=0; i<l; i++)
    {
      bool decode=0;
      for(int j=0; j<4; j++)
        {
          if(strchr(lines[j],str[i]))
            { cout << * (strrchr(lines[j],str[i])-1); decode=1;}
        }
        if (!decode) printf(" ");
      }
      cout << endl;
  }
}

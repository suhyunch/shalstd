#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  for(int T=1; T<=10; T++)
  {
    int N;
    cin >> N;

    stack<char> s;
    string str;
    cin >> str;
    for(int i=0; i<N; i++)
    {
      if(str[i]=='(' || str[i]=='[' || str[i]=='{' || str[i]=='<') s.push(str[i]);
      else if(s.top() == '(' && str[i] == ')') s.pop();
      else if(s.top() == '[' && str[i] == ']') s.pop();
      else if(s.top() == '{' && str[i] == '}') s.pop();
      else if(s.top() == '<' && str[i] == '>') s.pop();
	  else s.push(str[i]);
    }

    if(s.empty()) cout << "#" << T << " 1\n";
    else cout << "#" << T << " 0\n";
  }
}

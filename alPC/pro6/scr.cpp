#include <iostream>
#include <string>
using namespace std;
long reg[10];//10개의 레지스터
long ram[1000]; //1000워드 분량의 램..
int pc;//program counter


int main()
{
  int tc;
  cin >> tc;

  for(int i=1; i<=tc; i++)
  {
    int addr=0;
    /*ram reg initialize*/
    for(; addr<1000; addr++) ram[addr]=0;
    for(int i=0; i<10; i++) reg[i]=0;
    cout << "init " << endl;
    char line[4];
    gets(line);
    gets(line);
    /*    cin >> order;
    string ord=order;
    int length=ord.size();
    if(length!=3) break; //입력된 값이 3자리 정수가 아니면 == \n 개행
    else
    {
      encoding(order);
    }*/
    cout << "before IS" << endl;
       /*ram에 instruction set 저장*/
    addr=0;
    while(!ram[addr]) { cin >> ram[addr]; cout << addr <<"   : " << ram[addr] <<endl; addr++;}
    int result=0;
    pc=0;
    int done=0;
    while(!done)
    {

      int fst=ram[pc]/100;
      int snd=(ram[pc]/10)%10;
      int trd=ram[pc]%10;

      cout << fst << " " << snd << " " <<trd <<endl;
      pc++;
      result++;
      if(fst==1) done=1;
      else if(fst==2) { reg[snd]=trd;
        cout <<  "reg[" << snd << "]  : " << reg[snd] << endl;}
      else if(fst==3) reg[snd]+=trd;
      else if(fst==4) reg[snd]*=trd;
      else if(fst==5) reg[snd]=reg[trd];
      else if(fst==6) reg[snd]+=reg[trd];
      else if(fst==7) reg[snd]*=reg[trd];
      else if(fst==8) reg[snd]=ram[reg[trd]];
      else if(fst==9) ram[reg[trd]]=reg[snd];
      else
        if(reg[trd]!=0) pc = reg[snd];
    }

    if (tc>1) putchar('\n');
    cout << result << endl;
  }
}

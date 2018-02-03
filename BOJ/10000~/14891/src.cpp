//https://www.acmicpc.net/problem/14891
#include <iostream>
using namespace std;

int main()
{
  char gear_input[4][8];
  bool gear[4][8];

  for(int i=0; i<4; i++) cin >> gear_input[i];

  for(int i=0; i<4; i++) for(int j=0; j<8; j++) gear[i][j]=gear_input[i][j]-'0';
  int K;
  cin >> K;
 while(K-->0)
  {
    int rot_gear, dir;
    cin >> rot_gear >> dir;
    bool rot_chk[4][2];
    for(int i=0; i<4; i++) rot_chk[i][0]=rot_chk[i][1]=0;

    rot_chk[rot_gear-1][0]=1;
    if(dir==-1) rot_chk[rot_gear-1][1]=0;
    else  rot_chk[rot_gear-1][1]=1;
    //rot_chk[기어][0]=회전하는지 안하는지
    //rot_chk[기어][1]=회전방향 1:시계, 0:반시계

    for(int i=rot_gear-1; i<4; i++) // 선택 기어의 오른쪽 기어
    {
        if (gear[i][2]==gear[i+1][6])
        break;
      else
      {
        rot_chk[i+1][0]=1;
        if(rot_chk[i][1]==1)  rot_chk[i+1][1]=0;
        else rot_chk[i+1][1]=1;
      }
    }


    for(int i=rot_gear-1; i>=0; i--) // 선택 기어의 왼쪽 기어 제어
      if (gear[i][6]==gear[i-1][2])
        break;
      else
      {
        rot_chk[i-1][0]=1;
        if(rot_chk[i][1]==1)  rot_chk[i-1][1]=0;
        else rot_chk[i-1][1]=1;
      }
     for(int i=0; i<4; i++)
     {
       if(rot_chk[i][0])
       {
         if(rot_chk[i][1])//시계 방향 회전
         {
           int tmp=gear[i][7];
           for(int j=6; j>=0; j--)
             gear[i][j+1]=gear[i][j];
           gear[i][0]=tmp;
         }

         else // 반시계 방향 회전
         {
           int tmp=gear[i][0];
           for(int j=1; j<=7; j++)
             gear[i][j-1]=gear[i][j];
           gear[i][7]=tmp;
         }
       }
     }
  }

  int score=0;
  if(gear[0][0]) score +=1;
  if(gear[1][0]) score +=2;
  if(gear[2][0]) score +=4;
  if(gear[3][0]) score +=8;

   cout << score;
}

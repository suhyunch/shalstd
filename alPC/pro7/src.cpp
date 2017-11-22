#include <iostream>
using namespace std;
char map[8][8];

int main()
{
  while(1)
  {
    char whitek_x, whitek_y, black_x, black_y;
    bool chkW=0;
    bool chkB=0;
    int cnt=0;
    for(int i=0; i<8; i++)
     {
       cin >> map[i];
       for(int j=0; j<8; j++)
       {
         if(map[i][j]=='.') cnt++;
         if(map[i][j]=='K') { white_y=i; white_x=j;}
         if(map[i][j]=='k') { black_y=i; black_x=j;}
       }
     }

    if(cnt==64) return 0;

    /*white check*/
    {
      for(int i=0; i<8; i++)
        for(int j=0; j<8; j++)
        {
          /*pawn*/
          if(map[i][j]=='p')
            if(map[i+1][j-1]== 'K' || map[i+1][j+1] == 'K') chkW=1; break;

          /*rook*/
          if(map[i][j]=='r')
          {
            /*up*/
            for(int k=0; k<=i; k++)
            {
              if(map[i-k][j]!='.' && map[i-k][j]!='K') break;
              else if (map[i-k][j]=='K') chkW=1; break;
            }

            /*down*/
            for(int k=0; i+k<=7; k++)
            {
              if(map[i+k][j]!='.' && map[i+k][j]!='K') break;
              else if (map[i+k][j]=='K') chkW=1; break;
            }

            /*left*/
            for(int k=0; k<=j; k++)
            {
              if(map[i][j-k]!='.' && map[i][j-k]!='K') break;
              else if (map[i][j-k]=='K') chkW=1; break;
            }

            /*right*/
            for(int k=0; j+k<=7; k++)
            {
              if(map[i][j+k]!='.' && map[i][j+k]!='K') break;
              else if (map[i][j+k]=='K') chkW=1; break;
            }
          }




            if(map[i+1][j-1]== 'K' || map[i+1][j+1] == 'K') chkW=1; break;
        }
    }



  }
}

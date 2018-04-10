#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(int y, int x, vector<vector<int> > picture);
int visited[100][100];
int dy[4]={0, 0, 1, -1};
int dx[4]={1, -1, 0, 0};
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int> > picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            visited[i][j]=0;
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j]!=0 && visited[i][j]==0){
                int tmp=bfs(i,j, picture);
                if(max_size_of_one_area<tmp)
                    max_size_of_one_area=tmp;
                number_of_area++;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int bfs(int y, int x, vector<vector<int> > picture){
    int mx=0;
    queue<pair<int, int> > v;
    v.push(make_pair(y, x));

    while(!v.empty()){
        int nowy=v.front().first;
        int nowx=v.front().second;
        v.pop();

        for(int i=0; i<4; i++){
            int ny= y+dy[i];
            int nx= x+dx[i];

            if(picture[ny][nx]==picture[y][x] && !visited[ny][nx]){
                visited[ny][nx]=visited[y][x]+1;
                v.push(make_pair(ny, nx));

                if(mx<visited[ny][nx])
                    mx=visited[ny][nx];
            }
        }
    }
    return mx;
}
int main(){
     int m, n;
     cin >> m >> n;

     vector<pair<int, int> > picture;
     for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
               int now;
               cin >> now;
               picture[i].push_back(now);
          }
     }
}

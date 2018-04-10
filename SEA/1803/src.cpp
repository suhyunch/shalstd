#include <iostream>
using namespace std;
int graph[100001][100001];
int visited[100001];
int N, M, S, E;
long long int mn=100001;

void dfs(int tmp,long long int cost){
    if(tmp==E) {
        if(visited[E]<mn) mn=cost;
    }

    for(int i=1; i<N; i++){
        if( graph[tmp][i]!=0 && !visited[i] ) {
            visited[i]=cost+graph[tmp][i];
            dfs(i, visited[i]);
            visited[i]=0;
    	}
    }
}


int main(){
    int t;
    cin >>t;

    for(int TC=1; TC<=t; TC++){

        cin >> N >> M >> S >> E;

        while(M-->0){
            int a, b, c;
            cin >> a >> b >> c;

            if(graph[a][b]==0) graph[a][b]=graph[b][a]=c;
            else if(graph[a][b]>c) graph[a][b]=graph[b][a]=c;
        }
       mn=100000001;
        dfs(S, 0);
        cout << "#"<< TC <<" " << visited[E]<<endl;
    }
}

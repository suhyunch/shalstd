#include <bits/stdc++.h>
#define ll long long
#define N 10
using namespace std;
int n,m;
struct cells{

    int rs, cs;

    int re, ce;
    cells(int rs, int cs, int re, int ce) :
        rs(rs), cs(cs), re(re), ce(ce) { }

    bool operator <(const cells& other) const
    {
        return ((rs != other.rs) || (cs != other.cs) ||
               (re != other.re) || (ce != other.ce));
    }
};

int find(char mat[][N], int rs, int cs, int re, int ce, map<cells, int>& memo){
    int R = n, C = m;
    if (rs < 0 || rs >= R || cs < 0 || cs >= C)
        return 0;
    if (re < 0 || re < rs || ce < 0 || ce < cs)
        return 0;

    if (mat[rs][cs] != mat[re][ce])
        return 0;

    if (abs((rs - re) + (cs - ce)) <= 1)
        return 1;

    if (memo.find(cells(rs, cs, re, ce)) != memo.end())
        return memo[cells(rs, cs, re, ce)];
 
    int ret = 0;

    ret += find(mat, rs + 1, cs, re - 1, ce, memo);
    ret += find(mat, rs + 1, cs, re, ce - 1, memo);
    ret += find(mat, rs, cs + 1, re - 1, ce, memo);
    ret += find(mat, rs, cs + 1, re, ce - 1, memo);

    memo[cells(rs, cs, re, ce)] = ret;

    return ret;
}

int solve(char mat[][N], int n, int m){
    map<cells, int> memo;
    return find(mat, 0, 0, n - 1, m - 1, memo);
}

int main(){
	int t; cin>>t;

	while(t--){

        cin>>n>>m;
        char A[n][N];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>A[i][j];
            }
        }
        cout << solve(A,n,m) << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;

class cus {
public:
	int icus, idx, t;
	cus(){}
	cus(int icus, int t) {
		this->icus = icus;
		this->t = t;
	}
	cus(int idx, int t, int icus) {
		this->idx = idx;
		this->t = t;
		this->icus = icus;
	}
} rec[10], rep[10], recq[1001], repq[1001];

int N, M, K, A, B;
int a[10];
int b[10];
void input();
int solve();
int main() {
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		input();

		for (int i = 1; i <= K; i++) cout << recq[i].icus << "\t" << recq[i].t << endl;
		int ans = solve();
		cout << "#" << T << " ";
		if (ans == 0) cout << "-1" << endl;
		else cout << ans << endl;
	}
	return 0;

}

void input() {
	cin >> N >> M >> K >> A >> B;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 1; i <= M; i++) cin >> b[i];
	for (int i = 1; i <= K; i++) {
		int t;
		cin >> t;
		recq[i] = cus(i,t);
	}
	return;
}

int solve() {
	int ans = 0;
	int idx_c = 1;
	int idx_p = 0;
	int idx_w = 0;
	for (int t = recq[1].t, cnt = 1; cnt <= K; t++) {
		//접수 큐
		for (int i = 1; i <= N; i++) {
			if (rec[i].t > 0) {
				rec[i].t--;
				if (rec[i].t == 0) {//i창구의 접수 처리가 끝나면, repq(대기큐)로 옮김
					repq[idx_w++] = cus(i,t,rec[i].icus);
					cout << "move :: "<<repq[idx_w - 1].idx << "\t" << repq[idx_w - 1].t << "\t" << repq[idx_w - 1].icus << endl;
					//동시에 끝나도 창구 번호가 적은 순으로 대기큐로 들어감
					//i는 이용한 접수 창구 인덱스, t는 끝난 시간, icus는 이용한 손님 idx
				}
			}
			if (rec[i].t == 0) {
				if (recq[idx_c].t < t && idx_c <= K) {
					//recq[idx_c].t < t 현재 시간보다 먼저 도착한 손님
					//idx_c <= K 대기큐에 손님 존재하면
					rec[i] = cus(recq[idx_c++].icus, a[i]);
					cout << "in :: " << recq[idx_c-1].icus << "\t" << a[i] << endl;
				}
			}
		}

		//정비 큐
		for (int i = 1; i <= M; i++) {
			if (rep[i].t > 0) {
				rep[i].t--;
				if (rep[i].t == 0) //i창구의 정비 처리가 끝나면, cnt확인
					cnt++;
			}
			if (rep[i].t == 0) {
				//i창구가 이용 가능한 상태일때,
				if (idx_p < idx_w) {
					rep[i]= { repq[idx_p].idx, b[i]};
					if (repq[idx_p].idx == A && i == B) {
						ans += repq[idx_p].icus;
						cout << repq[idx_p].icus << endl;
					}
					idx_p++;
				}
			}
		}
	}
	//if (ans == 0) cout << "-1" << endl;
	//else cout << ans << endl;
	return ans;
}
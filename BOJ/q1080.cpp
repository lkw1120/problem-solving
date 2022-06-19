#include<bits/stdc++.h>
#define MAX 51
using namespace std;
string input[MAX];
string output[MAX];
bool dp[MAX][MAX] = {false};
int N,M,ans;
void flip(int a, int b) {
	for(int i=a-1;i<=a+1;i++) {
		for(int j=b-1;j<=b+1;j++) {
			dp[i][j] = !dp[i][j];
		}
	}
}
int solve() {
	int cnt = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			dp[i][j] = (input[i][j] == '1');
		}
	}
	for(int i=1;i<N-1;i++) {
		for(int j=1;j<M-1;j++) {
			if(dp[i-1][j-1] == (output[i-1][j-1] == '0')) {
				flip(i,j);
				cnt++;
			}
		}
	}
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(dp[i][j] != (output[i][j] == '1')) {
				cnt = -1;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>input[i];
	}
	for(int i=0;i<N;i++) {
		cin>>output[i];
	}
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(input[i][j] != output[i][j]) ans = -1;
		}
	}
	if(N >= 3 && M >= 3 && ans < 0) {
		ans = solve();
	}
	cout<<ans<<"\n";
	return 0;
}
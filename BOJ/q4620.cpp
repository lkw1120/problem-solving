#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll arr[35][35] = {0};
ll dp[35][35] = {0};
ll N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true) {
		cin>>N;
		if(N < 0) break;
		fill(&arr[0][0],&arr[34][35],0);
		fill(&dp[0][0],&dp[34][35],0);
		for(int i=0;i<N;i++) {
			string str;
			cin>>str;
			for(int j=0;j<N;j++) {
				arr[i][j] = str[j]-'0';	
			}
		}
		ans = 0;
		dp[0][0]= 1;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if((i != N-1 || j != N-1) && dp[i][j]) {
					int dx = i+arr[i][j];
					int dy = j+arr[i][j];
					if(dx < N) {
						dp[dx][j]+=dp[i][j];
					}
					if(dy < N) {
						dp[i][dy]+=dp[i][j];
					}
				}
			}
		}
		ans = dp[N-1][N-1];
		cout<<ans<<"\n";
	}
	return 0;
}
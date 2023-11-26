#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int MAX = 10001;
vector<int> v;
int arr[MAX];
int dp[MAX];
int T,X,N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>X>>N;
		for(int i=1;i<=N;i++) {
			cin>>arr[i];
		}
		fill(dp,dp+MAX,INF);
		dp[0] = 0;
		for(int i=1;i<=N;i++) {
			for(int j=MAX-1;j>=0;j--) {
				if(INF != dp[j] && j+arr[i] < MAX) {
					dp[j+arr[i]] = min(dp[j+arr[i]],dp[j]+1);
				}
			}
		}
		for(int i=X;i<MAX;i++) {
			if(INF != dp[i]) {
				cout<<i<<" "<<dp[i]<<"\n";	
				break;
			}
		}
	}
	return 0;
}
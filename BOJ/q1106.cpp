#include<bits/stdc++.h>
#define INF 999999
#define MAX 100001
using namespace std;
int dp[MAX] = {0};
vector<pair<int,int>> v;
int C,N,A,B,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>C>>N;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	ans = INF;
	for(auto cost: v) {
		dp[cost.first] = cost.second;
		for(int i=1;i<MAX;i++) {
			if(i >= cost.first) {
				dp[i] = max(dp[i],dp[i-cost.first]+cost.second);
			}
			if(dp[i] >= C) {
				ans = min(ans,i);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
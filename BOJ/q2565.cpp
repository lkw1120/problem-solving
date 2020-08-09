#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;
vector<pair<int,int>> v;
int dp[MAX];
int N,a,b,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(dp,dp+MAX,1);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++) {	
		for (int j=0;j<i;j++) {
			if (v[i].second > v[j].second) {
                dp[i] = max(dp[i],dp[j]+1);
			}
		}
	}
	ans = N-*max_element(dp,dp+N);
	cout<<ans<<"\n";
	return 0;
}
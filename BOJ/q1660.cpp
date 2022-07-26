#include<bits/stdc++.h>
#define MAX 300001
using namespace std;
vector<int> v;
int dp[MAX] = {0};
int N,cnt,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i*(i+1)*(i+2)/6<MAX;i++) {
		v.push_back(i*(i+1)*(i+2)/6);
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		dp[i] = i;
		for(auto item: v) {
			if(i-item >= 0) {
				dp[i] = min(dp[i],dp[i-item]+1);
			}
		}
	}
	ans = dp[N];
	cout<<ans<<"\n";
	return 0;	
}
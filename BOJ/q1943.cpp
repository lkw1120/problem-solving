#include<bits/stdc++.h>
using namespace std;
int N,A,B,ans;
bool solve() {
	vector<pair<int,int>> v;
	int dp[50001] = {0};
	int sum = 0;
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
		sum+=(A*B);
	}
	if(sum%2) return false;	
	int mid = sum/2;
	for(auto item: v) {
		A = item.first;
		B = item.second;
		for(int i=mid;i>=0;i--) {
			if(dp[i] || i == 0) {
				for(int j=1;j<=B;j++) {
					if(mid < i+A*j) break;
					dp[i+A*j]++;
				}
			}
		}
	}
	return dp[sum/2];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int t=0;t<3;t++) {
		ans = solve()? 1:0;	
		cout<<ans<<"\n";
	}
	
	return 0;
}
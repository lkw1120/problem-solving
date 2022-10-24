#include<bits/stdc++.h>
#define MAX 101
using namespace std;
int dp[MAX] = {0};
vector<string> v;
string S;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>S;
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	dp[0] = 1;
	for(int i=1;i<=S.size();i++) {
		if(dp[i-1] == 1) {
			for(int j=0;j<N;j++) {
				if(S.substr(i-1).find(v[j]) == 0) {
					dp[i+v[j].size()-1] = 1;
				}
			}
		}
	}
	ans = dp[S.size()];
	cout<<ans<<"\n";
	return 0;	
}
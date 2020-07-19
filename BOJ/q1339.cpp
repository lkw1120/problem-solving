#include<bits/stdc++.h>
using namespace std;
const int MAX = 26;
vector<string> v;
int dp[MAX] = {0};
int N,ans;
void solve() {
	for(auto item: v) {
		int size = item.size();
		for(int i=0;i<size;i++) {
			dp[item[i]-'A'] += pow(10,size-1-i);
		}
	}
	sort(dp,dp+MAX,greater<int>());
	int n = 10;
	for(int i=0;i<MAX;i++) {
		ans+=--n*dp[i];
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	string s;
	for(int i=0;i<N;i++) {
		cin>>s;
		v.push_back(s);
	}
	ans = 0;
	solve();
	cout<<ans<<"\n";
	return 0;
}
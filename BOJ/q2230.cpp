#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,ans;
void solve() {
	int l,h;
	l = 0;
	h = 1;
	while(h < N) {
		if(v[h]-v[l] == M) {
			ans = M;
			return ;
		}
		else if(v[h]-v[l] < M) {
			h++;
		}
		else if(v[h]-v[l] > M) {
			ans = min(ans,v[h]-v[l]);
			l++;
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	int n;
	for(int i=0;i<N;i++) {
		cin>>n;
		v.push_back(n);
	}
	sort(v.begin(),v.end());
	ans = INT_MAX;
	solve();
	cout<<ans<<"\n";
	return 0;
}
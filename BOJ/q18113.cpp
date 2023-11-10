#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,M,ans;
int find(int p) {
	int cnt = 0;
	for(auto item: v) {
		if(item <= K) continue;
		if(item < 2*K) {
			if(item-K != 0) {
				cnt+=(item-K)/p;
			}
		}
		else {
			if(item-2*K != 0) {
				cnt+=(item-2*K)/p;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int l,r;
	l = 1;
	r = 1e9+1;
	ans = -1;
	while(l <= r) {
		int mid = (l+r)/2;
		int cnt = find(mid);
		if(M <= cnt) {
			l = mid+1;
			ans = mid;
		}
		else {
			r = mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
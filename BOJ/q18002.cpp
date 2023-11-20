#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int N,W,ans;
int find(int t) {
	int l,r;
	l = r = 0;
	for(auto item: mp) {
		int w = item.first;
		int cnt = item.second;
		if(w < t) {
			l+=(w*cnt);
		}
		else if(t < w) {
			r+=(w*cnt);	
		}
		else {
			if(cnt%2) {
				cnt--;
			}
			cnt/=2;
			l+=(w*cnt);
			r+=(w*cnt);
		}
	}
	return r-=l;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>W;
		mp[W]++;
	}
	int l,r;
	l = 0;
	r = 200000;
	while(l <= r) {
		int mid = (l+r)/2;
		int res = find(mid);
		if(0 < res) {
			l = mid+1;
		}
		else {
			r = mid-1;
			ans = mid;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
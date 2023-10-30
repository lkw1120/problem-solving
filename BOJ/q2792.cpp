#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> v;
int N,M,K,ans;
int check(int m) {
	int cnt = 0;
	for(auto item: v) {
		cnt+=item/m;
		if(item%m) cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>K;
		v.push_back(K);
	}
	sort(v.begin(),v.end());
	int l,r;
	l = 1;
	r = v.back();
	while(l <= r) {
		int mid = (l+r)/2;
		int cnt = check(mid);
		if(N < cnt) {
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
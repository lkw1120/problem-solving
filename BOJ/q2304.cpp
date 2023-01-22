#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,L,H,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>L>>H;
		v.push_back({L,H});
	}
	sort(v.begin(),v.end());
	ans = L = H = 0;
	for(auto item: v) {
		if(H < item.second) {
			ans+=((item.first-L)*H);
			L = item.first;
			H = item.second;
		}
	}
	sort(v.begin(),v.end(),greater<>());
	L = H = 0;
	for(auto item: v) {
		if(H <= item.second) {
			ans+=((L-item.first)*H);
			L = item.first;
			H = item.second;
		}
	}
	ans+=H;
	cout<<ans<<"\n";
	return 0;
}
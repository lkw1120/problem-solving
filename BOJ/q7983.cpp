#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,D,T,ans;
bool compare(pair<int,int> a, pair<int,int> b) {
	if(a.second == b.second) {
		return a.first > b.first;
	}
	else {
		return a.second > b.second;	
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>D>>T;
		v.push_back({D,T});
	}
	sort(v.begin(),v.end(),compare);
	ans = v[0].second;
	for(auto item: v) {
		if(ans > item.second) {
			ans	= item.second;
		}
		ans-=item.first;
	}
	cout<<ans<<"\n";
	return 0;	
}
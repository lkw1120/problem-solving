#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>> v;
vector<pair<pair<int,int>,int>> res;
int N,S,E,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>S>>E>>C;
		v.push_back({{S,E},C});
	}
	sort(v.begin(),v.end(),less<>());
	S = v[0].first.first;
	E = v[0].first.second;
	C = v[0].second;
	for(int i=1;i<N;i++) {
		if((S <= v[i].first.first &&  v[i].first.first <= E) || 
		   (S <= v[i].first.second && v[i].first.second <= E)) {
			S = min(S,v[i].first.first);
			E = max(E,v[i].first.second);
			C = min(C,v[i].second);
		}
		else {
			res.push_back({{S,E},C});
			S = v[i].first.first;
			E = v[i].first.second;
			C = v[i].second;
		}
	}
	res.push_back({{S,E},C});
	ans = res.size();
	cout<<ans<<"\n";
	for(auto item: res) {
		cout<<item.first.first<<" "<<item.first.second<<" "<<item.second<<"\n";
	}
	return 0;
}
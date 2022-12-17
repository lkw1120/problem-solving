#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,L,A,B,P,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	sort(v.begin(),v.end());
	ans = P = 0;
	for(int i=0;i<N;i++) {
		if(P < v[i].first) {
			P = v[i].first;
		}
		while(P < v[i].second) {
			P+=L;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
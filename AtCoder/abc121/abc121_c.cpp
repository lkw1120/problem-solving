#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int>> v;
ll N,M,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	sort(v.begin(),v.end());
	int cnt = 0;
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<v[i].second;j++) {
			cnt++;
			ans+=v[i].first;
			if(cnt == M) break;
		}
		if(cnt == M) break;
	}
	cout<<ans<<"\n";
	return 0;
}
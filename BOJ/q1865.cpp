#include<bits/stdc++.h>
using namespace std;
const int MAX = 501;
vector<pair<pair<int,int>,int>> v;
int dist[MAX];
int T,N,M,W,a,b,c,ans;
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		v.clear();
		fill(dist,dist+MAX,0);
		cin>>N>>M>>W;
		for(int i=0;i<M;i++) {
			cin>>a>>b>>c;
			v.push_back({{a,b},c});
			v.push_back({{b,a},c});
		}
		for(int i=0;i<W;i++) {
			cin>>a>>b>>c;
			v.push_back({{a,b},-c});
		}
		bool flag = false;
		for(int i=1;i<=N;i++) {
			for(int j=0;j<v.size();j++) {
				a = v[j].first.first;
				b = v[j].first.second;
				c = v[j].second;
				if(dist[a] + c < dist[b]) {
					dist[b] = dist[a] + c;
				}
			}
		}
		for(int i=0;i<v.size();i++) {
			a = v[i].first.first;
			b = v[i].first.second;
			c = v[i].second;
			if(dist[a] + c < dist[b]) {
				flag = true;	
			}
		}
		if(flag) {
			cout<<"YES"<<"\n";	
		}
		else {
			cout<<"NO"<<"\n";	
		}
	}
	return 0;
}
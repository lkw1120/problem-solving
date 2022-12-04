#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<pair<ll,ll>> v;
ll N,X,Y,Z,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>X>>Y;
		v.push_back({X,Y});
	}
	sort(v.begin(),v.end());
	ll x1,x2,x3,y1,y2,y3;
	ans = 0;
	for(int i=0;i<N-2;i++) {
		for(int j=i+1;j<N-1;j++) {
			x1 = v[i].first;
			x2 = v[j].first;
			y1 = v[i].second;
			y2 = v[j].second;
			X = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
			for(int k=j+1;k<N;k++) {
				x3 = v[k].first;
				y3 = v[k].second;
				Y = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
				Z = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
				if(X + Y == Z || X + Z == Y || Y + Z == X) {
					ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
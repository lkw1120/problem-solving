#include<bits/stdc++.h>
using namespace std;
vector<pair<int,pair<int,int>>> v;
int N,H,L,R,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>H>>L>>R;
		v.push_back({H,{L,R}});
	}
	sort(v.begin(),v.end());
	ans = 0;
	for(int i=0;i<N;i++) {
		H = v[i].first;
		L = v[i].second.first;
		R = v[i].second.second-1;
		ans+=(2*H);
		for(int j=i-1;j>=0;j--) {
			if(v[j].second.first <= L && L < v[j].second.second) {
				ans-=v[j].first;
				break;
			}
		}
		for(int j=i-1;j>=0;j--) {
			if(v[j].second.first <= R && R < v[j].second.second) {
				ans-=v[j].first;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
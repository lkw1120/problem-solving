#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,X,Y,ans;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>X>>Y;
		v.push_back({X,Y});
	}
	sort(v.begin(),v.end());
	X = v[0].first;
	Y = v[0].second;
	for(int i=1;i<N;i++) {
		if(X <= v[i].first && v[i].first <= Y) {
			if(Y < v[i].second) {
				Y = v[i].second;
			}
		}
		else {
			ans+=(Y-X);
			X = v[i].first;
			Y = v[i].second;
		}
	}
	ans+=(Y-X);
	cout<<ans<<"\n";
    return 0;
}
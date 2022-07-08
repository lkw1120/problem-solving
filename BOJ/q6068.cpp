#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,T,S,ans;
bool compare(pair<int,int> a, pair<int,int> b) {
	if(a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;	
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>T>>S;
		v.push_back({S,T});
	}
	sort(v.begin(),v.end(),compare);
	ans = -1;
	for(int i=v[0].first-v[0].second;i>=0;i--) {
		int t = i + v[0].second;
		bool isFinish = true;
		for(int j=1;j<N;j++) {
			if(t > (v[j].first-v[j].second)) {
				isFinish = false;
				break;
			}
			t+=v[j].second;
		}
		if(isFinish) {
			ans = i;
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
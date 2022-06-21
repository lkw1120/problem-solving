#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int N,T,S,ans;
bool isPossible(int delay) {
	S = 0;
	T = delay;
	for(auto item: v) {
		S = item.first;
		T += item.second;
		if(T > S) return false;
	}
	return true;
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
	sort(v.begin(),v.end());
	ans = -1;
	for(int i=0;i<v[0].first;i++) {
		if(isPossible(i)) {
			ans = i;
		}
		else break;
	}
	cout<<ans<<"\n";
	return 0;
}
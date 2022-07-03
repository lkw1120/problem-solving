#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
vector<pair<int,int>> v;
int N,M,A,B,sum,cost,ans;
void solve() {
	ans = INT_MAX;
	sum = cost = 0;
	for(int i=0;i<N;i++) {
		if(i > 0 && v[i].first == v[i-1].first) {
			cost+=v[i].first;
		}
		else {
			cost = v[i].first;
		}
		sum+=v[i].second;
		if(sum >= M) {
			if(ans > cost) ans = cost;
		}
	}
	if(sum < M) ans = -1;
}
bool compare(pair<int,int> a, pair<int,int> b) {
	if(a.first == b.first) {
		return a.second > b.second;	
	}
	else {
		return a.first < b.first;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({B,A});
	}
	sort(v.begin(),v.end(),compare);
	solve();
	cout<<ans<<"\n";
	return 0;	
}
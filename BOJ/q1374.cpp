#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
priority_queue<int,vector<int>,greater<int>> pq;
int N,R,S,E,cnt,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>R>>S>>E;
		v.push_back({S,E});
	}
	sort(v.begin(),v.end());
	ans = 0;
	for(auto item: v) {
		while(!pq.empty() && pq.top() <= item.first) pq.pop();
		pq.push(item.second);
		ans = max(ans,(int)pq.size());
	}
	cout<<ans<<"\n";
	return 0;
}
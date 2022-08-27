#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<>> pq;
vector<pair<int,int>> v;
int N,a,b,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	pq.push(v[0].second);
	for(int i=1;i<N;i++) {
		if(pq.top() <= v[i].first) {
			pq.pop();
		}
		pq.push(v[i].second);
	}
	ans = pq.size();
	cout<<ans<<"\n";
	return 0;	
}
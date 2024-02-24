#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
bool check[21];
int N,S,F,ans;
void solve(int n, int size) {
	if(n == size) {
		stack<int> st;
		for(int i=0;i<size;i++) {
			if(check[i]) {
				if(st.empty() || st.top() <= v[i].first) {
					st.push(v[i].second);
				}
			}
		}
		ans = max(ans,(int)st.size());
		return ;
	}
	check[n] = true;
	solve(n+1,size);
	check[n] = false;
	solve(n+1,size);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(N--) {
		v.clear();
		fill(check,check+21,false);
		while(true) {	
			cin>>S>>F;
			if(S == 0 && F == 0) break;
			v.push_back({S,F});
		}
		sort(v.begin(),v.end());
		ans = 0;
		solve(0,v.size());
		cout<<ans<<"\n";
	}
	return 0;
}
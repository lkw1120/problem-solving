#include<bits/stdc++.h>
using namespace std;
vector<bool> check;
int T,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>A>>B;
	check.resize(T+1);
	queue<pair<int,bool>> q;
	q.push({0,false});
	check[0] = true;
	ans = 0;
	while(!q.empty()) {
		int now = q.front().first;
		bool drink = q.front().second;
		q.pop();
		ans = max(now,ans);
		if(now+A <= T && !check[now+A]) {
			check[now+A] = true;
			q.push({now+A,drink});
		}
		if(now+B <= T && !check[now+B]) {
			check[now+B] = true;
			q.push({now+B,drink});
		}
		if(!drink && !check[now/2]) {
			check[now/2] = true;
			q.push({now/2,true});
		}
	}
	cout<<ans<<"\n";
	return 0;
}
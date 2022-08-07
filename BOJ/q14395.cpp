#include<bits/stdc++.h>
#define MAX 1000000001
typedef long long ll;
using namespace std;
map<int,bool> visited;
queue<pair<ll,string>> q;
ll S,T;
string ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>S>>T;
	if(S != T) {
		q.push({S,""});
		visited[S] = true;
		while(!q.empty()) {
			ll t = q.front().first;
			string op = q.front().second;
			q.pop();
			if(t == T) {
				ans = op;
				break;
			}
			if(t*t <= T && visited[t*t] == false) {
				visited[t*t] = true;
				q.push({t*t,op + "*"});	
			}
			if(t+t <= T && visited[t+t] == false) {
				visited[t+t] = true;
				q.push({t+t,op + "+"});	
			}
			if(visited[t-t] == false) {
				visited[0] = true;
				q.push({t-t,op + "-"});	
			}
			if(t != 0 && visited[t/t] == false) {
				visited[1] = true;
				q.push({t/t,op + "/"});	
			}
		}
		if(ans.size() == 0) {
			ans = "-1";
		}
	}
	else {
		ans = "0";
	}
	cout<<ans<<"\n";
	return 0;	
}
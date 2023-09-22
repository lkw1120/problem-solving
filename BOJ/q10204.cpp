#include<bits/stdc++.h>
using namespace std;
string s1,s2,vx;
int T,N,E,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N>>E;
		map<string,vector<string>> mp;
		for(int i=0;i<E;i++) {
			cin>>s1>>s2;
			mp[s1].push_back(s2);
			mp[s2].push_back(s1);
		}
		cin>>vx;
		vector<string> res;
		queue<pair<string,int>> q;
		map<string,bool> visited;
		q.push({vx,0});
		visited[vx] = true;
		ans = 0;
		while(!q.empty()) {
			string now = q.front().first;
			int dist = q.front().second;
			q.pop();
			if(dist < 2) {
				for(auto next: mp[now]) {
					if(!visited[next]) {
						visited[next] = true;
						ans++;
						q.push({next,dist+1});
					}
				}
			}
		}
		cout<<"The number of supervillains in 2-hop neighborhood of ";
		cout<<vx<<" is ";
		cout<<ans<<"\n";
	}
	return 0;	
}
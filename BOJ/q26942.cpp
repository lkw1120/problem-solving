#include<bits/stdc++.h>
using namespace std;
map<string,vector<string>> mp;
map<string,bool> checked;
vector<string> v;
int N,M,ans;
void bfs(string str) {
	queue<string> q;
	q.push(str);
	while(!q.empty()) {
		str = q.front();
		q.pop();
		for(auto item: mp[str]) {
			if(checked[item] != true) {
				checked[item] = true;
				q.push(item);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	cin>>M;
	for(int j=0;j<M;j++) {
		string str1,str2;
		cin>>str1>>str2;
		mp[str1].push_back(str2);
		mp[str2].push_back(str1);
	}
	ans = 0;
	for(auto item: v) {
		if(checked[item] != true) {
			checked[item] = true;
			bfs(item);
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
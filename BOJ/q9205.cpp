#include<bits/stdc++.h>
using namespace std;
int T,N,X,Y;
string ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) {
		vector<pair<int,int>> v;
		map<pair<int,int>,bool> mp;
		queue<pair<int,int>> q;
		pair<int,int> p1,p2;
		cin>>N;
		cin>>X>>Y;
		p1 = {X,Y};
		for(int i=0;i<N;i++) {
			cin>>X>>Y;
			v.push_back({X,Y});
		}
		cin>>X>>Y;
		p2 = {X,Y};
		v.push_back(p2);
		q.push(p1);
		ans = "sad";
		while(!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if(x == p2.first && y == p2.second) {
				ans = "happy";
				break;
			}
			for(auto item : v) {
				if((abs(item.first-x) + abs(item.second-y) <= 1000) && !mp.count(item)) {
					mp[item] = true;
					q.push(item);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;	
}
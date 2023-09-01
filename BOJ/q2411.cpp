#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
map<pair<int,int>,bool> mp;
int dp[101][101] = {0};
int N,M,A,B,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>A>>B;
	for(int i=0;i<A;i++) {
		cin>>X>>Y;
		v.push_back({X,Y});
	}
	for(int i=0;i<B;i++) {
		cin>>X>>Y;
		mp[{X,Y}] = true;
	}
	sort(v.begin(),v.end());
	v.push_back({N,M});
	dp[1][1] = 1;
	int x,y;
	x = y = 1;
	for(auto item: v) {
		X = item.first;
		Y = item.second;
		for(int i=x;i<=X;i++) {
			for(int j=y;j<=Y;j++) {
				if(i == 1 && j == 1) continue;
				if(!mp[{i,j}]) {
					dp[i][j] = dp[i-1][j]+dp[i][j-1];
				}
			}
		}
		x = X,y = Y;
	}
	ans = dp[N][M];
	cout<<ans<<"\n";
	return 0;
}
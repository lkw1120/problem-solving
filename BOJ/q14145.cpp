#include<bits/stdc++.h>
using namespace std;
int arr[51][51];
vector<pair<int,int>> v;
map<int,int> mp;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,S,ans;
int find(int x, int y, int n) {
	queue<pair<int,int>> q;
	q.push({x,y});
	arr[x][y] = n;
	int cnt = 0;
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		cnt++;
		for(int i=0;i<4;i++) {
			int dx = x+dX[i];
			int dy = y+dY[i];
			if(0 < dx && dx <= R && 0 < dy && dy <= S && arr[dx][dy] == 1) {
				arr[dx][dy] = n;
				q.push({dx,dy});
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>S;
	for(int i=1;i<=R;i++) {
		string str;
		cin>>str;
		for(int j=1;j<=S;j++) {
			arr[i][j] = str[j-1]-'0';
		}
	}
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=S;j++) {
			if(arr[i][j] == 1) {
				int n = 1e5 + v.size();
				int cnt = find(i,j,n);
				v.push_back({cnt,n});
			}
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++) {
		mp[v[i].second] = i+1;
	}
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=S;j++) {
			int n = 0;
			if(arr[i][j]) {
				n = mp[arr[i][j]];
			}
			cout<<n;
		}
		cout<<"\n";
	}
	return 0;
}
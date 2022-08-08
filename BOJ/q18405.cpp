#include<bits/stdc++.h>
#define MAX 201
using namespace std;
int arr[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<tuple<int,int,int>> v;
queue<pair<tuple<int,int,int>,int>> q;
int N,K,S,X,Y,ans;
bool compare(tuple<int,int,int> a, tuple<int,int,int> b) {
	return (get<2>(a) < get<2>(b));
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];
			if(arr[i][j] != 0) {
				v.push_back(make_tuple(i,j,arr[i][j]));
			}
		}
	}
	sort(v.begin(),v.end(),compare);
	for(auto item: v) {
		q.push({make_tuple(get<0>(item),get<1>(item),get<2>(item)),0});	
	}
	cin>>S>>X>>Y;
	ans = 0;
	while(!q.empty()) {
		int x = get<0>(q.front().first);
		int y = get<1>(q.front().first);
		int k = get<2>(q.front().first);
		int s = q.front().second;
		if(s > S) {
			break;
		}
		if(arr[x][y] == 0) arr[x][y] = k;
		q.pop();
		for(int i=0;i<4;i++) {
			if((0 < x+dX[i] && x+dX[i] <= N) &&
			   (0 < y+dY[i] && y+dY[i] <= N) &&
			   arr[x+dX[i]][y+dY[i]] == 0) {
				q.push({make_tuple(x+dX[i],y+dY[i],k),s+1});
			}
		}
	}
	ans = arr[X][Y];
	cout<<ans<<"\n";
	return 0;	
}
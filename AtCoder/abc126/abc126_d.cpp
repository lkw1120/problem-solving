#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<pair<int,int>> v[MAX];
int arr[MAX];
int N,U,V,W;
void dfs(int now, int prev, int color) {
	arr[now] = color;
	for(auto [next,dist]: v[now]) {
		if(prev == next) continue;
		if(dist%2 == 0) {
			dfs(next,now,color);	
		}
		else {
			dfs(next,now,1-color);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	for(int i=1;i<N;i++) {
		cin>>U>>V>>W;
		v[U].push_back({V,W});
		v[V].push_back({U,W});
	}
	dfs(1,-1,0);
	for(int i=1;i<=N;i++) {
		cout<<arr[i]<<"\n";	
	}
	return 0;
}
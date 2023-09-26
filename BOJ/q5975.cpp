#include<bits/stdc++.h>
using namespace std;
int arr[101][101] = {0};
bool visited[101] = {false};
vector<int> res[101];
int N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];	
		}
	}
	queue<pair<int,int>> q;
	q.push({M,0});
	visited[M] = true;
	while(!q.empty()) {
		int now = q.front().first;
		int hop = q.front().second;
		q.pop();
		res[hop].push_back(now);
		for(int j=1;j<=N;j++) {
			if(arr[now][j] && !visited[j]) {
				visited[j] = true;
				q.push({j,hop+1});
			}
		}
	}
	for(int i=0;i<N;i++) {
		if(res[i].size() == 0) break;
		sort(res[i].begin(),res[i].end());
		for(auto item: res[i]) {
			cout<<item<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
vector<int> v[MAX];
bool visited[MAX];
int arr[MAX];
int N,M,X,Y,ans;
void find(int n, int d) {
	if(d == 2) {
		arr[n]++;
		return ;
	}
	for(auto next: v[n]) {
		if(visited[next]) continue ;
		visited[next] = true;
		find(next,d+1);
		visited[next] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		cin>>X>>Y;
		v[X].push_back(Y);
		v[Y].push_back(X);
	}
	visited[1] = true;
	find(1,0);
	ans = 0;
	for(int i=1;i<=N;i++) {
		ans+=(arr[i]*(arr[i]-1));
	}
	cout<<ans<<"\n";
	return 0;
}
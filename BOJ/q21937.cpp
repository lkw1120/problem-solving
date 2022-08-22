#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
bool visited[MAX] = {false};
vector<int> v[MAX];
int N,M,A,B,X,ans;
void solve(int x) {
	for(auto item: v[x]) {
		if(!visited[item]) {
			visited[item] = true;
			ans++;
			solve(item);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[B].push_back(A);
	}
	cin>>X;
	ans = 0;
	solve(X);
	cout<<ans<<"\n";
	return 0;
}
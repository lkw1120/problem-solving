#include<bits/stdc++.h>
#define MAX 500001
using namespace std;
bool visited[MAX] = {false};
vector<int> v[MAX];
int N,A,B,ans;
void dfs(int a, int dist) {
	visited[a] = true;
	bool flag = true;
	for(auto item: v[a]) {
		if(!visited[item]) {
			dfs(item,dist+1);
			flag = false;
		}
	}
	if(flag) ans+=dist;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N-1;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	ans = 0;
	dfs(1,0);
	if(ans%2) {
		cout<<"Yes"<<"\n";	
	}
	else {
		cout<<"No"<<"\n";	
	}
	return 0;	
}
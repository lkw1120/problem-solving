#include<bits/stdc++.h>
#define MAX 20001
using namespace std;
vector<int> v[MAX];
queue<pair<int,int>> q;
bool visited[MAX] = {false};
int node[MAX] = {0};
int N,M,A,B;
int num,dist,cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	q.push({1,0});
	visited[1] = true;
	dist = cnt = 0;
	while(!q.empty()) {
		int n = q.front().first;
		int d = q.front().second;
		q.pop();
		node[n] = d;
		dist = max(dist,d);
		for(auto item: v[n]) {
			if(!visited[item]) {
				visited[item] = true;
				q.push({item,d+1});
			}
		}
	}
	num = INT_MAX;
	for(int i=1;i<=N;i++) {
		if(node[i] == dist) {
			num = min(num,i);
			cnt++;
		}
	}
	cout<<num<<" "<<dist<<" "<<cnt<<"\n";
	return 0;	
}
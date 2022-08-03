 #include<bits/stdc++.h>
#define MAX 1001
using namespace std;
bool visited[MAX] = {false};
vector<pair<int,int>> v[MAX];
int N,M,A,B,D,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N-1;i++) {
		cin>>A>>B>>D;
		v[A].push_back({B,D});
		v[B].push_back({A,D});
	}
	for(int i=0;i<M;i++) {
		queue<pair<int,int>> q;
		fill(visited,visited+MAX,false);
		ans = 0;
		cin>>A>>B;
		visited[A] = true;
		for(auto item: v[A]) {
			q.push({item.first,item.second});
			visited[item.first] = true;
		}
		while(!q.empty()) {
			int n = q.front().first;
			int d = q.front().second;
			q.pop();
			if(n == B) {
				ans = d;
				break;
			}
			for(auto item: v[n]) {
				if(!visited[item.first]) {
					q.push({item.first,item.second + d});
					visited[item.first] = true;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
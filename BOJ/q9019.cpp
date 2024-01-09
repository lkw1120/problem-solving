#include<bits/stdc++.h>
using namespace std;
bool visited[10000];
int T,A,B;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>A>>B;
		fill(visited,visited+10000,false);
		queue<pair<int,string>> q;
		q.push({A,""});
		visited[A] = true;
		while(!q.empty()) {
			int num = q.front().first;
			string cmd = q.front().second;
			q.pop();
			if(num == B) {
				ans = cmd;
				break;
			}
			int tmp;
			tmp = (num*2)%10000;
			if(!visited[tmp]) {
				visited[tmp] = true;
				q.push({tmp,cmd+"D"});
			}
			tmp = num == 0? 9999: num-1;
			if(!visited[tmp]) {
				visited[tmp] = true;
				q.push({tmp,cmd+"S"});
			}
			tmp = (num%1000)*10 + num/1000;
			if(!visited[tmp]) {
				visited[tmp] = true;
				q.push({tmp,cmd+"L"});
			}
			tmp = (num/10) + (num%10)*1000;
			if(!visited[tmp]) {
				visited[tmp] = true;
				q.push({tmp,cmd+"R"});
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
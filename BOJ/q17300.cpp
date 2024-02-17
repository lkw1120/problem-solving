#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool visited[10];
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	visited[v[0]] = true;
	bool flag = true;
	for(int i=1;i<N;i++) {
		if(visited[v[i]]) {
			flag = false;
			break;
		}
		visited[v[i]] = true;
		if(!visited[2]) {
			if(v[i]+v[i-1] == 4) {
				flag = false;
				break;
			}
		}
		if(!visited[4]) {
			if((v[i] == 1 && v[i-1] == 7) || (v[i] == 7 && v[i-1] == 1)) {
				flag = false;
				break;
			}
		}
		if(!visited[5]) {
			if(v[i]+v[i-1] == 10) {
				flag = false;
				break;
			}
		}
		if(!visited[6]) {
			if((v[i] == 3 && v[i-1] == 9) || (v[i] == 9 && v[i-1] == 3)) {
				flag = false;
				break;
			}
		}
		if(!visited[8]) {
			if(v[i]+v[i-1] == 16) {
				flag = false;
				break;
			}
		}
	}
	if(flag) {
		cout<<"YES"<<"\n";
	}
	else {
		cout<<"NO"<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int area[101];
int car[2001];
bool parking[101];
map<int,int> mp;
queue<int> q;
int N,M,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>area[i];	
	}
	for(int i=1;i<=M;i++) {
		cin>>car[i];	
	}
	ans = 0;
	for(int i=0;i<2*M;i++) {
		cin>>K;
		if(0 < K) {
			bool flag = true;
			for(int j=1;j<=N;j++) {
				if(!parking[j]) {
					flag = false;
					parking[j] = true;
					mp[K] = j;
					break;
				}
			}
			if(flag) {
				q.push(K);
			}
		}
		else {
			ans+=area[mp[-K]]*car[-K];
			if(!q.empty()) {
				mp[q.front()] = mp[-K];
				q.pop();
			}
			else {
				parking[mp[-K]] = false;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
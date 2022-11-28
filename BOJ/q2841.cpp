#include<bits/stdc++.h>
using namespace std;
stack<int> guitar[7];
int N,P,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P;
	int n,p;
	ans = 0;
	for(int i=1;i<=6;i++) {
		guitar[i].push(0);	
	}
	for(int i=0;i<N;i++) {
		cin>>n>>p;
		if(guitar[n].top() < p) {
			ans++;
			guitar[n].push(p);
		}
		else if(p < guitar[n].top()) {
			while(p < guitar[n].top()) { 
				ans++;
				guitar[n].pop();
			}
			if(guitar[n].top() < p) {
				ans++;
				guitar[n].push(p);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
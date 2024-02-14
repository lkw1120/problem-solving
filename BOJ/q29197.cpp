#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> st[5];
int N,X,Y,ans;
int gcd(int a, int b) {
	return b == 0? a: gcd(b,a%b);	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>X>>Y;
		int tmp = gcd(X,Y);
		if(0 < X && 0 < Y) {
			st[1].insert({X/tmp,Y/tmp});
		}
		else if(X < 0 && 0 < Y) {
			st[2].insert({X/tmp,Y/tmp});
		}
		else if(X < 0 && Y < 0) {
			st[3].insert({X/tmp,Y/tmp});	
		}
		else if(0 < X && Y < 0) {
			st[4].insert({X/tmp,Y/tmp});	
		}
		else if(X == 0 && 0 < Y) {
			st[0].insert({0,1});	
		}
		else if(X == 0 && Y < 0) {
			st[0].insert({0,-1});	
		}
		else if(0 < X && Y == 0) {
			st[0].insert({1,0});	
		}
		else if(X < 0 && Y == 0) {
			st[0].insert({-1,0});	
		}
	}
	ans = 0;
	for(auto item: st) {
		ans+=item.size();
	}
	cout<<ans<<"\n";
	return 0;
}
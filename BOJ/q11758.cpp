#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int X,Y,ans;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int a = x1 * y2 + x2 * y3 + x3 * y1;
	int b = y1 * x2 + y2 * x3 + y3 * x1;
	return a - b;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<3;i++) {
		cin>>X>>Y;
		v.push_back({X,Y});
	}
	ans = ccw(v[0].first,v[0].second,v[1].first,v[1].second,v[2].first,v[2].second);
	if(ans < 0) ans = -1;
	else if(ans > 0) ans = 1;
	cout<<ans<<"\n";
	return 0;	
}

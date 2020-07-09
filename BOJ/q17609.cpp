#include<bits/stdc++.h>
using namespace std;
string str;
int T,ans;
void solve(int low, int high, bool skip) {
	if(low < high) {
		if(str[low] == str[high]) {
			solve(low+1,high-1,skip);
		}
		else {
			if(skip) {
				ans = min(ans,2);
				return ;
			}
			else {
				solve(low+1,high,true);
				solve(low,high-1,true);
			}
		}
	}
	else {
		if(!skip) {
			ans = min(ans,0);
		}
		else {
			ans = min(ans,1);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	while(T--) {
		ans = INT_MAX;
		cin>>str;
		solve(0,str.size()-1,false);
		cout<<ans<<"\n";
	}
	return 0;
}
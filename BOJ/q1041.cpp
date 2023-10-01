#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int three[8][3] = {
	{0,1,2},{0,1,3},{0,2,4},{0,3,4},
	{1,2,5},{1,3,5},{2,4,5},{3,4,5}
};
int two[12][2] = {
	{0,1},{0,2},{0,3},{0,4},
	{1,2},{1,3},{1,5},
	{2,4},{2,5},
	{3,4},{3,5},
	{4,5}
};
int dice[6] = {0};
ll N,sum,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<6;i++) {
		cin>>dice[i];
	}
	ans = 0;
	if(N == 1) {
		for(int i=0;i<6;i++) {
			ans+=dice[i];	
		}
		ans-=*max_element(dice,dice+6);
	}
	else {
		sum = LONG_MAX;
		for(int i=0;i<8;i++) {
			ll tmp = 0;
			for(int j=0;j<3;j++) {
				tmp+=dice[three[i][j]];	
			}
			sum = min(tmp,sum);
		}
		ans+=4*sum;
		sum = LONG_MAX;
		for(int i=0;i<12;i++) {
			ll tmp = 0;
			for(int j=0;j<2;j++) {
				tmp+=dice[two[i][j]];
			}
			sum = min(tmp,sum);
		}
		ans+=(8*N-12)*sum;
		sum = *min_element(dice,dice+6);
		ans+=(5*N*N-16*N+12)*sum;
	}
	cout<<ans<<"\n";
	return 0;
}
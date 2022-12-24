#include<bits/stdc++.h>
#define DIV 1000007
typedef long long ll;
using namespace std;
ll arr[201][201] = {0};
ll N,M,X,Y,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>X>>Y;
	ans = 0;
	for(int i=1;i<=N;i++) {
		arr[i][1] = 1;
	}
	for(int j=1;j<=M;j++) {
		arr[1][j] = 1;	
	}
	for(int i=2;i<=N;i++) {
		for(int j=2;j<=M;j++) {
			arr[i][j] = (arr[i-1][j]+arr[i][j-1])%DIV;
		}
	}
	ans = ((arr[N-X+1][M-Y+1]%DIV)*(arr[X][Y]%DIV))%DIV;
	cout<<ans<<"\n";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100;
ll matrix[2][MAX][MAX] = {0};
ll N,M,ans;
void split(int y, int x, int r) {
	ll sum[3] = {0};
	for(int i=0;i<=y;i++) {
		for(int j=0;j<=x;j++) {
			sum[0]+=matrix[r][i][j];
		}
	}
	for(int i=y+1;i<N;i++) {
		for(int j=0;j<M;j++) {
			sum[1]+=matrix[r][i][j];
		}
	}
	for(int i=y;i>=0;i--) {
		for(int j=x+1;j<M;j++) {
			sum[2]+=matrix[r][i][j];
		}
	}
	ans = max(ans,sum[0]*sum[1]*sum[2]);
	sum[1] = sum[2] = 0;
	for(int i=0;i<N;i++) {
		for(int j=x+1;j<M;j++) {
			sum[1]+=matrix[r][i][j];
		}
	}
	for(int i=y+1;i<N;i++) {
		for(int j=x;j>=0;j--) {
			sum[2]+=matrix[r][i][j];
		}
	}
	ans = max(ans,sum[0]*sum[1]*sum[2]);
}
void split_horizontal(int i, int cnt, ll sum, ll multi) {
	if(cnt < 3 && i < N) {
		for(int j=0;j<M;j++) {
			sum+=matrix[0][i][j];
		}
		split_horizontal(i+1,cnt,sum,multi);
		split_horizontal(i+1,cnt+1,0,sum*multi);
	}
	else {
		if(i == N) {
			ans = max(ans,multi);
		}
	}
}
void split_vertical(int j, int cnt, ll sum, ll multi) {
	if(cnt < 3 && j < M) {
		for(int i=0;i<N;i++) {
			sum+=matrix[0][i][j];
		}
		split_vertical(j+1,cnt,sum,multi);
		split_vertical(j+1,cnt+1,0,sum*multi);
	}
	else {
		if(j == M) {
			ans = max(ans,multi);
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	string str;
	for(int i=0;i<N;i++) {
		cin>>str;
		for(int j=0;j<M;j++) {
			matrix[0][i][j] = str[j]-'0';
			matrix[1][N-i-1][M-j-1] = matrix[0][i][j];
		}
	}
	ans = 0;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			split(i,j,0);
			split(i,j,1);
		}
	}
	split_horizontal(0,0,0,1);
	split_vertical(0,0,0,1);
	cout<<ans<<"\n";
	return 0;
}
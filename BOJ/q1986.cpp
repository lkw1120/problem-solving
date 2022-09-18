#include<bits/stdc++.h>
#define MAX 1001
using namespace std;
char arr[MAX][MAX];
int N,M,K,R,C,ans;
void queen(int a, int b) {
	int dX[8] = {-1,0,1,1,1,0,-1,-1};
	int dY[8] = {1,1,1,0,-1,-1,-1,0};
	for(int i=0;i<8;i++) {
		for(int j=1;;j++) {
			if((0 < a+dX[i]*j && a+dX[i]*j <= N) &&
			   (0 < b+dY[i]*j && b+dY[i]*j <= M) &&
			   (arr[a+dX[i]*j][b+dY[i]*j] != 'Q') &&
			   (arr[a+dX[i]*j][b+dY[i]*j] != 'K') &&
			   (arr[a+dX[i]*j][b+dY[i]*j] != 'P')) {
				arr[a+dX[i]*j][b+dY[i]*j] = 'D';
			}
			else break;
		}
	}
}
void knight(int a, int b) {
	int dX[8] = {-2,-1,1,2,2,1,-1,-2};
	int dY[8] = {1,2,2,1,-1,-2,-2,-1};
	for(int i=0;i<8;i++) {
		if((0 < a+dX[i] && a+dX[i] <= N) &&
		   (0 < b+dY[i] && b+dY[i] <= M) &&
		   (arr[a+dX[i]][b+dY[i]] == '.')) {
			arr[a+dX[i]][b+dY[i]] = 'D';
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill(&arr[0][0],&arr[MAX-1][MAX],'.');
	cin>>N>>M;
	cin>>K;
	for(int i=0;i<K;i++) {
		cin>>R>>C;
		arr[R][C] = 'Q';
	}
	cin>>K;
	for(int i=0;i<K;i++) {
		cin>>R>>C;
		arr[R][C] = 'K';
	}
	cin>>K;
	for(int i=0;i<K;i++) {
		cin>>R>>C;
		arr[R][C] = 'P';
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(arr[i][j] == 'Q') {
				queen(i,j);	
			}
			if(arr[i][j] == 'K') {
				knight(i,j);	
			}
		}
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(arr[i][j] == '.') ans++;	
		}
	}
	cout<<ans<<"\n";
	return 0;
}
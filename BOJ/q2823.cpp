#include<bits/stdc++.h>
using namespace std;
char arr[12][12];
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(&arr[0][0],&arr[11][12],'X');
	cin>>R>>C;
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			cin>>arr[i][j];	
		}
	}
	ans = 0;
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			if(arr[i][j] == '.') {
				int cnt = 0;
				for(int k=0;k<4;k++) {
					int dx = i+dX[k];
					int dy = j+dY[k];
					if(arr[dx][dy] == 'X') {
						cnt++;
					}
				}
				if(2 < cnt) {
					ans = 1;	
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
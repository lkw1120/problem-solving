#include<bits/stdc++.h>
using namespace std;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
char arr[12][12];
int R,C;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	fill(&arr[0][0],&arr[11][12],'.');
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			cin>>arr[i][j];	
		}
	}
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			if(arr[i][j] == 'X') {
				int cnt = 0;
				for(int k=0;k<4;k++) {
					if(arr[i+dX[k]][j+dY[k]] == '.') {
						cnt++;	
					}
				}
				if(3 <= cnt) {
					arr[i][j] = '#';	
				}
			}
		}
	}
	int a,b,c,d;
	a = b = INT_MAX;
	c = d = INT_MIN;
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			if(arr[i][j] == '#') {
				arr[i][j] = '.';	
			}
			if(arr[i][j] == 'X') {
				a = min(a,i);
				b = min(b,j);
				c = max(c,i);
				d = max(d,j);
			}
		}
	}
	for(int i=a;i<=c;i++) {
		for(int j=b;j<=d;j++) {
			cout<<arr[i][j];	
		}
		cout<<"\n";
	}
	return 0;
}
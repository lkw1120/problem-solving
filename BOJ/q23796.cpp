#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll game[8][8] = {0};
ll arr[8][8] = {0};
char input;
void push() {
	for(int i=0;i<8;i++) {
		for(int j=1;j<8;j++) {
			for(int k=j;k>0;k--) {
				if(arr[i][k] != 0 && arr[i][k-1] == 0) {
					arr[i][k-1] = arr[i][k];
					arr[i][k] = 0;
				}
			}
		}
	}
}
void solve() {
	push();
	for(int i=0;i<8;i++) {
		for(int j=1;j<8;j++) {
			if(arr[i][j] == arr[i][j-1]) {
				arr[i][j-1]+=arr[i][j];
				arr[i][j] = 0;
			}
		}
	}
	push();
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			cin>>game[i][j];	
		}
	}
	cin>>input;
	switch(input) {
		case 'U':
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					arr[j][i] = game[i][j];
				}
			}
			solve();
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					game[j][i] = arr[i][j];
				}
			}
			break;
		case 'D':
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					arr[8-j-1][8-i-1] = game[i][j];
				}
			}
			solve();
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					game[8-j-1][8-i-1] = arr[i][j];
				}
			}
			break;
		case 'L':
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					arr[i][j] = game[i][j];
				}
			}
			solve();
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					game[i][j] = arr[i][j];
				}
			}
			break;
		case 'R':
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					arr[i][8-j-1] = game[i][j];
				}
			}
			solve();
			for(int i=0;i<8;i++) {
				for(int j=0;j<8;j++) {
					game[i][8-j-1] = arr[i][j];
				}
			}
			break;
		default:
			break;
	}
	for(int i=0;i<8;i++) {
		for(int j=0;j<8;j++) {
			cout<<game[i][j]<<" ";	
		}
		cout<<"\n";
	}
	return 0;	
}
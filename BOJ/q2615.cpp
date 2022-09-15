#include<bits/stdc++.h>
using namespace std;
int arr[20][20] = {0};
int A,B,win;
bool omok(int a, int b) {
	bool flag = true;
	if(a+5 <= 20) {
		for(int i=1;i<5;i++) {
			if(arr[a+i][b] != arr[a][b]) {
				flag = false;
				break;
			}
		}
		if(flag && a+6 <= 20) {
			flag = (arr[a+5][b] != arr[a][b]);
		}
		if(flag && a-1 > 0) {
			flag = (arr[a-1][b] != arr[a][b]);	
		}
		if(flag) return true;
	}
	flag = true;
	if(b+5 <= 20) {
		for(int i=1;i<5;i++) {
			if(arr[a][b+i] != arr[a][b]) {	
				flag = false;
				break;
			}
		}
		if(flag && b+6 <= 20) {
			flag = (arr[a][b+5] != arr[a][b]);
		}
		if(flag && b-1 > 0) {
			flag = (arr[a][b-1] != arr[a][b]);	
		}
		if(flag) return true;
	}
	flag = true;
	if(a+5 <= 20 && b+5 <= 20) {
		for(int i=1;i<5;i++) {
			if(arr[a+i][b+i] != arr[a][b]) {
				flag = false;
				break;
			}
		}
		if(flag && a+6 <= 20 && b+6 <= 20) {
			flag = (arr[a+5][b+5] != arr[a][b]);
		}
		if(flag && a-1 > 0 && b-1 > 0) {
			flag = (arr[a-1][b-1] != arr[a][b]);	
		}
		if(flag) return true;
	}
	flag = true;
	if(a-5 >= 0 && b+5 <= 20) {
		for(int i=1;i<5;i++) {
			if(arr[a-i][b+i] != arr[a][b]) {
				flag = false;
				break;
			}
		}
		if(flag && a-6 >= 0 && b+6 <= 20) {
			flag = (arr[a-5][b+5] != arr[a][b]);
		}
		if(flag && a+1 < 20 && b-1 > 0) {
			flag = (arr[a+1][b-1] != arr[a][b]);
		}
		if(flag) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i=1;i<20;i++) {
		for(int j=1;j<20;j++) {
			cin>>arr[i][j];
		}
	}
	bool flag = true;
	for(int i=1;i<20;i++) {
		for(int j=1;j<20;j++) {
			if(flag && arr[i][j] && omok(i,j)) {
				win = arr[i][j];
				A = i;
				B = j;
				flag = false;
				break;
			}
		}
		if(!flag) break;
	}
	cout<<win<<"\n";
	if(win != 0) {
		cout<<A<<" "<<B<<"\n";
	}
	return 0;	
}
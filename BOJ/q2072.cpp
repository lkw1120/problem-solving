#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;
int arr[20][20] = {0};
int N,A,B,ans;
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
	cin>>N;
	ans = -1;
	for(int i=1;i<=N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	for(int i=1;i<=N;i++) {
		A = v[i-1].first;
		B = v[i-1].second;
		if(i%2) {
			arr[A][B] = 1;
		}
		else {
			arr[A][B] = 2;
		}
		if(i >= 9) {
			bool flag = false;
			for(int i=1;i<20;i++) {
				for(int j=1;j<20;j++) {
					if(arr[i][j]) {
						flag = omok(i,j);
					}
					if(flag) break;
				}
				if(flag) break;
			}
			if(flag) {
				ans = i;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
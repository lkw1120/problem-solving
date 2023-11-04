#include<bits/stdc++.h>
using namespace std;
char arr[101][101];
int H,W,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>H>>W;
	for(int i=1;i<=H;i++) {
		for(int j=1;j<=W;j++) {
			cin>>arr[i][j];
		}
	}
	int a,b;
	a = b = 0;
	for(int i=1;i<=H;i++) {
		for(int j=1;j<=W;j++) {
			if(arr[i][j] == '\\' || arr[i][j] == '/') {
				a++;	
			}
			if(a%2) {
				if(arr[i][j] == '.') {
					b++;	
				}
			}
		}
	}
	ans = a/2+b;
	cout<<ans<<"\n";
}
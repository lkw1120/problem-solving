#include<bits/stdc++.h>
using namespace std;
int N;
string arr[64];
bool check(int n, int m, int x, int y) {
	int tmp = 0;
	for(int i=n;i<x;i++) {
		for(int j=m;j<y;j++) {
			if(arr[i][j] == '1') tmp++;
		}
	}
	return tmp == 0 || tmp == (x-n)*(y-m);
}
string solve(int n, int m, int x, int y) {
	string str = "";
	if(check(n,m,(x+n)/2,(y+m)/2)) {
		str+=arr[n][m];
	}
	else {
		str+=solve(n,m,(x+n)/2,(y+m)/2);
	}
	if(check(n,(y+m)/2,(x+n)/2,y)) {
		str+=arr[n][(y+m)/2];
	}
	else {
		str+=solve(n,(y+m)/2,(x+n)/2,y);
	}
	if(check((x+n)/2,m,x,(y+m)/2)) {
		str+=arr[(x+n)/2][m];	
	}
	else {
		str+=solve((x+n)/2,m,x,(y+m)/2);
	}
	if(check((x+n)/2,(y+m)/2,x,y)) {
		str+=arr[(x+n)/2][(y+m)/2];
	}
	else {
		str+=solve((x+n)/2,(y+m)/2,x,y);
	}
	return "(" + str + ")";
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	if(check(0,0,N,N)) {
		cout<<arr[0][0]<<"\n";
	}
	else {
		cout<<solve(0,0,N,N)<<"\n";
	}
	return 0;
}
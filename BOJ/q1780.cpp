#include<bits/stdc++.h>
#define MAX 2188
using namespace std;
int arr[MAX][MAX] = {0};
int N,A,B,C;
void solve(int x, int y, int size) {
	bool flag = true;
	int a,b,c;
	a = b = c = 0;
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			if(arr[x+i][y+j] == -1) a++;
			if(arr[x+i][y+j] == 0) b++;
			if(arr[x+i][y+j] == 1) c++;
			if(arr[x][y] != arr[x+i][y+j]) {
				flag = false;
			}
		}
	}
	if(!b && !c) A++;
	if(!a && !c) B++;
	if(!a && !b) C++;
	if(!flag) {
		size/=3;
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				solve(x+size*i,y+size*j,size);	
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			cin>>arr[i][j];	
		}
	}
	A = B = C = 0;
	solve(1,1,N);
	cout<<A<<"\n"<<B<<"\n"<<C<<"\n";
}
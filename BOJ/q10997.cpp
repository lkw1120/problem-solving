#include<bits/stdc++.h>
using namespace std;
char arr[456][456];
int N;
void draw(int n, int idx) {
    if(n == 1) {
        arr[idx][idx] = '*';
        arr[idx+1][idx] = '*';
        arr[idx+2][idx] = '*';
    }
	else {
		int size = 4*(n-1)+1;
		for(int i=idx;i<size+idx;i++) {
			arr[idx][i] = '*';
			arr[idx+size+1][i] = '*';
		}
		for(int i=idx;i<size+idx+2;i++) {
			arr[i][idx] = '*';
			arr[i][idx+size-1] = '*';
		}
		arr[idx+1][idx+size-1] = ' ';
		arr[idx+2][idx+size-2] = '*';
		draw(n-1,idx+2);
	}
    return ;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
    if(N == 1) {
        cout<<"*"<<"\n";
    }
	else {
		int size = 4*(N-1)+1;
		for(int i=0;i<size+2;i++) {
			for(int j=0;j<size;j++) {
				arr[i][j] = ' ';
			}
		}
		draw(N,0);
		for(int i=0;i<size+2;i++){
			if(i == 1) {
				cout<<"*"<<"\n";
			}
			else {
				for(int j=0;j<size;j++){
					cout<<arr[i][j];
				}
				cout<<"\n";
			}
		}
	}
    return 0;
}
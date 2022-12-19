#include<bits/stdc++.h>
using namespace std;
void star(int x, int y, int n) {
    if((x/n)%3 == 1 && (y/n)%3 == 1) {
        cout<<" ";
    }
    else {
        if(n/3 == 0) {
            cout<<"*";
		}
        else {
            star(x,y,n/3);
		}
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			star(i,j,N);	
		}
		cout<<"\n";
	}
}
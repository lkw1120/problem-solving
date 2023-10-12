#include<bits/stdc++.h>
using namespace std;
int X1,Y1,X2,Y2,X3,Y3,X4,Y4;
char check() {
	if(Y4 < Y1 || X2 < X3 || Y2 < Y3 || X4 < X1) {
		return 'd';	
	}
	else if((X1 == X4 && Y1 == Y4) || (X1 == X4 && Y2 == Y3) || 
			(X2 == X3 && Y2 == Y3) || (X2 == X3 && Y1 == Y4)) {
		return 'c';
	}
	else if(X2 == X3 || Y2 == Y3 || X1 == X4 || Y1 == Y4) {
		return 'b';
	}
	return 'a';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<4;i++) {
		cin>>X1>>Y1>>X2>>Y2;
		cin>>X3>>Y3>>X4>>Y4;
		cout<<check()<<"\n";
	}
	return 0;
}
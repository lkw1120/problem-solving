#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll X1,Y1,X2,Y2,X3,Y3,X4,Y4;
char check() {
	if(Y4 < Y1 || X2 < X3 || Y2 < Y3 || X4 < X1) {
		return 'e';	
	}
	else if((X1 == X4 && Y1 == Y4) || (X1 == X4 && Y2 == Y3) || 
			(X2 == X3 && Y2 == Y3) || (X2 == X3 && Y1 == Y4)) {
		return 'a';
	}
	else if(X2 == X3 || Y2 == Y3 || X1 == X4 || Y1 == Y4) {
		return 'b';
	}
	return 'c';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>X1>>Y1>>X2>>Y2;
	cin>>X3>>Y3>>X4>>Y4;
	switch(check()) {
		case 'a':
			cout<<"POINT"<<"\n";
			break;
		case 'b':
			cout<<"LINE"<<"\n";
			break;
		case 'c':
			cout<<"FACE"<<"\n";
			break;
		default:
			cout<<"NULL"<<"\n";
			break;
	}
	return 0;
}
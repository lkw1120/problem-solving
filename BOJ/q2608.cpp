#include <bits/stdc++.h>
using namespace std;
char n[101];
char m[101];
int len1,len2,nNum,mNum,sum;
int change(char arr[101], int len) {
	int num = 0;
	for (int i=len-1;i>=0;i--) {
		switch (arr[i]) {
		case 'M':
			if(arr[i-1] == 'C')
				num+=900, i--;
			else
				num+=1000;
			break;
		case 'D':
			if(arr[i-1] == 'C')
				num+=400, i--;
			else
				num+=500;
			break;
		case 'C':
			if(arr[i-1] == 'X')
				num+=90, i--;
			else
				num+=100;
			break;
		case 'L':
			if(arr[i-1] == 'X')
				num+=40, i--;
			else
				num+=50;
			break;
		case 'X':
			if(arr[i-1] == 'I')
				num+=9, i--;
			else
				num+=10;
			break;
		case 'V':
			if(arr[i-1] == 'I')
				num+=4, i--;
			else
				num+=5;
			break;
		case 'I':
				num+=1;
			break;
		default:
			break;
		}
	}
	return num;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	cin>>m;
	len1 = strlen(n);
	len2 = strlen(m);
	nNum = change(n, len1);
	mNum = change(m, len2);
	sum = nNum + mNum;
	cout<<sum<<endl;
	while(sum > 0) {
		if(sum >= 1000)
			cout<<"M", sum-=1000;
		else if(sum >= 900)
			cout<<"CM", sum-=900;
		else if(sum >= 500)
			cout<<"D", sum-=500;
		else if(sum >= 400)
			cout<<"CD", sum-=400;
		else if(sum >= 100)
			cout<<"C", sum-=100;
		else if(sum >= 90)
			cout<<"XC", sum-=90;
		else if(sum >= 50)
			cout<<"L", sum-=50;
		else if(sum >= 40)
			cout<<"XL", sum-=40;
		else if(sum >= 10)
			cout<<"X", sum-=10;
		else if(sum >= 9)
			cout<<"IX", sum-=9;
		else if(sum >= 5)
			cout<<"V", sum-=5;
		else if(sum >= 4)
			cout<<"IV", sum-=4;
		else
			cout<<"I", sum-=1;
	}
	cout<<"\n";
    return 0;
}
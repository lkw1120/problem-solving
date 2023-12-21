#include<bits/stdc++.h>
using namespace std;
int segment[10][7] = {
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
int S;
string N;
void print(char c, int idx) {
	int x = c-'0';
	if(idx%3 == 0) {
		cout<<" ";
		if(segment[x][idx]) {
			for(int i=0;i<S;i++) {
				cout<<"-";
			}
		}
		else {
			for(int i=0;i<S;i++) {
				cout<<" ";
			}
		}
		cout<<"  ";
	}
	else {
		if(segment[x][idx]) {
			cout<<"|";
		}
		else {
			cout<<" ";
		}
		if(idx == 4 || idx == 5) {
			for(int i=0;i<S;i++) {
				cout<<" ";
			}
		}
		else {
			cout<<" ";	
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>S>>N;
	int size = N.size();
	for(int i=0;i<size;i++) {
		print(N[i],0);
	}
	cout<<"\n";
	for(int i=0;i<S;i++) {
		for(int j=0;j<size;j++) {
			print(N[j],5);
			print(N[j],1);
		}
		cout<<"\n";
	}
	for(int i=0;i<size;i++) {
		print(N[i],6);
	}
	cout<<"\n";
	for(int i=0;i<S;i++) {
		for(int j=0;j<size;j++) {
			print(N[j],4);
			print(N[j],2);
		}
		cout<<"\n";
	}
	for(int i=0;i<size;i++) {
		print(N[i],3);
	}
	cout<<"\n";
	return 0;
}
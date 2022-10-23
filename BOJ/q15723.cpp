#include<bits/stdc++.h>
#define INF 9999999
using namespace std;
int arr[26][26] = {0};
string str1,str2,tmp;
int N,M;
void preload() {
	for(int i=0;i<26;i++) {
		for(int j=0;j<26;j++) {
			if(i == j) {
				arr[i][j] = 0;	
			}
			else {
				arr[i][j] = INF;	
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	preload();
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>str1>>tmp>>str2;
		arr[str1[0]-'a'][str2[0]-'a'] = 1;
	}
	for(int j=0;j<26;j++) {
		for(int i=0;i<26;i++) {
			for(int k=0;k<26;k++) {
				if(arr[i][j] + arr[j][k] < arr[i][k]) {
					arr[i][k] = arr[i][j] + arr[j][k];
				}
			}
		}
	}
	cin>>M;
	for(int i=0;i<M;i++) {
		cin>>str1>>tmp>>str2;
		if(arr[str1[0]-'a'][str2[0]-'a'] != INF) {
			cout<<"T"<<"\n";
		}
		else {
			cout<<"F"<<"\n";	
		}
	}
	return 0;	
}
#include<bits/stdc++.h>
using namespace std;
int arr[26][200001] = {0};
string input;
char A;
int Q,L,R,ans;
void preset() {
	int size = input.size();
	arr[input[0]-'a'][1] = 1;
	for(int i=0;i<26;i++) {
		for(int j=2;j<=size;j++) {
			if(input[j-1] == (char)(i+'a')) {
				arr[i][j]+=arr[i][j-1]+1;
			}
			else {
				arr[i][j]+=arr[i][j-1];	
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	preset();
	cin>>Q;
	for(int i=0;i<Q;i++) {
		cin>>A>>L>>R;
		ans = arr[A-'a'][R+1]-arr[A-'a'][L];
		cout<<ans<<"\n";
	}
	return 0;
}
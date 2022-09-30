#include<bits/stdc++.h>
using namespace std;
string input,output;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>input;
	int size = input.size();
	input[size-1]++;
	if(input[size-1] > '9') {
		input[size-1] = '0';
		for(int i=size-2;i>=0;i--) {
			input[i]++;
			if(input[i] > '9') {
				input[i] = '0';
			}
			else {
				break;	
			}
		}
		if(input[0] == '0') {
			input = "1"+input;
		}
	}
	size = input.size();
	for(int i=0;i<size/2;i++) {
		output+=input[i];
	}
	for(int i=size%2 == 1?size/2:size/2-1;i>=0;i--) {
		output+=input[i];
	}
	if(input > output) {
		for(int i=size%2 == 1?size/2:size/2-1;i>=0;i--) {
			output[i]++;
			if(output[i] > '9') {
				output[i] = '0';	
			}
			else {
				break;	
			}
		}
		for(int i=0;i<size/2;i++) {
			output[size-1-i] = output[i];	
		}
	}
	cout<<output<<"\n";
	return 0;
}
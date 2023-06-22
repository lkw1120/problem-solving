#include<bits/stdc++.h>
using namespace std;
string input,str,ans;
int T;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>input;
		str = input;
		int size = str.size();
		for(int i=size-2;i>=0;i--) {
			bool flag = false;
			int arr[10] = {0};
			for(int j=i+1;j<size;j++) {
				arr[str[j]-'0']++;
				if(str[i] < str[j]) {
					flag = true;
				}
			}
			if(flag) {
				arr[str[i]-'0']++;
				for(int k=str[i]-'0'+1;k<10;k++) {
					if(arr[k]) {
						arr[k]--;
						str[i] = '0'+k;
						break;
					}
				}
				for(int j=i+1;j<size;j++) {
					for(int k=0;k<10;k++) {
						if(arr[k]) {
							arr[k]--;
							str[j] = '0'+k;
							break;
						}
					}
				}
				break;
			}
		}
		if(input < str) {
			ans = str;
		}
		else {
			ans = "BIGGEST";	
		}
		cout<<ans<<"\n";
	}
	return 0;
}
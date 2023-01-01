#include<bits/stdc++.h>
using namespace std;
int arr[11] = {0};
int N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
    for(int i=0;i<N;i++){
        cin>>M;
        for(int j=0;j<N;j++){
            if(M == 0 && !arr[j]) {
                arr[j] = i+1;
                break;
            }
            else if(!arr[j]){
				M--;
			}
        }
    }
    for(int i=0;i<N;i++){
        cout<<arr[i]<< " ";
    }
	cout<<"\n";
	return 0;	
}
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5+1;
int arr[MAX_N];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    bool flag = true;
    if(N == 2) {
        flag = arr[0] <= arr[1];
    }
    if(flag) {
        cout<<"YES"<<"\n";
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}
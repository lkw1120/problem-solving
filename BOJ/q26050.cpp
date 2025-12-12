#include<bits/stdc++.h>
using namespace std;
int arr[200001];
string str;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    cin>>str;
    for(int i=0;i<N;i++) {
        arr[i+1] = arr[i]+(str[i] == 'X');
    }
    int K = (int)floor(sqrt((double)N));
    ans = 0;
    for(int k=3;k<=K;k++) {
        int L = k*k;
        int border = 4*k-4;
        int inner  = (k-2)*(k-2);
        for(int i=0;i+L<=N;i++) {
            int cnt = arr[i+L]-arr[i];
            if(cnt == border || cnt == inner) {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
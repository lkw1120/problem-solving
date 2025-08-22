#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int prefix[200001];
string str;
int N,P,D,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>P>>D;
    cin>>str;
    for(int i=0;i<N*2;i++) {
        arr[i] = (str[i%N] == 'Z')? 1: 0;
    }
    for(int i=0;i<N*2;i++) {
        prefix[i+1] = prefix[i] + arr[i];
    }
    ans = 0;
    for(int i=0;i<N;i++) {
        int h = N+i;
        int l = h-P+1;
        int tmp = prefix[h+1]-prefix[l];
        if (tmp < D) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
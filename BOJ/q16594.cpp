#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 100001;
ll arr[MAX_N];
ll N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    ll mn,mx;
    mn = mx = 0;
    int tmp = min(N,M);
    for(int i=0;i<tmp;i++) {
        mn+=arr[i];
    }
    int a,b,c;
    a = N/M;
    b = N%M;
    c = a+1;
    int idx = 0;
    for(int i=0;i<b;i++) {
        mx+=arr[idx];
        idx+=c;
    }
    for(int i=0;i<M-b;i++) {
        if(0 < a) {
            mx+=arr[idx];
            idx+=a;
        }
    }
    cout<<mn<<" "<<mx<<"\n";
    return 0;
}
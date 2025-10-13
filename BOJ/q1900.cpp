#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 10001;
ll a[MAX_N],r[MAX_N];
int arr[MAX_N];
int N;
bool compare(int i, int j) {
    if(r[i] == 1 && r[j] != 1) return false;
    if(r[i] != 1 && r[j] == 1) return true;
    ll L,R;
    L = a[i]*(r[j]-1);
    R = a[j]*(r[i]-1);
    if(L != R) return L < R;
    return i < j;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>a[i]>>r[i];
        arr[i] = i;
    }
    sort(arr+1,arr+N+1,compare);
    for(int i=1;i<=N;i++) {
        cout<<arr[i]<<"\n";
    }
    return 0;
}
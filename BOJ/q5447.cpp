#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int arr[MAX];
int T,N,L,R;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
        }
        int l,r,tmp,sum;
        l = r = 1;
        tmp = sum = 0;
        for(int i=1;i<=N;i++) {
            if(0 <= tmp) {
                tmp+=arr[i];
                r = i;
            }
            else {
                tmp = arr[i];
                l = r = i;
            }
            if(sum < tmp) {
                L = l,R = r;
                sum = tmp;
            }
        }
        cout<<L<<" "<<R<<"\n";
    }
    return 0;
}
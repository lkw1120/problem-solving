#include<bits/stdc++.h>
using namespace std;
bool isPrime[10001];
int arr[10001];
int memo[10001];
int T,N,ans;
void eratosthenes() {
    fill(isPrime,isPrime+10001,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<10001;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<10001;j++) {
                isPrime[i*j] = false;
            }
        }
    }
}
bool check(int n) {
    int cap = sqrt(n);
    for(int i=2;i<=cap;i++) {
        if(isPrime[i] && n%i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>T;
    while(T--) {
        fill(arr,arr+10001,0);
        fill(memo,memo+10001,0);
        cin>>N;
        for(int i=1;i<=N;i++) {
            cin>>arr[i];
            memo[i] = memo[i-1]+arr[i];
        }
        int l,r,size;
        size = INT_MAX;
        for(int i=0;i<N;i++) {
            for(int j=i+2;j<=N;j++) {
                if(check(memo[j]-memo[i])) {
                    if(j-i < size) {
                        size = j-i;
                        l = i+1,r = j;
                    }
                }
            }
        }
        if(size != INT_MAX) {
            cout<<"Shortest primed subsequence is length "<<size<<": ";
            for(int i=l;i<=r;i++) {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        else {
            cout<<"This sequence is anti-primed."<<"\n";
        }
    }
    return 0;
}
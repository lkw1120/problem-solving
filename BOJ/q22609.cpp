#include<bits/stdc++.h>
using namespace std;
const int MAX = 200001;
bool isPrime[MAX];
vector<int> primes;
vector<int> v,vv;
int N,P,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(isPrime[i]) {
            for(int j=2;i*j<MAX;j++) {
                isPrime[i*j] = false;
            }
        }
    }
    for(int i=2;i<MAX;i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    while(1) {
        v.clear();
        vv.clear();
        cin>>N>>P;
        if(N == -1 && P == -1) break;
        int idx = upper_bound(primes.begin(),primes.end(),N) - primes.begin();
        for(int i=0;i<P;i++) {
            v.push_back(primes[idx+i]);
        }
        for(int i=0;i<P;i++) {
            for(int j=i;j<P;j++) {
                vv.push_back(v[i]+v[j]);
            }
        }
        sort(vv.begin(),vv.end());
        ans = vv[P-1];
        cout<<ans<<"\n";
    }
    return 0;
}
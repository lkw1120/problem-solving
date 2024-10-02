#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6+1;
bool isPrime[MAX];
vector<ll> v;
ll N;
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
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>N;
    for(int i=2;i<MAX;i++) {
        if(isPrime[i]) {
            while(N%i == 0) {
                N/=i;
                v.push_back(i);
            }
        }
    }
    if(N != 1) {
        v.push_back(N);
    }
    int size = v.size();
    cout<<size<<"\n";
    for(int i=0;i<size;i++) {
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
bool isPrime[MAX];
int A,B;
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
int key(vector<int> v) {
    int res = v[0];
    int size = v.size();
    for(int i=1;i<size;i++) {
        res-=v[i];
    }
    return res;
}
vector<int> pf(int n) {
    vector<int> v;
    int p = 2;
    while(1 < n) {
        if(n%p == 0) {
            v.push_back(p);
            while(n%p == 0) {
                n/=p;
            }
        }
        p++;
    }
    sort(v.begin(),v.end(),greater<int>());
    return v;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    while(1) {
        cin>>A>>B;
        if(!A && !B) break;
        vector<int> a,b;
        a = pf(A);
        b = pf(B);
        if(key(a) < key(b)) {
            cout<<"b"<<"\n";
        }
        else {
            cout<<"a"<<"\n";
        }
    }
    return 0;
}
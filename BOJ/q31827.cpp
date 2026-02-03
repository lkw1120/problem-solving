#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
bool isPrime[MAX];
vector<int> v;
int N,K;
void eratosthenes() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(!isPrime[i]) continue;
        for(int j=i*i;j<MAX;j+=i) {
            isPrime[j] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes();
    cin>>N>>K;
    for(int i=2;i<MAX && (int)v.size()<N;i++) {
        if(!isPrime[i]) continue;
        if(i%K == 1) {
            v.push_back(i);
        }
    }
    for(auto item: v) {
        cout<<item<<" ";
    }
    cout<<"\n";
    return 0;
}
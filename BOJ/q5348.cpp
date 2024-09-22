#include<bits/stdc++.h>
using namespace std;
const int MAX = 50000;
bool isPrime[MAX];
vector<int> v;
int T,N,ans;
void prime() {
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
    prime();
    cin>>T;
    while(T--) {
        v.clear();
        cin>>N;
        cout<<N<<": ";
        bool flag = true;
        for(int i=2;i<min(N,MAX);i++) {
            if(N%i == 0) flag = false;
        }
        if(flag) {
            cout<<"prime";
        }
        else {
            int n = 2;
            while(1<N) {
                if(N%n == 0) {
                    v.push_back(n);
                    N/=n;
                }
                else {
                    n++;
                }
            }
            for(auto item: v) {
                cout<<item<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1500000;
bool isPrime[MAX];
vector<int> v;
string str;
int L,H,ans;
void eratosthenes() {
    fill(isPrime,isPrime+MAX,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(isPrime[i]) {
            for(int j=i*i;j<MAX;j+=i) {
                isPrime[j]  = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratosthenes();
    cin>>L>>H;
    cin>>str;
    for(int i=2;i<MAX;i++) {
        if(isPrime[i]) v.push_back(i);
    }
    ans = 0;
    for(int i=L-1;i<H;i++) {
        string s = to_string(v[i]);
        if(s.find(str) != string::npos) {
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
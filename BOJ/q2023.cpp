#include<bits/stdc++.h>
using namespace std;
int N;
bool isPrime(int n) {
    if(n < 2) return false;
    for(int i=2;i*i<=n;i++) {
        if(n%i == 0) return false;
    }
    return true;
}
void dfs(int n, int len) {
    if(len == N) {
        cout<<n<<"\n";
        return ;
    }
    int m = n*10;
    for(int i=1;i<10;i++) {
        if(isPrime(m+i)) {
            dfs(m+i,len+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    dfs(0,0);
    return 0;
}
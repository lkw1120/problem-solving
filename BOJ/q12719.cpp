#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;
bool prime[MAX];
int parent[MAX];
int T,A,B,P;
void eratosthenes() {
    fill(prime,prime+MAX,true);
    prime[0] = prime[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(prime[i]) {
            for(int j=2;i*j<MAX;j++) {
                prime[i*j] = false;
            }
        }
    }
}
int find(int a) {
    if(parent[a] != a) {
        parent[a] = find(parent[a]);
    }
    return parent[a];
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        parent[b] = a;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>A>>B>>P;
        int n = B-A+1;
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
        for(int p=P;p<=B;p++) {
            if(!prime[p]) {
                continue;
            }
            int tmp = -1;
            for(int i=A;i<=B;i++) {
                if(i%p == 0) {
                    if(tmp == -1) {
                        tmp = i;
                    }
                    else {
                        merge(tmp-A,i-A);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i=0;i<n;i++) {
            if (find(i) == i) {
                cnt++;
            }
        }
        cout<<"Case #"<<t<<": "<<cnt<<"\n";
    }
    return 0;
}
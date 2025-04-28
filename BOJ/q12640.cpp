#include <bits/stdc++.h>
using namespace std;
int T,N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    cout<<fixed<<setprecision(6);
    for(int t=1;t<=T;t++) {
        cin>>N;
        double sum_p[3] = {};
        double sum_v[3] = {};
        for(int i=0;i<N;i++) {
            double p[3],v[3];
            cin>>p[0]>>p[1]>>p[2]>>v[0]>>v[1]>>v[2];
            for(int j=0;j<3;j++) {
                sum_p[j]+=p[j];
                sum_v[j]+=v[j];
            }
        }
        double p0[3],v[3];
        for(int i=0;i<3;i++) {
            p0[i] = sum_p[i]/N;
            v[i] = sum_v[i]/N;
        }
        double v2,dot_pv;
        v2 = dot_pv = 0.0;
        for(int i=0;i<3;i++) {
            v2+=v[i]*v[i];
            dot_pv+=p0[i]*v[i];
        }
        double t_min = 0.0;
        if(0.0 < v2) {
            double tmp = -dot_pv/v2;
            t_min = max(0.0,tmp);
        }
        double xyz[3] = {};
        for(int i=0;i<3;i++) {
            xyz[i] = p0[i]+v[i]*t_min;
        }
        double d_min = sqrt(xyz[0]*xyz[0]+xyz[1]*xyz[1]+xyz[2]*xyz[2]);
        cout<<"Case #"<<t<<": "<<d_min<<" "<<t_min<<"\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 
vll primeFactors(lli n) {
    vll factors;
    while(n%2==0){
        factors.push_back(2LL);
        n/=2;
    }
    for(lli i=3;i*i<=n;i+=2){
        while(n%i==0) {
            factors.push_back(i);
            n/=i;
        }
    }
    if(n>1){
        factors.push_back(n);
    }
    return factors;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
        }
        else{
            vll factors = primeFactors(n);
            if(factors.empty()) cout<<1<<" "<<n-1<<endl;
            else{
                cout<<n/factors[0]<<" "<<n-n/factors[0]<<endl;
            }
        }
    }
    return 0;
}
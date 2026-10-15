#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define sor(x) sort(all(x))
#define setbits(x) __builtin_popcountll(x)
#define bitlen(x) 64-__builtin_clzll(x)
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vector<pair<pair<lli,lli>,lli>> v(n),pos,neg;
        f(i,n){
            lli x,y;
            cin>>x>>y;
            v[i].first.first=x;
            v[i].first.second=y;
            v[i].second=i+1;
        }
        sor(v);
        
        f(i,n){
            if(i<n/2) neg.push_back(v[i]);
            else pos.push_back(v[i]);
        }

        sort(all(pos),[](auto &A, auto &B){
            return A.first.second < B.first.second;
        });
        sort(all(neg),[](auto &A, auto &B){
            return A.first.second < B.first.second;
        });

        reverse(all(pos));

        f(i,n/2){
            cout<<neg[i].second<<" "<<pos[i].second<<endl;
        }
    }
    return 0;
    
}
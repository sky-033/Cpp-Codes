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
const lli N=2e5+10;
const lli M=1e9+7; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    while(q--){
        map<lli,lli> hsh;
        lli n;
        cin>>n;
        vll a(n);
        f(i,n){
            cin>>a[i];
            hsh[a[i]]++;
        }
        sor(a);
        lli ans=0;
        vll freq;
        fa(hsh){
            freq.push_back(it.second);
        }
        sor(freq);
        reverse(all(freq));
        ff(1,freq.size(),1){
            if(freq[i]==freq[i-1]){
                freq[i]=max(0LL,freq[i-1]-1);
            }
        }
        fa(freq) ans+=it;
        cout<<ans<<endl;
    }
    return 0;
}
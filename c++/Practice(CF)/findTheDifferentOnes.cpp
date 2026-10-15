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
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
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
        vll a(n+1),op(n+1);
        ff(1,n,1) cin>>a[i];
        op[1]=-1;
        ff(2,n+1,1){
            if(a[i]==a[i-1]) op[i]=op[i-1];
            else op[i]=i-1;
        }
        lli q;
        cin>>q;
        while(q--){
            lli l,r;
            cin>>l>>r;
            if(op[l]==op[r]){
                cout<<-1<<" "<<-1<<endl;
            }
            else{
                lli val1=a[l];
                lli val2=a[r];
                if(val1!=val2){
                    cout<<l<<" "<<r<<endl;
                }
                else{
                    lli indx=lower_bound(all(op),r)-op.begin();
                    cout<<l<<" "<<indx-1<<endl;
                }
            }
        }
    }
    return 0;
}
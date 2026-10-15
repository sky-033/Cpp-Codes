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
        lli k,x;
        cin>>k>>x;
        lli maxi=k*k;
        if(maxi<=x){
            cout<<2*k-1<<endl;
        }
        else{
            lli val=k*k-k;
            val/=2;
            val+=k;
            if(val>=x){
                lli l=1,h=k,mid;
                while(h-l>1){
                    mid=(l+h)/2;
                    lli emote=mid*(mid+1)/2;
                    if(emote>=x) h=mid;
                    else l=mid+1;
                }
                lli l1=l*(l+1)/2,h1=h*(h+1)/2;
                if(l1-x>=0) cout<<l<<endl;
                else cout<<h<<endl;
            }
            else{
                x-=val;
                lli l=1,h=k-1,mid;
                lli emotes=h*(h+1)/2;
                while(h-l>1){
                    mid=(l+h)/2;
                    lli emote=emotes-mid*(mid-1)/2;
                    if(emote<=x) h=mid;
                    else l=mid;
                }
                // cout<<l<<" "<<h<<endl;
                lli h1=emotes-h*(h-1)/2,l1=emotes-l*(l-1)/2;
                if(h1-x>=0) cout<<k+(k-h)<<endl;
                else cout<<k+(k-l)<<endl;
            }
        }
    }
    return 0;
}
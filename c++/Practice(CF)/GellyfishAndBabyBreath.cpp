#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
const lli N=1e5+10;
const lli M=998244353; 

vll pow2(N);
void solve(){
    pow2[0]=1;
    ff(1,N,1){
        pow2[i]=(pow2[i-1]*2)%M;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    int t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vll p(n),q(n),p1(n),q1(n);
        f(i,n) cin>>p[i];
        f(i,n) cin>>q[i];
        lli h=1,i=0;
        p1[0]=0,q1[0]=0;
        while(h<n){
            if(p[h]>p[i]){
                i=h;
                p1[h]=i;
                h++;
            }
            else{
                p1[h]=i;
                h++;
            }
        }
        lli h1=1,j=0;
        while(h1<n){
            if(q[h1]>q[j]){
                j=h1;
                q1[h1]=j;
                h1++;
            }
            else{
                q1[h1]=j;
                h1++;
            }
        }
        vll r(n);
        ff(0,n,1){
            lli indx1=p1[i];
            lli indx2=q1[i];
            if(p[indx1]>q[indx2]){
                r[i]=(pow2[p[indx1]]+pow2[q[i-indx1]])%M;
            }
            else if(p[indx1]<q[indx2]){
                r[i]=(pow2[p[i-indx2]]+pow2[q[indx2]])%M;
            }
            else{
                lli x=p[indx1];
                lli y=max(q[i-indx1],p[i-indx2]);
                r[i]=(pow2[x]+pow2[y])%M;
            }
        }
        f(i,n) cout<<r[i]<<" ";
        cout<<endl;
    }
    return 0;
}
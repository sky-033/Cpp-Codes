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
        vll a(n);
        f(i,n) cin>>a[i];
        sor(a);
        lli maxi=-1;
        ff(1,n,1){
            if(a[i]==a[i-1]) maxi=max(maxi,a[i]);
        }
        lli ct=0;
        vll run;
        f(i,n){
            if(a[i]==maxi && ct<2){
                ct++;
            }
            else{
                run.push_back(a[i]);
            }
        }
        bool flag=false;
        if(maxi!=-1){
            f(i,n-2){
                lli val=maxi*2+run[i];
                lli indx=lower_bound(run.begin()+i,run.end(),val)-run.begin();
                if(indx-1!=i){
                    flag=true;
                    cout<<maxi<<" "<<maxi<<" "<<run[i]<<" "<<run[indx-1]<<endl;
                    break;
                }
            }
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}
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
const lli N=51;
const lli M=1e9+7; 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        lli n,q;
        cin>>n>>q;
        vll a(n),t(q);
        f(i,n) cin>>a[i];
        f(i,q) cin>>t[i];
        vll first_occurrence(51, 0); 
        f(i,n){
            if(first_occurrence[a[i]] == 0){
                first_occurrence[a[i]] = i+1; 
            }
        }
        f(i,q){
            cout<<first_occurrence[t[i]]<<" ";
            lli tick=first_occurrence[t[i]];
            if(tick!=1){
                g(j,51){
                    if(j==t[i]) first_occurrence[t[i]]=1;
                    else if(first_occurrence[j]!=0 && first_occurrence[j]<tick) first_occurrence[j]++;
                }
            }
        }
    
    return 0;
}
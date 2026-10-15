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
const lli N=2e5+10;
const lli M=1e9+7; 
vll removeDuplicates(vll &vec) {
    unordered_set<lli> seen;
    vll result;
    
    for (int num : vec) {
        // If insertion succeeds (element not seen before)
        if (seen.insert(num).second) {
            result.push_back(num);
        }
    }
    
    return result;
}

vll pow2(31);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pow2[0]=1;
    ff(1,31,1){
        pow2[i]=2*pow2[i-1];
    }
    int t;
    cin>>t;
    while(t--){
        lli n,q;
        cin>>n>>q;
        vll a(n),x(q);
        f(i,n) cin>>a[i];
        f(i,q){
            cin>>x[i];
            x[i]=pow2[x[i]];
        }
        vll new1=removeDuplicates(x);
        f(i,new1.size()){
            g(j,n){
                if(a[j]%new1[i]==0){
                    a[j]+=new1[i]/2;
                }
            }
        }
        f(i,n) cout<<a[i]<<" ";
        cout<<endl;
        
    }
    return 0;
}
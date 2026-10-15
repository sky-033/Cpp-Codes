#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
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
        vll a(n),suffix_sum(n),ans,maxiVec;
        f(i,n) cin>>a[i];
        suffix_sum[n-1]=a[n-1];
        fb(n-1,0,1){
            suffix_sum[i]=suffix_sum[i+1]+a[i];
        }
        lli l=0,h=1;
        maxiVec.push_back(a[0]);
        while(h<n){
            if(a[h]>=a[l]){
                maxiVec.push_back(a[h]);
                l=h;
                h++;
            }
            else{
                maxiVec.push_back(a[l]);
                h++;
            }
        }
        rf(i,n){
            lli sum=suffix_sum[i]-a[i]+maxiVec[i];
            if(sum>suffix_sum[i]) ans.push_back(sum);
            else ans.push_back(suffix_sum[i]); 
        }
        f(i,n) cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
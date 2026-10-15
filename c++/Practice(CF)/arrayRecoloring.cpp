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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        vll a(n);
        f(i,n) cin>>a[i];
        lli sum=0;
        lli indx=max_element(a.begin(),a.end())-a.begin();
        if(k==1 && (indx!=0 && indx!=n-1)){
            sum=*max_element(a.begin(),a.end());
            sum+=max(a[0],a[n-1]);
        }
        else{
            sort(a.begin(),a.end());
            k++;
            lli h=n-1;
            while(k>0){
                sum+=a[h];
                h--;
                k--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
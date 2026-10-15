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
        lli n,k;
        cin>>n>>k;
        vll a(n);
        lli sum=0;
        f(i,n){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(),a.end());
        vll mini,maxi;
        ff(0,2*k,2){
            mini.push_back(a[i]+a[i+1]); //mini ka pair ko add
        }
        for(lli i=n-1;i>=n-k;i--){
            maxi.push_back(a[i]); //maxi ko add
        }
        ff(1,k,1){
            mini[i]+=mini[i-1]; //prefix sum
            maxi[i]+=maxi[i-1]; //prefix sum
        }
        lli sum_mini=mini[k-1]; //mini ka pair ka total sum
        lli sum_maxi=maxi[k-1]; // maxi ka total sum
        mini.pop_back(),maxi.pop_back(); // last wala hatao dono se
        reverse(mini.begin(),mini.end()); //reverse karke kisi ek ko add krna hai
        vll ans; // isme sara required sum se jitna minus hoga wo wala sab value hoga
        f(i,k-1){
            ans.push_back(mini[i]+maxi[i]);
        }
        ans.push_back(sum_mini);
        ans.push_back(sum_maxi);
        lli final_ans=*min_element(ans.begin(),ans.end());
        cout<<sum-final_ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define fa(v) for (auto &it : v) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        lli n,k;
        cin>>n>>k;
        lli low=1,high=n-1;
        if(n%k!=0){
            cout<<1<<endl;
            cout<<n<<endl;
        }
        else{
            while(low<=high){
                if(high%k!=0 && low%k!=0){
                    cout<<2<<endl;
                    cout<<high<<" "<<low<<endl;
                    break;
                }
                else{
                    low++;
                    high--;
                }
            }
        }
        
        
    }
    return 0;
}
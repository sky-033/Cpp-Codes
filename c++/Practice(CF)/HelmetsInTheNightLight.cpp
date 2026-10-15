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
        lli n,p;
        cin>>n>>p;
        vp freq(n);
        vll a(n),b(n);
        f(i,n) cin>>a[i];
        f(i,n) cin>>b[i];
        f(i,n){
            freq[i].first=a[i];
            freq[i].second=b[i];
        }
        sort(freq.begin(), freq.end(), [](pair<lli, lli> &a, pair<lli, lli> &b) {
             return a.second < b.second;
                
        });
        lli take=p*n;
        lli rem=n-1;
        // f(i,n){
        //     cout<<freq[i].first<<" "<<freq[i].second<<endl;
        // }
            // n--;
            lli ans=0;
            // lli indx=-1;
           
                for(lli i=0;i<freq.size() && rem>0;i++){
                    if(p<=freq[i].second){
                        break;
                    //     ans+=p*n;
                    //     n=-1;
                    }
                    lli indx=min(rem,freq[i].first);
                        ans+=indx*freq[i].second;
                        rem-=indx;
                        
                        
                    
                
            }
            // if(indx!=-1) ans+=(n*freq[indx].second);
            ans+=((rem+1)*p);
            cout<<min(ans,take)<<endl;

        
    }
    return 0;
}


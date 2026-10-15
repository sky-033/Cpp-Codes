#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fa(v) for (auto &it : v) 
const lli N=4e5+10; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        unordered_map<char,lli> freq;
        lli n;
        cin>>n;
        string s;
        cin>>s;
        lli ans=0,a=1;
        f(i,n){
            if(freq[s[i]]==0){
                freq[s[i]]++;
                ans+=a;
                a++;
            }
            else{
                ans+=(a-1);
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// #define lli long long
// #define vll vector<lli>
// #define vvll vector<vector<lli>>
// #define vp vector<pair<lli,lli>>
// #define f(i,n) for(lli i=0;i<n;i++)
// #define fa(v) for (auto &it : v) 

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     cin>>t;
//     while(t--){
//         lli n;
//         cin>>n;
//         string s;
//         cin>>s;
//         lli maxi=1;
//         lli l=0,r=1;
//         for(lli i=0;i<n;i++){
//             for(lli j=i+1;j<n;j++){
//                 if(s[i]==s[j]){
//                     maxi=max(j-i+1,maxi);
//                 }
//                 else break;
//             }
//         }
//         cout<<maxi+1<<endl;
//     }
//     return 0;
// }

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
        lli n;
        cin>>n;
        string s;
        cin>>s;
        lli maxi=2;
        lli l=0,r=1;
        while(r<n){
            if(s[l]==s[r]){
                r++;
            }
            else{
                l=r;
                r++;
                
                // r++;
            }
            maxi=max(maxi,r-l+1);
        }
        cout<<maxi<<endl;
    }
    return 0;
}
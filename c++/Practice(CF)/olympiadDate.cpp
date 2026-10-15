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
//         int n;
//         cin>>n;
//         vector<int> a(n);
//         for(int i=0;i<n;i++){
//             cin>>a[i];
//         }
//         int ct0=0,ct1=0,ct2=0,ct3=0,ct5=0;
//         bool flag=false;
//         f(i,n){
//             if(a[i]==0) ct0++;
//             else if(a[i]==1) ct1++;
//             else if(a[i]==2) ct2++;
//             else if(a[i]==3) ct3++;
//             else if(a[i]==5) ct5++;
//             if(ct0>=3 && ct1>=1 && ct2>=2 && ct3>=1 && ct5>=1){
//                 cout<<i+1<<endl;
//                 flag=true;
//                 break;
//             }
//         }
//         if(flag==false) cout<<0<<endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
        
        int arr[n];
        int hash[10] = {0};

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            hash[arr[i]]++;
            
            if (hash[0] >= 3 && hash[1] >= 1 && hash[2] >= 2 && hash[3] >= 1 && hash[5] >= 1) {
                cout << i + 1 << endl;
                break;
            }
        }
        
       
    }
 
    return 0;
}
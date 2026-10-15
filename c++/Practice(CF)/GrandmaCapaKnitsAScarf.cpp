#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define vll vector<lli>
#define vvll vector<vector<lli>>
#define vp vector<pair<lli,lli>>
#define f(i,n) for(lli i=0;i<n;i++)
#define g(j,n) for(lli j=0;j<n;j++)
#define h(k,n) for(lli k=0;k<n;k++)
#define rf(i,n) for(lli i=n-1;i>=0;i--)
#define ff(a,b,c) for(lli i=a;i<b;i+=c)
#define fb(a,b,c) for(lli i=a-1;i>=b;i-=c)
#define fa(v) for (auto &it : v) 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define setbits(x) __builtin_popcountll(x)
const lli N=2e5+10;
const lli M=1e9+7; 
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }

    return true;
}
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
        bool flag=isPalindrome(s);
        lli mini=1e9;
        if(flag){
            mini=0;
        }
        else{
            f(i,26){
            lli ct=0;
            lli l=0,h=n-1;
            while(l<h){
                if(s[l]!=s[h]){
                    if(s[l]==char(97+i)){
                        l++;
                        ct++;
                    }
                    else if(s[h]==char(97+i)){
                        h--;
                        ct++;
                    }
                    else{
                        ct=0;
                        break;
                    }
                }
                else{
                    l++,h--;
                }
            }
            if(ct!=0){
                mini=min(mini,ct);
            }
        }
        if(mini==1e9) mini=-1;
        }
        cout<<mini<<endl;
    }
    return 0;
}
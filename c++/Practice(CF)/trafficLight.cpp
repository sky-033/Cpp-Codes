
#include<bits/stdc++.h>
using namespace std;
#define lli long long

int main(){
    int t;
    cin >> t;
    while(t--){
        lli n;
        cin >> n;
        char c;
        cin >> c;
        string s;
        cin >> s;

        vector<lli> g;
        for(lli i = 0; i < n; i++){
            if(s[i] == 'g') g.push_back(i);
        }

        lli ans = 0;
        for(lli i = 0; i < n; i++){
            if(s[i] == c){
                
                auto it = lower_bound(g.begin(), g.end(), i);
                lli dist;
                if(it != g.end()){
                    dist = *it - i;
                } else {
                    dist = n - i + g[0];
                }
                ans = max(ans, dist);
            }
        }

        cout << ans << endl;
    }
    return 0;
}
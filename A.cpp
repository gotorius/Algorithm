#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    map<int,char> mp;
    mp[10] = 'A', mp[11] = 'B', mp[12] = 'C', mp[13] = 'D', mp[14] = 'E', mp[15] = 'F';
    int cnt = n / 16;
    int cnt2 = n % 16;
    string ans = "";
    if(cnt > 9) ans += mp[cnt];
    else ans += to_string(cnt);
    if(cnt2 > 9) ans += mp[cnt2];
    else ans += to_string(cnt2);
    cout << ans << endl;
    return 0;
}
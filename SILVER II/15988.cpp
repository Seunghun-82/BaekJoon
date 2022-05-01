//
//  main.cpp
//  BaekJoon
//
//  Created by seunghun on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<long long int, int> a, pair<long long int, int> b) {
    return a.first < b.first;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int T, N;
    cin >> T;
    
    vector<long long int> dp(1000001, -1);
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    int max = 3;
    
    while(T--){
        
        cin >> N;
        if(N > max){
            for(int i = max + 1; i <= N; i++){
                dp[i] = (((dp[i - 1] + dp[i - 2]) % 1000000009) + dp[i - 3] ) % 1000000009;
            }
            max = N;
            cout << dp[N] % 1000000009 << "\n";
        }
        else{
            cout << dp[N] % 1000000009 << "\n";
        }
        
    }
    
    
    
    return 0;
    
}
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
    
    int N;
    
    cin >> N;
    
    vector<int> pack;
    
    pack.push_back(0);
    
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        pack.push_back(tmp);
    }
    
    vector<int> dp;
    
    dp.push_back(0);
    dp.push_back(pack[1]);
    
    for(int i = 2; i <= N; i++){
        int max_v;
        for(int j = 1; j <= i - 1; j++){
            max_v = max(dp[j] + dp[i - j], max_v );
        }
        dp.push_back(max(max_v, pack[i]));
    }
    
    cout << dp[N] << "\n";
    
    return 0;
    
}
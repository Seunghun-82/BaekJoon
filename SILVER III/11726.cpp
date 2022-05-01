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
    
    vector<int> dp;
    
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(2);
    
    for(int i = 3; i <= N; i++){
        dp.push_back((dp[i - 1] % 10007) + (dp[i - 2] % 10007) % 10007);
    }
    
    cout << (dp[N] % 10007) << "\n";
    
    return 0;
    
}
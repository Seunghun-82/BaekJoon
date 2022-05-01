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

int dp[201][201];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    
    cin >> N >> K;
    
    for(int i = 0; i <= 200; i++){
        for(int j = 0; j <= 200; j++){
            if(j == 1 || i == 0){
                dp[i][j] = 1;
            }
            else if(i == 1){
                dp[i][j] = j;
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 2; j <= 200; j++){
            dp[i][j] = ((dp[i - 1][j] % 1000000000) + (dp[i][j - 1] % 1000000000) % 1000000000);
        }
    }
    
    cout << dp[N][K] % 1000000000 << "\n";
    
    return 0;
    
}
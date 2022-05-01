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
    
    int N;
    
    scanf("%d", &N);
    
    long long int dp[1001][10] = {0,};
    for(int i = 0; i < 10; i++){
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < j + 1; k++){
                dp[i][j] += dp[i - 1][k] ;
            }
            dp[i][j] = dp[i][j] % 10007;
        }
    }
    
    long long int output = 0;
    
    for(int i = 0; i < 10; i++){
        output += dp[N][i];
    }
    
    printf("%lld\n", output % 10007);
    
    return 0;
}
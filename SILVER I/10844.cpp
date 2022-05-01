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
    
    vector<long long int> dp[10];
    
    dp[0].push_back(0);
    for(int i = 1; i < 10; i++){
        dp[i].push_back(1);
    }
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0){
                dp[j].push_back(dp[j + 1][i - 1] % 1000000000);
            }
            else if(j == 9){
                dp[j].push_back(dp[j - 1][i - 1] % 1000000000);
            }
            else{
                dp[j].push_back((dp[j + 1][i - 1] + dp[j - 1][i - 1]) % 1000000000);
            }
        }
    }
    
    long long int sum = 0;
    
    for(int i = 0 ; i < 10; i++){
        sum += dp[i][N - 1];
        sum = sum % 1000000000;
    }
    
    cout << sum % 1000000000 << "\n";
    
    return 0;
    
}
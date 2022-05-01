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
    
    vector<int> arr;
    vector<int> dp;
    
    dp.push_back(-10000000);
    arr.push_back(0);
    
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        dp.push_back(-10000000);
    }
    
    arr.push_back(-10000000);
    
    int sum = 0;
    
    for(int i = 1; i <= N; i++){
        int tmp_sum = sum;
        sum += arr[i];
        
        if(tmp_sum > sum){
            
            dp[i] = max(dp[i - 1], sum);
            
            if(sum < 0){
                sum = 0;
            }
        }
        else{
            dp[i] = max(dp[i - 1], sum);
        }
        
    }
    
    cout << dp[N] << "\n";
    
    return 0;
    
}
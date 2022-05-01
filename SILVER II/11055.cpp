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
    
    arr.push_back(0);
    dp.push_back(0);
    
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
        dp.push_back(tmp);
    }
    
    int max_v = dp[1];
    
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            if(arr[i] < arr[j]){
                dp[j] = max(dp[j], dp[i] + arr[j]);
                max_v = max(dp[j], max_v);
            }
        }
    }
    
    cout << max_v << "\n";
    
    return 0;
    
}
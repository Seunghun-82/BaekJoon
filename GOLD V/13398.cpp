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
    
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    vector<int> dp[2];
    
    int ans = arr[0];
    
    for(int i = 0; i < N; i++){
        if(i == 0){
            dp[0].push_back(arr[0]);
            dp[1].push_back(0);
            continue;
        }
        else{
            dp[0].push_back(max(dp[0][i - 1] + arr[i], arr[i]));
            dp[1].push_back(max(dp[1][i - 1] + arr[i], dp[0][i - 1]));
            
            ans = max(max(dp[0][i], dp[1][i]), ans);
            
        }
    }
    
    cout << ans << "\n";
    
    return 0;
    
}
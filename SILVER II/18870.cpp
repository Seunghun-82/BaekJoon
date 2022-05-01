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
    
    vector<pair<long long int, int>> num;
    
    for(int i = 0; i < N; i++){
        long long int tempt;
        scanf("%lld", &tempt);
        num.push_back(make_pair(tempt, i));
    }
    
    sort(num.begin(), num.end(), compare);
    
    vector<int> output(N);
    int count = 0;
    
    output[num[0].second] = count;
    
    for(int i = 1; i < N; i++){
        if(num[i - 1].first == num[i].first){
            output[num[i].second] = count;
        }
        else{
            count++;
            output[num[i].second] = count;
        }
    }
    
    for(int i = 0; i < N; i++){
        printf("%d ", output[i]);
    }
    
    printf("\n");
    
    return 0;
}
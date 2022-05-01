//
//  main.cpp
//  BaekJoon
//
//  Created by seunghun on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int N;
    
    scanf("%d", &N);
    
    vector<int> P;
    
    for(auto i = 0; i < N; i++){
        int tempt;
        scanf("%d", &tempt);
        P.push_back(tempt);
    }
    
    sort(P.begin(), P.end(), compare);
    
    long long int output =0;
    
    for(auto i = 0; i < N; i++){
        output = output + P[i] * (i+1);
    }
    
    printf("%lld\n", output);
    
    return 0;
}
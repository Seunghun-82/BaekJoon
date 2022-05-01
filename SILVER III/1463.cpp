//
//  main.cpp
//  BaekJoon
//
//  Created by seunghun on 2022/03/10.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define INT_MAX 2147483647

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int X;
    int output = 0;
    
    scanf("%d", &X);
    
    vector<int> num(X + 1);
    
    num[0] = 0;
    num[1] = 0;
    
    for(auto i = 2; i < X + 1; i++){
        int first, second, third;
        first = INT_MAX;
        second = INT_MAX;
        third = num[i - 1] + 1;
        if(i % 3 == 0){
            first = num[i / 3] + 1;
        }
        if(i % 2 == 0){
            second = num[i / 2] + 1;
        }
        num[i] = min(first, min(second, third));
    }
    
    
    printf("%d\n", num[X]);
    
    return 0;
}
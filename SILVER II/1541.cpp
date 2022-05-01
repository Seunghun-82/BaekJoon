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

bool compare(int a, int b) {
    return a > b;
}

int main() {
    
    string input;
    cin >> input;
    
    vector<int> num;
    vector<char> partition;
    
    for(auto i = 0; i < input.size(); i++){
        if(input[i] == '+' || input[i] == '-'){
            partition.push_back(input[i]);
        }
        else{
            int tempt = 0;
            for(auto j = 0; j < 5; j++){
                if(i + j >= input.size()){
                    i += j - 1;
                    break;
                }
                if(input[i + j] == '+' || input[i + j] == '-'){
                    i += j - 1;
                    break;
                }
                else{
                    tempt = tempt * 10 + (input[i + j] - '0');
                }
                if(j == 4){
                    i += j;
                }
            }
            num.push_back(tempt);
        }
    }
    int output = num[0];
    
    bool adder = true;
    
    for(auto i = 1; i < num.size(); i++){
        if(partition[i - 1] == '-'){
            adder = false;
        }
        if(adder){
            output += num[i];
        }
        else{
            output -= num[i];
        }

    }
    
    printf("%d\n", output);
    
    return 0;
}
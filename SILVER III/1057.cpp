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

bool compare(long long int a, long long int b) {
    return a > b;
}

int main() {

    int N, J, H;
    
    scanf("%d %d %d", &N, &J, &H);
    
    int output = 0;
    while(1){
        
        output++;
        
        if(J % 2 == 1 && H % 2 == 0){
            if(J + 1 == H){
                break;
            }
        }
        else if(H % 2 == 1 && J % 2 == 0){
            if(H + 1 == J){
                break;
            }
        }
        
        if(J % 2 == 1){
            if(J == 1){
                J = 1;
            }
            else{
                J = J / 2 + 1;
            }
        }
        else{
            J = J / 2;
        }
        if(H % 2 == 1){
            if(H == 1){
                H = 1;
            }
            else{
                H = H / 2 + 1;
            }
        }
        else{
            H = H / 2;
        }
        
    }
    
    printf("%d\n", output);

    
}
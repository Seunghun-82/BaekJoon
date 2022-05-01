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

vector<long long int> num;

bool compare(long long int a, long long int b) {
    return a > b;
}

int main() {

    long long int N , M;

    scanf("%lld %lld\n", &N, &M);

    for (int i = 0; i < N; i++) {
        long long int tempt;
        scanf("%lld", &tempt);
        num.push_back(tempt);
    }

    sort(num.begin(), num.end(), compare);
    
    long long int accum = 0;
    long long int height = 0;
    bool check = false;

    for (long long int i = 1; i < N; i++) {
        if (accum + (num[i - 1] - num[i]) * i >= M) {
            long long int need = M - accum;
            if (need % i == 0) {
                height = height + need / i;
            }
            else {
                height = height + need / i + 1;
            }
            check = true;
            break;
        }
        else {
            accum = accum + i * (num[i - 1] - num[i]);
            height = height + num[i - 1] - num[i];
        }
    }
    
    if(check == false){
        long long int need = M - accum;
        if (need % N == 0) {
            height = height + need / N;
        }
        else {
            height = height + need / N + 1;
        }
    }
    

    printf("%lld\n", num[0] - height);

    return 0;
}
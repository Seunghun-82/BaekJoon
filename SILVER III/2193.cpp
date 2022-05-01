#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N;

	scanf("%d", &N);

	vector<long long int> dp_0(N + 1);
	vector<long long int> dp_1(N + 1);
	dp_1[1] = 1;
	dp_0[1] = 0;
	for (int i = 2; i <= N; i++) {
		dp_1[i] = dp_0[i - 1];
		dp_0[i] = dp_0[i - 1] + dp_1[i - 1];
	}

	printf("%lld\n", dp_0[N] + dp_1[N]);

	return 0;
}
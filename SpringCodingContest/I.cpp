#include <iostream>

typedef long long LL;

#define MAXQ 1000010

LL answers[MAXQ];
int main() {
    LL q;
    std::cin >> q;

    LL a;
    std::cin >> a;

    for (int i = 1; i < MAXQ; i++) {
        for (int j = 2*i; j < MAXQ; j += i) {
            answers[j] += i;
        }
    }

    LL solution = 0;
    for (int i = 0; i < q; i++) {
        solution += answers[a];
        a = ((a*a) % 999983) + 1;
    }

    std::cout << solution << std::endl;
}

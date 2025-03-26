// 백준 G_5_11729

#include <iostream>

void hanoi(int n, int from, int by, int to) {
    if (n == 1) { std::cout << from << ' ' << to << '\n'; } else {
        hanoi(n - 1, from, to, by);
        std::cout << from << ' ' << to << '\n';
        hanoi(n - 1, by, from, to);
    }
}

int hanoiCnt(int n) {
    if (n == 1) return 1;
    return 2 * hanoiCnt(n - 1) + 1;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << hanoiCnt(n) << '\n';
    hanoi(n, 1, 2, 3);
}

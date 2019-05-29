#include <iostream>
#include <cmath>

int main(){
    int n, p;
    int sum = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++){
        std::cin >> p;
        sum += pow(p, i);
    }
    std::cout << sum << std::endl;
    return 0;
}
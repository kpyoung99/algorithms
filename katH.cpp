#include <iostream>
int main(){
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; i++){
        std::cin >> n;
        if (n == 1) n = 1;
        else{
            n *= i;
            n %= 10;
        }
        std::cout << n << std::endl;
    }
    return 0;
}
#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int temps[n];
    int frz = 0;
    for (int i = 0; i < n; i++){
        std::cin >> temps[i];
        if (temps[i] < 0)
            frz++;
    }
    std::cout << frz << std::endl;
    return 0;
}
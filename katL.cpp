#include <iostream>

int main(){
    int p, k, n;
    std::cin >> p;
    for (int i = 0; i < p; i++){
        std::cin >> k >> n;
        int s1 = n * (n + 1) / 2;
        int s2 = n * n;
        int s3 = n * (n + 1);
        std::cout << k << " " << s1 << " " << s2 << " " << s3 << std::endl;
    }
    return 0;
}
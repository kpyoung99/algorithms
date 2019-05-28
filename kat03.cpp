#include <iostream>
int quad(int x, int y){
    if(x > 0 && y > 0)  return 1;
    if(x < 0 && y > 0)  return 2;
    if(x < 0 && y < 0)  return 3;
    else    return 4;
}

int main(){
    int x, y, num;
    std::cin>> x;
    std::cin>> y;
    num = quad(x, y);
    std::cout<< num << std::endl;
    return 0;
}
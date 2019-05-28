#include <iostream>
int main(){
    int num, temps, numDays;
    std::cin >> num;
    std::cin >> temps;
    numDays = days();
    std::cout << numDays << std::endl;
    return 0;
}

int days(int num, int[] ){
    int days = 0;
    for (int i = 0; i < num; i++){
        if(temp < 0)    days++;
    }
    return days;
}
#include <iostream>
int nonDom(char c){
    switch(c){
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            return 2;
        case 'T':
            return 10;
    }
    return 0;
}
int dom(char c){
        switch(c){
        case 'A':
            return 11;
        case 'K':
            return 4;
        case 'Q':
            return 3;
        case 'J':
            return 20;
        case 'T':
            return 10;
        case '9':
            return 14;
    }
    return 0;
}
int main(){
    int hand;
    std::cin >> hand;
    char trump, num, suit;
    std::cin >> trump;
    int sum = 0;

    while(std::cin>>num && std::cin>>suit){
        if (suit == trump)
            sum += dom(num);
        else
            sum += nonDom(num);
    }

    std::cout << sum << std::endl;    
    return 0;
}
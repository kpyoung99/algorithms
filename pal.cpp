#include <iostream>

int main(){
    std::cout << "Enter a word to check if it is a palindrome" << std::endl;
    char *word;
    std::cin >> word;
    std::cout << pal(word) << std::endl;
    return 0;
}


bool pal(char* str){
    //Get length of str
    unsigned int length = 0;
    for(length; str[length]; ++length){

    for (int i = 0; i < length / 2; ++i){
        if (str[i] != str[length - i - 1]) return false;
    }      
    return true;
}


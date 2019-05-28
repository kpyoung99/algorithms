#include <iostream>
#include "string.hpp"

String::String(){
    array = new char[1];
    array[0] = '\0';
}

String::String(const char *str){
    unsigned int length = 0;
    for(length; str[length]; ++length);

    //Initialize our array
    array = new char[length] + 1;
    for (int i = 0; i <= length; ++i)
        array[i] = str[i];
}

String::~String(){
    delete[] array;
}

unsigned int String::length(){
    //if maintained length, return length;
    unsigned int length = 0;
    for(length; array[length]; ++length);
    return length;
}

void String::append(const char c){
    //Get length
    unsigned int length = this->length();
    //Create a new array
    char *new_arr = new char[length + 2];
    //Copy it over
    for(int i = 0; i < length; ++i) new_arr[i] = array[i];
    new_arr[length] = c;
    new_arr[length + 1] = '\0';
    //Free memory and set our new address up
    delete[] array;
    array = new_arr;
}

void String::reverse(){
    
}

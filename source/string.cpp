#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "string.hpp"

/* Constructors */
String::String() {
  // Allocate space.
  array = new char[1];
  // Add the null.
  array[0] = '\0';
  // Adjust private variables.
  _capacity = 0;
}

String::String(char c) {
  // Allocate space.
  array = new char[2];
  // Add the character and the null.
  array[0] = c;
  array[1] = '\0';
  // Adjust private variables.
  _capacity = 1;
}

String::String(char* str) {
  // Get the length of the incoming string.
  int length = 0;
  while (str[length])
    ++length;
  // Allocate space for the string plus a null.
  array = new char[length + 1];
  // Fill our array up, including the null.
  for (int i = 0; i <= length; ++i)
    array[i] = str[i];
  // Adjust private variables.
  _capacity = length;
}

/* Destructor */
String::~String() {
  delete[] array;
}

/* Methods Implementation */
char String::at(int idx) const{
    //Check if index out of bounds
    if (idx < 0 || idx >= size())
        throw "bad index";
    //Return character at index
    return array[idx];
}

bool String::empty() const{
    //If array size = 0, its empty
    if (size() == 0)  
        return true;
}

unsigned int String::size() const{
    int _size = 0;
    //While there are characters in the array at idx
    for (size_t i = 0; array[i]; i++){
        //increment size count
        _size++;
    }
    return _size;
}

unsigned int String::capacity() const{
    return size();
}

void String::reserve(unsigned int extra){
    //Create length of new array as current size + extra
    int ext = size() + extra;
    char* char_array;
    //Create new array with reserved length with space for null
    char_array = new char[ext + 1];
    //Add each character from old loop to new loop
    for (int i = 0; array[i]; i++)
        char_array[i] = array[i];
    //Delete old array
    delete[] array;
}

void String::insert(char c, int idx){
    //Reserve space for one character
    reserve(1);
    if (idx < 0)
        //If index is negative, insert at start of array
        c = array[0];
    else if (idx > size())
        //If index greater than size, insert at end of array
        c = array[size() - 1];
    else
        c = array[idx]; //Append at given index
}

void String::erase(char c){
    int length = size();
    char* new_array;
    for (int i = 0, j = 0; i < length; ++i){
        if(array[i] != c)
            new_array[j] = array[i];
            j++;
    }
    delete[] array;
}

void String::remove(int idx){
    int length = size();
    char* new_array;
    for (int i = 0, j = 0; i < length; ++i){
        
    }
}

void String::append(char c){
    /*
    char* new_array;
    new_array = new char[size() + 2];
    for (int i = 0; array[i]; i++)
        new_array[i] = array[i];
    new_array[size() - 1] = c;
    new_array[size()] = '\0';*/
    return;
}

void String::prepend(char c){
    char* new_array;
    new_array = new char[size() + 2];
    new_array[0] = c;
    for (int i = 1; array[i] != '\0'; i++){
        new_array[i] = array[i - 1];
    }
    new_array[size()] = '\0';
}

bool String::compare(char* str) const{
    if (*str == 0)
        return true;
    return compare(str + 1);
}

bool String::compare(String&) const{
    return true;
}
void String::concatenate(char* str){
    return;
}
void String::concatenate(String&){
    return;
}
unsigned int String::find(char* c, int start) const{
    return start;
}
unsigned int String::find(char c, int start) const{
    if (at(start) == c)
        return start;
    return find(c, start + 1);
}
unsigned int String::find(String&, int start) const{
    return start;
}

void String::reverse(){
    int s = 0;
    int e = size();
    array[s++] == array[e--];
}
void String::shift(int n){
    int shifted;
    // shifted = char + int;
    return;
}
int String::toInt() const{
    //stoi
    //get each ascii value and add
    //otherwise, throw exception
}

String String::substr(int start, int end) const{
    if (start == end)
        return substr(start, end);
    return substr(start++, end--);
}

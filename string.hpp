#ifndef __STRING__
#define __STRING__

class String {
    private:
        //declare data members here
        char * array;
        int length;

    public:
        //constructors and deconstructor
        String(); //Default
        String(const char*); //Parameterized
        ~String(); //Destructor (frees all memory)

    //Other methods
    unsigned int length();
    void reverse();
    void append(const char);
};

#endif
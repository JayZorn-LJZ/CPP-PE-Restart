#ifndef STRING2_H_
#define STRING2_H_
#include <iostream>
using std::ostream;
using std::istream;

class String
{
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;
    public:
        String(const char * s);
        String();
        String(const String &);
        ~String();
        int length() const {return len;}
        String & operator=(const String &);
        String & operator=(const char *);
        char & operator[](int i);
        const char & operator[](int i) const;
        friend bool operator<(const String &st, const String &st2);
        friend bool operator>(const String &, const String &);
        friend bool operator==(const String &, const String &);
        friend ostream & operator<<(ostream &, const String &);
        friend istream & operator>>(istream &, String &);
        static int HowMany();

        friend String operator+(const String &, const String & st);
        void stringlow();
        void stringup();
        int has(char);
};

#endif
#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>

namespace PERSON
{
    // const int LIMIT = 25; // 下面的常量的替代方案
    class Person
    {
        static const int LIMIT = 25;
        std::string lname;
        char fname[LIMIT];
        // enum limit {LIMIT = 25}; // 常量替代方案
        public:
            Person() {lname = ""; fname[0] = '\0';}
            Person(const std::string &, const char * fn = "Heyyou");
            void show() const;
            void formalshow() const;
    };
}

#endif
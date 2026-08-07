#include "cow.hpp"
#include <cstring>
#include <iostream>

// const int Cow::name_size = 0; // 非静态数据成员不能在其类的外部定义

// using namespace COW;
namespace COW
{
    // static int Cow::cow_size = 0; // 不能加上staticx限定符
    int Cow::cow_size = 0; // 不能加上staticx限定符

    void Cow::copy_hobby(const char * str)
    {
        int array_size = 0;
        for (; str[array_size]; array_size++)
            ;
        hobby = new char [++array_size];
        strcpy(hobby, str);
    }

    Cow::Cow()
    {
        strncpy(name, "None", name_size - 1);
        name[name_size - 1] = '\0';
        hobby = new char[1];
        hobby[0] = '\0';
        weight = 0.0;
        cow_size++;
    }

    Cow::Cow(const Cow & c) // 复制构造函数（拷贝构造函数）只用于“初始化”新对象
    {
        strncpy(name, c.name, name_size - 1);
        name[name_size - 1] = '\0';
        copy_hobby(c.hobby);
        weight = c.weight;
        cow_size++;
    }

    Cow::Cow(const char * nm, const char * ho, double wt)
    {
        strncpy(name, nm, name_size - 1);
        name[name_size - 1] = '\0';
        copy_hobby(ho);
        weight = wt;
        cow_size++;
    }

    Cow::~Cow()
    {
        delete [] hobby;
        cow_size--;
    }

    Cow & Cow::operator=(const Cow & c)
    {
        strcpy(name, c.name);
        delete [] hobby;
        copy_hobby(c.hobby);
        weight = c.weight;
        return *this;
    }

    // 至此，复制问题完美解决，可以将其作为一个结构体使用

    void Cow::ShowCow() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Hobby: " << hobby << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    }

    int Cow::getCowSize()
    {
        return cow_size;
    }
}

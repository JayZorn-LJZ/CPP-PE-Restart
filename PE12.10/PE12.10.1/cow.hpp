#ifndef COW_H_
#define COW_H_

namespace COW
{
    class Cow
    {
        private:
            // static int cow_size = 0; // 带有类内初始值设定项的成员必须为常量，要想使这段代码成立必须要在static后面加上const
            static int cow_size; // 不去初始值
            enum constant {name_size = 20};
            char name[name_size];
            char * hobby;
            double weight;
            void copy_hobby(const char *);
        protected:
            // 
        public:
            // 所有初始化函数
            Cow(); // 默认构造函数
            Cow(const Cow & c); // 复制构造函数
            Cow(const char * nm, const char * ho = "None", double wt = 0.0);
            // 构造函数兼转换函数
            // explicit Cow(const char * nm, const char * ho = "None", double wt = 0.0);
            // 仅显示转换版本
            // explicit operator char*() const; // 其他转换函数
            virtual ~Cow();
            virtual Cow & operator=(const Cow & c);
            // friend Cow & operator=(const Cow &, const Cow&) 友元版本的
            void ShowCow() const;
            static int getCowSize();
    };
}

#endif
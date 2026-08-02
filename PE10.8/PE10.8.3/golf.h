#ifndef GOLF_H_
#define GOLF_H_

// const int Len = 40;
// struct golf
// {
//     char fullname[Len];
//     int handicap;
// };

// void setgolf(golf & g, const char * name, int hc);
// int setgolf(golf & g);
// void handicap(golf & g, int hc);
// void showgolf(const golf & g);

class golf
{
    enum char_num : int {Len = 40};
    char fullname[Len];
    int handicap;
    bool nonename;
    public:
        golf(const char *, int);
        // int golf(); // 构造函数不能有返回值
        golf();
        ~golf();
        void get_handicap(int);
        void showgolf() const;
        bool emptyname() const {return nonename;}
};

#endif
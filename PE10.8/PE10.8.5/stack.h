#ifndef STACK_H_
#define STACK_H_

namespace STACK
{
    struct customer
    {
        char fullname[35];
        double payment;
    };
    typedef customer item;
    class stack
    {
        item array[20];
        int top;
        public:
            stack();
            item push();
            void put(item);
            double total() const;
            ~stack();
    };
}

#endif
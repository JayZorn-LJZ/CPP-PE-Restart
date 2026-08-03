#ifndef MOVE_H_
#define MOVE_H_

class move
{
    private:
        double x;
        double y;
    public:
        move(double a = 0, double b = 0);
        void showmove() const;
        move add(const move & m);
        void reset(double a = 0, double b = 0);
};

#endif
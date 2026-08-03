#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
    private:
        char name[19];
        int ci;
    public:
        Plorg();
        Plorg(const char *, int);
        ~Plorg();
        void set_ci(int);
        void report() const;
};

#endif
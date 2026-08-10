#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>

class Stock
{
    private:
        std::string company;
        int shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = shares * share_val;}
    public:
        Stock();
        Stock(const std::string &, long, double);
        ~Stock();
        void buy(long, double);
        void sell(long, double);
        void update(double);
        void show() const;
        const Stock & topval(const Stock & s) const;
};

#endif
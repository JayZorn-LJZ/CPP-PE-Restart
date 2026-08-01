#include <iostream>
#include "account.h"

int main(void)
{
    account my_account;
    my_account.show();

    my_account = account("Jayzorn", "wechat pay", 800);
    my_account.show();

    my_account.save(100);
    my_account.show();

    my_account.take(100);
    my_account.show();

    return 0;
}
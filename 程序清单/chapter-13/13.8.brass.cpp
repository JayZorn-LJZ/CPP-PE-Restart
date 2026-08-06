// brass.cpp -- bank account class methods
#include <iostream>
#include "13.7.brass.h"          // 包含类声明，其中定义了虚函数等
using std::cout;
using std::endl;
using std::string;

// ---------- 格式化辅助类型和函数声明 ----------
// 用于保存流格式标志和精度，方便恢复
typedef std::ios_base::fmtflags format;   // 格式标志类型
typedef std::streamsize precis;           // 精度类型（原图中误写为 std::streambase，这里修正）
format setFormat();                       // 设置为固定小数点格式，返回原格式
void restore(format f, precis p);         // 恢复格式和精度

// ---------- Brass 类方法实现 ----------

// 构造函数：使用初始化列表直接初始化私有成员（头文件中已提供默认参数）
Brass::Brass(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

// 存款：仅当金额非负时才增加余额
void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed: " << endl;
    else
        balance += amt;
}

// 取款（普通账户）：余额不足或金额为负时拒绝，否则扣除余额
void Brass::Withdraw(double amt)
{
    // 保存当前格式并设置为固定小数点、两位小数
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0)
        cout << "Withdrawal amount must be positive; "
             << "withdrawal canceled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal canceled.\n";
    // 恢复之前保存的格式和精度
    restore(initialState, prec);
}

// 查询余额（const 成员函数，不修改对象）
double Brass::Balance() const
{
    return balance;
}

// 显示账户信息（虚函数，可被派生类重写）
void Brass::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;

    restore(initialState, prec);
}

// ---------- BrassPlus 类方法实现 ----------

// 构造函数1：使用成员初始化列表调用基类构造函数 Brass(s, an, bal)，
// 再初始化派生类新增的数据成员。
BrassPlus::BrassPlus(const string & s, long an, double bal,
                     double ml, double r) : Brass(s, an, bal)
{
    maxLoan = ml;      // 最大透支额度
    owesBank = 0.0;    // 初始欠款为0
    rate = r;          // 贷款利率
}

// 构造函数2：基于一个 Brass 对象构造 BrassPlus 对象，
// 使用隐式复制构造函数 Brass(ba) 复制基类部分。
BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
    : Brass(ba)        // 调用基类的复制构造函数（编译器生成）
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// 重写 ViewAcct()：先显示基类部分，再显示派生类特有的信息
void BrassPlus::ViewAcct() const
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();   // 调用基类的公有方法显示基类数据（账户名、账号、余额）

    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    // 将利率显示为百分比，这里临时将精度改为3位小数
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";

    restore(initialState, prec);
}

// 重写 Withdraw()：支持透支取款
void BrassPlus::Withdraw(double amt)
{
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();   // 调用基类的公有方法获取当前余额

    if (amt <= bal)
    {
        // 若取款金额不超过余额，直接调用基类的取款方法
        Brass::Withdraw(amt);
    }
    else if (amt <= bal + maxLoan - owesBank)
    {
        // 若取款金额在“余额 + 可用信用额度”范围内，则进行透支
        double advance = amt - bal;                // 需要透支的金额
        owesBank += advance * (1.0 + rate);        // 欠款增加：本金 + 利息（一次性计入）
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);                          // 将透支金额存入账户（使余额变为 amt）
        Brass::Withdraw(amt);                      // 再从账户中取出全部 amt（实际上取走的是存款 + 透支部分）
    }
    else
    {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }

    restore(initialState, prec);
}

// ---------- 格式化辅助函数定义 ----------

// 设置输出为固定小数点格式（保留小数点后指定位数），返回原来的格式标志
format setFormat()
{
    // setf() 返回设置前的格式状态，以便后续恢复
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

// 恢复格式标志和精度
void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);  // 恢复格式标志（注意：setf 会覆盖之前的所有标志）
    cout.precision(p);                        // 恢复精度
}
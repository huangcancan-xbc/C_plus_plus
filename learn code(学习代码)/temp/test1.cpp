#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
public:
	BankAccount(string id, double value = 0)
		: accountId(id),
		balance(value)
	{
		cout << "账户创建成功！id：" << accountId << "，当前余额：" << balance << endl;
	}

	// 存款
	void deposit(double value)
	{
		if (value < 0)
		{
			cout << "存款金额不能为负数！" << endl;
			return;
		}

		balance += value;
		cout << "当前存款为：" << balance << endl;
	}

	// 取款
	void withdraw_money(double value)
	{
		if (balance >= value)
		{
			balance -= value;
		}
		else
		{
			cout << "余额不足！" << endl;
		}
	}

	// 查询余额
	double get_balance()
	{
		return balance;
	}

private:
	string accountId;	// 账户
	double balance;		// 余额
};


int main()
{
	BankAccount account("622202", 1000.0);
	account.deposit(500);
	account.withdraw_money(200);
	account.withdraw_money(2000);
	cout << "最终余额：" << account.get_balance() << endl;
	return 0;

	return 0;
}
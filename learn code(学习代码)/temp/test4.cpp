#include <iostream>
#include <string>
using namespace std;

class Payment
{
public:
	virtual bool pay(double amount) = 0;	// 支付接口，返回支付是否成功
	virtual bool refund(const string& id) = 0;	// 退款接口，参数：订单号，返回退款是否成功
	virtual string getPaymentName() = 0;	// 获取支付方式的名称
	virtual ~Payment() = default;			// 虚析构函数
};


class Alipay : public Payment
{
public:
	bool pay(double amount) override
	{
		cout << "支付宝成功支付" << amount << "元！" << endl;
		return true;	// 简化处理，默认支付成功
	}

	bool refund(const string& id) override
	{
		cout << "支付宝退款，订单号: " << id << endl;
		return true;	// 简化处理，默认退款成功
	}

	string getPaymentName() override
	{
		return "支付宝";
	}
};


class WechatPay : public Payment
{
public:
	bool pay(double amount) override
	{
		cout << "微信支付成功支付" << amount << "元！" << endl;
		return true;	// 简化处理，默认支付成功
	}

	bool refund(const string& id) override
	{
		cout << "微信退款，订单号: " << id << endl;
		return true;	// 简化处理，默认退款成功
	}

	string getPaymentName() override
	{
		return "微信";
	}
};


class PaymentProcessor
{
public:
	// 设置支付方式
	void getPaymentName(Payment* p)
	{
		payment = p;
	}

	void processOrder(double amount)
	{
		if (payment->pay(amount))
		{
			cout << "支付成功！支付方式：" << payment->getPaymentName() << endl;
		}
	}
private:
	Payment* payment;	// 支付方式对象指针
};



int main()
{
	PaymentProcessor processor;
	Alipay alipay;
	WechatPay wechat;

	// 1. 设置支付方式为支付宝，处理100元订单
	processor.getPaymentName(&alipay);
	processor.processOrder(100.0);

	// 2. 动态切换支付方式为微信，处理200元订单
	processor.getPaymentName(&wechat);
	processor.processOrder(200.0);

	return 0;
}
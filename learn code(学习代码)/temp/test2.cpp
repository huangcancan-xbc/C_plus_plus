#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee
{
public:
	Employee(string n, int i, double salary)
		: name(n),
		id(i),
		baseSalary(salary)
	{

	}

	virtual ~Employee() = default;

	// 计算实际工资
	virtual double calculateSalary() = 0;

	// 打印信息
	virtual void print()
	{
		cout << "ID：" << id << "，姓名：" << name << "，基本工资：" << baseSalary << endl;
	}

protected:
	string name;		// 名字
	int id;				// 员工号
	double baseSalary;	// 基本工资
};



// 正式员工：基本工资 + 奖金
class FullTimeEmployee : public Employee
{
public:
	FullTimeEmployee(string n, int i, double salary, double b)
		: Employee(n, i, salary),
		bonus(b)
	{

	}

	double calculateSalary() override
	{
		return baseSalary + bonus;
	}

	void print() override
	{
		Employee::print();
		cout << "奖金：" << bonus << "，实发工资：" << calculateSalary() << endl;
	}

private:
	double bonus;		// 奖金
};


// 兼职员工：按小时计费
class PartTimeEmployee : public Employee
{
public:
	PartTimeEmployee(string n, int i, int h, double r)
		: Employee(n, i, 0),
		hours(h),
		hourlyRate(r)
	{

	}

	double calculateSalary() override
	{
		return hours * hourlyRate;
	}

	void print() override
	{
		Employee::print();
		cout << "工作小时数：" << hours << "，时薪：" << hourlyRate << "，实发工资：" << calculateSalary() << endl;
	}
private:
	int hours;			// 小时数
	double hourlyRate;	// 时薪
};

int main()
{
	vector<Employee*> employees;

	employees.push_back(new FullTimeEmployee("张三", 1001, 5000, 2000));
	employees.push_back(new PartTimeEmployee("李四", 1002, 50, 80));
	employees.push_back(new FullTimeEmployee("王五", 1003, 8000, 3000));

	double totalSalary = 0;
	for (auto emp : employees)
	{
		emp->print();
		totalSalary += emp->calculateSalary();
	}

	cout << "公司总工资支出: " << totalSalary << endl;

	for (auto emp : employees)
	{
		delete emp;
	}

	return 0;
}
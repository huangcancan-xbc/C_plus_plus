#include <iostream>
using namespace std;

class Config
{
public:
	static Config& getInstance()
	{
		static Config instance;	// C++11 起：线程安全初始化
		return instance;
	}

	void loadConfig()
	{
		cout << "加载配置..." << endl;
	}
private:
	static Config* instance;

	Config()
	{
		cout << "配置已经创建！" << endl;
	}

	~Config()
	{
		cout << "配置已经销毁！" << endl;
	}

	Config(const Config&) = delete;
	Config& operator=(const Config&) = delete;
};



int main()
{
	Config& config1 = Config::getInstance();
	Config& config2 = Config::getInstance();

	if (&config1 == &config2)
	{
		cout << "config1和config2是同一个对象，指向同一个实例！" << endl;
	}
	else
	{
		cout << "config1和config2不是同一个对象，指向不同的实例！" << endl;
	}

	config1.loadConfig();
	config2.loadConfig();

	return 0;
}
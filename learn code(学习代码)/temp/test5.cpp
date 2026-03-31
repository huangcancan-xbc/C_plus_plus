#include <iostream>
using namespace std;

class Config
{
public:
	static Config* getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Config();
		}

		return instance;
	}

	// 显式销毁实例
	static void destroyInstance()
	{
		delete instance;
		instance = nullptr;
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
		//delete instance;	// 析构是私有的，无法直接调用，只能通过静态方法销毁实例
		cout << "配置已经销毁！" << endl;
	}

	Config(const Config&) = delete;
	Config& operator=(const Config&) = delete;
};

// 类内声明的静态成员变量，必须在类外进行初始化（否则编译器找不到该变量的内存分配位置）
Config* Config::instance = nullptr;


int main()
{
	Config* config1 = Config::getInstance();
	Config* config2 = Config::getInstance();

	if (config1 == config2)
	{
		cout << "config1和config2是同一个对象，指向同一个实例！" << endl;
	}
	else
	{
		cout << "config1和config2不是同一个对象，指向不同的实例！" << endl;
	}

	config1->loadConfig();
	config2->loadConfig();

	//delete config1; 析构是私有的，main函数无法访问到
	Config::destroyInstance();	// 正确释放资源

	return 0;
}
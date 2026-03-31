#include <iostream>
#include <ostream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>


// 形状类
class Shape
{
public:
	Shape(double x, double y)
		:_x(x),
		_y(y)
	{

	}

	virtual ~Shape() = default;

	virtual void draw() const = 0;				// 画
	virtual double getArea() const = 0;			// 面积
	virtual double getPerimeter() const = 0;	// 周长
	virtual std::string getType() const = 0;	// 类型
	virtual void serialize(std::ostream& os) const = 0;	// 序列化

	virtual void move(double dx, double dy)		// 移动
	{
		_x += dx;
		_y += dy;
	}

	virtual void print(std::ostream& os) const	// 打印
	{
		os << getType() << "(x=" << _x << ", y=" << _y << ")"
			<< ", 面积=" << getArea()
			<< ", 周长=" << getPerimeter();
	}
protected:
	double x() const { return _x; }
	double y() const { return _y; }

private:
	double _x;	// 初始位置
	double _y;	// 初始位置
};

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
	shape.print(os);
	return os;
}

// 圆形类
class Circle : public Shape
{
public:
	Circle(double x, double y, double r)
		: Shape(x, y),
		_radius(r)
	{

	}

	void draw() const override
	{
		std::cout << "画圆: " << *this << std::endl;
	}

	double getArea() const override
	{
		return Pi * _radius * _radius;	// 面积是Π*半径的平方
	}

	double getPerimeter() const override
	{
		return 2 * Pi * _radius;		// 周长是2Πr
	}

	std::string getType() const override
	{
		return "Circle";
	}

	void serialize(std::ostream& os) const override
	{
		os << "Circle " << x() << ' ' << y() << ' ' << _radius << std::endl;
	}

	void print(std::ostream& os) const override
	{
		Shape::print(os);
		os << ", radius=" << _radius;
	}
private:
	// constexpr 强制编译期计算，比 const 更严格的常量约束
	static constexpr double Pi = 3.1415926;
	double _radius;	// 半径
};


// 矩形类
class Rectangle : public Shape
{
public:
	Rectangle(double x, double y, double w, double h)
		:Shape(x, y),
		_width(w),
		_height(h)
	{

	}

	void draw() const override
	{
		std::cout << "画矩形：" << *this << std::endl;
	}

	double getArea() const override
	{
		return _width * _height;	// 面积是宽乘高
	}

	double getPerimeter() const override
	{
		return 2 * (_width + _height);	// 周长是2(宽+高)
	}

	std::string getType() const override
	{
		return "Rectangle";
	}

	void serialize(std::ostream& os) const override
	{
		os << "Rectangle " << x() << ' ' << y() << ' ' << _width << ' ' << _height << std::endl;
	}

	void print(std::ostream& os) const override
	{
		Shape::print(os);
		os << ", width=" << _width << ", height=" << _height;
	}
private:
	double _width;	// 宽度
	double _height;	// 高度
};


// 三角形类
class Triangle : public Shape
{
public:
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
		: Shape(x1, y1), _x2(x2), _y2(y2), _x3(x3), _y3(y3)
	{

	}

	void draw() const override
	{
		std::cout << "画三角形：" << std::endl;
	}

	double getArea() const override
	{
		double sum = x() * (_y2 - _y3) + _x2 * (_y3 - y()) + _x3 * (y() - _y2);	// 叉乘
		return std::abs(sum) * 0.5;
	}

	double getPerimeter() const override
	{
		return distance(x(), y(), _x2, _y2) +
			distance(x(), y(), _x3, _y3) +
			distance(_x2, _y2, _x3, _y3);
	}

	std::string getType() const override
	{
		return "Triangle";
	}

	void move(double dx, double dy) override
	{
		Shape::move(dx, dy);
		_x2 += dx;
		_y2 += dy;
		_x3 += dx;
		_y3 += dy;
	}

	void serialize(std::ostream& os) const override
	{
		os << "Triangle " << x() << ' ' << y() << ' '
			<< _x2 << ' ' << _y2 << ' '
			<< _x3 << ' ' << _y3 << '\n';
	}

	void print(std::ostream& os) const override
	{
		Shape::print(os);
		os << ", p2=(" << _x2<< ", " << _y2 << ")"
			<< ", p3=(" << _x3 << ", " << _y3 << ")";
	}
private:
	// 两点间距离公式
	double distance(double x1, double y1, double x2, double y2) const
	{
		return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}

	double _x2;
	double _y2;
	double _x3;
	double _y3;
};

class Manager
{
public:
	// 单例
	static Manager& getInstance()
	{
		static Manager instance;
		return instance;
	}

	// 添加图形
	void addShape(const std::shared_ptr<Shape>& shape)
	{
		// 如果图形存在，则不添加，反之如果图形的对象存在，则添加
		if (shape)
		{
			_shapes.push_back(shape);
		}
	}

	// 删除图形（按索引）
	bool delShape(int index)
	{
		if (index < 0 || index >= _shapes.size())
		{
			return false;
		}

		_shapes.erase(_shapes.begin() + index);
		return true;
	}

	// 显示所有图形
	void printAll() const
	{
		if (_shapes.empty())
		{
			std::cout << "目前没有任何图形！" << std::endl;
			return;
		}

		for (auto& x : _shapes)
		{
			std::cout << *x << std::endl;
		}
	}

	// 计算总面积
	double getTotalArea() const
	{
		double total = 0;
		for (auto& x : _shapes)
		{
			total += x->getArea();
		}

		return total;
	}

	// 拖动某一个图形
	bool moveShape(int index, double dx, double dy)
	{
		if (index < 0 || index >= _shapes.size())
		{
			return false;
		}
		
		_shapes[index]->move(dx, dy);
		return true;
	}

	// 保存到文件
	bool saveToFile(const std::string& file) const
	{
		std::ofstream ofs(file);
		if (!ofs)
		{
			return false;
		}

		for (const auto& x : _shapes)
		{
			x->serialize(ofs);
		}

		return true;
	}

	// 从文件加载（覆盖当前数据）
	bool loadFromFile(const std::string& file)
	{
		std::ifstream ifs(file);
		if (!ifs)
		{
			return false;
		}

		std::vector<std::shared_ptr<Shape>> load;
		std::string line;
		while (std::getline(ifs, line))
		{
			if (line.empty())
			{
				continue;
			}

			auto shape = parseShapeLine(line);
			if (shape)
			{
				load.push_back(shape);
			}
		}

		_shapes = std::move(load);
		return true;
	}

	// 运算符重载: ShapeManager + Shape 添加图形
	Manager& operator+(const std::shared_ptr<Shape>& shape)
	{
		addShape(shape);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Manager& manager)
	{
		os << "ShapeManager(count=" << manager._shapes.size()
			<< ", totalArea=" << manager.getTotalArea() << ")";
		return os;
	}

private:
	Manager() = default;

	// 解析图形行
	static std::shared_ptr<Shape> parseShapeLine(const std::string& line)
	{
		std::istringstream iss(line);
		std::string type;
		iss >> type;

		if (type == "Circle")
		{
			double x = 0.0, y = 0.0, r = 0.0;
			if (iss >> x >> y >> r)
			{
				return std::make_shared<Circle>(x, y, r);
			}
		}
		else if (type == "Rectangle")
		{
			double x = 0.0, y = 0.0, w = 0.0, h = 0.0;
			if (iss >> x >> y >> w >> h)
			{
				return std::make_shared<Rectangle>(x, y, w, h);
			}
		}
		else if (type == "Triangle")
		{
			double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
			if (iss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
			{
				return std::make_shared<Triangle>(x1, y1, x2, y2, x3, y3);
			}
		}

		return nullptr;
	}



	std::vector<std::shared_ptr<Shape>> _shapes;
};



int main()
{
	// 1. 获取单例
	auto& mgr = Manager::getInstance();
	std::cout << mgr << std::endl;

	// 2. 添加图形 (测试普通添加)
	auto circle = std::make_shared<Circle>(0, 0, 5);
	auto rect = std::make_shared<Rectangle>(10, 10, 4, 5);
	auto tri = std::make_shared<Triangle>(0, 0, 3, 0, 0, 4);

	mgr.addShape(circle);
	mgr.addShape(rect);
	mgr.addShape(tri);

	// 3. 测试运算符重载添加
	mgr + std::make_shared<Circle>(100, 100, 10);

	// 4. 打印所有
	mgr.printAll();
	std::cout << "总面积：" << mgr.getTotalArea() << std::endl;

	// 5. 移动图形
	mgr.moveShape(0, 10, 10);
	mgr.printAll();

	// 6. 保存到文件
	if (mgr.saveToFile("data.txt"))
	{
		std::cout << "保存成功" << std::endl;
	}
	else
	{
		std::cout << "保存失败" << std::endl;
	}

	// 7. 删除图形
	if (mgr.delShape(1))
	{
		std::cout << "删除成功" << std::endl;
	}
	mgr.printAll();

	// 8. 从文件加载 (覆盖当前)
	if (mgr.loadFromFile("data.txt"))
	{
		std::cout << "加载成功" << std::endl;
	}
	mgr.printAll();

	return 0;
}
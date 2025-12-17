#pragma once
#include <vector>
#include <functional>
using namespace std;

// 对于i节点：
// 下标从0开始：左孩下标：2i+1，右孩下标：2i+2
// 下标从1开始：左孩下标：2i，右孩下标：2i+1
// 注意：反之除2有小数就向下取整
namespace minbit
{
	template <class T>
	struct Less
	{
		bool operator()(const T& a, const T& b)
		{
			return a < b;
		}
	};

	template <class T>
	struct Greator
	{
		bool operator()(const T& a, const T& b)
		{
			return a > b;
		}
	};

	template <class T, class Container = vector<T>, class Compare = Less<T>>
	class priority_queue
	{
	public:
		priority_queue() = default;

		// 迭代器区间构造：用[begin, end)范围内的元素初始化队列，并构建堆
		template <class InPutIterator>
		priority_queue(InPutIterator begin, InPutIterator end)
			: _vec(begin, end)
		{
			// 从最后一个非叶子节点开始向下调整，完成堆的构建
			// 最后一个非叶子节点索引 = (元素总数 - 2) / 2（整数除法）
			for (int i = (_vec.size() - 2) / 2; i >= 0; i--)
			{
				adjust_down(i);
			}
		}

		const T& top() const
		{
			return _vec[0];
		}

		T& top()
		{
			return _vec[0];
		}

		void push(const T& val)
		{
			_vec.push_back(val);
			adjust_up(_vec.size() - 1);
		}

		// 删除堆顶元素：
		// 1. 交换堆顶（首元素）和尾部元素
		// 2. 删除尾部元素（原堆顶）
		// 3. 对新堆顶（原尾部元素）执行向下调整
		void pop()
		{
			swap(_vec[0], _vec[_vec.size() - 1]);
			_vec.pop_back();
			adjust_down(0);
		}

		size_t size()
		{
			return _vec.size();
		}

		size_t size() const
		{
			return _vec.size();
		}

		bool empty()
		{
			return _vec.empty();
		}

		bool empty() const
		{
			return _vec.empty();
		}

	private:
		// 向上调整
		void adjust_up(int child)	// child是新插入的位置index
		{
			Compare com;
			int parent = (child - 1) / 2;  // 父节点索引

			// 当子节点未到达根节点时，持续调整
			while (child > 0)
			{
				// 若父节点优先级低于子节点，交换两者
				if (com(_vec[parent], _vec[child]))
				{
					swap(_vec[child], _vec[parent]);
					child = parent;				// 更新位置
					parent = (child - 1) / 2;	// 重新计算父节点索引
				}
				else
				{
					break;  // 已满足堆结构，停止调整
				}
			}
		}

		// 向下调整
		void adjust_down(int parent)
		{
			Compare com;
			int child = 2 * parent + 1;  // 默认先比较左孩子

			// 当子节点未超出容器范围时，持续调整
			while (child < _vec.size())
			{
				// 若右孩子存在且优先级高于左孩子，选择右孩子进行比较
				if (child + 1 < _vec.size() && com(_vec[child], _vec[child + 1]))
				{
					child++;  // 切换到右孩子索引
				}

				// 若父节点优先级低于选中的子节点，交换两者
				if (com(_vec[parent], _vec[child]))
				{
					swap(_vec[child], _vec[parent]);
					parent = child;				// 更新位置
					child = 2 * parent + 1;		// 重新计算左孩子索引
				}
				else
				{
					break;
				}
			}
		}

	private:
		Container _vec;
		Compare _cmp;
	};
}
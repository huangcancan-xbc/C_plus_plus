//数字字符串格式化

//问题描述
//小M在工作时遇到了一个问题，他需要将用户输入的不带千分位逗号的数字字符串转换为带千分位逗号的格式，并且保留小数部分。
//小M还发现，有时候输入的数字字符串前面会有无用的 0，这些也需要精简掉。请你帮助小M编写程序，完成这个任务。
//
//测试样例
//
//样例1：
//输入：s = "1294512.12412"
//输出：'1,294,512.12412'
//
//样例2：
//输入：s = "0000123456789.99"
//输出：'123,456,789.99'
//
//样例3：
//输入：s = "987654321"
//输出：'987,654,321'


std::string solution(const std::string& s) 
{
    
    if (s.empty())
    {
        return "";                                                  // 检查输入是否有效
    }

    // 分离整数部分和小数部分
    size_t pos = s.find('.');
    string left = (pos == string::npos) ? s : s.substr(0, pos);     // 整数部分
    string right = (pos == string::npos) ? "" : s.substr(pos);      // 小数部分（包括小数点）

    size_t first_nonzero = left.find_first_not_of('0');             // 去除整数部分的前导零（注意：数字 "0" 应保留）
    if (first_nonzero == string::npos)                              // 如果全是零，整数部分应为 "0"
    {
        left = "0";
    }
    else 
    {
        left = left.substr(first_nonzero);
    }

    // 整数部分处理 - 插入千分位分隔符
    string temp;
    int count = 0;
    for (int i = left.size() - 1; i >= 0; --i) 
    {
        temp += left[i];
        count++;
        if (count % 3 == 0 && i > 0) 
        {
            temp += ',';
        }
    }
    reverse(temp.begin(), temp.end());

    string ret = temp + right;                                      // 结果拼接
    return ret;
}

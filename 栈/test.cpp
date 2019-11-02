#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;

		for (size_t i = 0; i < tokens.size(); ++i){
			string& str = tokens[i];
			if (!("+" == str || "-" == str || "*" == str || "/" == str)){
				//数字
				s.push(atoi(str.c_str()));
			}
			else{
				//操作符
				int right = s.top();
				s.pop();

				int left = s.top();
				s.pop();

				switch (str[0])
				{
				case'+':
					s.push(left + right);
					break;
				case'-':
					s.push(left - right);
					break;
				case'*':
					s.push(left * right);
					break;
				case'/':
					s.push(left / right);
					break;
				}
			}
		}
		return s.top();
	}
};


class Solution1 {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {

		//入栈序列和出栈序列的个数都不一样，那么肯定不匹配
		if (pushV.size() != popV.size())
			return false;

		stack<int>s;
		size_t inIdx = 0;     //标记入栈元素
		size_t outIdx = 0;    //标记待出栈元素

		while (outIdx < popV.size())
		{
			while (s.empty() || s.top() != popV[outIdx])
			{
				if (inIdx < pushV.size())
					s.push(pushV[inIdx++]);
				else
					return false;
			}
			s.pop();
			++outIdx;
		}
		return true;
	}
};

int main()
{

	system("pause");
	return 0;
}
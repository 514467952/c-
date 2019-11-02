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
				//����
				s.push(atoi(str.c_str()));
			}
			else{
				//������
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

		//��ջ���кͳ�ջ���еĸ�������һ������ô�϶���ƥ��
		if (pushV.size() != popV.size())
			return false;

		stack<int>s;
		size_t inIdx = 0;     //�����ջԪ��
		size_t outIdx = 0;    //��Ǵ���ջԪ��

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
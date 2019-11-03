
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
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


vector<vector<int>> ret[5][5] = { {0} };

ret[0][0] = 1;



struct levelNode{
	int level;
	TreeNode *root;
};
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector<vector<int>>ret;

		if (root == NULL){
			return ret;
		}
		queue<TreeNode*> q;
		q.push(root);   //�Ѿ�����һ������н��ŵ�������

		while (!q.empty())
		{
			//һ���ͽ�sһ������н�������
			vector<int > level;
			int levelSize = q.size();

			//ÿһ��
			for (size_t i = 0; i< levelSize; ++i)
			{
				TreeNode * pCur = q.front();
				level.push_back(pCur->val);

				//����ý������������
				if (pCur->left)
					q.push(pCur->left);
				if (pCur->right)
					q.push(pCur->right);

				q.pop();
			}


			ret.push_back(level);
		}
		return ret;
	}

};
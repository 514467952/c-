
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
		q.push(root);   //已经将第一层的所有结点放到队列种

		while (!q.empty())
		{
			//一次型将s一层的所有结点遍历完
			vector<int > level;
			int levelSize = q.size();

			//每一层
			for (size_t i = 0; i< levelSize; ++i)
			{
				TreeNode * pCur = q.front();
				level.push_back(pCur->val);

				//如果该结点有左右子树
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
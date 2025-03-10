/*
[USACO3.4] 美国血统 American Heritage
题目描述
农夫约翰非常认真地对待他的奶牛们的血统。然而他不是一个真正优秀的记帐员。他把他的奶牛 们的家谱作成二叉树，并且把二叉树以更线性的“树的中序遍历”和“树的前序遍历”的符号加以记录而 不是用图形的方法。

你的任务是在被给予奶牛家谱的“树中序遍历”和“树前序遍历”的符号后，创建奶牛家谱的“树的 后序遍历”的符号。每一头奶牛的姓名被译为一个唯一的字母。（你可能已经知道你可以在知道树的两 种遍历以后可以经常地重建这棵树。）显然，这里的树不会有多于 
26
26 个的顶点。

这是在样例输入和样例输出中的树的图形表达方式：

　　　　　　　　 C
　　　　　　   /  \
　　　　　　  /　　\
　　　　　　 B　　  G
　　　　　　/ \　　/
　　　　   A   D  H
　　　　　　  / \
　　　　　　 E   F

附注：

树的中序遍历是按照左子树，根，右子树的顺序访问节点；
树的前序遍历是按照根，左子树，右子树的顺序访问节点；
树的后序遍历是按照左子树，右子树，根的顺序访问节点。
输入格式
第一行一个字符串，表示该树的中序遍历。

第二行一个字符串，表示该树的前序遍历。

输出格式
单独的一行表示该树的后序遍历。
*/

#include<bits/stdc++.h>
using namespace std;

void def(string f,string m){//前序和中序
	if(f.empty()) return;//没有字符可分则退出
	
	char ch=f[0];//前序中开头为当前根节点
	int k=m.find(ch);//在中序中找到此节点并记录下标
    
	f.erase(f.begin());//删除前序的开头（因为之后不会再用到它
	
	def(f.substr(0,k),m.substr(0,k));//找到和中序左子树对应的前序 (此处 f.substr(0,k)相当于就是截取了根节点的左子树)
	def(f.substr(k),m.substr(k+1));//两者皆递归，先左后又（左右根）
    
	cout<<ch;//递归结束倒着输出
}

int main()
{
	string m,f;
	
	cin>>m>>f;
	def(f,m);
	
	return 0;
}
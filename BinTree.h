#pragma once

#include <assert.h>
#include <iostream>
#include <queue>		//leveloder
#include <stack>	
using namespace std;

#define MaxSize 100



template <class Ty>
class  BinTree;


template<class Ty>
class BinTreeNode
{
	friend class BinTree<Ty>;

public:
	BinTreeNode() :data(0), Left(NULL), Right(NULL)
	{}
	BinTreeNode(Ty item = Ty(), BinTreeNode<Ty>* left = NULL, BinTreeNode<Ty>* right = NULL ) :data(item), Left(left), Right(right)
	{}
	Ty getdata()const
	{
		return data;
	}
private:
	Ty data;
	BinTreeNode<Ty>* Left;
	BinTreeNode<Ty>* Right;
};


template <class Ty>
class  BinTree
{
public:
	BinTree( Ty ref = Ty()) :root(NULL), reference(ref)
	{}

public:
	void Create()
	{
		Create(root);
	}

	void Create(char* str)
	{
		Create(root,str);
	}

	void preoder()
	{
		preoder(root);
	}

	void inoder()
	{
		inoder(root)
	}

	void postoder()
	{
		postoder(root);
	}

	void leveoder()
	{
		leveoder(root);
	}

	void hight()
	{
		cout<<hight(root)<<endl;
	}

	void print()
	{
		print(root, hight(root));
	}

	void NotLeafNum()
	{
		cout<<NotLeafNum(root)<<endl;
	}

	void LeafNum()
	{
		cout << LeafNum(root)<<endl;
	}

	void Size()
	{
		cout << Size(root) << endl;
	}
	
	bool Empty()const
	{
		return (root == NULL);
	}

	BinTreeNode<Ty> Root()const
	{
		return root;
	}

	BinTreeNode<Ty>* LeftChild(BinTreeNode<Ty> *p)const
	{
		if (p == NULL)
			return NULL;

		return p->Left;
	}

	BinTreeNode<Ty>* RightChild(BinTreeNode<Ty> *p)const
	{
		if (p == NULL)
			return NULL;

		return p->Right;
	}

	BinTreeNode<Ty>* Search(const Ty &key)
	{
		return _Search(root, key);
	}

	void DestroyBinTree()
	{
		DestroyBinTree(root);
		cout << "BinTree has Del!" << endl;
		return;
	}

	BinTreeNode<Ty>* Parent(const Ty &key)
	{
		return Parent(root,key);
	}

	BinTreeNode<Ty>* Parent(BinTreeNode<Ty>* p)
	{
		return Parent(root, p);
	}

	bool Equal(BinTree<Ty> &bt)
	{
		return Equal(root,bt.root);
	}

	void Copy(BinTree<Ty> &bt)
	{
		DestroyBinTree(root);
		root = Copy(bt.root);
	}
	
	void preoder_()
	{
		preoder_(root);
	}

	void inoder_()
	{
		inoder_(root)
	}

	void postoder_()
	{
		postoder_(root);
	}

protected:
	void Create(BinTreeNode<Ty> *&t)
	{
		Ty item;
		cin >> item;

		if (item == reference)
		{
			t = NULL;
		}
		else
		{
			t = new BinTreeNode<Ty>(item);
			Create(t->Left);
			Create(t->Right);
		}
	}

	//void Create(BinTreeNode<Ty> *&t, const char* str)
	//{
	//	//abc##de##f##g#h##
	//	static const char* Str = str;
	//	if (*Str == '#' || *Str == '\0')
	//	{
	//		t = NULL;
	//	}
	//	else
	//	{
	//		t = new BinTreeNode<Ty>(*Str);
	//		Create(t->Left, ++Str);
	//		Create(t->Right, ++Str);
	//	}
	//}

	void Create(BinTreeNode<Ty> *&t, char* &Str) //引用的更改将以前的各处更改
	{
		//abc##de##f##g#h##
		if (*Str == '#' || *Str == '\0')
			t = NULL;
		else
		{
			t = new BinTreeNode<Ty>(*Str);
			Create(t->Left, ++Str);
			Create(t->Right, ++Str);
		}
	}

	void preoder(BinTreeNode<Ty> *t) const
	{
		if (t) 
		{
			cout << t->data << " ";
			preoder(t->Left);
			preoder(t->Right);
		}
	}

	void inoder(BinTreeNode<Ty> *t) const
	{
		if (t)
		{
			preoder(t->Left);
			cout << t->data << " ";
			preoder(t->Right);
		}
	}

	void postoder(BinTreeNode<Ty> *t) const
	{
		if (t)
		{
			preoder(t->Left);
			preoder(t->Right);
			cout << t->data << " ";
		}
	}

	int hight(BinTreeNode<Ty> *t)
	{
		if (t == NULL)
			return 0;
		return hight(t->Left) > hight(t->Right)?
			hight(t->Left) + 1 :hight(t->Right) + 1;
	}

	//	Re
	void leveoder(BinTreeNode<Ty> *t) const
	{
		if (t == NULL)
			return;

		queue <BinTreeNode<Ty> *> Q;
		BinTreeNode<Ty> *p;
		Q.push(t);
		while (!Q.empty())
		{
			p = Q.front();
			Q.pop();
			cout << p->data << " ";
			if (p->Left != NULL)
				Q.push(p->Left);
			if (p->Right != NULL)
				Q.push(p->Right);
		}
	} 

	void print(BinTreeNode<Ty> *t, int level)
	{
		int i;
		if (NULL == t)
			return;
		print(t->Right, level + 1);
		for (i = 0; i < level; ++i)
			cout << "	";
		cout << t->data << endl;
		print(t->Left, level + 1);
	}

	int NotLeafNum(BinTreeNode<Ty> *t)const
	{
		if (t==NULL)
			return 0;
		else if (!(t->Left) && !(t->Right))
			return 0;
		else
			return NotLeafNum(t->Left) + NotLeafNum(t->Right)+1;
	}

	int LeafNum(BinTreeNode<Ty> *t)const
	{
		if (t==NULL)
			return 0;
		else if (!(t->Left) && !(t->Right))
			return 1;
		else
			return LeafNum(t->Left) + LeafNum(t->Right);
	}

	int Size(BinTreeNode<Ty> *t)const
	{
		//return NotLeafNum(t) + LeafNum(t);
		if (t==NULL)
			return 0;
		else
			return Size(t->Left) + Size(t->Right) + 1;
	}

	void DestroyBinTree(BinTreeNode<Ty> *t)
	{
		if (t != NULL)
		{
			DestroyBinTree(t->Left);
			DestroyBinTree(t->Right);
			delete t;
			t = NULL;
		}
	}

	BinTreeNode<Ty>* _Search(BinTreeNode<Ty> *t, const Ty &key)	
	{
		if (t==NULL)
			return NULL;
		if (t->data == key)
			return t;
		BinTreeNode<Ty> *Pleft; 
		if ((Pleft = _Search(t->Left, key)) != NULL)
			return Pleft;
		else
			return _Search(t->Right, key);
	}

	BinTreeNode<Ty>* Parent(BinTreeNode<Ty> *t, const Ty &key)
	{
		if (t == NULL || t->data == key)
			return NULL;
		if ((t->Left!=NULL && t->Left->data == key) || (t->Right != NULL && t->Right->data == key))
			return t;
		BinTreeNode<Ty> *Pleft;
		if ((Pleft = Parent(t->Left, key)) != NULL)
			return Pleft;
		else
			return Parent(t->Right, key);
	}

	BinTreeNode<Ty>* Parent(BinTreeNode<Ty> *t, BinTreeNode<Ty> *p)
	{
		if (t == NULL || t== p)
			return NULL;
		if (t->Left==p || t->Right==p)
			return t;
		BinTreeNode<Ty> *Pleft;
		if ((Pleft = Parent(t->Left, p)) != NULL)
			return Pleft;
		else
			return Parent(t->Right, p);
	}

	bool  Equal(BinTreeNode<Ty>* t1, BinTreeNode<Ty>* t2)
	{
		if (t1 == NULL && t2 == NULL)
			return true;
		return (
			(t1 != NULL && t2 != NULL)
			&& t1->data == t2->data
			&& Equal(t1->Left, t2->Left)
			&& Equal(t1->Right, t2->Right)
			);
	}

	BinTreeNode<Ty>* Copy(BinTreeNode<Ty> *t)	
	{
		if (t == NULL)
			return NULL;
		else
		{
			BinTreeNode<Ty>* r = new BinTreeNode<Ty>(t->data);
			r->Left = Copy(t->Left);
			r->Right = Copy(t->Right);
			return r;
		}
	}

	void preoder_1(BinTreeNode<Ty> *t) const// 与内部压栈顺序不同，但达到目的
	{
		if (t == NULL)
			return;

		stack <BinTreeNode<Ty> *> St;
		BinTreeNode<Ty> *p;
		St.push(t);
		while (!St.empty())
		{
			p = St.top();
			St.pop();
			cout << p->data << " ";
			if (p->Right != NULL)
				St.push(p->Right);
			if (p->Left != NULL)
				St.push(p->Left);
		}
	}

	void preoder_(BinTreeNode<Ty> *t) const
	{
		stack <BinTreeNode<Ty> *> St;
		BinTreeNode<Ty> *p = t;
		while (p != NULL || !St.empty())
		{
			if (p != NULL)
			{
				cout << p->data << " ";
				St.push(p);
				p = p->Left;
			}
			else
			{
				p = St.top();
				//cout << p->data << " ";
				St.pop();
				p = p->Right;
			}
		}
	}

	void inoder_(BinTreeNode<Ty> *t) const
	{
		stack <BinTreeNode<Ty> *> St;
		BinTreeNode<Ty> *p = t;
		while (p != NULL || !St.empty())
		{
			if (p != NULL)
			{
				//cout << p->data << " ";
				St.push(p);
				p = p->Left;
			}
			else
			{
				p = St.top();
				cout << p->data << " ";
				St.pop();
				p = p->Right;
			}

		}
	}

	void postoder_(BinTreeNode<Ty> *t) const
	{
		stack<BinTreeNode<Ty>*> S;
		BinTreeNode<Ty>* Cur;
		BinTreeNode<Ty>* Pre=NULL;
		S.push(t);
		while (!S.empty())
		{
			Cur = S.top();
			if (
				(Cur->Right == NULL)
				|| (Pre != NULL && Pre == Cur->Right) 
				)
			{
				cout << Cur->data << " ";
				S.pop();
				Pre = Cur;
			}
			else
			{
				if (Cur->Right != NULL)
					S.push(Cur->Right);
				if (Cur->Left != NULL)
					S.push(Cur->Left);
			}
		}
	}


private:
	BinTreeNode<Ty>* root;
	Ty reference;



};
/*之形层序*/
/*
Given binary tree {3,9,20,#,#,15,7},

3
/ \
9  20
/  \
15   7


return its zigzag level order traversal as:

[
[3],
[20,9],
[15,7]
]
*/

/*
不同之处在于一行是从左到右遍历，
下一行是从右往左遍历，交叉往返的之字形的层序遍历。
根据其特点我们用到栈的后进先出的特点，
这道题我们维护两个栈，相邻两行分别存到两个栈中，
进栈的顺序也不相同，一个栈是先进左子结点然后右子节点，
另一个栈是先进右子节点然后左子结点，
这样出栈的顺序就是我们想要的之字形了
*/

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	vector<vector<int> >res;
	if (!root) return res;
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	s1.push(root);
	vector<int> out;
	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty()) {
			TreeNode *cur = s1.top();
			s1.pop();
			out.push_back(cur->val);
			if (cur->left) s2.push(cur->left);
			if (cur->right) s2.push(cur->right);
		}
		if (!out.empty()) res.push_back(out);
		out.clear();
		while (!s2.empty()) {
			TreeNode *cur = s2.top();
			s2.pop();
			out.push_back(cur->val);
			if (cur->right) s1.push(cur->right);
			if (cur->left) s1.push(cur->left);
		}
		if (!out.empty()) res.push_back(out);
		out.clear();
	}
	return res;
}

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
	BinTreeNode(Ty item = Ty(), BinTreeNode<Ty>* left = NULL, BinTreeNode<Ty>* right = NULL) :data(item), Left(left), Right(right)
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
	BinTree(Ty ref = Ty()) :root(NULL), reference(ref)
	{}

public:
	void Create()
	{
		Create(root);
	}

	void Create(char* str)
	{
		Create(root, str);
	}

	void preoder()
	{
		cout << "preoderRec:> ";
		preoder(root);
		cout << endl;
	}

	void inoder()
	{
		cout << "inoderRec:> ";
		inoder(root);
		cout << endl;
	}

	void postoder()
	{
		cout << "postoderRec:> ";
		postoder(root);
		cout << endl;
	}

	void leveoder()
	{
		cout << "leveoderNrec:> ";
		leveoder(root);
		cout << endl;
	}

	void hight()
	{
		cout << hight(root) << endl;
	}

	void print()
	{
		print(root, hight(root));
	}

	void NotLeafNum()
	{
		cout << NotLeafNum(root) << endl;
	}

	void LeafNum()
	{
		cout << LeafNum(root) << endl;
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
		return Parent(root, key);
	}

	BinTreeNode<Ty>* Parent_(BinTree<Ty> * p)
	{
		return Parent_(root, p);
	}

	bool Equal(BinTree<Ty> &bt)
	{
		return Equal(root, bt.root);
	}

	void Copy(BinTree<Ty> &bt)
	{
		DestroyBinTree(root);
		root = Copy(bt.root);
	}

	void preoder_()
	{
		cout << "preoder_Nrec:> ";
		preoder_(root);
		//preoder_1(root);
		cout << endl;
	}

	void inoder_()
	{
		cout << "inoder_Nrec:> ";
		inoder_(root);
		cout << endl;
	}

	void postoder_()
	{
		cout << "postoder_Nrec:> ";
		postoder_(root);
		cout << endl;
	}

	void CreatePre(char* pre, char* in, int n)
	{
		CreatePre(root, pre, in, n);
	}

	void CreatePost(char* post, char* in, int n)
	{
		CreatePost_(root, post, in, n);
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

	void CreatePost_(BinTreeNode<Ty> *&t, char* post, char* in, int n)//len：post
	{
		if (n == 0)
			return;
		else
		{
			int k = 0;
			while (post[n - 1] != in[k])
				k++;

			t = new BinTreeNode<Ty>(post[n - 1]);
			CreatePost_(t->Left, post, in, k);
			CreatePost_(t->Right, post + k, in + k + 1, n - k - 1);
		}
	}

	void CreatePre(BinTreeNode<Ty> *&t, char* pre, char* in, int n)
	{
		if (n == 0)
			return;
		else
		{
			int k = 0;
			while (pre[0] != in[k])
				k++;

			t = new BinTreeNode<Ty>(in[k]);
			CreatePre(t->Left, pre + 1, in, k);
			CreatePre(t->Right, pre + k + 1, in + k + 1, n - k - 1);
		}
	}

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
		if (t!=NULL)
		{
			cout << t->data << " ";
			preoder(t->Left);
			preoder(t->Right);
		}
	}

	void inoder(BinTreeNode<Ty> *t) const
	{
		if (t != NULL)
		{
			inoder(t->Left);
			cout << t->data << " ";
			inoder(t->Right);
		}
	}

	void postoder(BinTreeNode<Ty> *t) const
	{
		if (t != NULL)
		{
			postoder(t->Left);
			postoder(t->Right);
			cout << t->data << " ";
		}
	}

	int hight(BinTreeNode<Ty> *t)
	{
		if (t == NULL)
			return 0;
		return hight(t->Left) > hight(t->Right) ?
			hight(t->Left) + 1 : hight(t->Right) + 1;
	}

	void leveoder(BinTreeNode<Ty> *t) const
	{
		if (NULL == t)
			return ;
		queue<BinTreeNode<Ty>*> Q;
		BinTreeNode<Ty> *point;
		Q.push(t);
		while (!Q.empty())
		{
			point = Q.front();
			Q.pop();
			cout << point->data << " ";
			
			if (point->Left != NULL)
				Q.push(point->Left);
			if (point->Right != NULL)
				Q.push(point->Right);
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
		if (t == NULL)
			return 0;
		else if (!(t->Left) && !(t->Right))
			return 0;
		else
			return NotLeafNum(t->Left) + NotLeafNum(t->Right) + 1;
	}

	int LeafNum(BinTreeNode<Ty> *t)const
	{
		if (t == NULL)
			return 0;
		else if (!(t->Left) && !(t->Right))
			return 1;
		else
			return LeafNum(t->Left) + LeafNum(t->Right);
	}

	int Size(BinTreeNode<Ty> *t)const
	{
		//return NotLeafNum(t) + LeafNum(t);
		if (t == NULL)
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
		if (t == NULL)
			return NULL;
		if (key == t->data)
			return t;
		BinTreeNode<Ty>* PLeft = _Search(t->Left, key);
		if (PLeft != NULL)
			return PLeft;
		else
			return _Search(t->Right,key);
	}

	BinTreeNode<Ty>* Parent(BinTreeNode<Ty> *t, const Ty &key)
	{
		if (t == NULL || t->data == key)
			return NULL;
		if ((t->Left != NULL && t->Left->data == key) || (t->Right != NULL && t->Right->data == key))
			return t;
		BinTreeNode<Ty> *Pleft;
		if ((Pleft = Parent(t->Left, key)) != NULL)
			return Pleft;
		else
			return Parent(t->Right, key);
	}

	BinTreeNode<Ty>* Parent_(BinTreeNode<Ty> *t, BinTreeNode<Ty> *p)
	{
		if (t == NULL || t == p)
			return NULL;
		if (t->Left == p || t->Right == p)
			return t;
		BinTreeNode<Ty> *Pleft;
		if ((Pleft = Parent(t->Left, p)) != NULL)
			return Pleft;
		else
			return Parent(t->Right, p);
	}

	bool  Equal(BinTreeNode<Ty>* t1, BinTreeNode<Ty>* t2)
	{
		if (NULL == t1 && NULL == t2)
			return true;
		return((t1 != NULL && t2 != NULL)
			&& (t1->data == t2->data)
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
			BinTreeNode<Ty>* Newroot = new BinTreeNode<Ty>(t->data);
			Newroot->Left = Copy(t->Left);
			Newroot->Right = Copy(t->Right);
			return Newroot;
		}
	}

	void preoder_1(BinTreeNode<Ty> *t) const// 与内部压栈顺序不同，但达到目的
	{
		if (NULL == t)
			return;
		stack<BinTreeNode<Ty>*> St;
		BinTreeNode<Ty>* p;
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
				St.pop();
				p = p->Right;
			}
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
				St.pop();
				p = p->Right();
			}
		}
	}


	
	/*void inoder_(BinTreeNode<Ty> *t) const
	{
		stack <BinTreeNode<Ty> *> St;
		BinTreeNode<Ty> *p = t;
		do 
		{
			while (p!=NULL)
			{
				St.push(p);
				p = p->Left;
			}
			if (!St.empty())
			{
				p = St.top();
				cout << p->data << " ";
				St.pop();
				p = p->Right;
			}
		} while (p!=NULL || !St.empty());
	}*/

	void inoder_(BinTreeNode<Ty> *t) const
	{
		stack <BinTreeNode<Ty> *> St;
		BinTreeNode<Ty> *p = t;
		while (p != NULL || !St.empty())
		{
			if (p != NULL)
			{
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
		stack<BinTreeNode<Ty>*> St;
		BinTreeNode<Ty>* Cur = NULL;
		BinTreeNode<Ty>* Pre = NULL;	//指向刚弹出的元素
		St.push(t);

		while (!St.empty())
		{
			Cur = St.top();
			if (
				(Cur->Left == NULL && Cur->Right == NULL)/*叶子节点则出栈*/
				|| (Pre != NULL && (Pre == Cur->Left || Pre == Cur->Right))/*孩子已经出栈，则出栈*/
				)
			{
				cout << Cur->data << " ";
				St.pop();
				Pre = Cur;
			}
			else
			{
				if (Cur->Right != NULL)
					St.push(Cur->Right);
				if (Cur->Left != NULL)
					St.push(Cur->Left);
			}
		}

		
	}


	
private:
	BinTreeNode<Ty>* root;
	Ty reference;
};


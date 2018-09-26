#pragma once
#ifndef poly_h
#define poly_h
#define Status int
#define ERROR 0
#define OK 1
#include <iostream>
using namespace std;
typedef struct ElemType
{
	float coef;//系数
	int expn;//指数
}ElemType;
typedef struct Lnode 
{
	ElemType data;
	struct Lnode *next;
}Lnode;
class Poly
{
private:
	Lnode *head;
public:
	Poly();
	~Poly();
	Status InputPoly(int n);//正序建表
	void OutputPoly();
	void MergePoly(Poly &La, Poly &Lb);//一元多项式合并
};
Poly::Poly()
{
	head = new Lnode();
	head->next = NULL;
}
Poly::~Poly()
{
	delete[] head;
}
Status Poly::InputPoly(int n)//正序建表
{
	Lnode *last=head, *p;
	for(int j=0;j<n;j++)
	{
		p = new Lnode();
		if (!p) return ERROR;
		cin >> p->data.coef>>p->data.expn;
		last->next = p;
		last = p;
	}
	last->next = NULL;
	return OK;
}
void Poly::OutputPoly()
{
	Lnode *p = head->next;
	while(p)
	{
		cout << p->data.coef << "," << p->data.expn << endl;
		p = p->next;
	}
}
void Poly::MergePoly(Poly &La, Poly &Lb)//一元多项式合并
{
	Lnode *pa, *pb, *pc,*p;
	pa = La.head->next, pb = Lb.head->next, pc = head;
	while (pa&&pb)
	{
		if (pa->data.expn < pb->data.expn)
		{
			p = new Lnode(); p->data = pa->data;
			pc->next = p; pa = pa->next; pc = pc->next;
		}
		else if(pa->data.expn > pb->data.expn)
		{
			p = new Lnode(); p->data = pb->data;
			pc->next = p; pb = pb->next; pc = pc->next;
		}
		else
		{
			if(pa->data.coef+pb->data.coef)
			{
				p = new Lnode();
				p->data.coef = pa->data.coef + pb->data.coef;
				p->data.expn = pa->data.expn;
				pc->next=p; 
				pc = pc->next;
			}
			pa = pa->next; pb = pb->next;
		}
	}
	while (pa) { p = new Lnode(); p->data = pa->data; pc->next = p; pa =pa->next; pc = pc->next; }
	while (pb) { p = new Lnode(); p->data = pb->data; pc->next = p; pb = pb->next; pc = pc->next;}
}
#endif // !1


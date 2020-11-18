#include<iostream>

#define ElemType int
#define Status int
#define OK 1
#define ERROR 0


typedef struct DLNode
{
	ElemType data;
	DLNode *next;
	DLNode *pre;
}DLNode, *DLinkList;

void CreateNonCircu_DoubleLink(DLinkList&head, int num)
{
	head = (DLinkList)malloc(sizeof(DLNode));
	DLinkList s, r;
	r = head;
	for (int i = 0; i < num; i++)
	{
		s = (DLinkList)malloc(sizeof(DLNode));
		std::cin >> s->data;
		r->next = s;
		s->pre = r;
		r = s;
	}
	r->next = nullptr;

}

void CreateCircu_DoubleLink(DLinkList&head, int num)
{
	head = (DLinkList)malloc(sizeof(DLNode));
	DLinkList s, r;
	r = head;
	for (int i = 0; i < num; i++)
	{
		s = (DLinkList)malloc(sizeof(DLNode));
		std::cin >> s->data;
		r->next = s;
		s->pre = r;
		r = s;
	}
	r->next = head;

}
void CreateListTail(DLinkList *L, int n)
{
	DLinkList p, r;
	int i;
	*L = (DLinkList)malloc(sizeof(DLNode)); /* L为整个线性表 */
	r = *L;                                /* r为指向尾部的结点 */
	for (i = 0; i < n; i++)
	{
		p = (DLNode *)malloc(sizeof(DLNode)); /*  生成新结点 */
		std::cin >> p->data;           /*  随机生成100以内的数字 */
		r->next = p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}



void Output(DLinkList& L, int n)
{
	DLinkList p;
	p = L->next;
	int flag = 1;
	while (n--)
	{
		if (flag)
		{
			flag = 0;
			std::cout << p->data;
		}
		else
			std::cout << " " << p->data;
		p = p->next;
	}
	std::cout << std::endl;
}

Status DuplexBubbleSort(DLinkList&L)
{
	if (!L)
	{
		return false;
	}
	bool exchange = true;//是否发生交换
	DLinkList head = L;//表头，向下冒泡的起点
	DLinkList tail = nullptr;//表尾,向上冒泡起点
	DLinkList p = nullptr;
	while (exchange)
	{
		p = head->next;//工作指针，指向当前节点
		exchange = false;//假定无交换
		while (p->next!=tail)//向下冒泡，每一次使最大元素沉底
		{
			if (p->data>p->next->data)
			{
				//交换
				exchange = true;
				ElemType tmp = p->data;
				p->data = p->next->data;
				p->next->data = tmp;
	
			}
			else
			{
				p = p->next;//无交换,指针后移
			}//if
		}//while

		tail = p;//准备向上起泡
		p = tail->pre;

		while (exchange&&p->pre!=head)//向上冒泡，每一次最小元素冒出
		{
			if (p->data<p->pre->data)//交换
			{
				exchange = true;
				ElemType tmp = p->data;
				p->data = p->pre->data;
				p->pre->data = tmp;

			}
			else
			{
				p = p->pre;//无交换，指针前移
			}//if
		}//while

		head = p;//准备向下起泡
	}//while(exchange)
	return true;
}

int main()
{
	while (true)
	{
		DLinkList DL = nullptr;
		int num;
		std::cin >> num;
		if (!num)
		{
			break;
		}
		//CreateCircu_DoubleLink(DL, num);
		CreateNonCircu_DoubleLink(DL, num);
		if (DuplexBubbleSort(DL))
		{
			Output(DL, num);
		} 
	}
	return 0;
}
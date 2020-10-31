#include<iostream>
#include<stack>





#define ok 1
#define error 0
#define true 1
#define false 0
#define succeed 0//�ǵݹ�������򻮷ֳɹ�
#define max_length_insert_sort 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */

typedef int status; 


#define maxsize 100  /* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� ��Ҫ̫���Ա���overflow */
typedef struct
{
	int r[maxsize+1];	/* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
	int length;			/* ���ڼ�¼˳���ĳ��� */
}sqlist;

/* ����l������r���±�Ϊi��j��ֵ */
void swap(sqlist *l,int i,int j) 
{ 
	int temp=l->r[i]; 
	l->r[i]=l->r[j]; 
	l->r[j]=temp; 
}

/* �ǵݹ���������Ż��㷨 */
int partition2(sqlist *l, int& low, int& high)
{
	int pivotkey;

	//int m = low + (high - low) / 2; /* ���������м��Ԫ�ص��±� */
	//if (l->r[low] > l->r[high])
	//	swap(l, low, high);	/* ����������Ҷ����ݣ���֤��˽�С */
	//if (l->r[m] > l->r[high])
	//	swap(l, high, m);		/* �����м����Ҷ����ݣ���֤�м��С */
	//if (l->r[m] > l->r[low])
	//	swap(l, m, low);		/* �����м���������ݣ���֤��˽�С */

	pivotkey = l->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	l->r[0] = pivotkey;  /* ������ؼ��ֱ��ݵ�l->r[0] */
	while (low < high) /*  �ӱ�����˽�������м�ɨ�� */
	{
		while (low < high&&l->r[high] >= pivotkey)
			high--;
		l->r[low] = l->r[high];
		while (low < high&&l->r[low] <= pivotkey)
			low++;
		l->r[high] = l->r[low];
	}
	l->r[low] = l->r[0];
	return low; /* ������������λ�� */
}

/* ����˳���l���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int partition3(sqlist *l, int& low, int& high)
{
	int pivotkey;

	pivotkey = l->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	while (low < high) /*  �ӱ�����˽�������м�ɨ�� */
	{
		while (low < high&&l->r[high] >= pivotkey)
			high--;
		swap(l, low, high);/* ���������¼С�ļ�¼�������Ͷ� */
		while (low < high&&l->r[low] <= pivotkey)
			low++;
		swap(l, low, high);/* ���������¼��ļ�¼�������߶� */
	}
	return low; /* ������������λ�� */
}

void print(sqlist l)
{
	int i;
	for(i=1;i<l.length;i++)
		printf("%d,",l.r[i]);
	printf("%d",l.r[i]);
	printf("\n");
}

/* ��˳���l����������ð����������棩 */
void bubblesort0(sqlist *l)
{ 
	int i,j;
	for(i=1;i<l->length;i++)
	{
		for(j=i+1;j<=l->length;j++)
		{
			if(l->r[i]>l->r[j])
			{
				 swap(l,i,j);/* ����l->r[i]��l->r[j]��ֵ */
			}
		}
	}
}

/* ��˳���l��ð������ */
void bubblesort(sqlist *l)
{ 
	int i,j;
	for(i=1;i<l->length;i++)
	{
		for(j=l->length-1;j>=i;j--)  /* ע��j�ǴӺ���ǰѭ�� */
		{
			if(l->r[j]>l->r[j+1]) /* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				 swap(l,j,j+1);/* ����l->r[j]��l->r[j+1]��ֵ */
			}
		}
	}
}

/* ��˳���l���Ľ�ð���㷨 */
void bubblesort2(sqlist *l)
{ 
	int i,j;
	status flag=true;			/* flag������Ϊ��� */
	for(i=1;i<l->length && flag;i++) /* ��flagΪtrue˵���й����ݽ���������ֹͣѭ�� */
	{
		flag=false;				/* ��ʼΪfalse */
		for(j=l->length-1;j>=i;j--)
		{
			if(l->r[j]>l->r[j+1])
			{
				 swap(l,j,j+1);	/* ����l->r[j]��l->r[j+1]��ֵ */
				 flag=true;		/* ��������ݽ�������flagΪtrue */
			}
		}
	}
}


/* ��˳���l����ѡ������ */
void selectsort(sqlist *l)
{
	int i,j,min;
	for(i=1;i<l->length;i++)
	{ 
		min = i;						/* ����ǰ�±궨��Ϊ��Сֵ�±� */
		for (j = i+1;j<=l->length;j++)/* ѭ��֮������� */
        {
			if (l->r[min]>l->r[j])	/* �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;				/* ���˹ؼ��ֵ��±긳ֵ��min */
        }
		if(i!=min)						/* ��min������i��˵���ҵ���Сֵ������ */
			swap(l,i,min);				/* ����l->r[i]��l->r[min]��ֵ */
	}
}

/* ��˳���l��ֱ�Ӳ������� */
void insertsort(sqlist *l)
{ 
	int i,j;
	for(i=2;i<=l->length;i++)
	{
		if (l->r[i]<l->r[i-1]) /* �轫l->r[i]���������ӱ� */
		{
			l->r[0]=l->r[i]; /* �����ڱ� */
			for(j=i-1;l->r[j]>l->r[0];j--)
				l->r[j+1]=l->r[j]; /* ��¼���� */
			l->r[j+1]=l->r[0]; /* ���뵽��ȷλ�� */
		}
	}
}

/* ��˳���l��ϣ������ */
void shellsort(sqlist *l)
{
	int i,j,k=0;
	int increment=l->length;
	do
	{
		increment=increment/3+1;/* �������� */
		for(i=increment+1;i<=l->length;i++)
		{
			if (l->r[i]<l->r[i-increment])/*  �轫l->r[i]�������������ӱ� */ 
			{ 
				l->r[0]=l->r[i]; /*  �ݴ���l->r[0] */
				for(j=i-increment;j>0 && l->r[0]<l->r[j];j-=increment)
					l->r[j+increment]=l->r[j]; /*  ��¼���ƣ����Ҳ���λ�� */
				l->r[j+increment]=l->r[0]; /*  ���� */
			}
		}
		printf("	��%d��������: ",++k);
		print(*l);
	}
	while(increment>1);

}


/* ������********************************** */

/* ��֪l->r[s..m]�м�¼�Ĺؼ��ֳ�l->r[s]֮�������ѵĶ��壬 */
/* ����������l->r[s]�Ĺؼ���,ʹl->r[s..m]��Ϊһ���󶥶� */
void heapadjust(sqlist *l,int s,int m)
{ 
	int temp,j;
	temp=l->r[s];
	for(j=2*s;j<=m;j*=2) /* �عؼ��ֽϴ�ĺ��ӽ������ɸѡ */
	{
		if(j<m && l->r[j]<l->r[j+1])
			++j; /* jΪ�ؼ����нϴ�ļ�¼���±� */
		if(temp>=l->r[j])
			break; /* rcӦ������λ��s�� */
		l->r[s]=l->r[j];
		s=j;
	}
	l->r[s]=temp; /* ���� */
}

/*  ��˳���l���ж����� */
void heapsort(sqlist *l)
{
	int i;
	for(i=l->length/2;i>0;i--) /*  ��l�е�r������һ������� */
		 heapadjust(l,i,l->length);

	for(i=l->length;i>1;i--)
	{ 
		 swap(l,1,i); /* ���Ѷ���¼�͵�ǰδ�����������е����һ����¼���� */
		 heapadjust(l,1,i-1); /*  ��l->r[1..i-1]���µ���Ϊ����� */
	}
}

/* **************************************** */


/* �鲢����********************************** */

/* �������sr[i..m]��sr[m+1..n]�鲢Ϊ�����tr[i..n] */
void merge(int sr[],int tr[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* ��sr�м�¼��С����ز���tr */
	{
		if (sr[i]<sr[j])
			tr[k]=sr[i++];
		else
			tr[k]=sr[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			tr[k+l]=sr[i+l];		/* ��ʣ���sr[i..m]���Ƶ�tr */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			tr[k+l]=sr[j+l];		/* ��ʣ���sr[j..n]���Ƶ�tr */
	}
}


/* �ݹ鷨 */
/* ��sr[s..t]�鲢����Ϊtr1[s..t] */
void msort(int sr[],int tr1[],int s, int t)
{
	int m;
	int tr2[maxsize+1];
	if(s==t)
		tr1[s]=sr[s];
	else
	{
		m=(s+t)/2;				/* ��sr[s..t]ƽ��Ϊsr[s..m]��sr[m+1..t] */
		msort(sr,tr2,s,m);		/* �ݹ�ؽ�sr[s..m]�鲢Ϊ�����tr2[s..m] */
		msort(sr,tr2,m+1,t);	/* �ݹ�ؽ�sr[m+1..t]�鲢Ϊ�����tr2[m+1..t] */
		merge(tr2,tr1,s,m,t);	/* ��tr2[s..m]��tr2[m+1..t]�鲢��tr1[s..t] */
	}
}

/* ��˳���l���鲢���� */
void mergesort(sqlist *l)
{ 
 	msort(l->r,l->r,1,l->length);
}

/* �ǵݹ鷨 */
/* ��sr[]�����ڳ���Ϊs�������������鲢��tr[] */
void mergepass(int sr[],int tr[],int s,int n)
{
	int i=1;
	int j;
	while(i <= n-2*s+1)
	{/* �����鲢 */
		merge(sr,tr,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) /* �鲢����������� */
		merge(sr,tr,i,i+s-1,n);
	else /* �����ֻʣ�µ��������� */
		for(j =i;j <= n;j++)
			tr[j] = sr[j];
}

/* ��˳���l���鲢�ǵݹ����� */
void mergesort2(sqlist *l)
{
	int* tr=(int*)malloc(l->length * sizeof(int));/* �������ռ� */
    int k=1;
	while(k<l->length)
	{
		mergepass(l->r,tr,k,l->length);
		k=2*k;/* �����г��ȼӱ� */
		mergepass(tr,l->r,k,l->length);
		k=2*k;/* �����г��ȼӱ� */       
	}
}

//�ǵݹ鷨�������㷨
status quicksort3(sqlist*a)
{
	int length = a->length;
	if (!a&&length <= 0)
	{
		return error;
	}

	int low = 1, high = length ;//���½�
	int low_new = 1, high_new = length;//�±����½�
	int flag = ok;//�����Ƿ�ɹ�
	int mid = length / 2;//���м�λ��
	while (flag)
	{
		low = partition3(a, low, high);//ok
		//low = partition2(a, low, high);//no
		

		if (low == mid - 1)//���ֳɹ�
		{
			flag = succeed;
		}
		else
		{
			if (low < mid - 1)
			{
				low_new = ++low;
				high = high_new;
			}
			else
			{
				high_new = --high;
				low = low_new;
			}
		}

	}
	return ok;
}

/* **************************************** */

/* ��������******************************** */
 
/* ����˳���l���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�� */
/* ��ʱ����֮ǰ(��)�ļ�¼������(С)������ */
int partition(sqlist *l,int low,int high)
{ 
	int pivotkey;

	pivotkey=l->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	while(low<high) /*  �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(low<high&&l->r[high]>=pivotkey)
			high--;
		 swap(l,low,high);/* ���������¼С�ļ�¼�������Ͷ� */
		 while(low<high&&l->r[low]<=pivotkey)
			low++;
		 swap(l,low,high);/* ���������¼��ļ�¼�������߶� */
	}
	return low; /* ������������λ�� */
}

/* ��˳���l�е�������l->r[low..high]���������� */
void qsort(sqlist *l,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=partition(l,low,high); /*  ��l->r[low..high]һ��Ϊ�����������ֵpivot */
			qsort(l,low,pivot-1);		/*  �Ե��ӱ�ݹ����� */
			qsort(l,pivot+1,high);		/*  �Ը��ӱ�ݹ����� */
	}
}

/* ��˳���l���������� */
void quicksort(sqlist *l)
{ 
	qsort(l,1,l->length);
}

/* **************************************** */

/* �Ľ����������******************************** */

/* ���������Ż��㷨 */
int partition1(sqlist *l,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* ���������м��Ԫ�ص��±� */  
	if (l->r[low]>l->r[high])			
		swap(l,low,high);	/* ����������Ҷ����ݣ���֤��˽�С */
	if (l->r[m]>l->r[high])
		swap(l,high,m);		/* �����м����Ҷ����ݣ���֤�м��С */
	if (l->r[m]>l->r[low])
		swap(l,m,low);		/* �����м���������ݣ���֤��˽�С */
	
	pivotkey=l->r[low]; /* ���ӱ�ĵ�һ����¼�������¼ */
	l->r[0]=pivotkey;  /* ������ؼ��ֱ��ݵ�l->r[0] */
	while(low<high) /*  �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(low<high&&l->r[high]>=pivotkey)
			high--;
		 l->r[low]=l->r[high];
		 while(low<high&&l->r[low]<=pivotkey)
			low++;
		 l->r[high]=l->r[low];
	}
	l->r[low]=l->r[0];
	return low; /* ������������λ�� */
}



void qsort1(sqlist *l,int low,int high)
{ 
	int pivot;
	if((high-low)>max_length_insert_sort)
	{
		while(low<high)
		{
			pivot=partition1(l,low,high); /*  ��l->r[low..high]һ��Ϊ�����������ֵpivot */
			qsort1(l,low,pivot-1);		/*  �Ե��ӱ�ݹ����� */
			/* qsort(l,pivot+1,high);		/*  �Ը��ӱ�ݹ����� */
			low=pivot+1;	/* β�ݹ� */
		}
	}
	else
		insertsort(l);
}

void _qsort1_for_iteration(int &low,int &high,const int& piv)
{
	high = piv - 1;
}


//�����ĳɵ���
void qsort1_iteration(sqlist *l, int low, int high)
{
	int pivot;


	while (low < high)
	{
		pivot = partition1(l, low, high); /*  ��l->r[low..high]һ��Ϊ�����������ֵpivot */
		_qsort1_for_iteration(low, high, pivot);
		low = pivot + 1;
	}
	
}

//void quicksort1_iteration_access(sqlist *l)
//{
//	qsort1_iteration(l, 1, l->length);
//}
//
/* ��˳���l���������� */
void quicksort1(sqlist *l)
{ 
	qsort1(l,1,l->length);
}



void QuicksortNonRecur(sqlist *L, int b, int e) {
	if (b >= e) return;
	std::stack< std::pair<int, int> > stk;
	stk.push(std::make_pair(b, e));
	while (!stk.empty()) {
		std::pair<int, int> pair = stk.top();
		stk.pop();
		if (pair.first >= pair.second) continue;
		int p = partition(L, pair.first, pair.second);
		if (p < pair.second) stk.push(std::make_pair(p + 1, e));
		if (p > pair.first) stk.push(std::make_pair(b, p - 1));
	}
}

void QuicksortNonRecur_Access(sqlist*l)
{
	QuicksortNonRecur(l, 1, l->length);
}


//void QuicksortNonRecur2(sqlist *L, int b, int e) {//����
//	if (b >= e) return;
//	std::stack< std::pair<int, int> > stk;
//	stk.push(std::make_pair(b, e));
//	while (!stk.empty()) {
//		std::pair<int, int> pair = stk.top();
//		stk.pop();
//		if (pair.first >= pair.second) continue;
//		int p = partition1(L, pair.first, pair.second);//����
//		if (p < pair.second) stk.push(std::make_pair(p + 1, e));
//		if (p > pair.first) stk.push(std::make_pair(b, p - 1));
//	}
//}

void QuicksortNonRecur_Access2(sqlist*l)
{
	QuicksortNonRecur2(l, 1, l->length);
}
/* **************************************** */
#define n 9
int main()
{
   int i;
   
   /* int d[n]={9,1,5,8,3,7,4,6,2}; */
   int d[n]={50,10,90,30,70,40,80,60,20};
   /* int d[n]={9,8,7,6,5,4,3,2,1}; */

   sqlist l0, l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11,l12;
   
   for(i=0;i<n;i++)
     l0.r[i+1]=d[i];
   l0.length=n;
   l12 = l1 = l2 = l3 = l4 = l5 = l6 = l7 = l8 = l9 = l10 = l11 = l0;
   printf("����ǰ:\n");
   print(l0);

   printf("����ð������:\n");
   bubblesort0(&l0);
   print(l0);
   
   printf("ð������:\n");
   bubblesort(&l1);
   print(l1);
   
   printf("�Ľ�ð������:\n");
   bubblesort2(&l2);
   print(l2);
   
   printf("ѡ������:\n");
   selectsort(&l3);
   print(l3);
   
   printf("ֱ�Ӳ�������:\n");
   insertsort(&l4);
   print(l4);

   printf("ϣ������:\n");
   shellsort(&l5);
   print(l5);
	
   printf("������:\n");
   heapsort(&l6);
   print(l6);

   printf("�鲢���򣨵ݹ飩:\n");
   mergesort(&l7);
   print(l7);

   printf("�鲢���򣨷ǵݹ飩:\n");
   mergesort2(&l8);
   print(l8);

   printf("��������:\n");
   quicksort(&l9);
   print(l9);

   printf("�Ľ���������:\n");
   quicksort1(&l10);
   print(l10);

   printf("�ǵݹ��������:\n");
   QuicksortNonRecur_Access(&l11);
   print(l11);

   printf("�ǵݹ���������Ż�:\n");//����
   QuicksortNonRecur_Access2(&l12);
   print(l12);

   //printf("�ǵݹ���������Ż�:\n");
   //quicksort1_iteration_access(&l12);
   //print(l12);
    /*����������*/
	/* 
	srand(time(0));  
	int max=10000;
	int d[10000];
	int i;
	sqlist l0;
	for(i=0;i<max;i++)
		d[i]=rand()%max+1;
	for(i=0;i<max;i++)
		l0.r[i+1]=d[i];
	l0.length=max;
	mergesort(l0);
	print(l0);
	*/
	return 0;
}

#include<iostream>
#include<stack>





#define ok 1
#define error 0
#define true 1
#define false 0
#define succeed 0//非递归快速排序划分成功
#define max_length_insert_sort 7 /* 用于快速排序时判断是否选用插入排序阙值 */

typedef int status; 


#define maxsize 100  /* 用于要排序数组个数最大值，可根据需要修改 不要太大以避免overflow */
typedef struct
{
	int r[maxsize+1];	/* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
	int length;			/* 用于记录顺序表的长度 */
}sqlist;

/* 交换l中数组r的下标为i和j的值 */
void swap(sqlist *l,int i,int j) 
{ 
	int temp=l->r[i]; 
	l->r[i]=l->r[j]; 
	l->r[j]=temp; 
}

/* 非递归快速排序优化算法 */
int partition2(sqlist *l, int& low, int& high)
{
	int pivotkey;

	//int m = low + (high - low) / 2; /* 计算数组中间的元素的下标 */
	//if (l->r[low] > l->r[high])
	//	swap(l, low, high);	/* 交换左端与右端数据，保证左端较小 */
	//if (l->r[m] > l->r[high])
	//	swap(l, high, m);		/* 交换中间与右端数据，保证中间较小 */
	//if (l->r[m] > l->r[low])
	//	swap(l, m, low);		/* 交换中间与左端数据，保证左端较小 */

	pivotkey = l->r[low]; /* 用子表的第一个记录作枢轴记录 */
	l->r[0] = pivotkey;  /* 将枢轴关键字备份到l->r[0] */
	while (low < high) /*  从表的两端交替地向中间扫描 */
	{
		while (low < high&&l->r[high] >= pivotkey)
			high--;
		l->r[low] = l->r[high];
		while (low < high&&l->r[low] <= pivotkey)
			low++;
		l->r[high] = l->r[low];
	}
	l->r[low] = l->r[0];
	return low; /* 返回枢轴所在位置 */
}

/* 交换顺序表l中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均不大(小)于它。 */
int partition3(sqlist *l, int& low, int& high)
{
	int pivotkey;

	pivotkey = l->r[low]; /* 用子表的第一个记录作枢轴记录 */
	while (low < high) /*  从表的两端交替地向中间扫描 */
	{
		while (low < high&&l->r[high] >= pivotkey)
			high--;
		swap(l, low, high);/* 将比枢轴记录小的记录交换到低端 */
		while (low < high&&l->r[low] <= pivotkey)
			low++;
		swap(l, low, high);/* 将比枢轴记录大的记录交换到高端 */
	}
	return low; /* 返回枢轴所在位置 */
}

void print(sqlist l)
{
	int i;
	for(i=1;i<l.length;i++)
		printf("%d,",l.r[i]);
	printf("%d",l.r[i]);
	printf("\n");
}

/* 对顺序表l作交换排序（冒泡排序初级版） */
void bubblesort0(sqlist *l)
{ 
	int i,j;
	for(i=1;i<l->length;i++)
	{
		for(j=i+1;j<=l->length;j++)
		{
			if(l->r[i]>l->r[j])
			{
				 swap(l,i,j);/* 交换l->r[i]与l->r[j]的值 */
			}
		}
	}
}

/* 对顺序表l作冒泡排序 */
void bubblesort(sqlist *l)
{ 
	int i,j;
	for(i=1;i<l->length;i++)
	{
		for(j=l->length-1;j>=i;j--)  /* 注意j是从后往前循环 */
		{
			if(l->r[j]>l->r[j+1]) /* 若前者大于后者（注意这里与上一算法的差异）*/
			{
				 swap(l,j,j+1);/* 交换l->r[j]与l->r[j+1]的值 */
			}
		}
	}
}

/* 对顺序表l作改进冒泡算法 */
void bubblesort2(sqlist *l)
{ 
	int i,j;
	status flag=true;			/* flag用来作为标记 */
	for(i=1;i<l->length && flag;i++) /* 若flag为true说明有过数据交换，否则停止循环 */
	{
		flag=false;				/* 初始为false */
		for(j=l->length-1;j>=i;j--)
		{
			if(l->r[j]>l->r[j+1])
			{
				 swap(l,j,j+1);	/* 交换l->r[j]与l->r[j+1]的值 */
				 flag=true;		/* 如果有数据交换，则flag为true */
			}
		}
	}
}


/* 对顺序表l作简单选择排序 */
void selectsort(sqlist *l)
{
	int i,j,min;
	for(i=1;i<l->length;i++)
	{ 
		min = i;						/* 将当前下标定义为最小值下标 */
		for (j = i+1;j<=l->length;j++)/* 循环之后的数据 */
        {
			if (l->r[min]>l->r[j])	/* 如果有小于当前最小值的关键字 */
                min = j;				/* 将此关键字的下标赋值给min */
        }
		if(i!=min)						/* 若min不等于i，说明找到最小值，交换 */
			swap(l,i,min);				/* 交换l->r[i]与l->r[min]的值 */
	}
}

/* 对顺序表l作直接插入排序 */
void insertsort(sqlist *l)
{ 
	int i,j;
	for(i=2;i<=l->length;i++)
	{
		if (l->r[i]<l->r[i-1]) /* 需将l->r[i]插入有序子表 */
		{
			l->r[0]=l->r[i]; /* 设置哨兵 */
			for(j=i-1;l->r[j]>l->r[0];j--)
				l->r[j+1]=l->r[j]; /* 记录后移 */
			l->r[j+1]=l->r[0]; /* 插入到正确位置 */
		}
	}
}

/* 对顺序表l作希尔排序 */
void shellsort(sqlist *l)
{
	int i,j,k=0;
	int increment=l->length;
	do
	{
		increment=increment/3+1;/* 增量序列 */
		for(i=increment+1;i<=l->length;i++)
		{
			if (l->r[i]<l->r[i-increment])/*  需将l->r[i]插入有序增量子表 */ 
			{ 
				l->r[0]=l->r[i]; /*  暂存在l->r[0] */
				for(j=i-increment;j>0 && l->r[0]<l->r[j];j-=increment)
					l->r[j+increment]=l->r[j]; /*  记录后移，查找插入位置 */
				l->r[j+increment]=l->r[0]; /*  插入 */
			}
		}
		printf("	第%d趟排序结果: ",++k);
		print(*l);
	}
	while(increment>1);

}


/* 堆排序********************************** */

/* 已知l->r[s..m]中记录的关键字除l->r[s]之外均满足堆的定义， */
/* 本函数调整l->r[s]的关键字,使l->r[s..m]成为一个大顶堆 */
void heapadjust(sqlist *l,int s,int m)
{ 
	int temp,j;
	temp=l->r[s];
	for(j=2*s;j<=m;j*=2) /* 沿关键字较大的孩子结点向下筛选 */
	{
		if(j<m && l->r[j]<l->r[j+1])
			++j; /* j为关键字中较大的记录的下标 */
		if(temp>=l->r[j])
			break; /* rc应插入在位置s上 */
		l->r[s]=l->r[j];
		s=j;
	}
	l->r[s]=temp; /* 插入 */
}

/*  对顺序表l进行堆排序 */
void heapsort(sqlist *l)
{
	int i;
	for(i=l->length/2;i>0;i--) /*  把l中的r构建成一个大根堆 */
		 heapadjust(l,i,l->length);

	for(i=l->length;i>1;i--)
	{ 
		 swap(l,1,i); /* 将堆顶记录和当前未经排序子序列的最后一个记录交换 */
		 heapadjust(l,1,i-1); /*  将l->r[1..i-1]重新调整为大根堆 */
	}
}

/* **************************************** */


/* 归并排序********************************** */

/* 将有序的sr[i..m]和sr[m+1..n]归并为有序的tr[i..n] */
void merge(int sr[],int tr[],int i,int m,int n)
{
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* 将sr中记录由小到大地并入tr */
	{
		if (sr[i]<sr[j])
			tr[k]=sr[i++];
		else
			tr[k]=sr[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			tr[k+l]=sr[i+l];		/* 将剩余的sr[i..m]复制到tr */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			tr[k+l]=sr[j+l];		/* 将剩余的sr[j..n]复制到tr */
	}
}


/* 递归法 */
/* 将sr[s..t]归并排序为tr1[s..t] */
void msort(int sr[],int tr1[],int s, int t)
{
	int m;
	int tr2[maxsize+1];
	if(s==t)
		tr1[s]=sr[s];
	else
	{
		m=(s+t)/2;				/* 将sr[s..t]平分为sr[s..m]和sr[m+1..t] */
		msort(sr,tr2,s,m);		/* 递归地将sr[s..m]归并为有序的tr2[s..m] */
		msort(sr,tr2,m+1,t);	/* 递归地将sr[m+1..t]归并为有序的tr2[m+1..t] */
		merge(tr2,tr1,s,m,t);	/* 将tr2[s..m]和tr2[m+1..t]归并到tr1[s..t] */
	}
}

/* 对顺序表l作归并排序 */
void mergesort(sqlist *l)
{ 
 	msort(l->r,l->r,1,l->length);
}

/* 非递归法 */
/* 将sr[]中相邻长度为s的子序列两两归并到tr[] */
void mergepass(int sr[],int tr[],int s,int n)
{
	int i=1;
	int j;
	while(i <= n-2*s+1)
	{/* 两两归并 */
		merge(sr,tr,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) /* 归并最后两个序列 */
		merge(sr,tr,i,i+s-1,n);
	else /* 若最后只剩下单个子序列 */
		for(j =i;j <= n;j++)
			tr[j] = sr[j];
}

/* 对顺序表l作归并非递归排序 */
void mergesort2(sqlist *l)
{
	int* tr=(int*)malloc(l->length * sizeof(int));/* 申请额外空间 */
    int k=1;
	while(k<l->length)
	{
		mergepass(l->r,tr,k,l->length);
		k=2*k;/* 子序列长度加倍 */
		mergepass(tr,l->r,k,l->length);
		k=2*k;/* 子序列长度加倍 */       
	}
}

//非递归法，划分算法
status quicksort3(sqlist*a)
{
	int length = a->length;
	if (!a&&length <= 0)
	{
		return error;
	}

	int low = 1, high = length ;//上下界
	int low_new = 1, high_new = length;//新表上下界
	int flag = ok;//划分是否成功
	int mid = length / 2;//表中间位置
	while (flag)
	{
		low = partition3(a, low, high);//ok
		//low = partition2(a, low, high);//no
		

		if (low == mid - 1)//划分成功
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

/* 快速排序******************************** */
 
/* 交换顺序表l中子表的记录，使枢轴记录到位，并返回其所在位置 */
/* 此时在它之前(后)的记录均不大(小)于它。 */
int partition(sqlist *l,int low,int high)
{ 
	int pivotkey;

	pivotkey=l->r[low]; /* 用子表的第一个记录作枢轴记录 */
	while(low<high) /*  从表的两端交替地向中间扫描 */
	{ 
		 while(low<high&&l->r[high]>=pivotkey)
			high--;
		 swap(l,low,high);/* 将比枢轴记录小的记录交换到低端 */
		 while(low<high&&l->r[low]<=pivotkey)
			low++;
		 swap(l,low,high);/* 将比枢轴记录大的记录交换到高端 */
	}
	return low; /* 返回枢轴所在位置 */
}

/* 对顺序表l中的子序列l->r[low..high]作快速排序 */
void qsort(sqlist *l,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
			pivot=partition(l,low,high); /*  将l->r[low..high]一分为二，算出枢轴值pivot */
			qsort(l,low,pivot-1);		/*  对低子表递归排序 */
			qsort(l,pivot+1,high);		/*  对高子表递归排序 */
	}
}

/* 对顺序表l作快速排序 */
void quicksort(sqlist *l)
{ 
	qsort(l,1,l->length);
}

/* **************************************** */

/* 改进后快速排序******************************** */

/* 快速排序优化算法 */
int partition1(sqlist *l,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* 计算数组中间的元素的下标 */  
	if (l->r[low]>l->r[high])			
		swap(l,low,high);	/* 交换左端与右端数据，保证左端较小 */
	if (l->r[m]>l->r[high])
		swap(l,high,m);		/* 交换中间与右端数据，保证中间较小 */
	if (l->r[m]>l->r[low])
		swap(l,m,low);		/* 交换中间与左端数据，保证左端较小 */
	
	pivotkey=l->r[low]; /* 用子表的第一个记录作枢轴记录 */
	l->r[0]=pivotkey;  /* 将枢轴关键字备份到l->r[0] */
	while(low<high) /*  从表的两端交替地向中间扫描 */
	{ 
		 while(low<high&&l->r[high]>=pivotkey)
			high--;
		 l->r[low]=l->r[high];
		 while(low<high&&l->r[low]<=pivotkey)
			low++;
		 l->r[high]=l->r[low];
	}
	l->r[low]=l->r[0];
	return low; /* 返回枢轴所在位置 */
}



void qsort1(sqlist *l,int low,int high)
{ 
	int pivot;
	if((high-low)>max_length_insert_sort)
	{
		while(low<high)
		{
			pivot=partition1(l,low,high); /*  将l->r[low..high]一分为二，算出枢轴值pivot */
			qsort1(l,low,pivot-1);		/*  对低子表递归排序 */
			/* qsort(l,pivot+1,high);		/*  对高子表递归排序 */
			low=pivot+1;	/* 尾递归 */
		}
	}
	else
		insertsort(l);
}

void _qsort1_for_iteration(int &low,int &high,const int& piv)
{
	high = piv - 1;
}


//继续改成迭代
void qsort1_iteration(sqlist *l, int low, int high)
{
	int pivot;


	while (low < high)
	{
		pivot = partition1(l, low, high); /*  将l->r[low..high]一分为二，算出枢轴值pivot */
		_qsort1_for_iteration(low, high, pivot);
		low = pivot + 1;
	}
	
}

//void quicksort1_iteration_access(sqlist *l)
//{
//	qsort1_iteration(l, 1, l->length);
//}
//
/* 对顺序表l作快速排序 */
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


//void QuicksortNonRecur2(sqlist *L, int b, int e) {//存疑
//	if (b >= e) return;
//	std::stack< std::pair<int, int> > stk;
//	stk.push(std::make_pair(b, e));
//	while (!stk.empty()) {
//		std::pair<int, int> pair = stk.top();
//		stk.pop();
//		if (pair.first >= pair.second) continue;
//		int p = partition1(L, pair.first, pair.second);//存疑
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
   printf("排序前:\n");
   print(l0);

   printf("初级冒泡排序:\n");
   bubblesort0(&l0);
   print(l0);
   
   printf("冒泡排序:\n");
   bubblesort(&l1);
   print(l1);
   
   printf("改进冒泡排序:\n");
   bubblesort2(&l2);
   print(l2);
   
   printf("选择排序:\n");
   selectsort(&l3);
   print(l3);
   
   printf("直接插入排序:\n");
   insertsort(&l4);
   print(l4);

   printf("希尔排序:\n");
   shellsort(&l5);
   print(l5);
	
   printf("堆排序:\n");
   heapsort(&l6);
   print(l6);

   printf("归并排序（递归）:\n");
   mergesort(&l7);
   print(l7);

   printf("归并排序（非递归）:\n");
   mergesort2(&l8);
   print(l8);

   printf("快速排序:\n");
   quicksort(&l9);
   print(l9);

   printf("改进快速排序:\n");
   quicksort1(&l10);
   print(l10);

   printf("非递归快速排序:\n");
   QuicksortNonRecur_Access(&l11);
   print(l11);

   printf("非递归快速排序优化:\n");//存疑
   QuicksortNonRecur_Access2(&l12);
   print(l12);

   //printf("非递归快速排序优化:\n");
   //quicksort1_iteration_access(&l12);
   //print(l12);
    /*大数据排序*/
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

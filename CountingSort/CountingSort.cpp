#include<iostream>
using namespace std;
//https://blog.csdn.net/qq_42111463/article/details/84146915
void Sort(int R1[], int R2[], int n)
{
	for (int i = 0; i < n; i++)	//R1[i]在数组中比num个数大，则R2[num]=R1[i]
	{
		int num = 0;        	//每次统计前num都要更新为0
		for (int j = 0; j < n; j++)	//R1[i]依次与R1[j]比较
			if (R1[i] > R1[j])
				num++;
		R2[num] = R1[i];		//R1[i]统计完，赋值给R2[num]
	}
}
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		int i, R1[100], R2[100];
		for (i = 0; i < n; i++)
			cin >> R1[i];
		Sort(R1, R2, n);
		for (i = 0; i < n - 1; i++)
			cout << R2[i] << " ";
		cout << R2[n - 1] << endl;	//区分空格和回车
	}
}
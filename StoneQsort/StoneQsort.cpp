// StoneQsort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
void swap(char&a, char&b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

void QKSort(char r[], int num)
{
	int first_white = 0, red = 0;
	int last_white = num - 1, blue = num - 1;
	while (red < last_white)//遍历所有石头
	{
		while ('B' == r[blue])//找到第一个非蓝石头
		{
			--blue;
			--last_white;
		}
		while ('R' == r[red])//找到第一个非红石头
		{
			++red;
			++first_white;
		}
		if ('B' == r[red])
		{
			swap(r[last_white], r[first_white]);
			while ('R' == r[first_white])//继续找
			{
				++first_white;
				++red;
			}
			while ('B' == r[blue])
			{
				--last_white;
				--blue;
			}
		}
		else if ('R' == r[blue])
		{
			swap(r[first_white], r[last_white]);
			while ('R' == r[first_white])
			{
				++first_white;
				++red;
			}
			while ('B' == r[blue])
			{
				--last_white;
				--blue;
			}
		}
		else//两块均白色
		{
			while ('W' == r[red])//从左向右找第一块非白石头
			{
				++red;
			}
			if (red>=blue)//会和，已找完
			{
				break;
			}
			if ('R'==r[red])//红色，从左至右交换
			{
				swap(r[red],r[first_white]);
				++first_white;
			}
			else//蓝色，从右至左交换
			{
				swap(r[red], r[last_white]);
				-- last_white;
			}
		}
	}
}
int main()
{
	while (true)
	{
		char Stones[100] = { 0 };//装 红白蓝石头
		int size = 0;
		std::cin >> size;
		if (!size)
		{
			break;
		}
		for (int i = 0; i < size; i++)
		{
			std::cin >> Stones[i];
		}
		QKSort(Stones,size);
		for (int i = 0; i < size; i++)
		{
			if (i==size-1)
			{
				std::cout << Stones[i] << std::endl;
			}
			else
			{
				std::cout << Stones[i] << " ";
			}
		}
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

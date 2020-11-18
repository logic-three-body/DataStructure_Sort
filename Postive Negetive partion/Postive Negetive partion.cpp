#include<iostream>
typedef int ElemType;
const int N = 100;
void swap(ElemType& num1, ElemType& num2)
{
	ElemType tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void Partion(ElemType *Array, int len)
{
	int low = 0, high = len - 1;
	while (low < high)
	{
		while (low < high &&  Array[low] < 0)//左至右非负值记录
		{
			++low;
		}
		while (low < high &&  Array[high] > 0)//右至左非负值记录
		{
			--high;
		}
		// swap
		if (low < high)
		{
			swap(Array[low], Array[high]);
			++low;
			--high;
		}
	}
}

int main()
{
	while (true)
	{
		ElemType A[N] = { 0 };
		int length = 0;
		std::cin >> length;
		if (!length)
		{
			break;
		}
		for (int i = 0; i < length; i++)
		{
			std::cin >> A[i];
		}
		Partion(A, length);
		for (int i = 0; i < length; i++)
		{
			if (i==length-1)
			{
				std::cout << A[i] << std::endl;
			}
			else
			{
				std::cout << A[i] << " ";
			}
		}
	}

	return 0;
}
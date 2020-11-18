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

int Qpartion(ElemType r[], int low, int high, ElemType pivotkey)
{
	while (low < high) /*  从表的两端交替地向中间扫描 */
	{
		if (r[low] > pivotkey&&r[high] < pivotkey)
		{
			high--;
			low++;
		}
		while (low <= high && r[high] > pivotkey)
			high--;
		if (r[high] == pivotkey)
		{
			return high;
		}
		while (low <= high && r[low] < pivotkey)
			low++;
		if (r[low] == pivotkey)
		{
			return low;
		}
	}
	std::cout << "not find\n";
	return -1;
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
		ElemType key = 0;
		std::cin>>key;
		if (Qpartion(A, 0, length-1 , key)>0)
		{
			std::cout << Qpartion(A, 0, length - 1, key)+1 << " " << key << std::endl;
		}
	}

	return 0;
}
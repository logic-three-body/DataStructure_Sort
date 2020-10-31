#include<iostream>
#include<algorithm>
#include<string>
#include<deque>
#include<list>
using namespace std;

struct $
{
	int id;
	int val;
	bool operator < ($ &p)const {
		if (val == p.val)return id < p.id;
		else return val < p.val;
	}
	bool operator > ($ &p)const {
		if (val == p.val)return id > p.id;
		else return val > p.val;
	}
}e[1007];
bool cmp($ a, $ b)
{
	return a > b;
}
int main()
{
	/*
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> e[i].id >> e[i].val;
	}
	sort(e, e + n, cmp); cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << e[i].id << " " << e[i].val << endl;
	}		
	*/

	deque<int> deq;
	list<int> li;
	
	deq.push_back(3);
	deq.push_front(2);
	deq.push_back(4);
	for (auto tmp:deq)
	{
		cout << tmp << endl;
	}
	sort(deq.begin(), deq.end(), greater<int>());
	for (auto tmp : deq)
	{
		cout << tmp << endl;
	}
	sort(deq.begin(), deq.end());
	for (auto tmp : deq)
	{
		cout << tmp << endl;
	}
	string s = "54321BaCbAd";
	cout << *s.begin() << endl;
	//cout << *s.end() << endl; 越界
	cout << *--s.end() << endl; 

	sort(s.begin(), s.end());
	cout << s << endl;

	//s.erase(s.begin(),s.begin()+3);
	//s.erase(0, 5);
	//s.erase(5);

	//cout<<s.substr(0, 3)<<endl;
	cout<<s.substr(4, -3)<<endl;
	

	return 0;
}

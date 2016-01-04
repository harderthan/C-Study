#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
	int id;
	int coin;
	char * name;
public:
	Person(int _id, int _coin, char * _name)
		:id(_id), coin(_coin)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	Person(const Person & ref)
		:id(ref.id), coin(ref.coin)
	{
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
	}
	~Person()
	{
		delete[] name;
	}


	void inputCoin(int _coin) 
	{
		if (_coin <= 0)
			cout << "올바른 값을 입력하세요." << endl;
		else
			coin += _coin;
	}
	void outputCoin(int _coin) 
	{
		if (_coin <= 0)
		{

			cout << "올바른 값을 입력하세요." << endl;
			return;
		}
		if (coin<_coin)
		{
			cout << "잔액이 충분하지 않습니다." << endl;
			return;
		}
		coin -= _coin;
		return;
	}
	int getID() const
	{
		return id;
	}
	void ShowPerson() const
	{
		cout << endl;
		cout << "계좌ID: " << id << endl;
		cout << "이 름: " << name << endl;
		cout << "잔 액: " << coin << endl;
		cout << endl;
	}
};


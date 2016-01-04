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
			cout << "�ùٸ� ���� �Է��ϼ���." << endl;
		else
			coin += _coin;
	}
	void outputCoin(int _coin) 
	{
		if (_coin <= 0)
		{

			cout << "�ùٸ� ���� �Է��ϼ���." << endl;
			return;
		}
		if (coin<_coin)
		{
			cout << "�ܾ��� ������� �ʽ��ϴ�." << endl;
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
		cout << "����ID: " << id << endl;
		cout << "�� ��: " << name << endl;
		cout << "�� ��: " << coin << endl;
		cout << endl;
	}
};


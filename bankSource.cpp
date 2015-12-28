#include <iostream>
#include <cstring>

#define PERSON_NUM 100
#define NAME_LEN 20
using namespace std;

int sc;
int tmp=0;

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
		name = new char[strlen(_name)+1];
		strcpy(name, _name);
	}
	void inputCoin(int _coin)
	{
		if(_coin<=0)
			cout << "�ùٸ� ���� �Է��ϼ���." << endl;
		else
			coin += _coin;
	}
	void outputCoin(int _coin)
	{
		if(_coin<=0)
		{

			cout << "�ùٸ� ���� �Է��ϼ���." << endl;
			return;
		}
		if(coin<_coin)
		{
			cout << "�ܾ��� ������� �ʽ��ϴ�." << endl;
			return;
		}
		coin -= _coin;
		return;
	}
	int getID()
	{
		return id;
	}
	void ShowPerson()
	{
		cout << endl;
		cout << "����ID: "<< id << endl;
		cout << "�� ��: "<< name << endl;
		cout << "�� ��: "<< coin << endl;
		cout << endl;
	}
	~Person()
	{
		delete[] name;
	}
};

Person * person[PERSON_NUM];

void ShowPeopleInfo()
{
	for(int i=0; i<tmp; i++)
	{
		person[i]->ShowPerson();
	}
}

void newPerson()
{
	int id;
	int coin;
	char name[NAME_LEN];
	cout << "[���°���]"<<endl;
	cout << "����ID: "; cin >> id;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> coin;
	cout << endl;
	cout << "���� �Ϸ�" << endl;
	cout << endl;
	person[tmp] = new Person(id,coin,name);
	tmp++;
}

void inputCoin()
{
	int checkID;
	int coin;
	cout << "[��   ��]" << endl;
	cout << "����ID: " ; cin >> checkID;
	cout << "�Աݾ�: " ; cin >> coin;
	
	for(int i=0; i<tmp; i++)
	{
		if(checkID==(person[i]->getID()))
		{
			person[i]->inputCoin(coin);
			cout << "�Ա� �Ϸ�" <<endl;
		}
		else
			cout<<"�ùٸ� ID�� �Է��ϼ���." << endl;
	}
	cout << endl;
}

void ouputCoin()
{
	int checkID;
	int coin;
	cout << "[��   ��]" << endl;
	cout << "����ID: " ; cin >> checkID;
	cout << "�Աݾ�: " ; cin >> coin;
	
	for(int i=0; i<tmp; i++)
	{
		if(checkID==(person[i]->getID()))
		{
			person[i]->outputCoin(coin);
			cout << "��� �Ϸ�" <<endl;
		}
		else
			cout<<"�ùٸ� ID�� �Է��ϼ���." << endl;
	}
	cout << endl;
}


void ShowMenu()
{
	cout<<"-----Menu-----"<<endl;
	cout<<"1. ���°���"<<endl;
	cout<<"2. �� ��" <<endl;
	cout<<"3. �� ��" <<endl;
	cout<<"4. �������� ��ü ���" <<endl;
	cout<<"5. ���α׷�����"<<endl;
}



int main()
{
	while(1)
	{
		ShowMenu();
		cin >> sc;   // menu ��ȣ �Է� �ޱ�
		switch(sc)
		{
			case 1:  // ���� ����
				newPerson();
				break;
			case 2:  // �Ա�
				inputCoin();
				break;
			case 3:  // ���
				ouputCoin();
				break;
			case 4:  // ���� ��ü ���
				ShowPeopleInfo();
				break;
			case 5:  // ���α׷� ����
				return 0;
			default:
				cout << "�ùٸ� ��ȣ�� ��������." <<endl;
				break;
		}
	}

	return 0;
}





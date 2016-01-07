
#include "HighAccount.h"


#define PERSON_NUM 100
#define NAME_LEN 20
using namespace std;


class PersonHandler
{
private:

	int tmp;
	Person * person[PERSON_NUM];

public:
	PersonHandler()
		: tmp(0)
	{}
	void setsc();
	int getsc();
	void ShowPeopleInfo() const;  // ���� ��ü ��� ���
	void newPerson();  // ���ο� ���� ����
	void inputCoin();  // �Ա�
	void ouputCoin();  // ���
	void ShowMenu();  // �޴� ���
	~PersonHandler()
	{
		for (int i = 0; i < PERSON_NUM; i++)
		{
			delete[]person[i];
		}
	}

};


void PersonHandler::ShowPeopleInfo() const
{
	for (int i = 0; i<tmp; i++)
	{
		person[i]->ShowPerson();
	}
}

void PersonHandler::newPerson()
{
	int id;
	int coin;
	char name[NAME_LEN];
	double ratio;
	int sc;
	int grade;
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	
	cout << "����: "; cin >> sc; cout << endl;

	switch (sc)
	{
	case 1:
		cout << "[���뿹�ݰ��°���]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�� ��: "; cin >> name;
		cout << "�Աݾ�: "; cin >> coin;
		cout << "������: "; cin >> ratio;
		cout << endl;
		person[tmp++] = new NormalAccount(id, coin, name, ratio);
		break;
	case 2:
		cout << "[�ſ�ŷڰ��°���]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�� ��: "; cin >> name;
		cout << "�Աݾ�: "; cin >> coin;
		cout << "������: "; cin >> ratio;
		cout << "�ſ���(1,2,3): "; cin >> grade;
		cout << endl;
		person[tmp++] = new HighAccount(id, coin, name, ratio, grade);
		break;
	default:
		cout << "�ùٸ� ��ȣ�� �Է��ϼ���." << endl;
	}
	
	
}

void PersonHandler::inputCoin()
{
	int checkID;
	int coin;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> checkID;
	cout << "�Աݾ�: "; cin >> coin;

	for (int i = 0; i<tmp; i++)
	{
		if (checkID == (person[i]->getID()))
		{
			person[i]->inputCoin(coin);
			cout << "�Ա� �Ϸ�" << endl;
		}
		else
			cout << "�ùٸ� ID�� �Է��ϼ���." << endl;
	}
	cout << endl;
}

void PersonHandler::ouputCoin()
{
	int checkID;
	int coin;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> checkID;
	cout << "�Աݾ�: "; cin >> coin;

	for (int i = 0; i<tmp; i++)
	{
		if (checkID == (person[i]->getID()))
		{
			person[i]->outputCoin(coin);
			cout << "��� �Ϸ�" << endl;
		}
		else
			cout << "�ùٸ� ID�� �Է��ϼ���." << endl;
	}
	cout << endl;
}


void PersonHandler::ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷�����" << endl;
}





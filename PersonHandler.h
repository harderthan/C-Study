#include <iostream>
#include <cstring>
#include "Person.h"

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
	void ShowPeopleInfo() const;  // 계좌 전체 목록 출력
	void newPerson();  // 새로운 계좌 생성
	void inputCoin();  // 입금
	void ouputCoin();  // 출금
	void ShowMenu();  // 메뉴 출력
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
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> coin;
	cout << endl;
	cout << "개설 완료" << endl;
	cout << endl;
	person[tmp] = new Person(id, coin, name);
	tmp++;
}

void PersonHandler::inputCoin()
{
	int checkID;
	int coin;
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> checkID;
	cout << "입금액: "; cin >> coin;

	for (int i = 0; i<tmp; i++)
	{
		if (checkID == (person[i]->getID()))
		{
			person[i]->inputCoin(coin);
			cout << "입금 완료" << endl;
		}
		else
			cout << "올바른 ID를 입력하세요." << endl;
	}
	cout << endl;
}

void PersonHandler::ouputCoin()
{
	int checkID;
	int coin;
	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> checkID;
	cout << "입금액: "; cin >> coin;

	for (int i = 0; i<tmp; i++)
	{
		if (checkID == (person[i]->getID()))
		{
			person[i]->outputCoin(coin);
			cout << "출금 완료" << endl;
		}
		else
			cout << "올바른 ID를 입력하세요." << endl;
	}
	cout << endl;
}


void PersonHandler::ShowMenu()
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램종료" << endl;
}





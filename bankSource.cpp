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
			cout << "올바른 값을 입력하세요." << endl;
		else
			coin += _coin;
	}
	void outputCoin(int _coin)
	{
		if(_coin<=0)
		{

			cout << "올바른 값을 입력하세요." << endl;
			return;
		}
		if(coin<_coin)
		{
			cout << "잔액이 충분하지 않습니다." << endl;
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
		cout << "계좌ID: "<< id << endl;
		cout << "이 름: "<< name << endl;
		cout << "잔 액: "<< coin << endl;
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
	cout << "[계좌개설]"<<endl;
	cout << "계좌ID: "; cin >> id;
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> coin;
	cout << endl;
	cout << "개설 완료" << endl;
	cout << endl;
	person[tmp] = new Person(id,coin,name);
	tmp++;
}

void inputCoin()
{
	int checkID;
	int coin;
	cout << "[입   금]" << endl;
	cout << "계좌ID: " ; cin >> checkID;
	cout << "입금액: " ; cin >> coin;
	
	for(int i=0; i<tmp; i++)
	{
		if(checkID==(person[i]->getID()))
		{
			person[i]->inputCoin(coin);
			cout << "입금 완료" <<endl;
		}
		else
			cout<<"올바른 ID를 입력하세요." << endl;
	}
	cout << endl;
}

void ouputCoin()
{
	int checkID;
	int coin;
	cout << "[출   금]" << endl;
	cout << "계좌ID: " ; cin >> checkID;
	cout << "입금액: " ; cin >> coin;
	
	for(int i=0; i<tmp; i++)
	{
		if(checkID==(person[i]->getID()))
		{
			person[i]->outputCoin(coin);
			cout << "출금 완료" <<endl;
		}
		else
			cout<<"올바른 ID를 입력하세요." << endl;
	}
	cout << endl;
}


void ShowMenu()
{
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금" <<endl;
	cout<<"3. 출 금" <<endl;
	cout<<"4. 계좌정보 전체 출력" <<endl;
	cout<<"5. 프로그램종료"<<endl;
}



int main()
{
	while(1)
	{
		ShowMenu();
		cin >> sc;   // menu 번호 입력 받기
		switch(sc)
		{
			case 1:  // 계좌 생성
				newPerson();
				break;
			case 2:  // 입금
				inputCoin();
				break;
			case 3:  // 출금
				ouputCoin();
				break;
			case 4:  // 계좌 전체 출력
				ShowPeopleInfo();
				break;
			case 5:  // 프로그램 종료
				return 0;
			default:
				cout << "올바른 번호를 누르세요." <<endl;
				break;
		}
	}

	return 0;
}





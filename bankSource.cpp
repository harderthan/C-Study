#include <iostream>

#include "PersonHandler.h"

int main()
{
	PersonHandler PH;
	int sc;
	
	while(1)
	{
		PH.ShowMenu();
		cin >> sc;   // menu 번호 입력 받기
		switch(sc)
		{
			case 1:  // 계좌 생성
				PH.newPerson();
				break;
			case 2:  // 입금
				PH.inputCoin();
				break;
			case 3:  // 출금
				PH.ouputCoin();
				break;
			case 4:  // 계좌 전체 출력
				PH.ShowPeopleInfo();
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

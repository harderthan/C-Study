#include <iostream>

#include "PersonHandler.h"

int main()
{
	PersonHandler PH;
	int sc;
	
	while(1)
	{
		PH.ShowMenu();
		cin >> sc;   // menu ��ȣ �Է� �ޱ�
		switch(sc)
		{
			case 1:  // ���� ����
				PH.newPerson();
				break;
			case 2:  // �Ա�
				PH.inputCoin();
				break;
			case 3:  // ���
				PH.ouputCoin();
				break;
			case 4:  // ���� ��ü ���
				PH.ShowPeopleInfo();
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

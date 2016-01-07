
#ifndef __HIGHACCOUNT_H_
#define __HIGHACCOUNT_H_

#include "NormalAccount.h"

class HighAccount : public NormalAccount
{
private:
	double grade;
public:
	HighAccount(int _id, int _coin, char * _name, double _ratio, int _grade)
		: NormalAccount(_id, _coin, _name, _ratio)
	{
		switch (_grade)
		{
		case 1:
			_grade = 7;
			break;
		case 2:
			_grade = 4;
			break;
		case 3:
			_grade = 2;
			break;
		default:
			break;
		}
		grade = _grade*0.01;
	}

	virtual void inputCoin(int _coin)
	{
		NormalAccount::inputCoin(_coin);
		Person::inputCoin((int)(_coin*grade));
	}
};

#endif
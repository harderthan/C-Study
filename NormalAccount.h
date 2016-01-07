

#ifndef __NORMALACCOUNT_H_
#define __NORMALACCOUNT_H_

#include "Person.h"

class NormalAccount : public Person
{
private:
	double ratio;
public:
	NormalAccount(int _id, int _coin, char * _name, double _ratio)  // 여기 까지!!!
		: Person(_id, _coin, _name)
	{
		ratio = 1 + _ratio*0.01;
	}

	virtual void inputCoin(int _coin)
	{
		Person::inputCoin((int)(_coin*ratio));
	}
};

#endif
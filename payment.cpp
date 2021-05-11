#include "payment.h"

payment::payment()
{
	type = " ";
	cardnumber = " ";
}

payment::payment(string card, string ty)
{
	type = ty;
	cardnumber = card;
}

payment::payment(const payment &p)
{
	type = p.type;
	cardnumber = p.cardnumber;
}

const payment& payment::operator=(const payment *p)
{
	if (this != p)
	{
		type = p->type;
		cardnumber = p->cardnumber;
	}
	return *this;
}

void payment::setmethod(string s) {
	type = s;
}


	
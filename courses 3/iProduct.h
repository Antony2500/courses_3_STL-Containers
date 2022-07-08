#ifndef IPRODUCT_H
#define IPRODUCT_H
#include"constants.h"
#include<fstream>
#include <string>
#include<vector>

namespace sict 
{
	class iProduct // интерфейс
	{
	public:

		virtual void display(std::ostream& os) const = 0;

		virtual double price() const = 0;

		friend std::ostream& operator<<(std::ostream& os, const iProduct& p);

		virtual iProduct* readRecord(std::ifstream& file) = 0;

		virtual int get_number() const = 0;

		virtual float get_price() const = 0;
	};
}

#endif

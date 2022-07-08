#ifndef SALE_H
#define SALE_H
#include"iProduct.h"
#include"Product.h"

namespace sict
{
	class Sale
	{
	private:
		std::vector<iProduct*> m_catalog;

	public:
		 Sale(const char* puth);

		virtual void display(std::ostream& os)const;

		
		/*virtual double price() const;

		//static std::ostream& operator<<(std::ostream& os, const iProduct& p);

		virtual iProduct* readRecord(std::ifstream& file);
		*/


	};
}

#endif

#ifndef PRODUCT_H
#define PRODUCT_H
#include"iProduct.h"
#include<map>

namespace sict
{
	class Product : public iProduct
	{
	protected:
		int m_number = 0;
		float m_price = 0;

	public:
		Product();

		Product(int number, float price) :m_number(number), m_price(price)
		{
		}

		virtual void display(std::ostream& os) const;

		virtual double price() const;

		friend std::ostream& operator<<(std::ostream& os, const iProduct& p);

		virtual iProduct* readRecord(std::ifstream& file) override;

		virtual int get_number() const;
		

		virtual float get_price()const;
		
	};

	class TaxableProduct : public Product
	{
	private:
		std::string m_type_of_tax = "";
		static std::map<std::string, float> m_tax_percentage;

	public:
		TaxableProduct();

		TaxableProduct(int number, float price, std::string type_of_tax)
			:Product(number, price), m_type_of_tax(type_of_tax)
		{
		}


		virtual double price() const;

		virtual void display(std::ostream& os) const;

		virtual iProduct* readRecord(std::ifstream& file);

	};

}

#endif

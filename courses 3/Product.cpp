#include"Product.h"
#include <iostream>


sict::Product::Product()
{
}


void sict::Product::display(std::ostream& os) const
{
	
	std::string line = std::to_string(m_number) + " " + std::to_string(m_price);
	line.resize(FW);
	os << line << "\n";
}

double sict::Product::price() const
{
	return m_price;
}

sict::iProduct* sict::Product::readRecord(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cout << "Mistake ! File don't find :( ";
	}
	else
	{
		int number;
		float price;
		std::string line;
		std::getline(file, line);
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
			{
				number = std::stoi(line.substr(0, i));
				price = std::stof(line.substr(i + 1));
			}
		}
		sict::iProduct* new_product = new sict::Product(number, price);
		return new_product;
	}
}

int sict::Product::get_number()const
{
	return m_number;
}

float sict::Product::get_price()const
{
	return m_price;
}

std::ostream& operator<<(std::ostream& os, const sict::iProduct& p)
{
	os << p.get_number() << " " << p.get_price() << "\n";
	return os;
}




//virtual std::ostream& operator<<(std::ostream& os, const iProduct& p);
//sict::TaxableProduct::m_tax_percentage.insert(std::pair<std::string, float>("H", 0.13));
std::map<std::string, float> sict::TaxableProduct::m_tax_percentage = { {"H",0.13},{"P",0.08} };

double sict::TaxableProduct::price() const
{
	return m_price + m_price * m_tax_percentage[m_type_of_tax];
}

sict::iProduct* sict::TaxableProduct::readRecord(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cout << "Mistake ! File don't find :( ";
	}
	else
	{
		std::string line;
		std::vector<std::string> line_split_by_spaces;
		std::getline(file, line);
		for (int i = 0,j = 0; i < line.size(); i++)
		{
			if (line[i] == ' ' || i + 1 == line.size())
			{
				line_split_by_spaces.push_back(line.substr(j, i + j));
				j = i + 1;
			}
			
		}
		
		if (line_split_by_spaces.size() == 2)
		{
			sict::iProduct* new_product = new sict::Product(std::stoi(line_split_by_spaces[0]), std::stof(line_split_by_spaces[1]));
			return new_product;
		}
		else
		{
			sict::iProduct* new_product = new sict::TaxableProduct(std::stoi(line_split_by_spaces[0]), std::stof(line_split_by_spaces[1]), line_split_by_spaces[2]);
			return new_product;
		}
	}
}

void sict::TaxableProduct::display(std::ostream& os) const
{
	std::string m_price_str = std::to_string(m_price);
	m_price_str.resize(5);
	std::string line = std::to_string(m_number) + " " + m_price_str + " " + m_type_of_tax;
	os <<line << "\n";
}

sict::TaxableProduct::TaxableProduct()
{
}
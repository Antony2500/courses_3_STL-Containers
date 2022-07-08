#include"Sale.h"
#include<iostream>

sict::Sale::Sale(const char* path)
{
	std::ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		std::cout << "Mistake ! File don't find :( ";
	}
	else
	{
		std::string information;
		size_t numer_of_lines;
		numer_of_lines = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
		file.clear();
		file.seekg(0);


		TaxableProduct product;
		for (int i = 0; i < numer_of_lines; i++)
		{
			sict::iProduct* fff = product.readRecord(file);
			m_catalog.push_back(fff);
			//------------------------------------
			//std::getline(file,information);
			//m_catalog.push_back(information);
		}


	
	}
	file.close();
}

void sict::Sale::display(std::ostream& os)const
{
	for (int i = 0; i < m_catalog.size(); i++)
	{
		m_catalog[i]->display(os);
	}
}

/*
double sict::Sale::price() const
{}

sict::iProduct* sict::Sale::readRecord(std::ifstream& file)
{}
*/
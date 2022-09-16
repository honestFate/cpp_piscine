#include "serialization.hpp"
#include "Data.hpp"

int main()
{
	Data * data = new Data();
	data->setC('*');
	data->setX(42);
	std::cout << "data->_c = " << data->getC() << std::endl;
	std::cout << "data->_x = " << data->getX() << std::endl;

	uintptr_t srl = serialize(data);
	std::cout << "Serialized data: " << srl << std::endl;
	Data * tmp = deserialize(srl);

	if (data == tmp)
	{
		std::cout << "Pointers are equals" << std::endl;
	}
	else
	{
		std::cout << "Error!" << std::endl;
	}
	std::cout << "tmp->_c = " << tmp->getC() << std::endl;
	std::cout << "tmp->_x = " << tmp->getX() << std::endl;

	Data * dataNull = NULL;
	uintptr_t srlNull = serialize(dataNull);
	std::cout << "Serialized dataNull: " << srlNull << std::endl;
	Data * tmpNull = deserialize(srlNull);
	if (dataNull == tmpNull)
	{
		std::cout << "dataNull == tmpNull" << std::endl;
	}
	else
	{
		std::cout << "Error!" << std::endl;
	}

	delete tmp;

	return 0;
}

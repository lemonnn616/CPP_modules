#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;

	data.id = 42;
	data.name = "answer";
	data.value = 3.14;
	data.flag = 'X';

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Data contents:" << std::endl;
	std::cout << "id = " << data.id << std::endl;
	std::cout << "name = " << data.name << std::endl;
	std::cout << "value= " << data.value << std::endl;
	std::cout << "flag = " << data.flag << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\nSerialized value (uintptr_t): " << raw << std::endl;

	Data* restored = Serializer::deserialize(raw);
	std::cout << "Restored Data* address: " << restored << std::endl;
	if (restored)
	{
		std::cout << "\nRestored Data contents:" << std::endl;
		std::cout << "id = " << restored->id << std::endl;
		std::cout << "name = " << restored->name << std::endl;
		std::cout << "value= " << restored->value << std::endl;
		std::cout << "flag = " << restored->flag << std::endl;
	}

	return 0;
}

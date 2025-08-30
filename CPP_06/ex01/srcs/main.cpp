#include "../includes/Serializer.hpp"

int main(void)
{
	Data* original = new Data;
	original->name = "Sheldon the Dog.";
	original->value = -10;

	std::cout << "Data Structure before serialization:" << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << "Data original -> name: " << original->name << std::endl;
	std::cout << "Data original -> value:" << original->value << std::endl;
	std::cout << "====================================" << std::endl;
	std::cout << std::endl;

	uintptr_t raw = Serializer::serialize(original);
	Data* copy = Serializer::deserialize(raw);

	std::cout << "Original adress:		" << original << std::endl;
	std::cout << "Serialized uintptr:		" << raw << std::endl;
	std::cout << "Deserialized ptr:		" << copy << std::endl;
	std::cout << "copy->name:			" << copy->name << std::endl;
	std::cout << "copy->value:			" << copy->value << std::endl;

	delete original;
}

#include "Serializer.hpp"
#include <iostream>

void Init_struct(Data *initData)
{
	initData->message = "J'aime les frites";
}

int main(void)
{
	Data *mymessage = new Data;
	Init_struct(mymessage);
	Data *other;
	uintptr_t serialize;
	std::cout << "---Serializing Data---" << std::endl;
	std::cout << "Converting struct with message " << mymessage->message << " into a uintptr_t" << std::endl;
	serialize = Serializer::serialize(mymessage);
	std::cout << "uintptr_t = " << serialize << std::endl;
	std::cout << "Assigning Data *other with deserialization of uintptr_t" << std::endl;
	other = Serializer::deserialize(serialize);
	std::cout << "---Deserializing Data---" << std::endl; 
	std::cout << "other message = " << other->message << std::endl;
}
#pragma once
#include"reflect.h"

class demo {
public:
	int* age;

	REGISTER_INNER(demo)

	SETTER_METHOD(demo, int*, age)

public:
	static std::map<std::string, set_method> properties;

public:
	static void register_properties();
};
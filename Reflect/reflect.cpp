#include"reflect.h"

using namespace std;

void reflect::registe_class(std::string class_name, create_method method) {
	if (factories.find(class_name) == factories.end()) {
		factories.insert(pair<string, create_method>(class_name, method));
	}
}

void* reflect::get_instance_by_type(std::string class_name) {
	if (factories.find(class_name) == factories.end()) {
		return nullptr;
	}
	return (*factories[class_name])();
}

reflect * reflect::get_singleton() {
	static reflect _reflect;
	return &_reflect;
}

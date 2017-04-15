#include"reflect.h"
#include"demo.h"
#include<iostream>

using namespace std;

int main() {
	demo* d=(demo*)reflect::get_singleton()->get_instance_by_type("demo");

	int age = 25;
	int *p = &age;

	demo::register_properties();

	(*(d->properties["set_age"]))(d, p);

	cout << *(d->age) << endl;

	system("pause");
}
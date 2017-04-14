#include"demo.h"

using namespace std;

REGISTER_OUTTER(demo)

std::map<std::string, set_method> demo::properties;

void demo::register_properties() {
	properties["set_age"] = set_age;
}
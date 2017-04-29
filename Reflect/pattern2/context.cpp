#include"context.h"
#include"invoke.h"

using namespace std;

context* context::__context = nullptr;

context::context(const std::string& path) :configuration_path(path) {
	loader = new bean_loader(path);
}

context::~context() {
	delete loader;
}

void context::create_context(const std::string& path) {
	static context _context = context(path);
	__context = &_context;
	__context->init();
}

context* context::get_context() {
	assert(__context != nullptr);
	return __context;
}

void context::init() {
	parseConfiguration();

	create_and_init_bean();
}

void context::parseConfiguration() {
	bean_definitions.swap(loader->load());
}

void context::create_and_init_bean() {
	for (bean_definition* definition : bean_definitions) {
		string bean_id = definition->id;
		string class_type = definition->class_type;
		object* _obj = new_instance(class_type);
		assert(_obj != nullptr);
		assert(bean_map.insert({ bean_id ,_obj }).second);
		for (bean_property p : definition->properties) {
			cout << "set_" + p.name << endl;
			cout << p.value << endl;
			invoke(_obj, "set_" + p.name, p.value);
		}
	}
}


int main() {
	context::create_context("E:\\CppProgram\\Reflect\\Reflect\\pattern2\\beans.xml");
	
	system("pause");
}
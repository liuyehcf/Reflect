#pragma once
#include<string>
#include<vector>
#include<utility>
#include"bean_definition.h"

/*
* bean加载器
*/
class bean_loader {
private:
	const std::string configuration_path;

public:
	bean_loader(const std::string& path) :configuration_path(path) {}

public:
	/*
	* 加载配置文件生成bean_definition对象,并返回一个指定初始化顺序的数组,初始化顺序即下标
	*/
	std::vector<bean_definition*> load();

private:
	bean_definition* bean_loader::create_bean_definition(const std::string s);

	void add_property(bean_definition* definition, const std::string s);

	void add_dependency(bean_definition* definition, const std::string s);
};
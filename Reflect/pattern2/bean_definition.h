#pragma once
#include<string>
#include<vector>

struct bean_property {
	const std::string name;//属性名
	const std::string value;//属性值,保存为string
	bean_property(const std::string& t_name, const std::string& t_value)
		:name(t_name), value(t_value) {}

	std::string to_string(int n);
};

struct bean_definition {
	std::string id;
	std::string class_type;

	std::vector<bean_property> properties;//属性集合
	std::vector<std::string> dependencies;//依赖项

	std::vector<bean_definition*> adj_list;//邻接表

	std::string to_string();
};
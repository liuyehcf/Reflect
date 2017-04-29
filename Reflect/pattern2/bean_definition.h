#pragma once
#include<string>
#include<vector>

struct bean_property {
	const std::string name;//������
	const std::string value;//����ֵ,����Ϊstring
	bean_property(const std::string& t_name, const std::string& t_value)
		:name(t_name), value(t_value) {}

	std::string to_string(int n);
};

struct bean_definition {
	std::string id;
	std::string class_type;

	std::vector<bean_property> properties;//���Լ���
	std::vector<std::string> dependencies;//������

	std::vector<bean_definition*> adj_list;//�ڽӱ�

	std::string to_string();
};
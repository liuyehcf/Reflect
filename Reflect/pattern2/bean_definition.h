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

struct bean_dependency {
	const std::string name;//������
	const std::string ref_id;//������bean id
	bean_dependency(const std::string& t_name, const std::string& t_ref_id)
		:name(t_name), ref_id(t_ref_id) {}

	std::string to_string(int n);
};

struct bean_definition {
	std::string id;//bean��Ψһid
	std::string class_type;//bean������

	std::vector<bean_property> properties;//���Լ���
	std::vector<bean_dependency> dependencies;//������
	std::vector<std::string> pre_processors;//Ԥ������(������֮��,����ע��֮ǰ��Ҫִ�еĳ�ʼ������)
	std::vector<std::string> post_processors;//������(����ע�����Ҫִ�еĳ�ʼ������)
	std::string to_string();
};
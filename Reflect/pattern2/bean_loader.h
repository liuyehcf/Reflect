#pragma once
#include<string>
#include<vector>
#include<utility>
#include"bean_definition.h"

/*
* bean������
*/
class bean_loader {
private:
	const std::string configuration_path;

public:
	bean_loader(const std::string& path) :configuration_path(path) {}

public:
	/*
	* ���������ļ�����bean_definition����,������һ��ָ����ʼ��˳�������,��ʼ��˳���±�
	*/
	std::vector<bean_definition*> load();

private:
	bean_definition* bean_loader::create_bean_definition(const std::string s);

	void add_property(bean_definition* definition, const std::string s);

	void add_dependency(bean_definition* definition, const std::string s);
};
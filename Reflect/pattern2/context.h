#pragma once
#include<unordered_map>
#include<string>
#include<assert.h>
#include"object.h"

/*
* ������
*/
class context {
private:
	const std::string configuration_path;

	std::unordered_map<std::string, object*> bean_map;

	/*
	* ����ģʽ,˽�л����캯��
	*/
private:
	static context* __context;
private:
	context(const std::string& path) :configuration_path(path) {}
public:
	static void create_context(const std::string& path) {
		static context _context = context(path);
		__context = &_context;
	}

	static context* get_context() {
		assert(__context != nullptr);
		return __context;
	}

private:
	/*
	* ������ʼ��
	*/
	void init();

	/*
	* ���������ļ�
	*/
	void parseConfiguration();

	/*
	* ����ָ��˳���ʼ������bean
	*/
	void create_and_init_bean();
};
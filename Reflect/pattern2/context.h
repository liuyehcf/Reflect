#pragma once
#include<unordered_map>
#include<string>
#include<assert.h>
#include"object.h"

/*
* 容器类
*/
class context {
private:
	const std::string configuration_path;

	std::unordered_map<std::string, object*> bean_map;

	/*
	* 单例模式,私有化构造函数
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
	* 容器初始化
	*/
	void init();

	/*
	* 解析配置文件
	*/
	void parseConfiguration();

	/*
	* 按照指定顺序初始化所有bean
	*/
	void create_and_init_bean();
};
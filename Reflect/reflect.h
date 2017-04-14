#pragma once
#include<map>
#include<string>
#include<utility>

/*
* 定义工厂方法的类型别名
*/
typedef void* (*create_method)();

class reflect {

	std::map<std::string, create_method> factories;

public:

	void registe_class(std::string class_name,create_method method);

	void* get_instance_by_type(std::string class_name);

public:
	static reflect * get_singleton();
};

/*
* 该类的唯一作用是：
* 在创建该类的实例时，将传入的参数注册到reflect中
* 这一点非常巧妙，否则就需要在程序最开始，将需要反射的类注册到reflect中，就会需要有一个执行在main函数最开头的函数来完成这样一个工作
* 通过这一技巧，可以使得该过程在静态变量初始化的过程中完成这件事
*/
class factory_register {
public:
	factory_register(std::string class_name, create_method method) {
		reflect::get_singleton()->registe_class(class_name, method);
	}
};

/*
* 该宏定义工厂方法，该工厂方法名会被REGISTER_OUTTER宏用到
* 定义了表示该类型名字的静态字符串,定义了静态的注册器实例，该实例的类外初始化完成了向reflect注册的功能
*/
#define REGISTER_INNER(class_type)\
public:\
	inline static void* create_instance() {\
		return (void*)new class_type();\
	}\
private:\
	const static std::string _class_name;\
	static factory_register* fr;


/*
* 与REGISTER_INNER呼应，完成了向reflect进行注册的功能
*/
#define REGISTER_OUTTER(class_type) \
const std::string class_type::_class_name=#class_type; \
factory_register* class_type::fr=new factory_register(class_type::_class_name,class_type::create_instance);



/*
* 定义通用set方法的类型别名
*/
typedef void(*set_method)(void* obj, void* value);


/*
* 该宏定义了创建指定属性的setter方法的模式，避免重复劳动
*/
#define SETTER_METHOD(class_type,property_type,property_name) \
public:\
	inline static void set_##property_name(void* obj,void* value) {\
		class_type* temp=(class_type*) obj;\
		temp->property_name=(property_type)value;\
	}\
private:
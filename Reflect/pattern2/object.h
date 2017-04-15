#pragma once
#include<string>

/*
* 友元声明
*/
#define INVOKE_FRIEND_DECLARED \
friend void invoke(object* obj, const std::string& method_name);\
\
template <typename T1>\
friend void invoke(object* obj, const std::string& method_name, T1&& param1); \
\
template <typename T1,typename T2>\
friend void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2); \
\
template <typename T1,typename T2, typename T3>\
friend void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3); \
\
template <typename T1,typename T2, typename T3, typename T4>\
friend void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3, T4&& param4); \
\
template <typename T1,typename T2, typename T3, typename T4, typename T5>\
friend void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3, T4&& param4, T5&& param5);


/*
* 定义了反射的基类
*/
class object {
	INVOKE_FRIEND_DECLARED
public:
	void* operator new(size_t size, long class_id) {
		//对分配一个long，作为类型头
		void* raw = ::operator new(size + sizeof(long));
		char* pc = (char*) raw;
		*((long*)pc) = class_id;
		return pc + sizeof(long);
	}

	void operator delete(void *p) {
		::operator delete ((char*)p - sizeof(long));
	}

public:
	long get_class_id() {
		return *((long*)((char*)this - sizeof(long)));
	}

protected:
	static long class_id;
};


/*
* 注册类型id的宏
*/
#define REGISTE_CLASS_ID(class_type)\
protected:\
	static const long class_id;\

/*
* 定义工厂方法
*/
#define REGISTE_FACTORY_METHOD(class_type)\
public:\
	static object* new_instance(){\
		return new class_type();\
	}\
private:

/*
* 重载operator new操作符的宏
*/
#define OVERRIDE_OPERATOR_NEW(class_type)\
public:\
	void* operator new(size_t size) {\
		return object::operator new(size, class_type::class_id);\
	}\
private:

/*
* 重载operator delete操作符的宏
*/
#define OVERRIDE_OPERATOR_DELETE(class_type)\
public:\
	void operator delete(void*p){\
		object::operator delete(p);\
	}\
private:

/*
* 该宏组合了上面几个宏，用于被反射的类进行注册
*/
#define REGISTE_MEMBER_HEAD(class_type)\
INVOKE_FRIEND_DECLARED \
REGISTE_CLASS_ID(class_type) \
REGISTE_FACTORY_METHOD(class_type) \
OVERRIDE_OPERATOR_NEW(class_type) \
OVERRIDE_OPERATOR_DELETE(class_type) \

/*
* 在源文件中初始化类型id
*/
#define REGISTE_MEMBER_RESOURCE(class_type)\
const long class_type::class_id = ++object::class_id;
#pragma once
#include<stdexcept>
#include"object.h"
#include"demo.h"

/*
* 类型判断开始
*/
#define REGISTE_CLASS_START(class_type)\
if(class_id==class_type::class_id){\
	class_type * __##class_type = (class_type*)obj;\
	if (method_name == "") {\
		throw std::logic_error("反射调用函数失败"); \
	}

/*
* 类型判断结束
*/
#define REGISTE_CLASS_END(class_type)\
	else {\
		throw std::logic_error("反射调用函数失败");\
	}\
}

/*
* 零元函数判断及调用
*/
#define REGISTE_METHOD_ZERO(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method();\
	}

/*
* 一元函数判断及调用
*/
#define REGISTE_METHOD_ONE(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1);\
	}

/*
* 二元函数判断及调用
*/
#define REGISTE_METHOD_TWO(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2);\
	}

/*
* 三元函数判断及调用
*/
#define REGISTE_METHOD_THREE(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2,param3);\
	}

/*
* 四元函数判断及调用
*/
#define REGISTE_METHOD_FOUR(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2,param3,param4);\
	}

/*
* 五元函数判断及调用
*/
#define REGISTE_METHOD_FIVE(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2,param3,param4,param5);\
	}


/*
* 零元函数反射注册
*/
void invoke(object* obj, const std::string& method_name) {
	long class_id = obj->get_class_id();


	REGISTE_CLASS_START(demo)
	REGISTE_METHOD_ZERO(demo, func)
	REGISTE_CLASS_END(demo)

}

/*
* 一元函数反射注册
*/
template <typename T1>
void invoke(object* obj, const std::string& method_name, T1&& param1) {
	long class_id = obj->get_class_id();


	REGISTE_CLASS_START(demo)
	REGISTE_METHOD_ONE(demo, set_age)
	REGISTE_CLASS_END(demo)

}

/*
* 二元函数反射注册
*/
template <typename T1, typename T2>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2) {
	long class_id = obj->get_class_id();

}

/*
* 三元参数反射注册
*/
template <typename T1, typename T2, typename T3>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3) {
	long class_id = obj->get_class_id();

}

/*
* 四元函数反射注册
*/
template <typename T1, typename T2, typename T3, typename T4>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3, T4&& param4) {
	long class_id = obj->get_class_id();

	REGISTE_CLASS_START(demo4)
	REGISTE_METHOD_FOUR(demo4, add)
	REGISTE_CLASS_END(demo4)
}

/*
* 五元参数反射注册
*/
template <typename T1, typename T2, typename T3, typename T4, typename T5>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3, T4&& param4, T5&& param5) {
	long class_id = obj->get_class_id();

}
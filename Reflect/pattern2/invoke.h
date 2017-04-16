#pragma once
#include<stdexcept>
#include"micro.h"
#include"object.h"
#include"demo.h"


/*
* 零元函数反射注册
*/
void invoke(const object* obj, const std::string& method_name) {
	long class_id = obj->get_class_id();


	REGISTE_CLASS_START(demo1)
		REGISTE_METHOD_ZERO(demo1, print_age)
		REGISTE_METHOD_ZERO(demo1, print_time)
		REGISTE_METHOD_ZERO(demo1, print_woman)
		REGISTE_METHOD_ZERO(demo1, print_man)
	REGISTE_CLASS_END(demo1)

		REGISTE_CLASS_START(demo2)
		REGISTE_METHOD_ZERO(demo2, print_age)
		REGISTE_METHOD_ZERO(demo2, print_time)
		REGISTE_METHOD_ZERO(demo2, print_woman)
		REGISTE_METHOD_ZERO(demo2, print_man)
		REGISTE_CLASS_END(demo2)

		REGISTE_CLASS_START(demo3)
		REGISTE_METHOD_ZERO(demo3, print_age)
		REGISTE_METHOD_ZERO(demo3, print_time)
		REGISTE_METHOD_ZERO(demo3, print_woman)
		REGISTE_METHOD_ZERO(demo3, print_man)
		REGISTE_CLASS_END(demo3)

}

/*
* 函数反射注册
* 参数类型：int
*/
void invoke(const object* obj, const std::string& method_name, int param1) {
	long class_id = obj->get_class_id();

	REGISTE_CLASS_START(demo1)
		REGISTE_METHOD_ONE(demo1,set_age)
	REGISTE_CLASS_END(demo1)

		REGISTE_CLASS_START(demo2)
		REGISTE_METHOD_ONE(demo2, set_age)
		REGISTE_CLASS_END(demo2)

		REGISTE_CLASS_START(demo3)
		REGISTE_METHOD_ONE(demo3, set_age)
		REGISTE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：long
*/
void invoke(const object* obj, const std::string& method_name, long param1) {
	long class_id = obj->get_class_id();

	REGISTE_CLASS_START(demo1)
		REGISTE_METHOD_ONE(demo1, set_time)
		REGISTE_CLASS_END(demo1)

		REGISTE_CLASS_START(demo2)
		REGISTE_METHOD_ONE(demo2, set_time)
		REGISTE_CLASS_END(demo2)

		REGISTE_CLASS_START(demo3)
		REGISTE_METHOD_ONE(demo3, set_time)
		REGISTE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：float
*/
void invoke(const object* obj, const std::string& method_name, float param1) {
	long class_id = obj->get_class_id();

	REGISTE_CLASS_START(demo1)
		REGISTE_METHOD_ONE(demo1, set_woman)
		REGISTE_CLASS_END(demo1)

		REGISTE_CLASS_START(demo2)
		REGISTE_METHOD_ONE(demo2, set_woman)
		REGISTE_CLASS_END(demo2)

		REGISTE_CLASS_START(demo3)
		REGISTE_METHOD_ONE(demo3, set_woman)
		REGISTE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：double
*/
void invoke(const object* obj, const std::string& method_name, double param1) {
	long class_id = obj->get_class_id();

	REGISTE_CLASS_START(demo1)
		REGISTE_METHOD_ONE(demo1, set_man)
		REGISTE_CLASS_END(demo1)

		REGISTE_CLASS_START(demo2)
		REGISTE_METHOD_ONE(demo2, set_man)
		REGISTE_CLASS_END(demo2)

		REGISTE_CLASS_START(demo3)
		REGISTE_METHOD_ONE(demo3, set_man)
		REGISTE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：void*
*/
void invoke(const object* obj, const std::string& method_name, void* param1) {
	long class_id = obj->get_class_id();

	REGISTE_CLASS_START(demo1)
		REGISTE_METHOD_ONE(demo1, set_v)
		REGISTE_CLASS_END(demo1)

		REGISTE_CLASS_START(demo2)
		REGISTE_METHOD_ONE(demo2, set_v)
		REGISTE_CLASS_END(demo2)

		REGISTE_CLASS_START(demo3)
		REGISTE_METHOD_ONE(demo3, set_v)
		REGISTE_CLASS_END(demo3)
}

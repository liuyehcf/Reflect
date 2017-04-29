#pragma once
#include<stdexcept>
#include"micro.h"
#include"object.h"
#include"demo.h"
#include"config.h"



/*
* 零元函数反射注册
*/
object* new_instance(const std::string& class_name) {
	FACTORY_INVOKE_HEAD
		FACTORY_INVOKE(global_control_config)
		FACTORY_INVOKE(gtt_highspeed_config)
		return nullptr;
}

/*
* 零元函数反射注册
*/
void invoke(const object* obj, const std::string& method_name) {
	long class_id = obj->get_class_id();


	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_age)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_time)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_woman)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_man)
	METHOD_INVOKE_CLASS_END(demo1)

		METHOD_INVOKE_CLASS_START(demo2)
		METHOD_INVOKE_ZERO_PARAM(demo2, print_age)
		METHOD_INVOKE_ZERO_PARAM(demo2, print_time)
		METHOD_INVOKE_ZERO_PARAM(demo2, print_woman)
		METHOD_INVOKE_ZERO_PARAM(demo2, print_man)
		METHOD_INVOKE_CLASS_END(demo2)

		METHOD_INVOKE_CLASS_START(demo3)
		METHOD_INVOKE_ZERO_PARAM(demo3, print_age)
		METHOD_INVOKE_ZERO_PARAM(demo3, print_time)
		METHOD_INVOKE_ZERO_PARAM(demo3, print_woman)
		METHOD_INVOKE_ZERO_PARAM(demo3, print_man)
		METHOD_INVOKE_CLASS_END(demo3)

}

/*
* 函数反射注册
* 参数类型：int
*/
void invoke(const object* obj, const std::string& method_name, int param1) {
	long class_id = obj->get_class_id();

	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ONE_PARAM(demo1,set_age)
	METHOD_INVOKE_CLASS_END(demo1)

		METHOD_INVOKE_CLASS_START(demo2)
		METHOD_INVOKE_ONE_PARAM(demo2, set_age)
		METHOD_INVOKE_CLASS_END(demo2)

		METHOD_INVOKE_CLASS_START(demo3)
		METHOD_INVOKE_ONE_PARAM(demo3, set_age)
		METHOD_INVOKE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：long
*/
void invoke(const object* obj, const std::string& method_name, long param1) {
	long class_id = obj->get_class_id();

	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ONE_PARAM(demo1, set_time)
		METHOD_INVOKE_CLASS_END(demo1)

		METHOD_INVOKE_CLASS_START(demo2)
		METHOD_INVOKE_ONE_PARAM(demo2, set_time)
		METHOD_INVOKE_CLASS_END(demo2)

		METHOD_INVOKE_CLASS_START(demo3)
		METHOD_INVOKE_ONE_PARAM(demo3, set_time)
		METHOD_INVOKE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：float
*/
void invoke(const object* obj, const std::string& method_name, float param1) {
	long class_id = obj->get_class_id();

	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ONE_PARAM(demo1, set_woman)
		METHOD_INVOKE_CLASS_END(demo1)

		METHOD_INVOKE_CLASS_START(demo2)
		METHOD_INVOKE_ONE_PARAM(demo2, set_woman)
		METHOD_INVOKE_CLASS_END(demo2)

		METHOD_INVOKE_CLASS_START(demo3)
		METHOD_INVOKE_ONE_PARAM(demo3, set_woman)
		METHOD_INVOKE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：double
*/
void invoke(const object* obj, const std::string& method_name, double param1) {
	long class_id = obj->get_class_id();

	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ONE_PARAM(demo1, set_man)
		METHOD_INVOKE_CLASS_END(demo1)

		METHOD_INVOKE_CLASS_START(demo2)
		METHOD_INVOKE_ONE_PARAM(demo2, set_man)
		METHOD_INVOKE_CLASS_END(demo2)

		METHOD_INVOKE_CLASS_START(demo3)
		METHOD_INVOKE_ONE_PARAM(demo3, set_man)
		METHOD_INVOKE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：void*
*/
void invoke(const object* obj, const std::string& method_name, void* param1) {
	long class_id = obj->get_class_id();

	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ONE_PARAM(demo1, set_v)
		METHOD_INVOKE_CLASS_END(demo1)

		METHOD_INVOKE_CLASS_START(demo2)
		METHOD_INVOKE_ONE_PARAM(demo2, set_v)
		METHOD_INVOKE_CLASS_END(demo2)

		METHOD_INVOKE_CLASS_START(demo3)
		METHOD_INVOKE_ONE_PARAM(demo3, set_v)
		METHOD_INVOKE_CLASS_END(demo3)
}

/*
* 函数反射注册
* 参数类型：void*
*/
void invoke(const object* obj, const std::string& method_name, const std::string& param1) {
	long class_id = obj->get_class_id();


	METHOD_INVOKE_CLASS_START(global_control_config)
		METHOD_INVOKE_ONE_PARAM(global_control_config, set_ntti)

		METHOD_INVOKE_CLASS_END(global_control_config)


	METHOD_INVOKE_CLASS_START(gtt_highspeed_config)
		METHOD_INVOKE_ONE_PARAM(gtt_highspeed_config, set_road_length)
		METHOD_INVOKE_ONE_PARAM(gtt_highspeed_config, set_road_width)

		METHOD_INVOKE_CLASS_END(gtt_highspeed_config)
}

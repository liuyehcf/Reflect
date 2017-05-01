#include<stdexcept>
#include"invoke.h"
#include"demo.h"

REGISTE_CLASS_ID_RESOURCE(demo1)

/*
* ��Ԫ��������ע��
*/
object* new_instance(const std::string& class_name) {
	FACTORY_INVOKE_START
		FACTORY_INVOKE(demo1)
		FACTORY_INVOKE_END
}

/*
* ��Ԫ��������ע��
*/
void invoke(const object* obj, const std::string& method_name) {
	long class_id = obj->get_class_id();
	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_age)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_time)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_man)
		METHOD_INVOKE_ZERO_PARAM(demo1, print_woman)
		METHOD_INVOKE_CLASS_END(demo1)
}

/*
* ��������ע��
* �������ͣ�int
*/
void invoke(const object* obj, const std::string& method_name, int param1) {
	long class_id = obj->get_class_id();

}

/*
* ��������ע��
* �������ͣ�long
*/
void invoke(const object* obj, const std::string& method_name, long param1) {
	long class_id = obj->get_class_id();


}

/*
* ��������ע��
* �������ͣ�float
*/
void invoke(const object* obj, const std::string& method_name, float param1) {
	long class_id = obj->get_class_id();


}

/*
* ��������ע��
* �������ͣ�double
*/
void invoke(const object* obj, const std::string& method_name, double param1) {
	long class_id = obj->get_class_id();

}

/*
* ��������ע��
* �������ͣ�void*
*/
void invoke(const object* obj, const std::string& method_name, void* param1) {
	long class_id = obj->get_class_id();

}

/*
* ��������ע��
* �������ͣ�void*
*/
void invoke(const object* obj, const std::string& method_name, const std::string& param1) {
	long class_id = obj->get_class_id();
	METHOD_INVOKE_CLASS_START(demo1)
		METHOD_INVOKE_ONE_PARAM(demo1, set_age)
		METHOD_INVOKE_ONE_PARAM(demo1, set_time)
		METHOD_INVOKE_ONE_PARAM(demo1, set_man)
		METHOD_INVOKE_ONE_PARAM(demo1, set_woman)
		METHOD_INVOKE_CLASS_END(demo1)
}


void invoke(const object* obj, const std::string& method_name, object* param1) {
	long class_id = obj->get_class_id();
}

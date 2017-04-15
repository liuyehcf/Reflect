#pragma once
#include<stdexcept>
#include"object.h"
#include"demo.h"

/*
* �����жϿ�ʼ
*/
#define REGISTE_CLASS_START(class_type)\
if(class_id==class_type::class_id){\
	class_type * __##class_type = (class_type*)obj;\
	if (method_name == "") {\
		throw std::logic_error("������ú���ʧ��"); \
	}

/*
* �����жϽ���
*/
#define REGISTE_CLASS_END(class_type)\
	else {\
		throw std::logic_error("������ú���ʧ��");\
	}\
}

/*
* ��Ԫ�����жϼ�����
*/
#define REGISTE_METHOD_ZERO(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method();\
	}

/*
* һԪ�����жϼ�����
*/
#define REGISTE_METHOD_ONE(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1);\
	}

/*
* ��Ԫ�����жϼ�����
*/
#define REGISTE_METHOD_TWO(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2);\
	}

/*
* ��Ԫ�����жϼ�����
*/
#define REGISTE_METHOD_THREE(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2,param3);\
	}

/*
* ��Ԫ�����жϼ�����
*/
#define REGISTE_METHOD_FOUR(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2,param3,param4);\
	}

/*
* ��Ԫ�����жϼ�����
*/
#define REGISTE_METHOD_FIVE(class_type,method)\
	else if(method_name == #method){\
		__##class_type -> method(param1,param2,param3,param4,param5);\
	}


/*
* ��Ԫ��������ע��
*/
void invoke(object* obj, const std::string& method_name) {
	long class_id = obj->get_class_id();


	REGISTE_CLASS_START(demo)
	REGISTE_METHOD_ZERO(demo, func)
	REGISTE_CLASS_END(demo)

}

/*
* һԪ��������ע��
*/
template <typename T1>
void invoke(object* obj, const std::string& method_name, T1&& param1) {
	long class_id = obj->get_class_id();


	REGISTE_CLASS_START(demo)
	REGISTE_METHOD_ONE(demo, set_age)
	REGISTE_CLASS_END(demo)

}

/*
* ��Ԫ��������ע��
*/
template <typename T1, typename T2>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2) {
	long class_id = obj->get_class_id();

}

/*
* ��Ԫ��������ע��
*/
template <typename T1, typename T2, typename T3>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3) {
	long class_id = obj->get_class_id();

}

/*
* ��Ԫ��������ע��
*/
template <typename T1, typename T2, typename T3, typename T4>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3, T4&& param4) {
	long class_id = obj->get_class_id();

	REGISTE_CLASS_START(demo4)
	REGISTE_METHOD_FOUR(demo4, add)
	REGISTE_CLASS_END(demo4)
}

/*
* ��Ԫ��������ע��
*/
template <typename T1, typename T2, typename T3, typename T4, typename T5>
void invoke(object* obj, const std::string& method_name, T1&& param1, T2&& param2, T3&& param3, T4&& param4, T5&& param5) {
	long class_id = obj->get_class_id();

}
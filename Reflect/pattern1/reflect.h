#pragma once
#include<map>
#include<string>
#include<utility>

/*
* ���幤�����������ͱ���
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
* �����Ψһ�����ǣ�
* �ڴ��������ʵ��ʱ��������Ĳ���ע�ᵽreflect��
* ��һ��ǳ�����������Ҫ�ڳ����ʼ������Ҫ�������ע�ᵽreflect�У��ͻ���Ҫ��һ��ִ����main�����ͷ�ĺ������������һ������
* ͨ����һ���ɣ�����ʹ�øù����ھ�̬������ʼ���Ĺ�������������
*/
class factory_register {
public:
	factory_register(std::string class_name, create_method method) {
		reflect::get_singleton()->registe_class(class_name, method);
	}
};

/*
* �ú궨�幤���������ù����������ᱻREGISTER_OUTTER���õ�
* �����˱�ʾ���������ֵľ�̬�ַ���,�����˾�̬��ע����ʵ������ʵ���������ʼ���������reflectע��Ĺ���
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
* ��REGISTER_INNER��Ӧ���������reflect����ע��Ĺ���
*/
#define REGISTER_OUTTER(class_type) \
const std::string class_type::_class_name=#class_type; \
factory_register* class_type::fr=new factory_register(class_type::_class_name,class_type::create_instance);



/*
* ����ͨ��set���������ͱ���
*/
typedef void(*set_method)(void* obj, void* value);


/*
* �ú궨���˴���ָ�����Ե�setter������ģʽ�������ظ��Ͷ�
*/
#define SETTER_METHOD(class_type,property_type,property_name) \
public:\
	inline static void set_##property_name(void* obj,void* value) {\
		class_type* temp=(class_type*) obj;\
		temp->property_name=(property_type)value;\
	}\
private:
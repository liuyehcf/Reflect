#pragma once
#include<string>

/*
* ��Ԫ����
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
* �����˷���Ļ���
*/
class object {
	INVOKE_FRIEND_DECLARED
public:
	void* operator new(size_t size, long class_id) {
		//�Է���һ��long����Ϊ����ͷ
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
* ע������id�ĺ�
*/
#define REGISTE_CLASS_ID(class_type)\
protected:\
	static const long class_id;\

/*
* ���幤������
*/
#define REGISTE_FACTORY_METHOD(class_type)\
public:\
	static object* new_instance(){\
		return new class_type();\
	}\
private:

/*
* ����operator new�������ĺ�
*/
#define OVERRIDE_OPERATOR_NEW(class_type)\
public:\
	void* operator new(size_t size) {\
		return object::operator new(size, class_type::class_id);\
	}\
private:

/*
* ����operator delete�������ĺ�
*/
#define OVERRIDE_OPERATOR_DELETE(class_type)\
public:\
	void operator delete(void*p){\
		object::operator delete(p);\
	}\
private:

/*
* �ú���������漸���꣬���ڱ�����������ע��
*/
#define REGISTE_MEMBER_HEAD(class_type)\
INVOKE_FRIEND_DECLARED \
REGISTE_CLASS_ID(class_type) \
REGISTE_FACTORY_METHOD(class_type) \
OVERRIDE_OPERATOR_NEW(class_type) \
OVERRIDE_OPERATOR_DELETE(class_type) \

/*
* ��Դ�ļ��г�ʼ������id
*/
#define REGISTE_MEMBER_RESOURCE(class_type)\
const long class_type::class_id = ++object::class_id;
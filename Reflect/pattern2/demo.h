#pragma once
#include"object.h"
#include<iostream>

class demo :public object {
	/*
	* 要实现反射必须进行注册
	*/
	REGISTE_MEMBER_HEAD(demo)

private:
	int age;
public:
	void set_age(int age) {
		this->age = age;
	}
	int get_age() {
		return age;
	}

public:
	void func() {
		std::cout << "hehe" << std::endl;
	}
};


class demo2 :public object {
	REGISTE_MEMBER_HEAD(demo2)
};

class demo3 :public object {
	REGISTE_MEMBER_HEAD(demo3)
};

class demo4 :public object {
	REGISTE_MEMBER_HEAD(demo4)
public:
	int add(int i, int j, int m, int k) {
		int res = i + j + m + k;
		std::cout << res << std::endl;
		return i + j + m + k;
	}
};

class demo5 :public object {
	REGISTE_MEMBER_HEAD(demo5)
};
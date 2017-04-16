#pragma once
#include"object.h"
#include<vector>
#include<iostream>

class demo1 :public object {
	/*
	* 要实现反射必须进行注册
	*/
	REGISTE_MEMBER_HEAD(demo1)

private:
	int age;
	long time;
	float woman;
	double man;
	std::vector<int> v;
public:
	void set_age(int age) {
		this->age = age;
	}
	void print_age() {
		std::cout << "demo1's age: " << this->age << std::endl;
	}

	void set_time(long time) {
		this->time = time;
	}
	void print_time() {
		std::cout << "demo1's time: " << this->time << std::endl;
	}

	void set_woman(float woman) {
		this->woman = woman;
	}
	void print_woman() {
		std::cout << "demo1's woman: " << this->woman << std::endl;
	}

	void set_man(double man) {
		this->man = man;
	}
	void print_man() {
		std::cout << "demo1's man: " << this->man << std::endl;
	}

	void set_v(void *p) {
		v = *(std::vector<int>*)p;
	}

	void print_v() {
		std::cout << "demo1's v: ";
		for (int i : v) {
			std::cout << i << ", ";
		}
		std::cout << std::endl;
	}


};


class demo2 :public object {
	REGISTE_MEMBER_HEAD(demo2)

private:
	int age;
	long time;
	float woman;
	double man;
	std::vector<int> v;
public:
	void set_age(int age) {
		this->age = age;
	}
	void print_age() {
		std::cout << "demo2's age: " << this->age << std::endl;
	}

	void set_time(long time) {
		this->time = time;
	}
	void print_time() {
		std::cout << "demo2's time: " << this->time << std::endl;
	}

	void set_woman(float woman) {
		this->woman = woman;
	}
	void print_woman() {
		std::cout << "demo2's woman: " << this->woman << std::endl;
	}

	void set_man(double man) {
		this->man = man;
	}
	void print_man() {
		std::cout << "demo2's man: " << this->man << std::endl;
	}

	void set_v(void *p) {
		v = *(std::vector<int>*)p;
	}

	void print_v() {
		std::cout << "demo2's v: ";
		for (int i : v) {
			std::cout << i << ", ";
		}
		std::cout << std::endl;
	}
};

class demo3 :public object {
	REGISTE_MEMBER_HEAD(demo3)

private:
	int age;
	long time;
	float woman;
	double man;
	std::vector<int> v;
public:
	void set_age(int age) {
		this->age = age;
	}
	void print_age() {
		std::cout << "demo3's age: " << this->age << std::endl;
	}

	void set_time(long time) {
		this->time = time;
	}
	void print_time() {
		std::cout << "demo3's time: " << this->time << std::endl;
	}

	void set_woman(float woman) {
		this->woman = woman;
	}
	void print_woman() {
		std::cout << "demo3's woman: " << this->woman << std::endl;
	}

	void set_man(double man) {
		this->man = man;
	}
	void print_man() {
		std::cout << "demo3's man: " << this->man << std::endl;
	}

	void set_v(void *p) {
		v = *(std::vector<int>*)p;
	}

	void print_v() {
		std::cout << "demo1's v: ";
		for (int i : v) {
			std::cout << i << ", ";
		}
		std::cout << std::endl;
	}
};

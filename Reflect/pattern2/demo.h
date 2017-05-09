#pragma once
#include"object.h"
#include<vector>
#include<string>
#include<iostream>

class demo2;

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


	void set_age(std::string age) {
		this->age = stoi(age);
	}
	void print_age() {
		std::cout << "demo1's age: " << this->age << std::endl;
	}

	void set_time(std::string time) {
		this->time = stol(time);
	}
	void print_time() {
		std::cout << "demo1's time: " << this->time << std::endl;
	}

	void set_woman(std::string woman) {
		this->woman = stof(woman);
	}
	void print_woman() {
		std::cout << "demo1's woman: " << this->woman << std::endl;
	}

	void set_man(std::string man) {
		this->man = stod(man);
	}
	void print_man() {
		std::cout << "demo1's man: " << this->man << std::endl;
	}

private:
	demo2* _demo2 = nullptr;
	void set_demo2(object* t_demo2) {
		_demo2 = (demo2*)t_demo2;
	}

private:
	void init() {
		std::cout << "demo1's init" << std::endl;
	}
};

class demo2 :public object {
	/*
	* 要实现反射必须进行注册
	*/
	REGISTE_MEMBER_HEAD(demo2)

private:
	demo1* _demo1 = nullptr;
	void set_demo1(object* t_demo1) {
		_demo1 = (demo1*)t_demo1;
	}

private:
	void init() {
		std::cout << "demo2's init" << std::endl;
	}
};
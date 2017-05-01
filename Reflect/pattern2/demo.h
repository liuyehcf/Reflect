#pragma once
#include"object.h"
#include<vector>
#include<string>
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
};

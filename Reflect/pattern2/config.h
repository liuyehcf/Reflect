#pragma once
#include<vector>
#include<string>
#include"object.h"

#define INVALID -1

class config_loader;

class global_control_config :object{
	/*
	* 要实现反射必须进行注册
	*/
	REGISTE_MEMBER_HEAD(global_control_config)

	/*
	* 仿真时长
	*/
private:
	int m_ntti;
	void set_ntti(std::string t_ntti) {
		m_ntti = stoi(t_ntti);
	}
public:
	int get_ntti() {
		return m_ntti;
	}
};


class gtt_highspeed_config:public object  {
	/*
	* 要实现反射必须进行注册
	*/
	REGISTE_MEMBER_HEAD(gtt_highspeed_config)
	
	/*
	* 路长,单位m
	*/
private:
	double m_road_length = INVALID;
public:
	void set_road_length(std::string t_road_length) {
		m_road_length = stod(t_road_length);
	}
	double get_road_length() {
		return m_road_length;
	}

	/*
	* 路宽，单位m
	*/
private:
	double m_road_width = INVALID;
public:
	void set_road_width(std::string t_road_width) {
		m_road_width = stod(t_road_width);
	}
	double get_road_width() {
		return m_road_width;
	}
};

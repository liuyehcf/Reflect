#include"demo.h"
#include"invoke.h"
#include<iostream>

using namespace std;


static int main1() {
	object *d1 = demo1::new_instance();
	object *d2 = demo2::new_instance();
	object *d3 = demo3::new_instance();


	invoke(d1, "set_age", 5);
	invoke(d1, "set_time", 1000L);
	invoke(d1, "set_woman", 1.5f);
	invoke(d1, "set_man", 0.99);

	invoke(d1, "print_age");
	invoke(d1, "print_time");
	invoke(d1, "print_woman");
	invoke(d1, "print_man");

	invoke(d2, "set_age", 5);
	invoke(d2, "set_time", 1000L);
	invoke(d2, "set_woman", 1.5f);
	invoke(d2, "set_man", 0.99);

	invoke(d2, "print_age");
	invoke(d2, "print_time");
	invoke(d2, "print_woman");
	invoke(d2, "print_man");

	invoke(d3, "set_age", 5);
	invoke(d3, "set_time", 1000L);
	invoke(d3, "set_woman", 1.5f);
	invoke(d3, "set_man", 0.99);

	invoke(d3, "print_age");
	invoke(d3, "print_time");
	invoke(d3, "print_woman");
	invoke(d3, "print_man");
	

	system("pause");
}



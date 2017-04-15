#include"demo.h"
#include"invoke.h"
#include<iostream>

using namespace std;


int main() {
	object *d1 = demo::new_instance();

	invoke(d1, "set_age", 25);

	invoke(d1, "func");

	cout << ((demo*)d1)->get_age() << endl;

	cout << "class_id of demo: " << d1->get_class_id() << endl;

	delete d1;


	object *d2 = new demo2();
	object *d3 = new demo3();
	object *d4 = new demo4();
	object *d5 = new demo5();

	cout << "class_id of demo2: " << d2->get_class_id() << endl;
	delete d2;
	cout << "class_id of demo3: " << d3->get_class_id() << endl;
	delete d3;
	cout << "class_id of demo4: " << d4->get_class_id() << endl;
	invoke(d4, "add", 1, 2, 3, 4);

	delete d4;
	cout << "class_id of demo5: " << d5->get_class_id() << endl;
	delete d5;
	system("pause");
}
#include"context.h"

using namespace std;

context* context::__context = nullptr;

void context::init() {
	parseConfiguration();

	create_and_init_bean();
}

void context::parseConfiguration() {

}

void context::create_and_init_bean() {

}
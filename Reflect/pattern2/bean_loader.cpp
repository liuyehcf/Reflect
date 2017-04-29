#include<regex>
#include<fstream>
#include<iostream>
#include"bean_loader.h"

using namespace std;

vector<bean_definition*> bean_loader::load() {
	vector<bean_definition*> res;

	const regex BEAN_REGEX("<bean([^>]+)>([\\s\\S]*?)</bean>");


	//¶ÁÈ¡´ý½âÎö×Ö·û´®
	ifstream in(configuration_path);
	istreambuf_iterator<char> if_it(in), if_eof;
	string content(if_it, if_eof);
	in.close();

	//½âÎö£¬²¢´æ´¢
	for (sregex_iterator it(content.begin(), content.end(), BEAN_REGEX), eof; it != eof; ++it) {
		string inside_info = it->operator[](1);
		string content_info = it->operator[](2);

		bean_definition* definition = create_bean_definition(inside_info);

		add_property(definition, content_info);
		add_dependency(definition, content_info);

		cout << definition->to_string() << endl;
		system("pause");
	}

	return res;
}


bean_definition* bean_loader::create_bean_definition(const std::string s) {
	bean_definition* definition = new bean_definition();
	const regex REGEX("id *= *\"([^\"]+)\" *, *class *= *\"([^\"]+)\"");
	sregex_iterator it(s.begin(), s.end(), REGEX);
	definition->id = it->operator[](1);
	definition->class_type = it->operator[](2);
	return definition;
}

void bean_loader::add_property(bean_definition* definition, const std::string s) {
	const regex REGEX("<property +name *= *\"([^\"]+)\" *, *value *= *\"([^\"]+)\" */>");
	for (sregex_iterator it(s.begin(), s.end(), REGEX), eof; it != eof; ++it) {
		definition->properties.push_back(bean_property(
			it->operator[](1),
			it->operator[](2)
			));
	}
}

void bean_loader::add_dependency(bean_definition* definition, const std::string s) {
	const regex REGEX("<dependency +ref-id *= *\"([^\"]+)\" */>");
	for (sregex_iterator it(s.begin(), s.end(), REGEX), eof; it != eof; ++it) {
		definition->dependencies.push_back(it->operator[](1));
	}
}


int main() {
	bean_loader bl("E:\\CppProgram\\Reflect\\Reflect\\pattern2\\beans.xml");
	bl.load();
	system("pause");
}
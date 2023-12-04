#include <iostream>
#include <map>
#include <vector>
#include "SqlQueryBuilder.h"

void static_assert1(std::string vol, std::string test)
{
	if (vol == test)
		std::cout << "Test Ok" << "\n";
	else
		std::cout << "Test faled!!!\n" << ":> " << vol << "\n" << ":> " << test << "\n";
}

int main()
{
	SQLSelectQueryBuilder query_builder;
	query_builder.AddColumn("name").AddColumn("phone");
	query_builder.AddFrom("students");
	query_builder.AddWhere("id", "42").AddWhere("name", "John");
	static_assert1(query_builder.BuildQuery(), 
				"SELECT name, phone FROM students WHERE id=42 AND name=John;");

	SQLSelectQueryBuilder query_builder2;
	std::map<std::string, std::string> search_cond;
	search_cond.emplace("_id", "35");
	search_cond.emplace("first_name", "Polya");
	query_builder2.AddWhere(search_cond);
	std::vector <std::string> columns;
	columns.push_back("color");
	columns.push_back("volume");
	query_builder2.AddColumns(columns);
	query_builder2.AddFrom("rocket");
	static_assert1(query_builder2.BuildQuery(),
		"SELECT color, volume FROM rocket WHERE _id=35 AND first_name=Polya;");
}

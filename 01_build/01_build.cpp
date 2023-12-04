#include <iostream>
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
//	static_assert(query_builder.BuildQuery() != "SELECT name, phone FROM students WHERE id = 42 AND name = John; ", "Test failed");
}

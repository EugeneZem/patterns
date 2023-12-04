#pragma once
#include <iostream>
#include <vector>
#include <map>


struct SQLSelectQuery
{
	std::vector<std::string> columns;
	std::string table;
	std::map<std::string, std::string> where;
};

class SQLSelectQueryBuilder
{
public:
	SQLSelectQueryBuilder& AddColumn(const std::string& column);
	SQLSelectQueryBuilder& AddFrom(const std::string& table);
	SQLSelectQueryBuilder& AddWhere(const std::string& key, const std::string& va);
	std::string BuildQuery();

private:
	SQLSelectQuery SelectQuery;
};

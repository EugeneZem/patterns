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
	SQLSelectQueryBuilder& AddColumns(const std::vector<std::string>& columns) noexcept;
	SQLSelectQueryBuilder& AddFrom(const std::string& table);
	SQLSelectQueryBuilder& AddWhere(const std::string& key, const std::string& va);
	SQLSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv) noexcept;

	std::string BuildQuery();

private:
	SQLSelectQuery SelectQuery;
};

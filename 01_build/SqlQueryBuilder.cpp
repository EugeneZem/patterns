#include "SqlQueryBuilder.h"

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddColumn(const std::string& column)
{
	SelectQuery.columns.push_back(column);
	return *this;
}

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddFrom(const std::string& table)
{
	SelectQuery.table = table;
	return *this;
}

SQLSelectQueryBuilder& SQLSelectQueryBuilder::AddWhere(const std::string& key, const std::string& val)
{
	{
		SelectQuery.where[key] = val;
	}
	return *this;
}

std::string SQLSelectQueryBuilder::BuildQuery()
{
	if (SelectQuery.table.empty())
	{
		return "";
	}

	std::string Query = "SELECT ";	

	if (!SelectQuery.columns.empty()) 
	{
		bool f = true;
		for (const std::string& collumn : SelectQuery.columns)
		{
			if (f)
			{			
				Query += collumn; 
				f = false;
			}
			else
			{
				Query += ", " + collumn;
			}
		}
	}
	else
	{
		Query += "*";
	}

	Query += " FROM " + SelectQuery.table;

	if (!SelectQuery.where.empty())
	{
		Query += " WHERE ";
		bool f = true;
		for (const std::pair<std::string, std::string>& where : SelectQuery.where)
		{
			if (f)
			{
				Query += where.first + "=" + where.second;
				f = false;
			}
			else
			{
				Query += " AND " + where.first + "=" + where.second;
			}
		}
	}

	Query += ";";

	return Query;
}
#pragma once
#include <memory>
#include "date.h"

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	And,
	Or
};

class Node
{
public:
	virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node
{
public:
	bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& c, const Date& d)
		: cmp{ c }
		, date_{ d }
	{
	}
	bool Evaluate(const Date& date, const std::string& event) const override;
	const Comparison cmp;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& c, const std::string& event)
		: cmp{ c }
		, event_{ event }
	{
	}
	bool Evaluate(const Date& date, const std::string& event) const override;
	const Comparison cmp;
	const std::string event_;
};

class LogicalOperationNode : public Node
{
public:
	LogicalOperationNode(const LogicalOperation& l_op, const std::shared_ptr<Node>& l, const std::shared_ptr<Node>& r)
		: logical_operation{ l_op }
		, left{ l }
		, right{ r }
	{
	}
	bool Evaluate(const Date& date, const std::string& event) const override;
	const LogicalOperation logical_operation;
	const std::shared_ptr<Node> left;
	const std::shared_ptr<Node> right;
};
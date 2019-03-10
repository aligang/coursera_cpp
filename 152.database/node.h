#pragma once

#include <memory>

#include "date.h"


enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};


enum class LogicalOperation {
    And,
    Or
};


class Node{
    public:
        virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
}; 


class EmptyNode:public Node {
    public:
        bool Evaluate(const Date& date, const std::string& event) const;
};


class DateComparisonNode:public Node{
    public:
        DateComparisonNode(const Comparison& comparison, const Date& date);
        bool Evaluate(const Date& date, const std::string& event) const;
    private:
        Comparison _comparison;
        Date _date;
};


class EventComparisonNode:public Node{
    public:
        EventComparisonNode(const Comparison& comparison, const std::string& event);
        bool Evaluate(const Date& date, const std::string& event) const;
    private:
        Comparison _comparison;
        std::string _event;
};


class LogicalOperationNode:public Node{
    public:
        LogicalOperationNode(
            const LogicalOperation& logical_operation, 
            std::shared_ptr<Node> left_node, 
            std::shared_ptr<Node> right_node
        );
        bool Evaluate(const Date& date, const std::string& event) const;
    private:
        LogicalOperation _logical_operation;
        std::shared_ptr<Node> _left_node, _right_node;  
};
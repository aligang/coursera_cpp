#include "node.h"

template <class ComparisonElementClass>
bool PerformFieldComparison(
    const ComparisonElementClass& left, 
    const Comparison& comparison, 
    const ComparisonElementClass& right
){
    if (comparison == Comparison::Greater){
        return left > right;
    } else if (comparison == Comparison::GreaterOrEqual){
        return left >= right;
    } else if (comparison == Comparison::Less){
        return left < right;
    } else if (comparison == Comparison::LessOrEqual){
        return left <= right;
    } else if (comparison == Comparison::Equal){
        return left == right;
    } else if (comparison == Comparison::NotEqual){
        return left != right;
    }
}


//virtual bool Node::Evaluate(const Date& date, const std::string& event) const = 0;


bool EmptyNode::Evaluate(const Date& date, const std::string& event) const{
    return true;
};


DateComparisonNode::DateComparisonNode(const Comparison& comparison, const Date& date): _comparison(comparison), _date(date) {};

bool DateComparisonNode::Evaluate(const Date& date, const std::string& event) const {
    return PerformFieldComparison(date, _comparison, _date);
};


EventComparisonNode::EventComparisonNode(const Comparison& comparison, const std::string& event): _comparison(comparison), _event(event){};

bool EventComparisonNode::Evaluate(const Date& date, const std::string& event) const {
    return PerformFieldComparison(event, _comparison, _event);
};


LogicalOperationNode::LogicalOperationNode(
    const LogicalOperation& logical_operation, 
    std::shared_ptr<Node> left_node, 
    std::shared_ptr<Node> right_node
): 
    _logical_operation(logical_operation)
    {
        _left_node = left_node;
        _right_node = right_node;
    };

bool LogicalOperationNode::Evaluate(const Date& date, const std::string& event) const {
    if (_logical_operation == LogicalOperation::And){
        return (_left_node->Evaluate(date, event) && _right_node->Evaluate(date, event));
    } else if (_logical_operation == LogicalOperation::Or) {
        return (_left_node->Evaluate(date, event) || _right_node->Evaluate(date, event));
    }
};
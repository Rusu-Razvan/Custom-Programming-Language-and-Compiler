#include <string>
#include <cstring>
class ASTNode {
public:
    std::string type = "null";
    std::string nodeType = "null";
    std::string value = "invalid";  
    ASTNode* son1 = nullptr;
    ASTNode* son2 = nullptr;

    //ASTNode(int constantValue): nodeType("constant"), value(std::to_string(constantValue)), type(type) {};
    ASTNode(std::string value, std::string type) :  nodeType("variable"), value(value), type(type) {};
    ASTNode(int value, std::string type) :  nodeType("variable"), value(std::to_string(value)), type(type) {};
    ASTNode(ASTNode* member) :  nodeType("unary"), son1(member) {};
    ASTNode(ASTNode* memberLeft, ASTNode* memberRight) : nodeType("binary"), son1(memberLeft), son2(memberRight) {};

    ~ASTNode();

    std::string getValue();

    std::string evaluate();
};

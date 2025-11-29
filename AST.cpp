#include "AST.h"
#include <stdexcept>
#include <iostream>

ASTNode::~ASTNode()
{
    delete son1;
    delete son2;
}

std::string ASTNode::getValue() { return this->value; }

std::string ASTNode::evaluate()
{
    if (nodeType == "constant" || nodeType == "variable")
    {
        if (this->value == "invalid")
        {
            printf("a");
            return "invalid";
        }
        else
            return this->value;
    }
    else if (nodeType == "unary")
    {
        son1->evaluate();
        if (son1->value == "invalid")
        {
            return "invalid";
        }
        std::string operandValue = this->son1->evaluate();
        if (value == "-")
        {
            if (son1->type == "bool")
            {
                printf("Cannot use '-' to negate bool!\n");
                return "invalid";
            }
            type = son1->type;
            return "-" + operandValue;
        }
        if (value == "!")
        {
            if (son1->type != "bool")
            {
                printf("Cannot use '!' on non-bool variable!\n");
                return "invalid";
            }
            if (operandValue == "real")
                return "fake";
            else
                return "real";
        }
        return "invalid";
    }
    else if (nodeType == "binary")
    {
        std::string leftValue = son1->evaluate();
        std::string rightValue = son2->evaluate();
        if (leftValue == "invalid" || rightValue == "invalid")
        {
            return "invalid";
        }
        if (value == "+")
        {
            if (son1->type != son2->type)
            {
                printf("Two different types in an equation\n");
                return "invalid";
            }
            else if (son1->type == "bool" || son2->type == "bool")
            {
                printf("Can't use + and - on bool operands!\n");
                return "invalid";
            }
            else
            {
                try
                {
                    this->type = son1->type;
                    if (this->type == "int")
                    {
                        return std::to_string(std::stoi(leftValue) + std::stoi(rightValue));
                    }
                    else
                    {
                        return std::to_string(std::stof(leftValue) + std::stof(rightValue));
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    printf("Invalid use! %s\n", e.what());
                    return "invalid";
                }
            }
        }
        if (value == "-")
        {
            if (son1->type != son2->type)
            {
                printf("Two different types in an equation\n");
                return "invalid";
            }
            else if (son1->type == "bool" || son2->type == "bool")
            {
                printf("Can't use + and - on bool operands!\n");
                return "invalid";
            }
            else
            {
                try
                {
                    this->type = son1->type;
                    if (this->type == "int")
                    {
                        return std::to_string(std::stoi(leftValue) - std::stoi(rightValue));
                    }
                    else
                    {
                        return std::to_string(std::stof(leftValue) - std::stof(rightValue));
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    printf("Invalid use! %s\n", e.what());
                    return "invalid";
                }
            }
        }
        if (value == "*")
        {
            if (son1->type != son2->type)
            {
                printf("Two different types in an equation\n");
                return "invalid";
            }
            else if (son1->type == "bool" || son2->type == "bool")
            {
                printf("Can't use * on bool operands!\n");
                return "invalid";
            }
            else
            {
                try
                {
                    this->type = son1->type;
                    if (this->type == "int")
                    {
                        return std::to_string(std::stoi(leftValue) * std::stoi(rightValue));
                    }
                    else
                    {
                        return std::to_string(std::stof(leftValue) * std::stof(rightValue));
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    printf("Invalid use! %s\n", e.what());
                    return "invalid";
                }
            }
        }
        if (value == "/")
        {
            if (rightValue == "0")
            {
                printf("Division by zero");
                return "Invalid usage\n";
            }
            if (son1->type != son2->type)
            {
                printf("Two different types in an equation\n");
                return "invalid";
            }
            else if (son1->type == "bool" || son2->type == "bool")
            {
                printf("Can't use / on bool operands!\n");
                return "invalid";
            }
            else
            {
                try
                {
                    this->type = son1->type;
                    if (this->type == "int")
                    {
                        return std::to_string(std::stoi(leftValue) / std::stoi(rightValue));
                    }
                    else
                    {
                        return std::to_string(std::stof(leftValue) / std::stof(rightValue));
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    printf("Invalid use! %s\n", e.what());
                    return "invalid";
                }
            }
        }
        if (value == "<")
        {
            this->type = "bool";
            if (son1->type == "bool" || son2->type == "bool")
            {
                printf("Can't use < on bool operands!\n");
            }
            try
            {
                if (std::stoi(leftValue) < std::stoi(rightValue))
                {
                    return "real";
                }
                else
                    return "fake";
            }
            catch (const std::invalid_argument &e)
            {
                printf("Invalid use! %s\n", e.what());
                return "invalid";
            }
        }
        if (value == ">")
        {
            this->type = "bool";

            if (son1->type == "bool" || son2->type == "bool")
            {
                printf("Can't use > on bool operands!\n");
            }
            try
            {
                if (std::stoi(leftValue) > std::stoi(rightValue))
                {
                    return "real";
                }
                else
                    return "fake";
            }
            catch (const std::invalid_argument &e)
            {
                printf("Invalid use! %s\n", e.what());
                return "invalid";
            }
        }
        if (value == ">=")
        {
            this->type = "bool";

            try
            {
                if (std::stoi(leftValue) >= std::stoi(rightValue))
                {
                    return "real";
                }
                else
                    return "fake";
            }
            catch (const std::invalid_argument &e)
            {
                printf("Invalid use! %s\n", e.what());
                return "invalid";
            }
        }
        if (value == "<=")
        {
            this->type = "bool";

            try
            {
                if (std::stoi(leftValue) <= std::stoi(rightValue))
                {
                    return "real";
                }
                else
                    return "fake";
            }
            catch (const std::invalid_argument &e)
            {
                printf("Invalid use! %s\n", e.what());
                return "invalid";
            }
        }
        if (value == "==")
        {
            this->type = "bool";
            if (son1->type != "bool")
            {
                try
                {
                    if (std::stoi(leftValue) == std::stoi(rightValue))
                    {
                        return "real";
                    }
                    else
                        return "fake";
                }
                catch (const std::invalid_argument &e)
                {
                    printf("Invalid use! %s\n", e.what());
                    return "invalid";
                }
            }
            else
            {
                if (leftValue == rightValue)
                {
                    return "real";
                }
                else
                    return "fake";
            }
        }
        if (value == "&&")
        {
            this->type = "bool";

            if (son1->type != "bool" || son2->type != "bool")
            {
                printf("Can't use && and || on non-bool operands!\n");
            }
            if (leftValue == "real" && rightValue == "real")
            {
                return "real";
            }
            else
                return "fake";
        }
        if (value == "||")
        {
            this->type = "bool";

            if (son1->type != "bool" || son2->type != "bool")
            {
                printf("Can't use && and || on non-bool operands!\n");
            }
            if (leftValue == "real" || rightValue == "real")
            {
                return "real";
            }
            else
                return "fake";
        }
    }
    return "invalid";
}
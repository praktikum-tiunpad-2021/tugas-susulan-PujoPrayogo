#include "problem_a.hpp"

using namespace strukdat::stack;

template <typename T>
int getMax(Stack<T> Top)
{
    if (isEmpty(Top))
    {
        return 0;
    }
    else
    {
        T max = peek(Top);
        pointer<T> delElement = nullptr;
        while (pop(Top, delElement))
        {
            if (peek(Top) > max)
            {
                max = peek(Top);
            }
        }
        return max;
    }
}

template <typename T>
int getEqualStack(Stack<T> Top1, Stack<T> Top2, Stack<T> Top3)
{
    int sum1 = 1, sum2 = 2, sum3 = 3;
    pointer<T> delElem, curr;
    while (sum1 != sum2 && sum2 != sum3)
    {
        sum1 = sum2 = sum3 = 0;
        for (curr = Top1; curr != nullptr; curr = curr->next)
        {
            sum1 += curr->data;
        }
        for (curr = Top2; curr != nullptr; curr = curr->next)
        {
            sum2 += curr->data;
        }
        for (curr = Top3; curr != nullptr; curr = curr->next)
        {
            sum3 += curr->data;
        }
        if (sum1 > sum2)
        {
            if (sum1 > sum3)
            {
                pop(Top1, delElem);
            }
            else
            {
                pop(Top3, delElem);
            }
        }
        else if (sum1 < sum2)
        {
            if (sum2 > sum3)
            {
                pop(Top2, delElem);
            }
            else
            {
                pop(Top3, delElem);
            }
        }
    }
    sum1 = 0;
    for (curr = Top1; curr != nullptr; curr = curr->next)
    {
        sum1 += curr->data;
    }
    return sum1;
}

bool isBracketBalanced(std::string expression)
{
    Stack<char> new_stack = createStack(new_stack);
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[')
        {
            Stack<char> new_node;
            createElement(new_node, expression[i]);
            new_stack = push(new_stack, new_node);
        }
        else
        {
            if (expression[i] == '}' && peek(new_stack) == '{')
            {
                Stack<char> nDelete;
                nDelete = pop(new_stack, nDelete);
            }
            else if (expression[i] == ']' && peek(new_stack) == '[')
            {
                Stack<char> nDelete;
                nDelete = pop(new_stack, nDelete);
            }
            else if (expression[i] == ')' && peek(new_stack) == '(')
            {
                Stack<char> nDelete;
                nDelete = pop(new_stack, nDelete);
            }
            else
            {
                return false;
            }
        }
    }
    if (isEmpty(new_stack))
    {
        return true;
    }
    else
    {
        return false;
    }
}

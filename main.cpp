
#include <iostream>
#include <string>

using std::string, std::cout, std::cin, std::stoi;

float calc()
{
    string expression = {};
    string c;
    string working_copy = {};
    cout << "This program will help you to solve arithmetic expressions which have following characters '+', '-', '*'"
            " and '/' \n";
    cout << "In order to avoid further problems, please use '.' for numbers with floating point \n";
    cout << "Enter your expression: \n";
    cin >> expression;
    cout<<"Your result: ";
    int i,j,k;
    float left_oper, right_oper, result;
    while ((expression.find('pi')!=string::npos)||(expression.find('e')!=string::npos))
    {
        if (expression.find('p')!=string::npos)
            expression.replace(expression.find('p'),2,"3.141592");
        if (expression.find('e')!=string::npos)
            expression.replace(expression.find('e'),1,"2.718281");
    }
    working_copy=expression;
    while ((working_copy.find('*')!=string::npos)||(working_copy.find('/')!=string::npos))
    {
        for (i = 0; i<working_copy.size();i++)
        {
            if ((working_copy[i] == '*') || (working_copy[i] == '/'))
            {
                for (j = i - 1; j > 0; j--)
                    if ((working_copy[j] == '+') || (working_copy[j] == '-') || (working_copy[j] == '*') || (working_copy[j] == '/'))
                    {
                        left_oper = stof(working_copy.substr(j + 1, i - j - 1));
                        break;
                    }
                if (j==0) {
                    left_oper = stof(working_copy.substr(0, i));
                    j --;
                }
                for (k = i + 1; k<working_copy.size(); k++)

                    if ((working_copy[k] == '+') || (working_copy[k] == '-') || (working_copy[k] == '*') || (working_copy[k] == '/'))
                    {
                        right_oper = stof(working_copy.substr(i + 1, k - i - 1));
                        break;
                    }
                if (k==working_copy.size())
                    right_oper = stof(working_copy.substr(i + 1, working_copy.size() - i - 1));

                if (working_copy[i] == '*')
                    result = left_oper * right_oper;
                else if (working_copy[i] == '/')
                    result = left_oper / right_oper;
                working_copy.replace(working_copy.find(working_copy.substr(j+1,k-j-1)),
                                     working_copy.substr(j+1,k-j-1).size(),std::to_string(result));
                break;
            }

        }
    }
    while ((working_copy.find('+')!=string::npos)||(working_copy.find('-')!=string::npos))
    {
        for (i = 0; i<working_copy.size();i++)
        {
            if ((working_copy[i] == '+') || (working_copy[i] == '-')) {
                if (i!=0)
                {
                    for (j = i - 1; j > 0; j--)
                        if ((working_copy[j] == '+') || (working_copy[j] == '-'))
                        {
                            left_oper = '-' + stof(working_copy.substr(j + 1, i - j - 1));
                            break;
                        }
                    if (j == 0)
                    {

                        if (working_copy[j] != '-')
                            left_oper = stof(working_copy.substr(0, i));
                        else left_oper = stof(working_copy.substr(0, i));
                        j--;
                    }
                }
                else
                {
                    //
                    if ((working_copy.substr(1,working_copy.size()-1).find('+')==string::npos) && (working_copy.substr(1,working_copy.size()-1).find('-')==string::npos))
                        return (stof(working_copy));
                    else
                    {
                        continue;
                    }
                }
                for (k = i + 1; k<working_copy.size(); k++)

                    if ((working_copy[k] == '+') || (working_copy[k] == '-'))
                    {
                        right_oper = stof(working_copy.substr(i + 1, k - i - 1));
                        break;
                    }
                if (k==working_copy.size())
                    right_oper = stof(working_copy.substr(i + 1, working_copy.size() - i - 1));

                if (working_copy[i] == '+')
                    result = left_oper + right_oper;
                else if (working_copy[i] == '-')
                    result = left_oper - right_oper;
                working_copy.replace(working_copy.find(working_copy.substr(j+1,k-j-1)),
                                     working_copy.substr(j+1,k-j-1).size(),std::to_string(result));
                break;
            }

        }

    }
    return (stof(working_copy));
}
int main()

{
    cout<<calc();
}
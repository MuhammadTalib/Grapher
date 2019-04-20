#pragma once

#include<stdlib.h>
#include<conio.h>
#include"Stack.h"
#include"Stack.cpp"
#include"LinkedList.h"
#include"LinkedList.cpp"
#include<math.h>

class ExpressionTree
{
public:
	ExpressionTree(LinkedList<char> *infixx)
	{
		this->infix = infixx;
	}
	LinkedList<char>* Infix_ToPostfixConversion()
	{
		Stack<char> *top = new Stack<char>;
		LinkedList<char> *CURR = this->infix;
		if (CURR->value == this->infix->value)
		{
			this->postfix->AddNode(CURR->value);
			CURR = CURR->Next;
		}
		while (CURR != NULL && CURR->value != NULL)
		{
			if ((*(CURR->value) >= 'a' && *(CURR->value) <= 'z') || (*(CURR->value) >= 'A' && *(CURR->value) <= 'Z') || (*(CURR->value) >= '0' && *(CURR->value) <= '9'))
			{
				this->postfix->AddNode(CURR->value);
			}
			else if (*(CURR->value) == '*' || *(CURR->value) == '+' || *(CURR->value) == '-' || *(CURR->value) == '/' || *(CURR->value) == '=' || *(CURR->value) == '>' || *(CURR->value) == '<' || *(CURR->value) == '~' || *(CURR->value) == '&' || *(CURR->value) == '|' || *(CURR->value) == '(' || *(CURR->value) == ')'|| *(CURR->value) == '^')
			{
				while (1)
				{
					if (top->value == NULL || CheckPrecedence(*(top->value)) < CheckPrecedence(*(CURR->value)) || *(CURR->value) == '(' || *(top->value) == '(')
					{

						top->push(CURR->value);
						break;
					}
					else if ((CheckPrecedence(*(top->value)) >= CheckPrecedence(*(CURR->value))) && *(CURR->value) != ')')
					{
						this->postfix->AddNode(top->value);
						top->pop();
					}
					else if (*(CURR->value) == ')')
					{

						while (*(top->value) != '(')
						{
							this->postfix->AddNode(top->value);
							top->pop();
						}
						top->pop();
						break;
					}

				}
			}
			CURR = CURR->Next;

		}
		while (top->value != NULL)
		{
			this->postfix->AddNode(top->value);
			top->pop();
		}
		return this->postfix;

	}
	float Evaluate(float *x)
	{
		LinkedList<char> *CURR = this->postfix;
		Stack<float> *top = new Stack<float>;

		while (CURR != NULL && CURR->value != NULL)
		{
			if ((*(CURR->value) == 'X' || *(CURR->value) == 'x'))
			{
				top->push(x);
			}
			else if (*(CURR->value) >= '0' && *(CURR->value) <= '9')
			{
				float *valueint = new float;
				*valueint = *(CURR->value) - 48;
				top->push(valueint);
			}
			else if (*(CURR->value) == '*' || *(CURR->value) == '+' || *(CURR->value) == '-' || *(CURR->value) == '/' || *(CURR->value) == '=' || *(CURR->value) == '>' || *(CURR->value) == '<' || *(CURR->value) == '~' || *(CURR->value) == '&' || *(CURR->value) == '|'|| *(CURR->value) == '^')
			{
				float *temp = new float;
				*temp = 0.0;
				float tempo = 0.0;
				switch (*(CURR->value))
				{
				case('+'):
				{
					*temp = *(top->pop()) + *(top->pop());
					break;
				}
				case('*'):
				{
					*temp = *(top->pop()) * *(top->pop());
					break;
				}
				case('-'):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) - tempo;
					break;
				}
				case('/'):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) / tempo;
					break;
				}
				case('<'):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) < tempo;
					break;
				}
				case('>'):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) > tempo;
					break;
				}
				case('|'):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) || tempo;
					break;
				}
				case('&'):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) && tempo;
					break;
				}
				case('~'):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) != tempo;
					break;
				}
				case('='):
				{
					tempo = *(top->pop());
					*temp = *(top->pop()) == tempo;
					break;
				}
				case('^'):
				{
					tempo = *(top->pop());
					*temp = pow(*(top->pop()) , tempo);
					break;
				}

				}
				top->push(temp);

			}
			CURR = CURR->Next;
		}
		return *(top->pop());
	}



	LinkedList<char> *infix;
	LinkedList<char> *postfix = new LinkedList<char>;
	int value;
	int CheckPrecedence(char value)
	{
		{
			if (value == '|')
				return 1;
			else if (value == '&')
				return 2;
			else if (value == '<' || value == '>' || value == '=' || value == '~')
				return 3;
			else if (value == '-' || value == '+')
				return 4;
			else if (value == '/' || value == '*')
				return 5;
			else if (value == '^')
				return 6;
			else
				return NULL;
		}
	}
private:
};


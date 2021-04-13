// Thayna Gomes da Silva TIA:32092229
#include "Stack.h"
#include <string.h>
#include <iostream>
using namespace std;


namespace MyDataStructures
{
	namespace Stack {
		StaticStack Create()
		{
			//struct StaticStack
			//{
			//	int current; // Topo da pilha.
			//	char values[STATIC_STACK_CAPACITY]; // Dados da pilha.
			//};

			StaticStack stack = { 0, { 0 } };
			return stack;
		}


		bool Push(StaticStack& stack, int elem)
		{
			if (stack.count == STATIC_STACK_CAPACITY)
			{
				return false;
			}

			stack.values[stack.count] = elem;
			++stack.count;

			return true;
		}


		int Pop(StaticStack& stack)
		{
			if (IsEmpty(stack))
			{
				return 0;
			}

			char temp = stack.values[stack.count - 1];
			stack.values[stack.count - 1] = 0;
			--stack.count;

			return temp;
		}


		int Top(const StaticStack& stack)
		{
			if (IsEmpty(stack))
			{
				return 0;
			}

			return stack.values[stack.count - 1];
		}


		int Size(const StaticStack& stack)
		{
			return sizeof(stack.values) / sizeof(stack.values[0]);
		}


		int Count(const StaticStack& stack)
		{
			return stack.count;
		}


		bool IsEmpty(const StaticStack& stack)
		{
			return stack.count == 0;
		}


		bool Clear(StaticStack& stack)
		{

			while (!IsEmpty(stack))
			{
				Pop(stack);
			}

			return IsEmpty(stack);
		}


		char Items(StaticStack& stack) {

			// print stack 

			cout << " Fila: " << endl;

			for (int i = 0; i < Count(stack); i++) {
				cout << stack.values[i] << " ";
			}
			return 0;
		}
	}
}
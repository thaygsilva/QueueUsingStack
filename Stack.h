// Thayna Gomes da Silva TIA:32092229
#ifndef __STATIC_STACK_H__
#define __STATIC_STACK_H__

namespace MyDataStructures
{

	namespace Stack
	{
		const int STATIC_STACK_CAPACITY = 5;

		struct StaticStack
		{
			int count; // Quantidade de elementos empilhados (índice do elemento no topo da pilha = count - 1).
			int values[STATIC_STACK_CAPACITY]; // Dados da pilha.
		};


		StaticStack Create();

		bool Push(StaticStack& stack, int elem);


		int Pop(StaticStack& stack);


		int Top(const StaticStack& stack);


		int Size(const StaticStack& stack);


		int Count(const StaticStack& stack);


		bool IsEmpty(const StaticStack& stack);


		bool Clear(StaticStack& stack);


		char Items(StaticStack& stack);

	}
}



#endif // __STATIC_STACK_QUEUE_H__

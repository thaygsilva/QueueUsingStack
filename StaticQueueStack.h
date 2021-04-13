// Thayna Gomes da Silva TIA:32092229
#ifndef __STATIC_STACK_QUEUE_H__
#define __STATIC_STACK_QUEUE_H__
#include "Stack.h"

namespace MyDataStructures
{
	//para o exemplo de Queue
	namespace Queue
	{

		const int STATIC_QUEUE_CAPACITY = 5;

		struct StaticQueue
		{
			int front;
			int rear;
			int count;

			int values[STATIC_QUEUE_CAPACITY];
			Stack::StaticStack normalStack;
			Stack::StaticStack inverseStack;
		};

		StaticQueue Create();

		bool Enqueue(StaticQueue& queue, int elem);

		char Dequeue(StaticQueue& queue);

		int Front(StaticQueue& queue);

		int Size(const StaticQueue& queue);

		int Count(const StaticQueue& queue);

		bool IsEmpty(const StaticQueue& queue);

		bool Clear(StaticQueue& queue);

		void PrintQueue(const StaticQueue& queue);

		void insertInverse(StaticQueue& queue);

		void insertNormal(StaticQueue& queue);

	}

}
#endif // __STATIC_STACK_QUEUE_H__

// Thayna Gomes da Silva TIA:32092229
#include "StaticQueueStack.h"
#include "Stack.h"
#include <string.h>
#include <iostream>
using namespace std;


namespace MyDataStructures
{
	
	namespace Queue
	{
		StaticQueue Create()
		{
			StaticQueue queue =
			{
				0, // int front;
				0, // int rear;
				0, // int count;
				{0}, // int values[STATIC_QUEUE_CAPACITY];
				Stack::Create(),
				Stack::Create()

			};
			return queue;
		}
		

		bool Enqueue(StaticQueue& queue, int elem)
		{
			int i = 0;

			if (i < Stack::STATIC_STACK_CAPACITY) {
				cout << "Insira um elemento na fila para enche-la: " << endl;
				cin >> elem;
				Stack::Push(queue.normalStack, elem);
				cout << Stack::Items(queue.normalStack) << endl;
				i++;
			}
			if (Stack::Count(queue.normalStack) == Stack::STATIC_STACK_CAPACITY) cout << "Fila cheia" << endl;

			return true;
		}

		char Dequeue(StaticQueue& queue)
		{
			// remove o último item da pilha inversa, pois corresponde ao primeiro item da pilha normal, tendo assim, uma fila.
			cout << endl << "Elemento removido: " << Stack::Top(queue.inverseStack) << endl;
			Stack::Pop(queue.inverseStack);

			Queue::insertNormal(queue);
			//cout << Stack::Items(queue.normalStack) << endl;
			int value = queue.normalStack.values[queue.front];

			/*if (IsEmpty(queue))
			{
				return '\0';
			}

			queue.values[queue.front] = '\0';

			queue.front = (queue.front + 1) % Size(queue); 

			--queue.count;*/

			return value;
		}

		int Front(const StaticQueue& queue)
		{
			return IsEmpty(queue.normalStack) ? '\0' : queue.normalStack.values[queue.front];
		}

		int Size(const StaticQueue& queue)
		{
			return sizeof(queue.values) / sizeof(queue.values[0]); // return STATIC_QUEUE_CAPACITY;
		}

		int Count(const StaticQueue& queue)
		{
			return queue.normalStack.count;
		}

		bool IsEmpty(const StaticQueue& queue)
		{
			return queue.count == 0;
		}

		bool Clear(StaticQueue& queue)
		{
			Stack::Clear(queue.normalStack);
			Stack::Clear(queue.inverseStack);
			return IsEmpty(queue.normalStack);
		}


		void insertInverse(StaticQueue& queue) {
			//passar os itens da normalStack pra inverseStack
			while (!Stack::IsEmpty(queue.normalStack)) {
				int top = Stack::Top(queue.normalStack);
				Stack::Push(queue.inverseStack, top);
				Stack::Pop(queue.normalStack);
			}
		}
		void insertNormal(StaticQueue& queue) {
			// passar todos os items da pilha inversa para a pilha normal que está vazia
			while (!IsEmpty(queue.inverseStack)) {
				int top = Stack::Top(queue.inverseStack);
				Stack::Push(queue.normalStack, top);
				Stack::Pop(queue.inverseStack);
			}
		}

		void PrintQueue(const StaticQueue& queue) {
				cout << "Front: " << Front(queue) << " (" << Count(queue) << "/" << Size(queue) << ")\n";
				cout << "Capacidade da fila: " << Stack::Size(queue.inverseStack) << '\n';
				cout << "Quantidade de elementos preenchidos: " << Stack::Count(queue.normalStack) << '\n';
				//cout << "Topo da fila: " << queue.normalStack.values[0] << " (" << Stack::Count(queue.normalStack) << "/" << Stack::Size(queue.normalStack) << ")\n";
				cout << "A fila está vazia? " << Stack::IsEmpty(queue.normalStack) << endl;

		}
	}
}
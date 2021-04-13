// Thayna Gomes da Silva TIA:32092229
#include <iostream>
#include <string.h>
#include "StaticQueueStack.h"
#include "Stack.h"
#include <locale.h>

using namespace MyDataStructures;
using namespace std;

int main()
{
	setlocale(LC_ALL, "portuguese");
	
	Queue::StaticQueue Queue = Queue::Create();
	int option = -1;
	int elem = 0;

	
	while (option != 4) {
		// menu principal
		cout << "/////////////////// MENU PRINCIPAL  ///////////////////" << endl;
		cout << endl << "0 - Exemplo de Queue " << endl << "1 - Inserir elemento " << endl <<
			"2 - Remover elemento" << endl << "3 - Limpar fila" << endl << "4 - Sair/informações" << endl;
		cin >> option;
		//exemplo usando uma fila 
		if (option == 0) {
			Queue::StaticQueue exampleQueue = Queue::Create();
			int op = -1;
			while (op != 0) {
				// menu fila usando queue
				cout << endl << "MENU EXEMPLO - Como uma fila funciona? Você pode: " << endl;
				cout << endl << "0 - Sair/informações" << endl << "1 - Inserir elemento"
					<< endl << "2 - Remover elemento" << endl << "3 - Limpar fila" << endl;
				cin >> op;

				if (op == 1) {
					cout << endl << "Na fila só é possível inserir no final" << endl;
					Queue::Enqueue(exampleQueue, elem);
					cout << endl << "O item foi inserido no final da fila!" << endl;
					Queue::PrintQueue(exampleQueue);
				}
				else {
					Queue::insertInverse(exampleQueue);
				}
				if (op == 2) {
					cout << endl << "Você acabou de remover um item no inicio da fila!" << endl;
					cout << "Em uma fila, só é possível remover o seu primeiro item" << endl;
					Queue::Dequeue(exampleQueue);
				}
				if (op == 3) {
					cout << endl << "Você limpou todos os itens da fila!" << endl;
					Queue::Clear(exampleQueue);
				}
				
				else if (op == 0) {
					cout << endl << "O que podemos obter: " << endl;
					Queue::insertNormal(exampleQueue);
					Queue::PrintQueue(exampleQueue);
					return 0;
				}

			}
		}

		if (option == 1) {
			Queue::Enqueue(Queue, elem);
			Queue::PrintQueue(Queue);
		}
		else {
			Queue::insertInverse(Queue);
		}
		if (option == 2) {
			Queue::Dequeue(Queue);
		}

		else if (option == 3) {
			Queue::Clear(Queue);
		}
		else if (option == 4) {
			Queue::insertNormal(Queue);
			Queue::PrintQueue(Queue);
			return 0;
		}
	}
}


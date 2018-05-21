#include "Stack.h"
#include <iostream>
Stack::Stack() : First(0), Last(0)
{}
bool Stack::isEmpty() {
	if (First == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

int Stack::Push(int num) {
	if (isEmpty()) {
		Node *nw = new Node;
		nw->numero = num;
		First = Last = nw;
		return 0;
	}
	/*else if (Lenght()==1) {
		Node *nw = new Node;
		nw->numero = num;
		Last->sig = nw;
		First->ant = nw;
		First = nw;
	}*/
	else {
		Node *nw = new Node;
		
		nw->numero = num;
		nw->ant = First;
		First->sig = nw;
		First = nw;
		return 0;
	}
}

int Stack::Pop() {
	if (!isEmpty()) {
		Node *tmp = First->ant;
		delete First;
		First = tmp;
		return 0;
	}
	else {
		return 1;
	}
}

void Stack::Print() {
	Node *tmp = Last;

	while (tmp!=0)
	{
		std::cout << tmp->numero << "\t";
		tmp = tmp->sig;
	}
	std::cout << std::endl;
}

Stack& operator++(Stack&st) {
	if (st.Lenght() >= 2){
	Node *tmp1 = st.First->ant;
	Node *tmp2 = tmp1->ant;
	
	int result = tmp1->numero + tmp2->numero;
	st.Pop();
	st.Pop();

	st.Push(result);
	}

	return st;
}

Stack& operator--(Stack&st) {
	if (st.Lenght()>=2) {
		Node *tmp1 = st.First->ant;
		Node *tmp2 = tmp1->ant;
		
		int result = tmp1->numero + tmp2->numero;
		st.Pop();
		st.Pop();

		st.Push(result);
	}

	return st;
}

int Stack::Lenght() {
	Node *tmp = First;
	int i = 0;
	while (tmp!=0)
	{
		i++;
		tmp = tmp->ant;
	}
	return i;
}
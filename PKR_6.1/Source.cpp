#include <iostream>

using namespace std;

struct Elem
{
	Elem* next;
	Elem* previos;
	int info;
};

void del(Elem*& p);

int main() {

	Elem* p = new Elem;
	p->info = 1;
	
	p->next = new Elem;
	p->next->info = 2;

	p->next->next = new Elem;
	p->next->next->info = 3;

	p->next->next->previos = new Elem;
	p->next->next->previos->info = 4;
	p->next->next->previos->previos = NULL;
	//1
	p->previos = p->next->next->previos->previos;
	//2
	p->next->previos = p->previos;
	//3
	p->next->next->next = p;
	//4
	p->next->next->previos->next = p->next->next->next;

	cout << p->info << endl;			//1
	cout << p->next->info << endl;		//2
	cout << p->next->next->info << endl;//3
	cout << p->next->next->previos->info << endl;	//4

	del(p);

	return 0;
}

void del(Elem*& p) {
	delete p->next->next->previos;
	delete p->next->next;
	delete p->next;
	delete p;
}
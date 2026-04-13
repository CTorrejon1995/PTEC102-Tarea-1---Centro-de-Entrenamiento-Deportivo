#include <iostream>
#include "metodos.cpp"

int main() {
	
	Orquestador* programa = new Orquestador();
	programa->coordinador();
	delete programa;
	
	return 0;
}

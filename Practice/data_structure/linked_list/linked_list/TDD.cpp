#include <iostream>
#include "linked_list.h"

int main(void) {
	List<int> a;
	
	a.Add(5);
	std::cout << a.GetData() << "\n";
	std::cout << a.GetSize() << "\n\n";
	
	a.Add(1);
	std::cout << a.GetData() << "\n";
	std::cout << a.GetSize() << "\n\n";

	if (!(a.IsEmpty())) {
		a.Remove();
		std::cout << a.GetData() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

	if (!(a.IsEmpty())) {
		a.Remove();
		std::cout << a.GetData() << "\n";
		std::cout << a.GetSize() << "\n\n";
	}

	
}
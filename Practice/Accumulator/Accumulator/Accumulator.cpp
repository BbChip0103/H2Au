#include <iostream>
#include <string>

class Accumulator
{
public:
	Accumulator();
	Accumulator(char *Expression);

	double Add(double _value1, double _value2);
	double Subtrack(double _value1, double _value2);
	double Multiply(double _value1, double _value2);
	double Divide(double _value1, double _value2);

private:

};

Accumulator::Accumulator(){
}

Accumulator::Accumulator(char *Expression){
	std::cout << "������ �����ε�.\n";
}

double Accumulator::Add(double _value1, double _value2) {
	double result = _value1 + _value2;
	return result;
}

double Accumulator::Subtrack(double _value1, double _value2) {
	double result = _value1 - _value2;
	return result;
}

double Accumulator::Multiply(double _value1, double _value2) {
	double result = _value1 * _value2;
	return result;
}

double Accumulator::Divide(double _value1, double _value2) {
	double result = _value1 / _value2;
	return result;
}

void FlushBuffer();

int main(void) {
	Accumulator accu("asd");
	double value1, value2;

	std::cout << "ù��° ���� : ";
	std::cin >> value1;

	while (std::cin.fail()) {
		FlushBuffer();
		std::cout << "���ڸ� �Է����ּ���.\n\n";
		std::cout << "ù��° ���� : ";
		std::cin >> value1;
	}
	FlushBuffer();

	std::cout << "�ι�° ���� : ";
	std::cin >> value2;

	while (std::cin.fail()) {
		FlushBuffer();
		std::cout << "���ڸ� �Է����ּ���.\n\n";
		std::cout << "�ι�° ���� : ";
		std::cin >> value2;
	}
	FlushBuffer();

	std::cout << "�� : " << accu.Add(value1, value2) << "\n";
	std::cout << "�� : " << accu.Subtrack(value1, value2) << "\n";
	std::cout << "�� : " << accu.Multiply(value1, value2) << "\n";
	std::cout << "���� : " << accu.Divide(value1, value2) << "\n";	// �̰Ŵ� �ѱ��ڷ� ����� ����;;

	return 0;
}

void FlushBuffer() {
	char ch = NULL;

	while (ch != '\n') { 
		ch = std::cin.get();
		std::cin.clear();
	}
}

#include <iostream>
#include <string>

//��� ����ؼ� Ŭ���� ����(�̷����� �ڵ�)
class Accumulator
{
private:
	int num;
public:
	Accumulator();
	Accumulator(char *Expression);

	//���ø� �����ؾߴ�
	double Add(double _value1, double _value2) {
		double result = _value1 + _value2;
		return result;
	}
	double Subtrack(double _value1, double _value2) {
		double result = _value1 - _value2;
		return result;
	}
	double Multiply(double _value1, double _value2) {
		double result = _value1 * _value2;
		return result;
	}
	double Divide(double _value1, double _value2) {
		double result = _value1 / _value2;
		return result;
	}

private:

};

Accumulator::Accumulator():num(0)
{
};

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
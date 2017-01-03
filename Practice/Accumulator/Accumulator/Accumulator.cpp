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
	std::cout << "생성자 오버로딩.\n";
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

	std::cout << "첫번째 숫자 : ";
	std::cin >> value1;

	while (std::cin.fail()) {
		FlushBuffer();
		std::cout << "숫자만 입력해주세요.\n\n";
		std::cout << "첫번째 숫자 : ";
		std::cin >> value1;
	}
	FlushBuffer();

	std::cout << "두번째 숫자 : ";
	std::cin >> value2;

	while (std::cin.fail()) {
		FlushBuffer();
		std::cout << "숫자만 입력해주세요.\n\n";
		std::cout << "두번째 숫자 : ";
		std::cin >> value2;
	}
	FlushBuffer();

	std::cout << "합 : " << accu.Add(value1, value2) << "\n";
	std::cout << "차 : " << accu.Subtrack(value1, value2) << "\n";
	std::cout << "곱 : " << accu.Multiply(value1, value2) << "\n";
	std::cout << "나눔 : " << accu.Divide(value1, value2) << "\n";	// 이거는 한글자로 뭐라고 하지;;

	return 0;
}

void FlushBuffer() {
	char ch = NULL;

	while (ch != '\n') { 
		ch = std::cin.get();
		std::cin.clear();
	}
}

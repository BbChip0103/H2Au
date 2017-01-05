#include <iostream>
#include <string>

//상속 고려해서 클래스 설계(미래지향 코딩)
class Accumulator
{
private:
	int num;
public:
	Accumulator();
	Accumulator(char *Expression);

	//템플릿 수정해야대
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
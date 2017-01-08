#include <iostream>
#include <string>

//��� ����ؼ� Ŭ���� ����(�̷����� �ڵ�)

//template <typename type>
class Calculator
{
public:
	//Calculator() {};

	template <typename type>
	type Add(type _value1, type _value2) {
		double result = _value1 + _value2;
		return result;
	}
	template <typename type>
	type Subtrack(type _value1, type _value2) {
		double result = _value1 - _value2;
		return result;
	}
	template <typename type>
	type Multiply(type _value1, type _value2) {
		double result = _value1 * _value2;
		return result;
	}
	template <typename type>
	type Divide(type _value1, type _value2) {
		double result = _value1 / _value2;
		return result;
	}
};

class StringCalculator : public Calculator
{
	//type value1, value2, result;

public:
	StringCalculator() {};
	StringCalculator(char *expression);
	~StringCalculator() {};

	template <typename type>
	type Calculate(type _value1, type _value2, char _operator) {
		type result;

		if (_operator == '+') result = Add(_value1, _value2);
		else if (_operator == '-') result = Subtrack(_value1, _value2);
		else if (_operator == '*') result = Multiply(_value1, _value2);
		else if (_operator == '/') result = Divide(_value1, _value2);
		else result = 0;

		PrintResult(result);
		return result;
	}

private:
	template <typename type>
	void PrintResult(type result) {
		std::cout << "��� �� : " << result << "\n";
	}
};

void FlushBuffer();

int main(void) {
	Calculator accu;
	StringCalculator accu_string;
	//double value1, value2;

	accu_string.Calculate(3.5, 1.2, '+');
	accu_string.Calculate(3.5, 1.2, '-');
	accu_string.Calculate(3.5, 1.2, '?');



	/*

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

	*/

	return 0;
}

void FlushBuffer() {
	char ch = NULL;

	while (ch != '\n') {
		ch = std::cin.get();
		std::cin.clear();
	}
}
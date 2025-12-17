#include "Rpn.hpp"

Rpn::Rpn(): _argv("") {}
Rpn::Rpn(std::string const& argv) :_argv(argv) {}
Rpn::Rpn(Rpn const& other) :_argv(other._argv), _stk(other._stk) {}
Rpn& Rpn::operator=(Rpn const& other) {
	if(this != &other) {
		this->_argv = other._argv;
		this->_stk = other._stk;
	}
	return *this;
}

void Rpn::opAdd() {
	if (_stk.size() < 2)
		throw std::runtime_error("Error");
	int b = _stk.top();
	_stk.pop();
	int a = _stk.top();
	_stk.pop();
	_stk.push(a + b);
}
void Rpn::opSub() {
	if (_stk.size() < 2)
		throw std::runtime_error("Error");
	int b = _stk.top();
	_stk.pop();
	int a = _stk.top();
	_stk.pop();
	_stk.push(a - b);
}
void Rpn::opMul() {
	if (_stk.size() < 2)
		throw std::runtime_error("Error");
	int b = _stk.top();
	_stk.pop();
	int a = _stk.top();
	_stk.pop();
	_stk.push(a * b);
}
void Rpn::opDiv() {
	if (_stk.size() < 2)
		throw std::runtime_error("Error");
	int b = _stk.top();
	_stk.pop();
	int a = _stk.top();
	_stk.pop();
	if (b == 0)
		throw std::runtime_error("Error");
	_stk.push(a / b);
}

const char Rpn::operation[4] = {
	'+','-','*','/'
};

const Rpn::funct Rpn::action[4] = {
	&Rpn::opAdd,
	&Rpn::opSub,
	&Rpn::opMul,
	&Rpn::opDiv
	
};



void Rpn::processRpn() {
	try {
		for(size_t i = 0; i < _argv.size(); i++) {
			if(std::isspace(static_cast<unsigned char>(_argv[i]))) continue;
			if(std::isdigit(static_cast<unsigned char>(_argv[i]))) {
				int n = _argv[i] - '0';
				_stk.push(n);
				continue;
			}
			int j = 0;
			for(; j < 4; j++) {
				if(_argv[i] == operation[j]) break;}
			switch (j)
			{
				case ADD:
					(this->*action[ADD])();
					break;
				case SUB:
					(this->*action[SUB])();
					break;
				case MUL:
					(this->*action[MUL])();
					break;
				case DIV:
					(this->*action[DIV])();
					break;
				
				default:
					throw std::runtime_error("Error");
			}
			
		}
		if (_stk.size() != 1)
			throw std::runtime_error("Error");
		std::cout << _stk.top() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error" << std::endl;
	}
}


Rpn::~Rpn() {}
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <stdexcept>

enum lev {
	ADD,
	SUB,
	MUL,
	DIV,
};

class Rpn {
	public:
		Rpn();
		Rpn(std::string const& argv);
		Rpn(Rpn const& other);
		Rpn& operator=(Rpn const& other);
		void processRpn();
		void opAdd();
		void opSub();
		void opMul();
		void opDiv();
		typedef void (Rpn::*funct)();
		static const char operation[4];
		static const funct action[4];
		~Rpn();

	private:
		std::string _argv;
		std::stack<int> _stk;
};

#endif
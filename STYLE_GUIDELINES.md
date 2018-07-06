# MathX Style Guidelines

## 1. Classes 

	class X {
	public:
		// Variable description of a
		int a;
		// Variable description of b
		int b;
		// Decription of func(x)
		void func(int x);
	};
	void X::func (int x) {
		// Do something
	}

## 2. Functions: 

	int func_that_returns_product (int x, int y);	// Declaration
	int func_that_returns_product (int x, int y) {
		return x*y;
	}	// Definition
	int c = func_that_returns_product(4, 5);	// Call (Notice no space between name and '(')

## 3. Variables: 

	int complete_description_of_variable;
	int *pointer;
	int initialised_var = 54;

## 4. If-else, for, switch-case: 

	if (x > 4) {
		// Do something
	}
	for (int i = 0; i < 4; ++i) {
		// Loop
	}
	switch (number) {
		case 1 :
		case 2 : y = 2;
				a = 5;
				break;
		default : y = 6;
				a = 5;
	}

## 5. Operators: 

Maintain spaces between operators except for `->`, `++`, `--` 

	c = a + b;
	n = (a + b) * (c + d);
	x = ptr->num;
	x++;

## 6. Other General Guidelines: 

1. Keep similar code blocks close. Seperate un-related blocks with an empty line
2. End a file with endline
3. Document all functions and classes.
4. Use `.editorconfig` package for your text-editor to take care of spaces and tab related conflicts.

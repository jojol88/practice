#include <iostream>

template <class Type>
class SmartPointer
{
public:
	SmartPointer(Type* p) : pointer(p)
	{
	}
	operator Type*()
	{
		return pointer;
	}
	Type *operator->()
	{
		if (!pointer)
		{
			pointer = new Type();
			std::cerr << "Bad pointer!"
		}
		return pointer;
	}
	std::ptrdiff_t operator-(SmartPointer<Type> p)
	{
		return (pointer - p)
	}
	std::ptrdiff_t operator-(void *p)
	{
		return (pointer - p)
	}

private:
	Type* pointer;
	
};

class Foo
{
public:
	Foo() : a(0), b(0)
	{
	}
	Foo(int a, int b) : a(a), b(b)
	{
	}
	int Sum()
	{
		return (a + b);
	}

private:
	int a, b;
};

int main(int argc, char **argv)
{
	//SmartPointer<Foo> sp(new Foo(2, 2));
	SmartPointer<Foo> sp(NULL);
	std::cout << sp->Sum() << std::endl;

	system("pause");
	return 0;
}
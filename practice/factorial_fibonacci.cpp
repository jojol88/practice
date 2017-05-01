int factorial(const int digit)
{
	if(0 > digit)
		return 0;

	if(0 == digit)
		return 1;
	
    else
    	return digit * factorial(digit - 1);
}

int fibonacci(const int digit)
{
	if(0 == digit)
		return 0;

	if(1 == digit)
		return 1;
	
    else
    	return digit + fibonacci(digit - 1);
}
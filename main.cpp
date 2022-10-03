#include"stdio.h"

//’À‹à‚ÌŒvZ
int Recursive(int n)
{
	if (n <= 1)
	{
		return(1);
	}

	return (n * Recursive(n - 1));
}

//”äŠr
int Compare(int a,int b)
{
	if (a >= b)
	{
		return printf("%d‚Ì•û‚ª–×‚©‚Á‚Ä‚¢‚é\n",a);
	}
	return printf("%d‚Ì•û‚ª–×‚©‚Á‚Ä‚¢‚é\n", b);
}

int main()
{
	int n = 10;	//ŠKæ‚·‚é’l
	int result; //ŒvZŒ‹‰Ê
	//ˆê”Ê“I‚È’À‹à
	const int generalWage = 1072;

	result = Recursive(n);
	printf("%d‚ÌŠKæ = %d\n", n, result);
	Compare(generalWage, result);

}
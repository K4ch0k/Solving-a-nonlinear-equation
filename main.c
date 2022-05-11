#include <stdio.h>
#include <windows.h>
#include <math.h>

double f(double x)
{
	return log(x + 5) + x*x - 20;	//	Нелинейное уравнение
}

int main() 
{
	system("title Lab2.2 #24");
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	
	double a, b, x, diff;	//	Основные переменные
	double eps;		//	Точность вычислений
	int i;			//	Счетчик шагов вычисления
	
	eps = 0.00001;	// Можно изменять
	a = 3.2;		// Можно изменять
	b = 5;			// Можно изменять
	printf("\n\tx = [%.4f, %.4f]\n\n", a, b);
	
	i = 1;
	diff = b-a;
	a = f(a);
	
	printf("%3d\\\tx \t= %f\n\tF(x) \t= %f\n\t|b-a| \t= %f\n\n", i, b, a, fabs(diff));
	
	while(fabs(diff) > eps)
	{
		i++;
		x = f(b);
		diff = diff/(a-x)*x;
		a = x;
		b = b + diff;
		printf("%3d\\\tx \t= %.10f\n\tF(x) \t= %.10f\n\t|b-a| \t= %.10f\n\n", i, b, a, fabs(diff));
	}
	
	printf("\tX = %f\n\n", b);
	system("pause");
	return 0;
}
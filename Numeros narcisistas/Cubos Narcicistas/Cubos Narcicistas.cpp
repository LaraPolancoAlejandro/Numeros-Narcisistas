/*Este programa tiene la finalidad de encontrar los numeros narcistas entre el 100 y el 999 mejor conocidos como "cubos narcicistas"
Creado por Alejandro Lara ID:1106231
*/

#include<conio.h>
#include<iostream>
#include<math.h>
#include <cstdlib>

using namespace std;
int main()
{
	int num = 1, Num1, Num2, i = 0,numero; //variables utilizadas 
		
	int menu1= 0;
	string menu2;

	
	//Menu para para activar lso rangos de numero

	cout << " Quieres seleccionar un rango de numeros? [Y/N]: ";
	cin >> menu2;

	if (menu2 == "y" || menu2 == "Y")
	{
		menu1 = 1;
	}
	if (menu2 == "N" || menu2 == "n")
	{
		menu1 = 0;
	}
	switch (menu1)  //Switch para el menú que actualmente esta desactivado y por defecto es 0
	{
	case 1: //Asignar rango de numeros
			cout << " Ingresa el primer numero de tu rango" << endl;
			cin >> Num1;
			cout << " Ingresa el segundo numero de tu rango" << endl;
			cin >> Num2;
			break;
	default: //numeros por defecto usados por el menú
		Num1 = 100; 
		Num2=999;
		break;
	}
	system("cls"); //Console clear

	cout << " Del numero " << Num1 << " hasta el numero " << Num2 << " los siguientes numeros son narcisistas" << endl << endl;

	if (Num2 > Num1) //Utilizado cuando el segundo numero es mayor que el primero 
	{
		i = Num2 + 1 - Num1;

		numero = Num1-1;
		num = Num1;
	}
	else // cuando el primer numero es mas grande que el segundo para que el codigo no de fallo
	{
		i = Num1 + 1 - Num2;

		numero = Num2-1;
		num = Num2;
	}
	for (num; num <= i+numero; num++) // bucle para iterar desde un numero "x" hasta otro numero "y"
	{
		int numx, numy, digitos = 1, sum1 = 1, resto, suma = 0; //variables declaradas dentro para reiniciarlas cada vez que se ejecute el bucle.

		numx = num;
		numy = num;

		while (numx >= 10) //para saber cuantos digitos tiene la cifra un numero "numx"
		{
			numx = numx / 10;
			digitos++;
		}


		while (numy > 0) // Al dividr un numero entre 10 y quedarnos con el resto ese resto siempre va a ser el ultimo digito
		{
			resto = numy % 10;
			sum1 = 1;
			for (int i = 1; i <= digitos; i++)
			{
				sum1 = sum1 * resto; //ejecuta la potencia al numero segun la cantidad de digitos
			}

			suma = suma + sum1;
			numy = numy / 10; //indica cuantas veces se va a ejecutar el while
		}

		if (num == suma) {
			cout << " el numero " <<num<< " es narcisista" << endl; //imprime el numero narcicista.
		}

		
	}
	_getch();
}
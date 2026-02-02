// pruebaOMP.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include <omp.h>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(int* d);

int main()
{
    std::cout << "Hello World!\n";

	std::cout << "Verificando la ejecucion de las directivas OMP!\n";

	# ifdef _OPENMP
		std::cout << "OMP disponible y funcionando" << std::endl;
	# endif

	std::cout << "Sumando arreglos en paralelo!\n";
	int a[N], b[N], c[N];

	int i;

	for (i = 0; i < N; i++)
	{
		a[i] = i;
		b[i] = i * 10;
	}

	int pedazos = chunk;

	#pragma omp parallel for \
	shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo a " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo b " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros" << mostrar << " valores del arreglo c " << std::endl;
	imprimeArreglo(c);
}

void imprimeArreglo(int* d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

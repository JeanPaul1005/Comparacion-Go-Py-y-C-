#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime> 

using namespace std;

//funcion para imprimir el array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

//algoritmo Insertion Sort
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
//-------------------------------------------------------

int main() {
  	unsigned t0, t1; // variables para el tiempo
  	int datos[50000] = {0}; // arreglo que contendrá los datos del txt
	ifstream archivo; //archivo
	string texto; //texto que se lee
	int i = 0;//var para ir colocando los valores a Datos
	
	archivo.open("Datos50000.txt",ios::in);//Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"; // Si existe un error
		exit(1);
	}

	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto); //obtenemos la linea en la variabe texto
		int num =  atoi(texto.c_str());  // convertimos el string a int
		datos[i] = num; //Ingresamos el valor al array
		i++; // incrementamos contador
	}
	archivo.close(); //Cerramos el archivo
	t0 = clock();//tiempo de inicio
	insertionSort(datos, 50000); // Corremos la función
	t1 = clock();//tiempo de fin

	double time = (double(t1-t0)/CLOCKS_PER_SEC); // Obtenemos la diferencia entre el tiempo inicial y final
	cout << "El tiempo transcurrido es: " << time << endl;

  	//printArray(datos, 50000); // imprimimos los datos


}
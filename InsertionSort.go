package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"time"
)

//Algoritmo
func insertionSort(arr []int) []int {
	var key, j, i int
	for i = 1; i < len(arr); i++ {
		key = arr[i]
		j = i - 1

		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key

	}
	return arr
}

//-------------------------------------------------

func main() {
	// Abrimos el archivo
	file, err := os.Open("Datos50000.txt")

	//Por si hubo un error al abrir el archivo
	if err != nil {
		log.Fatalf("Error al abrir el archivo: %s", err)
	}

	//Iniciamos el scanner
	fileScanner := bufio.NewScanner(file)

	//Variable que contendrá los datos leidos del txt
	var datos []int

	// Leemos el archivo linea por linea
	for fileScanner.Scan() {

		lineStr := fileScanner.Text() //obtenemos la cadena

		num, _ := strconv.Atoi(lineStr) //Convertimos la cadena a entero

		datos = append(datos, num) // lo agregamos al array da datos

	}

	// Por si hubo error al leer el archivo
	if err := fileScanner.Err(); err != nil {
		log.Fatalf("Error al leer el archivo: %s", err)
	}

	file.Close() // cerramos el archivo

	//corremos el algoritmo
	s := time.Now() //tiempo inicio
	arrOrdenado := insertionSort(datos)
	e := time.Since(s) //Teimpos transcurrido hasta el nuevo momento

	//imprimimos el Arreglo Ordenado
	for _, val := range arrOrdenado {
		fmt.Println(val)
	}
	fmt.Println(e)

}

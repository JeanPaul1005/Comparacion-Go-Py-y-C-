import time
#Algoritmoooooo
def insertionSort(arr):
 
    for i in range(1, len(arr)):
 
        key = arr[i]
 
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
    return arr
#------------------------------------------------

 
archivo = open("Datos50000.txt", "r", encoding='utf-8')  #Se abre el archivo
datos = []  #variable que almacenará los datos del txt
#Leemos los datos
while(True):
    linea = archivo.readline() #Lee la linea
    if not linea:
        break #Si ya no existe la linea, entonces corta el bucle
    datos.append(int(linea.strip()))#Convertimos a entero y lo agregamos al array
archivo.close#Cerramos el archivo

#Corremos el algoritmo
start = time.time() #tiempo de inicio
arr = insertionSort(datos)
end = time.time() #tiempo de fin

#Imprimimos el arreglo
for i in range(1, len(arr)):
    print(arr[i])

print("El tiempo transcurrido es: ", end-start)  #Imprimos el tiempo que se demoró (end - start)
          

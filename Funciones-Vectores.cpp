#include <iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

// lEER ELEMENTOS DE UN VECTOR
void leer_vector(double vector[], double tamanio){
    for (int x=0; x<tamanio; x++) {
        cout << "Ingrese el elemento #" << (x + 1) << ": ";
        cin >> vector[x];
    }
}

// MUESTRA EL VECTOR
void imprime_vector(double vector[], double tamanio){
    cout << endl << endl << "Elementos del vector";
    for (int x=0; x<tamanio; x++){
        cout << endl << "Elemento # " << (x + 1) << " : " << vector[x];
    }
}

// SUMA DE ELEMENTOS DE VECTORES
double sumatoria_vector(double vector[], double tamanio){
    double suma = 0;
    for (int x=0; x<tamanio; x++){
        suma = suma + vector[x];
    }
    return suma;
}

// PROMEDIO DE VALORES MEDIANTE VECTORES
double promedio_vector(double vector[], double tamanio){
    double suma = 0;
    suma = sumatoria_vector(vector, tamanio) / tamanio;
    return suma;
}

// MÁXIMO DE UN VECTOR (AHORA YA NO POR VOID)
double max_vector(double vector[], double tamanio) {
    double mayor=vector[0];
    for (int x=1; x<tamanio; x++) {
        if (vector[x] > mayor) {
            mayor=vector[x];
        }
    }
    return mayor;
}

// MÍNIMO DE UN VECTOR (AHORA YA NO POR VOID)
double min_vector(double vector[], double tamanio){
    double menor=vector[0];
    for (int x=1; x<tamanio; x++){
        if (vector[x] < menor){
            menor=vector[x];
        }
    }
    return menor;
}

// REPASAR REFERENCIAS
void max_min_referencia(double vector[], double tamanio, double &ma, double &mi){
    ma = max_vector(vector, tamanio);
    mi = min_vector(vector, tamanio);
}

// GENERAR VECTOR CON ELEMENTOS ALEATORIOS
void vector_aleatorio(double vector[], double tamanio){
    for (int x=0; x<tamanio; x++){
        vector[x] = rand();
    }
}

// FUNCION ORDENAR VALORES DEL VECTOR DE MENOR A MAYOR (EN CLASES)
void ordenar(double vector[], double tamanio){
    for (int x=0; x<tamanio; x++){
        for (int i=x+1; i<tamanio; i++){
            if (vector[x] > vector[i]){
                double aux;
                aux = vector[x];
                vector[x] = vector[i];
                vector[i] = aux;
            }
        }
    }
}

// TAREA 1): FUNCIÓN QUE BUSQUE NÚMERO ENTERO EN EL VECTOR
// 			 LA FUNCIÓN DEBE DEVOLVER VERDADERO SI EL ELEMENTO EXISTE EN EL VECTOR O FALSO PARA LO CONTRARIO
bool elemento_entero_en_vector(double vector[], double max){
    int tof = true;
    for (int x=0; x<max; x++){
        int a = vector[x];
        if ((vector[x]-a) > 0){
            tof = false;
        }
			else{
           		tof = true;
           		break;
        	}
    }
    return tof;
}

// TAREA 2): FUNCIÓN QUE BUSQUE NÚMERO ENTERO EN EL VECTOR
// 			 LA FUNCIÓN DEBE DEVOLVER LA POSICÓN DEL ELEMENTO ENTERO, SI NO EXISTE DEBE DEVOLVER -1
int posicion_elemento_entero_en_vector(double vector[], double max){
    int pos = 0;
    for (int x=0; x<max; x++){
        int a = vector[x];
        if ((vector[x]-a) > 0){
            pos = -1;
        } 
			else{
           		pos = x+1;
            break;
        	}
    }
    return pos;
}

main(){
	setlocale(LC_ALL, "spanish");
    srand(time(NULL));
    const int max = 3;
    double num[max];
    
    leer_vector(num, max);
    imprime_vector(num, max);
    
    double suma = sumatoria_vector(num, max); 
    cout << endl << "La sumatoria del vector es: " << suma;
    
    double promedio = promedio_vector(num, max);
    cout << endl << "El promedio del vector es: " << promedio;
    
    cout << endl << "El mayor elemento del vector es: " << max_vector(num, max);
    cout << endl << "El menor elemento del vector es: " << min_vector(num, max);
    
    double v1, v2;
    cout << endl << endl << "(MAYOR ELEMENTO Y MENOR ELEMENTO DE UN VECTOR POR REFERENCIA)";
    max_min_referencia(num, max, v1, v2);
    cout << endl << "El elemento mayor es: " << v1;
    cout << endl << "El elemento menor es: " << v2;
    /*
    cout << endl << endl << "(VECTOR ALEATORIO)";
    double vector_1[max];
    vector_aleatorio(vector_1, max);
    imprime_vector(vector_1, max); */
    
    // (TAREA 02/08/2021) //
    // 1)
    cout << endl << endl << "(¿EXISTE ENTERO EN EL VECTOR?)" << endl;
    int f1 = elemento_entero_en_vector(num, max);
    if (f1 == 1){
        cout << endl << "SI HAY UN ENTERO EN EL VECTOR" << endl;
    }
		else{
    		cout << endl << "NO HAY UN ENTERO EN EL VECTOR" << endl;
    	}
    	
    // 2)	
    cout << endl << "(POSICIÓN DEL ENTERO)" << endl;	
    int f2 = posicion_elemento_entero_en_vector(num, max);
    if (f2 == -1){
        cout << endl << "(-1) NO EXISTE ENTERO EN EL VECTOR" << endl;
    } 
		else{
       		cout << endl << "LA POSICIÓN DEL ENTERO ES: " << f2 << endl;
    	}
}

#include <iostream>
#include <stack> //esta libreria permite crear y operar con una pila 
#include <queue> //esta es una bibleoteca estándar de plantillas soporta el uso de estructuras de cola 
#include <string>

using namespace std;
//Esta es una funcion donde se puede agregar las tareas usando el comando stack
void agregarTarea(stack<string>& pila, queue<string>& cola, const string& tarea) {
    pila.push(tarea);//push sirve para apilar las tareas que se ingresaron
    cola.push(tarea);
}
//Funcion para la opcion dos del menú y completarUltimaTarea
void completarUltimaTarea(stack<string>& pila) {
    if (!pila.empty()) { //en esta parte es un ciclo if donde de hay parametros donde pila se va a 
    //vaciar o ver si existe algo en la cola o las pilas. 
        cout << "Completando tarea: " << pila.top() << endl;
        pila.pop();//pila.pop es para retirar o despilar
    } else {
        cout << "No hay tareas para completar." << endl;
    }
}
//En esta funcion sirve para atender la tarea mas antigua que se realiza en la prumera opcion del menu
void atenderTareaMasAntigua(queue<string>& cola) {
    if (!cola.empty()) {
        cout << "Atendiendo tarea: " << cola.front() << endl; //el front sirve también para verificar
        cola.pop(); //la opcion poo es para desapilar la opcion de la cola de los datos ingresados
    } else {
        cout << "No hay tareas para atender." << endl;
    }
}
//funcion para llegar a mostrar las tareas que se ingresaron
void mostrarTareas(const stack<string>& pila, const queue<string>& cola) {
    stack<string> tempPila = pila; //el stack lo utilizamos para una estructura de datos en el modo de elementos LIFO
    queue<string> tempCola = cola; //posee unicamente seir metodos y dos constructores. insertando en push

    cout << "Tareas en la pila (ultima primero):" << endl;
    while (!tempPila.empty()) {
        cout << tempPila.top() << endl;
        tempPila.pop();
    }

    cout << "\nTareas en la cola (primera primero):" << endl;
    while (!tempCola.empty()) {
        cout << tempCola.front() << endl;
        tempCola.pop();
    }
}

int main() {
    stack<string> pila;
    queue<string> cola;
    int opcion;
    string tarea;
    //string entrada;
    
	//en esta parte se pone como un menu general donde se van pidiendo las opciones a realizar en cada parte
	//en la primera opcion se vaa a ir agregando cada tarea que se realiza en un trabajo de limpieza.
	//En la segunda opcion se complementa la ultima tarea más antigua que se ha realizado
	//Muestra todas las tareas que todavía estan en exitencia que no se ha eliminado
    do {
    	cout << "*****BIENVENIDO AL MENU DE TAREAS DE UNA EMPRESA(departamento de limpieza)*****"<< endl;
    	cout << "*****Lourdes Santos Guzman*****"<< endl;
        cout << "1. Agregar tareas" << endl;
        cout << "2. Completar ultima tarea realizada" << endl;
        cout << "3. Atender tarea mas antigua realizada" << endl;
        cout << "4. Mostrar todas las tareas" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona la opcion que deseas:  ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) { //nos sirve para el menu que vamos a tener en consola. 
            case 1:
                cout << "Introduce la tarea: ";
                
				//cout << "Ingrese los nombres de los productos uno por uno (o 'terminar' para finalizar): ";
				getline(cin, tarea);
                agregarTarea(pila, cola, tarea);
                break;
            case 2:
                completarUltimaTarea(pila);
            	system("pause"); //se coloca un pause para que tengamos tiempo en escribir las tareas 
                system("cls"); //para poder limpiar la pantalla de los datos registrados anteriormente. 
                break;
            case 3:
                atenderTareaMasAntigua(cola);
                system("pause");
                system("cls");
                break;
            case 4:
                mostrarTareas(pila, cola);
                system("pause");
                system("cls");
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);

    return 0;
}
//Stephanie Cristina Sabán Cárcamo
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;
//función donde se aplica stack y queue
void agregarTarea(stack<string>& pila, queue<string>& cola, const string& tarea) {
    pila.push(tarea);//para agregar una tarea (elemento) en la pila
    cola.push(tarea);//para agregar una tarea (elemento) en la cola
}

void completarUltimaTarea(stack<string>& pila) {
    if (!pila.empty()) {
        cout << "Completando tarea: " << pila.top() << endl;//trae e imprime el elemento (tarea) que está de primero
        pila.pop();//y la elimina de la fila
    } else {
        cout << "No hay tareas para completar." << endl;//si no hay tareas en la pila muestra un mensaje
    }
}

void atenderTareaMasAntigua(queue<string>& cola) {
    if (!cola.empty()) {//se usa un condicional para verificar que hayan datos en la cola
        cout << "Atendiendo tarea: " << cola.front() << endl;// si hay datos imprime la primer tarea
        cola.pop();//luego de imprimirla la borra de la cola
    } else {
        cout << "No hay tareas para atender." << endl;//si la cola esta vacia imprime el mensaje
    }
}

void mostrarTareas(const stack<string>& pila, const queue<string>& cola) {
    stack<string> tempPila = pila;//crea una pila temporal
    queue<string> tempCola = cola;//crea una cola temporal

    cout << "Tareas en la pila (ultima primero):" << endl;
    while (!tempPila.empty()) {//siempre que la pila no este vacia va imprimir las tareas de forma (last in first out)
        cout << tempPila.top() << endl;
        tempPila.pop();
    }

    cout << "\nTareas en la cola (primera primero):" << endl;
    while (!tempCola.empty()) {//siempre que la pila no este vacia va imprimir las tareas de forma (first in first out)
        cout << tempCola.front() << endl;
        tempCola.pop();
    }
}

int main() {
    stack<string> pila;
    queue<string> cola;
    int opcion;
    string tarea;

    do {//utilizamos un do while para hacer el menu y que no se cierre hasta que nosotros lo digamos.
    	cout<<"Stephanie Cristina Saban Carcamo"<<endl;
    	cout<<"Menu de actividades pendientes de oficios en la casa:"<<endl;
        cout << "1. Agregar tarea por hacer" << endl;
        cout << "2. Completar ultima tarea" << endl;
        cout << "3. Atender tarea mas antigua" << endl;
        cout << "4. Mostrar todas las tareas en cola y en pila" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore();
//utilizamos un switch para tener case y poder hacer llamado de las funciones de una manera más ordenada.
        switch (opcion) {
            case 1:
            	do{//utilizo un do while para no estar ingresando una y otra vez la opcion 1 para ingresar las tareas
                cout << "Introduce la tarea o escribe 'terminar': ";
                getline(cin, tarea);
                agregarTarea(pila, cola, tarea);
                }while(tarea!= "terminar");
                break;
            case 2:
                completarUltimaTarea(pila);
                system ("pause");//para esperar un rato en pantalla y ver lo que imprime
                system ("cls");//para limpiar lo que hay en pantalla y no se sature.
                break;
            case 3:
                atenderTareaMasAntigua(cola);//realiza la tarea más antigua y la va borrando
                system ("pause");
                system ("cls");
                break;
            case 4:
                mostrarTareas(pila, cola);//muestra todas las tareas que hay por hacer o que aun no se han atendido.
                system ("pause");
                system ("cls");
                break;
            case 5:
                cout << "Saliendo del programa." << endl;//ultima opcion para salir del programa
                break;
            default:
                cout << "Opcion invalida." << endl;//si pone una opcion que no esta en el menu sale este mensaje
        }
    } while (opcion != 5);

    return 0;
}
#include "DocumentsManager.hh"
#include "SimilarityAlgorithms.hh"
using namespace std;

void commands(){
    cout << "1. Crear texto base" << endl;
    cout << "2. Crear permutaciones" << endl;
    cout << "3. Crear k-shingles" << endl;
    cout << "4. Crear k-shingles permutaciones" << endl;
    cout << "5. Calcular la similitud de Jaccard" << endl;
    cout << "6. Calcular minHash" << endl;
    cout << "7. Calcular LSH" << endl;
    cout << "8. Comandos" << endl;
    cout << "9. Salir" << endl;
}

int main(){
    /*DocumentsManager prueba;

    string archivo;
    cin >> archivo;

    int k;
    cin >> k;

    //prueba.creationTextBase(archivo);
    //prueba.k_shinglesGenerator(archivo, k);
    prueba.k_shinglesPermutationsGenerator(archivo, 10, 10, 10);*/

    DocumentsManager Manager;
    SimilarityAlgorithms Algorithm;

    commands();
    int option;
    cin >> option;
    while (option != 9){
        switch (option) {
            case 1: {
                // Logica para crear texto base
                cout << "Crear texto base seleccionado" << endl;
                cout << "Introduce el archivo a leer (por ejemplo <<noticia_chatgpt_y_deepseek>>), recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                string archivo;
                cin >> archivo;
                Manager.creationTextBase(archivo);
                break;
            }
            case 2: {
                // Logica para crear permutaciones
                cout << "Crear permutaciones seleccionado" << endl;
                cout << "Introduce el archivo a leer (por ejemplo <<noticia_chatgpt_y_deepseek>>), recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                string archivo;
                cin >> archivo;
                int size, num_permutations;
                cout << "Introduce el tamano de las permutaciones: ";
                cin >> size;
                cout << "Introduce el numero de permutaciones: ";
                cin >> num_permutations;
                Manager.permutationsGenerator(archivo, size, num_permutations);
                break;
            }
            case 3: {
                // Logica para crear k-shingles
                cout << "Crear k-shingles seleccionado" << endl;
                cout << "Introduce el archivo a leer (por ejemplo <<noticia_chatgpt_y_deepseek>>), recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                string archivo;
                cin >> archivo;
                int k;
                cout << "Introduce el valor de k: ";
                cin >> k;
                Manager.k_shinglesGenerator(archivo, k);
                break;
            }
            case 4: {
                // Logica para crear k-shingles permutaciones
                cout << "Crear k-shingles permutaciones seleccionado" << endl;
                cout << "Introduce el archivo a leer (por ejemplo <<noticia_chatgpt_y_deepseek>>), recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                string archivo;
                cin >> archivo;
                int size, num_permutations, n;
                cout << "Introduce el tamano de las permutaciones: ";
                cin >> size;
                cout << "Introduce el numero de permutaciones: ";
                cin >> num_permutations;
                cout << "Introduce el numero de k-shingles a seleccionar: ";
                cin >> n;
                Manager.k_shinglesPermutationsGenerator(archivo, size, num_permutations, n);
                break;
            }
            case 5: {
                // Logica para calcular la similitud de Jaccard
                cout << "Calcular la similitud de Jaccard seleccionado" << endl;
                cout << "Introduce el primer archivo a comparar, recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                string archivo1, archivo2;
                cin >> archivo1;
                cout << "Introduce el segundo archivo a comparar, recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                cin >> archivo2;
                int k;
                cout << "Introduce el valor de k: ";
                cin >> k;
                Algorithm.JaccardSimilarity(archivo1, archivo2, k);
                break;
            }
            case 6: {
                // Logica para calcular minHash
                cout << "Calcular minHash seleccionado" << endl;
                cout << "Introduce el primer archivo a comparar, recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                string archivo1, archivo2;
                cin >> archivo1;
                cout << "Introduce el segundo archivo a comparar, recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                cin >> archivo2;
                int T;
                cout << "Introduce el numero de funciones hash: ";
                cin >> T;
                int k;
                cout << "Introduce el valor de k: ";
                cin >> k;
                Algorithm.minHash(archivo1, archivo2, T, k);
                break;
            }
            case 7: {
                // Logica para calcular LSH
                cout << "Calcular LSH seleccionado" << endl;
                cout << "Introduce el primer archivo a comparar, recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                string archivo1, archivo2;
                cin >> archivo1;
                cout << "Introduce el segundo archivo a comparar, recuerda, debe ser SIN .txt y debe estar en la carpeta /documents: ";
                cin >> archivo2;
                int T, b;
                cout << "Introduce el numero de funciones hash: ";
                cin >> T;
                cout << "Introduce el numero de bandas: ";
                cin >> b;
                int k;
                cout << "Introduce el valor de k: ";
                cin >> k;
                Algorithm.LSH(archivo1, archivo2, T, b, k);
                break;
            }
            case 8:
                // Mostrar comandos
                commands();
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        cout << "Introduce una opcion: ";
        cin >> option;
    }

    cout << "Saliendo del programa..." << endl;
}

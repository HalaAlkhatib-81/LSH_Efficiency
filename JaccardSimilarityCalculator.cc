/** @file JaccardSimilarityCalculator.cc
    @brief Implementación de la clase para calcular la similitud de Jaccard entre documentos.
*/

#include "JaccardSimilarityCalculator.hh"
<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void JaccardSimilarityCalculator::readLinesFromFile(const string &filename, set<string> &doc) {
=======


void JaccardSimilarityCalculator::readElementsFromFile(const string &filename, set<string> &doc, int opcion, int k) {
>>>>>>> 4fdd0edc12fe90efb7db5424d71e7bea9026dcc5
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return;
    }

<<<<<<< HEAD
    string line;
    while (getline(file, line)) {
        doc.insert(line);
    }
}

double JaccardSimilarityCalculator::computeSimilarity(const string &filename1, const string &filename2) {
    set<string> doc1, doc2;
    readLinesFromFile(filename1, doc1);
    readLinesFromFile(filename2, doc2);
=======
    string palabra;

    if (opcion == 1) {
        while (file >> palabra) {
            doc.insert(palabra);
        }
    }
    else if (opcion == 2) {
        int count = 0;
        string grupo;
    
        while (file >> palabra) {
            if (count == 0) {
                grupo += palabra;
            } else {
                grupo += " " + palabra;
            }
    
            count++;
    
            if (count == k) {
                doc.insert(grupo);
                grupo.clear();
                count = 0;
            }
        }
    }

    file.close();
}

double JaccardSimilarityCalculator::computeSimilarity(const string &filename1, const string &filename2, int opcion, int k = 0) {
    set<string> doc1, doc2;
    readElementsFromFile(filename1, doc1, opcion, k);
    readElementsFromFile(filename2, doc2, opcion, k);
>>>>>>> 4fdd0edc12fe90efb7db5424d71e7bea9026dcc5

    if (doc1.empty() || doc2.empty()) {
        cerr << "Error: Uno o ambos documentos están vacíos o no se pudieron leer correctamente." << endl;
        return 0.0;
    }

    set<string> intersectionSet, unionSet;

    // Calcular la intersección de los conjuntos
    set_intersection(doc1.begin(), doc1.end(), doc2.begin(), doc2.end(),
                     inserter(intersectionSet, intersectionSet.begin()));

    // Calcular la unión de los conjuntos
    set_union(doc1.begin(), doc1.end(), doc2.begin(), doc2.end(),
              inserter(unionSet, unionSet.begin()));

    if (unionSet.empty()) return 0.0;

    return static_cast<double>(intersectionSet.size()) / unionSet.size();
}

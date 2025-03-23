/** @file JaccardSimilarityCalculator.cc
    @brief Implementación de la clase para calcular la similitud de Jaccard entre documentos.
*/

#include "JaccardSimilarityCalculator.hh"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void JaccardSimilarityCalculator::readLinesFromFile(const string &filename, set<string> &doc) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        doc.insert(line);
    }
}

double JaccardSimilarityCalculator::computeSimilarity(const string &filename1, const string &filename2) {
    set<string> doc1, doc2;
    readLinesFromFile(filename1, doc1);
    readLinesFromFile(filename2, doc2);

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

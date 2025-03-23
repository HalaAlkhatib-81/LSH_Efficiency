/** @file minHash.cc
 * @brief implementacion de la clase minHash */
#include "minHash.hh"

const int T = 10;
vector<uint32_t> minHash::computarMinHash(set<string> shingles){
    vector<uint32_t> minhashes(T, UINT32_MAX);
    for(string shin: shingles){
        for(int i = 0; i < T; i++){
            uint32_t hash = XXH32(shin.c_str(), shin.size(), i);
            minhashes[i] = min(minhashes[i], hash);
        }
    }
    return minhashes;
}

void minHash::readElementsFromFile(const string &filename, set<string> &doc, int opcion, int k) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo " << filename << endl;
        return;
    }

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

double minHash::funcion_general_minHash(string docA, string docB, int option, int k){
    set<string> shinglesA;
    set<string> shinglesB;
    readElementsFromFile(docA, shinglesA, option, k);
    readElementsFromFile(docB, shinglesB, option, k);

    vector<uint32_t> firmaA = computarMinHash(shinglesA);
    vector<uint32_t> firmaB = computarMinHash(shinglesB);

    double count = 0;
    for(size_t i = 0; i < firmaA.size(); i++){
        if(firmaA[i] == firmaB[i]){
            count++;
        }
    }
    double numeros = count/T;    
    return numeros;
}




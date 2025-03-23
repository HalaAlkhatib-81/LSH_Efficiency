#include "SimilarityAlgorithms.hh"

void SimilarityAlgorithms::JaccardSimilarity(const string& archivo1, const string& archivo2){
    DocumentsManager manager;
    unordered_set<string> doc1 = manager.selectionDoc(archivo1);
    unordered_set<string> doc2 = manager.selectionDoc(archivo2);

    cout << "El resultado de la similitud de Jaccard es " << computeSimilarity(doc1, doc2) << endl;
}


void SimilarityAlgorithms::minHash(const string& archivo1, const string& archivo2, int& T){
    DocumentsManager manager;
    unordered_set<string> doc1 = manager.selectionDoc(archivo1);
    unordered_set<string> doc2 = manager.selectionDoc(archivo2);

    cout << "El resultado del minHash es " << funcion_general_minHash(doc1, doc2, T) << endl;
}


void SimilarityAlgorithms::LSH(const string& archivo1, const string& archivo2, int& T, int& b){
    DocumentsManager manager;
    unordered_set<string> doc1 = manager.selectionDoc(archivo1);
    unordered_set<string> doc2 = manager.selectionDoc(archivo2);

    cout << "El resultado del LSH es " << funcion_general_LSH(doc1, doc2, T, b) << endl;
}


double SimilarityAlgorithms::computeSimilarity(unordered_set<string>& doc1, unordered_set<string>& doc2) {
    unordered_set<string> intersectionSet, unionSet;

    // Calcular la intersección de los conjuntos
    set_intersection(doc1.begin(), doc1.end(), doc2.begin(), doc2.end(),
                     inserter(intersectionSet, intersectionSet.begin()));

    // Calcular la unión de los conjuntos
    set_union(doc1.begin(), doc1.end(), doc2.begin(), doc2.end(),
              inserter(unionSet, unionSet.begin()));

    if (unionSet.empty()) return 0.0;

    return static_cast<double>(intersectionSet.size()) / unionSet.size();
}


vector<uint32_t> SimilarityAlgorithms::computarMinHash(unordered_set<string> shingles, int& T){
    vector<uint32_t> minhashes(T, UINT32_MAX);
    for(string shin: shingles){
        for(int i = 0; i < T; i++){
            uint32_t hash = XXH32(shin.c_str(), shin.size(), i);
            minhashes[i] = min(minhashes[i], hash);
        }
    }
    return minhashes;
}


double SimilarityAlgorithms::funcion_general_minHash(unordered_set<string>& shinglesA, unordered_set<string>& shinglesB, int& T){
    vector<uint32_t> firmaA = computarMinHash(shinglesA, T);
    vector<uint32_t> firmaB = computarMinHash(shinglesB, T);

    double count = 0;
    for(size_t i = 0; i < firmaA.size(); i++){
        if(firmaA[i] == firmaB[i]){
            count++;
        }
    }
    double numeros = count/T;    
    return numeros;
}


vector<vector<int>> SimilarityAlgorithms::bandes(vector<uint32_t> minhashes, int& T, int& b){
    vector<vector<int>> bandes;
    int r = T/b;
    for(int i = 0; i < b; i++){
        vector<int> band;
        for(int j = 0; j < r; j++){
            band.push_back(minhashes[i*r + j]);
        }
        bandes.push_back(band);
    }
    return bandes;
}


void SimilarityAlgorithms::localitySensitiveHashing(const vector<vector<int>> &bandes, int docId, unordered_map<size_t, vector<int>> &lshTable) {
    for (int i = 0; i < bandes.size(); i++) {
        int hash = 0;
        for (int j = 0; j < bandes[i].size(); j++) {
            hash = hash * 31 + bandes[i][j];
        }
        lshTable[hash].push_back(docId);
    }
}


double SimilarityAlgorithms::similitudJaccard(const vector<uint32_t> &firmaA, const vector<uint32_t> &firmaB, int& T) {
    int coincidencies = 0;
    for (int i = 0; i < T; i++) {
        if (firmaA[i] == firmaB[i]) coincidencies++;
    }
    return (double)coincidencies / T;
}


double SimilarityAlgorithms::funcion_general_LSH(unordered_set<string>& shinglesA, unordered_set<string>& shinglesB, int& T, int& b){
    vector<uint32_t> firmaA = computarMinHash(shinglesA, T);
    vector<uint32_t> firmaB = computarMinHash(shinglesB, T);
    vector<vector<int>> bandesA = bandes(firmaA, T, b);
    vector<vector<int>> bandesB = bandes(firmaB, T, b);

    unordered_map<size_t, vector<int>> lshTable;
    localitySensitiveHashing(bandesA, 1, lshTable);
    localitySensitiveHashing(bandesB, 2, lshTable);

    bool sonCandidats = false;
    for (pair<int, vector<int>> entry: lshTable) {
        if (entry.second.size() > 1) {
            cout << "Possible parella similar trobada en banda hash: " << entry.first << endl;
            sonCandidats = true;
        }
    }

    if (sonCandidats) {
        double sim = similitudJaccard(firmaA, firmaB, T);
        cout << "S'han trobat candidats similars." << endl;
        return sim;
    } else {
        cout << "No s'han trobat candidats similars." << endl;
        return 0;        
    }
}
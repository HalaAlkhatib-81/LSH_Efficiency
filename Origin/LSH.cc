#include "LSH.hh"
const int T = 10;
vector<uint32_t> LSH::computarMinHash(set<string> shingles){
    vector<uint32_t> minhashes(T, UINT32_MAX);
    for(string shin: shingles){
        for(int i = 0; i < T; i++){
            uint32_t hash = XXH32(shin.c_str(), shin.size(), i);
            minhashes[i] = min(minhashes[i], hash);
        }
    }
    return minhashes;
}


void LSH::readElementsFromFile(const string &filename, set<string> &doc, int opcion, int k) {
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

vector<vector<int>> LSH::bandes(vector<uint32_t> minhashes, const int& b){
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

void LSH::localitySensitiveHashing(const vector<vector<int>> &bandes, int docId, unordered_map<size_t, vector<int>> &lshTable) {
    for (int i = 0; i < bandes.size(); i++) {
        int hash = 0;
        for (int j = 0; j < bandes[i].size(); j++) {
            hash = hash * 31 + bandes[i][j];
        }
        lshTable[hash].push_back(docId);
    }
}

double LSH::similitudJaccard(const vector<uint32_t> &firmaA, const vector<uint32_t> &firmaB) {
    int coincidencies = 0;
    for (int i = 0; i < T; i++) {
        if (firmaA[i] == firmaB[i]) coincidencies++;
    }
    return (double)coincidencies / T;
}

double LSH::funcion_general_LSH(string docA, string docB, int option, int k, int b){
    set<string> shinglesA;
    set<string> shinglesB;
    readElementsFromFile(docA, shinglesA, option, k);
    readElementsFromFile(docB, shinglesB, option, k);

    vector<uint32_t> firmaA = computarMinHash(shinglesA);
    vector<uint32_t> firmaB = computarMinHash(shinglesB);
    vector<vector<int>> bandesA = bandes(firmaA, b);
    vector<vector<int>> bandesB = bandes(firmaB, b);

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
        double sim = similitudJaccard(firmaA, firmaB);
        cout << "S'han trobat candidats similars." << endl;
        return sim;
    } else {
        cout << "No s'han trobat candidats similars." << endl;
        return 0;        
    }


}

/*int main(){

    set<string> shinglesA;
    set<string> shinglesB;
    readLinesFromFile("docA.txt", shinglesA);
    readLinesFromFile("docB.txt", shinglesB);

    vector<uint32_t> firmaA = computarMinHash(shinglesA);
    vector<uint32_t> firmaB = computarMinHash(shinglesB);
    vector<vector<int>> bandesA = bandes(firmaA, 6);
    vector<vector<int>> bandesB = bandes(firmaB, 6);

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
        double sim = similitudJaccard(firmaA, firmaB);
        cout << "Similitud de Jaccard real: " << sim << endl;
    } else {
        cout << "No s'han trobat candidats similars." << endl;
    }

    return 0;
}*/
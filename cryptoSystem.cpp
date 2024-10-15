#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using matrix = vector<vector<char>>;

class Matrix {
    matrix m;
    string text;

public:
    Matrix() {}

    void setMatrix() {
        size_t n = static_cast<size_t>(sqrt(text.size())); 
        m.resize(n, vector<char>(n, ' '));
        
        int index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (index < text.size()) {
                    m[i][j] = text[index];
                    index++;
                } else {
                    m[i][j] = ' '; 
                }
            }
        }
    }

    void setText(const string& inputText) {
        this->text = inputText;
        setMatrix();
    }

    void printMatrix() {
        for (const auto& row : m) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
    void printtextE(){
        cout<<"\n"<<endl;
        
        cout << "\nEncryption:" << endl;
        for (const auto& row : m) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
        }
    }
    
    void printtextD(){
        cout<<"\n"<<endl;
        
        cout << "\nDencryption:" << endl;
        for (const auto& row : m) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
        }
    }

    void encryptMatrix() {
        
        for (int i = 0; i < m.size(); i++) {
            for (int j = i + 1; j < m.size(); j++) {
                swap(m[i][j], m[j][i]);
            }
        }

        printMatrix();
        printtextE();
    }

    void decryptMatrix() {
        encryptMatrix();
        printMatrix();
        
        printtextD();
    }
};

int main() {
    Matrix cryptoSystem;
    string text;

    cout << "Enter your text: " << endl;
    getline(cin, text);
    
    cryptoSystem.setText(text);
    cryptoSystem.encryptMatrix();
    cryptoSystem.decryptMatrix();

    return 0;
}

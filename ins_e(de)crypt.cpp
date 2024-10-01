
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


string encrypt(const string& input, const unordered_map<char, char>& template_map) {
    string result = input;
    for (char& c : result) {
        if (template_map.find(c) != template_map.end()) {
            c = template_map.at(c);
        }
    }
    return result;
}

string decrypt(const string& input, const unordered_map<char, char>& template_map) {
    string result = input;
    unordered_map<char, char> reverse_map;

    for (const auto& pair : template_map) {
        reverse_map[pair.second] = pair.first;
    }

    for (char& c : result) {
        if (reverse_map.find(c) != reverse_map.end()) {
            c = reverse_map.at(c);
        }
    }
    return result;
}

int main() {
    unordered_map<char, char> template_map = {
        {'a', 'm'},
        {'b', 'n'},
        {'c', 'o'},
        {'d', 'p'},
        {'e', 'q'},
        {'f', 'r'},
        {'g', 's'},
        {'h', 't'},
        {'i', 'u'},
        {'j', 'v'},
        {'k', 'w'},
        {'l', 'x'},
        {'m', 'y'},
        {'n', 'z'},
        {'o', 'a'},
        {'p', 'b'},
        {'q', 'c'},
        {'r', 'd'},
        {'s', 'e'},
        {'t', 'f'},
        {'u', 'g'},
        {'v', 'h'},
        {'w', 'i'},
        {'x', 'j'},
        {'y', 'k'},
        {'z', 'l'}
    };
    string input = "bahcbdldhlbaalhvbsdh";
    string encrypted = encrypt(input, template_map);
    string decrypted = decrypt(encrypted, template_map);

    cout << "encrypt: " << encrypted << endl;
    cout << "decrypt: " << decrypted << endl;

    return 0;
}

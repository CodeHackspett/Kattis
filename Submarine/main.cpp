#include <iostream>
#include <vector>

using namespace std;

int encr_len;
int frag_len;

// Function is_consistent - checks if a mapping from char1 to char2 (or viceversa) already exists in char_map
bool is_consistent(char char_1, char char_2, char char_map[][2], int index){
    for(int i=0; i<=index; i++){
        if ((char_map[i][0] == char_1) || (char_map[i][1] == char_2)){
            if (!((char_map[i][0] == char_1) && (char_map[i][1] == char_2))) return false;
        }
    }
    return true;
}

// Function that validates if the encryption between the two given strings is possible or not
bool is_valid_encryption(string enc_substring, string fragment, char char_map[][2]){
    int index = -1; 
    for(int i = 0; i<frag_len; i++){
        if(is_consistent(enc_substring[i], fragment[i], char_map, index)){
            char_map[index+1][0] = enc_substring[i];
            char_map[index+1][1] = fragment[i];
            index++;
        } else return false;
    }
    return true;
}

int main() {
    string encrypted, fragment;
    cin >> encrypted >> fragment;

    encr_len = encrypted.length();
    frag_len = fragment.length();

    vector<string> collection; // Vector that stores all the valide encryptions
    char char_map[frag_len][2]; //char map : multidimensional array


    string enc_substring = "";
     // shift the substring forward until it reaches the end of the encrypted string
    for (int start=0; start <= (encr_len-frag_len); ++start) {
            enc_substring = encrypted.substr(start, frag_len);
            if (is_valid_encryption(enc_substring, fragment, char_map)) {
            collection.push_back(enc_substring); //stores the valid encription
        }
    }

    if(collection.size()==1) cout << collection[0]; //if one connection only then print it
    else cout << collection.size(); //print size of collection vector
}

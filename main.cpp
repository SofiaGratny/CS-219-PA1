//Author: Sofia Gratny
//Date: 11/4/22
// Programming Assignment 2


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>
using namespace std;

//cmds
vector<string> loadFile();
string choice(vector<string>);
uint32_t loadHex(string);
void saveFile(string, string);

//operations
string ADD(string, string);
string AND(string, string);
string ASR(string, string);
string LSR(string, string);
string LSL(string, string);
string NOT(string);
string ORR(string, string);
string SUB(string, string);
string XOR(string, string);


int main() {
    string s, filename = "output.txt";
    vector<string> Contents = loadFile(); //loads file, don't have custom filenames yet
    s = choice(Contents); //polls the text.txt choices
    saveFile(s, filename);
    cout << s;
    return 0;
}

void saveFile(string s, string filename) {
    ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << s;
    }
    file.close();
}

vector<string> loadFile() {
    ifstream file;
    vector<string> fileContent;
    string line, a;
    file.open("text.txt");
    //after initialization of the file

    if (file.is_open()) {
        int i;
        while (getline(file, line)) { // loop through and then pushback the vector per 'word' found
            stringstream s(line);
            while (s >> a) { fileContent.push_back(a); }
        }
    }
    return fileContent;
}

string choice(vector<string> Contents) {
    string s;
    for (int i = 0; i < Contents.size(); i++) { // ADD (0), x(1), x(2), add(3)
        if ((Contents[i].compare("ADD")==0)) { //        ADD
            s = s + ADD(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("AND")==0)) { // AND
            s = s + AND(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("ASR")==0)) { // ASR
            s = s + ASR(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("LSR")==0)) { // LSR
            s = s + LSR(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("LSL")==0)) { // LSl
            s = s + LSL(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("NOT")==0)) { // NOT
            s = s + NOT(Contents[i+1]) + "\n";
            i--;
        } else if ((Contents[i].compare("ORR")==0)) { // ORR
            s = s + ORR(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("SUB")==0)) { // SUB
            s = s + SUB(Contents[i+1], Contents[i+2]) + "\n";
        } else if ((Contents[i].compare("XOR")==0)) { // XOR
            s = s + XOR(Contents[i+1], Contents[i+2]) + "\n";
        } else {
            cout << "Error in processing text.txt" << endl;
        } i++; i++;
    }
    return s;
}

uint32_t loadHex(string Hex) {
    uint32_t bin1;
    stringstream ss; //stringstream for dynamic stuff makes hex conversion really easy

    ss << hex << Hex;
    ss >> bin1;

    return bin1; // returns the hex value given in the form of uint32_t
}


string ADD(string c1, string c2) { //done
    uint32_t bin1 = loadHex(c1), bin2 = loadHex(c2), binF = bin1 + bin2;
    bitset<32> c(binF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << binF;
    sss >> ss;
    s = "ADD 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string AND(string c1, string c2) { //done
    uint32_t bin1 = loadHex(c1), bin2 = loadHex(c2), binF = (bin1&bin2);
    bitset<32> c(binF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << binF;
    sss >> ss;
    s = "AND 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string ASR(string c1, string c2) { //done
    int32_t op1 = loadHex(c1), opF;
    int op2 = stoi(c2);
    opF = op1>>op2;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ASR 0x" + c1 + " = 0x" + ss;
    return s;
}

string LSR(string c1, string c2) { //done
    uint32_t op1 = loadHex(c1), opF;
    int op2 = stoi(c2);
    opF = op1>>op2;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "LSR 0x" + c1 + " = 0x" + ss;
    return s;
}

string LSL(string c1, string c2) { //done
    uint32_t op1 = loadHex(c1), opF;
    int op2 = stoi(c2);
    opF = op1<<op2;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "LSL 0x" + c1 + " = 0x" + ss;
    return s;
}

string NOT(string c1) {  //done
    uint32_t op1 = loadHex(c1), opF = ~op1;
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "NOT 0x" + c1 + " = 0x" + ss;
    return s;
}

string ORR(string c1, string c2) {  //done
    uint32_t op1 = loadHex(c1), op2 = loadHex(c2), opF = (op1|op2);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ORR 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string SUB(string c1, string c2) {  //done
    uint32_t op1 = loadHex(c1), op2 = loadHex(c2), opF = op1 - op2;
    bitset<32> c(opF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ORR 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}

string XOR(string c1, string c2) {  //done
    uint32_t op1 = loadHex(c1), op2 = loadHex(c2), opF = (op1^op2);
    bitset<32> c(opF);
    string s, ss;
    stringstream sss;
    sss << uppercase << hex << opF;
    sss >> ss;
    s = "ORR 0x" + c1 + " 0x" + c2 + " = 0x" + ss;
    return s;
}
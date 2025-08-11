#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <string>

using namespace std;

// Convert string to binary, store in vector and queue
void convertStrToBin(const string& strToBin, vector<string>& binaryVector, queue<string>& binaryQueue) {
    for (char c : strToBin) {
        bitset<8> binary(c); // Convert character to 8-bit binary
        string binaryStr = binary.to_string();
        binaryVector.push_back(binaryStr);
        binaryQueue.push(binaryStr);
    }
}

// Convert binary vector back to string
void convertBinToStr(const vector<string>& binToStr, string& result) {
    result = "";
    for (const string& bin : binToStr) {
        bitset<8> binaryChar(bin);
        char character = static_cast<char>(binaryChar.to_ulong());
        result += character;
    }
}

int main() {
    string inputString;
    vector<string> binaryVector;
    queue<string> binaryQueue;
    string result;

    cout << "Enter string: ";
    getline(cin, inputString);

    // Convert string to binary
    convertStrToBin(inputString, binaryVector, binaryQueue);

    // Output the binary vector
    cout << "\nBinary vector:\n";
    for (const string& bin : binaryVector) {
        cout << bin << " ";
    }

    // Output the binary queue
    cout << "\n\nBinary queue (FIFO):\n";
    queue<string> tempQueue = binaryQueue; // copy to preserve original queue
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }

    // Convert back to original string
    convertBinToStr(binaryVector, result);
    cout << "\n\nRecovered string: " << result << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Convert string to binary, store in vector and queue
void convertStrToBin(const string& strToBin, vector<int>& binaryVector) {
    for (char c : strToBin) {
        bitset<8> binary(c); // Convert character to 8-bit binary
        //string binaryStr = binary.to_string();
        for(int i=0;i<8;i++){
            binaryVector.push_back(binary[i]);
        }
        

    }
}

//Push in queue from vector 
void pushQueue( vector<int>& binaryVector, queue<int>& binaryQueue){
    cout<<endl;
    for(int i=0;i<binaryVector.size();i++){
         binaryQueue.push(binaryVector[i]);
        
    }
    
}

// Convert binary vector back to string
void convertBinToStr(const vector<int>& binToStr, string& result) {
    result = "";
    size_t bitIndex = 0;
    bitset<8> binaryChar;
    for (int bin : binToStr) {
        binaryChar[bitIndex] = bin;  // Set the corresponding bit
        bitIndex++;

        // Once we've filled 8 bits, convert to char and reset
        if (bitIndex == 8) {
            result += static_cast<char>(binaryChar.to_ulong());  // Convert to char and append
            binaryChar.reset();  // Reset for next character
            bitIndex = 0;  // Reset bit index
        }
    }

    // Handle case where there might be leftover bits (if the vector size isn't a multiple of 8)
    if (bitIndex > 0) {
        result += static_cast<char>(binaryChar.to_ulong());
    }
}

void falseBitOptn(vector<int>& falsebit,vector<int>& falseBitPos){
    
        int flips = falsebit.size()/4;
        int count = 0;
        
         while (count < flips) {
        int index = rand() % falsebit.size();
        if (falsebit[index] == 1) {
            falsebit[index] = 0;
            falseBitPos.push_back(index);
            ++count;
        }
        else{
            falsebit[index] = 1;
            falseBitPos.push_back(index);
            ++count;
        }
            
        }
    }



int main() {
    srand(time(nullptr));
    string inputString;
    vector<int> binaryVector;
    queue<int> binaryQueue;
    vector <int> falseBitindex;
    string result;

    cout << "Enter string: ";
    getline(cin, inputString);

    // Convert string to binary
    convertStrToBin(inputString, binaryVector);

    // Output the binary vector
    cout << "\nBinary vector:\n";
    for (int bin : binaryVector) {
        cout << bin << " ";
    }
    
    //falsebit operation chnage bits 
    falseBitOptn(binaryVector,falseBitindex);
    
    
    //for where is flase bits 
    cout<<endl<<"Binray  False Bit Index: "<<endl;
    for(int i=0;i<falseBitindex.size();i++){
        cout<<falseBitindex[i]<<" ";
        
    }
    
    
    //push elemnt from vector to queue 
    pushQueue(binaryVector,binaryQueue);

    // Output the binary queue
    cout << "\n\nBinary queue (FIFO):\n";
    queue<int> tempQueue = binaryQueue; // copy to preserve original queue
    while (!tempQueue.empty()) {
        cout << tempQueue.front() << " ";
        tempQueue.pop();
    }

    // Convert back to original string
    convertBinToStr(binaryVector, result);
    cout << "\n\nRecovered string: " << result << endl;

    return 0;
}
 

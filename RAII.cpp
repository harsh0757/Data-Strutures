#include<iostream>
#include <fstream>
using namespace std;

class FileWrapper{
    ifstream file;
public:
    FileWrapper(const string& filename){
        file.open(filename);
        if(!file.is_open()){
            cout<<"failed to open the file"<<filename<<endl;
        }
    }
    ~FileWrapper(){
        file.close(); //resource automatically released
        cout<<"file closed"<<endl;
    }

    void printContent(){
        string line;
        while(getline(file, line)){
            cout<<line<<endl;
        }
    }
};

int main(){
    FileWrapper fw("sample.txt"); //RAII : file opened here
    std::cout << "Reading contents from file:\n";
    fw.printContent(); // Read and print file contents
}
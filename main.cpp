#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Database{
public:
    vector< vector <string> > tab;
};

int main()
{
    ifstream fin;
    fin.open("students.txt");
    ofstream fout;
    fout.open("output.txt");

    int col=6;
    const int line = 15;

    string a;
    while(fin>>a){
        fout<<a;
        int spaces=line-a.length();
            for(int i=0; i<spaces; i++){
            fout<<" ";
            }
        fout << endl;
    }


//    Database database;
//    string a;
//    int count=0;
//    while(!fin.eof()){
//    fin>>a;
//    database.tab=a;
//    count++;
//    }

//    for(int i=0; i<count; i++){
//        fout<<database.tab;
//    }

    fin.close();
    fout.close();
    return 0;
}




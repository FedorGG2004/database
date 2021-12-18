#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Database{
public:
    vector < vector <string> > tab;
    Database(){
        vector < vector <string> > tab (19, vector <string> (12));
};
    int get_titul(int line){
            for(int j=0 ;j<6; j++){
                cout<<tab[0][j];
                int spaces=line-tab[0][j].length();
                    for(int k=0; k<spaces; k++){
                    cout<<" ";
                }
            }
    }
};
int main()
{
    ifstream fin;
    fin.open("students.txt");

    const int col=6;
    const int line = 15;
    Database database;
    string a;

    vector<string> vspom;
    for(int i=0; i<4; i++){
        for(int j=0 ;j<6; j++){
            fin>>a;
            vspom.push_back(a);
        }
        database.tab.push_back(vspom);
        vspom.clear();
    }


    for(int i=0; i<4; i++){
        for(int j=0 ;j<6; j++){
            cout<<database.tab[i][j];
            int spaces=line-database.tab[i][j].length();
                for(int k=0; k<spaces; k++){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    while(true){
        string a;
        cin>>a;
        if(a=="titul")
            database.get_titul(line);
    }

    fin.close();
    return 0;
}



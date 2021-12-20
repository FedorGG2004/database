#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Database{
public:
    vector < vector <string> > tab;
    Database(){
        vector < vector <string> > tab (1000, vector <string> (1000));
};
    void get_titul(int line){
            for(int j=0 ;j<6; j++){
                cout<<tab[0][j];
                int spaces=line-tab[0][j].length();
                    for(int k=0; k<spaces; k++){
                    cout<<" ";
                }
            }
    }
    void show_tab(int line, int strok){
        for(int i=0; i<strok; i++){
            for(int j=0 ;j<6; j++){
                cout<<tab[i][j];
                int spaces=line-tab[i][j].length();
                    for(int k=0; k<spaces; k++){
                    cout<<" ";
                }
            }
        cout<<endl;
        }
    }
    void create_new_line(){
        vector<string> tmp;
        cout<<"input id: ";
        string word;
        cin>>word;
        tmp.push_back(word);
        cout<<"input Surname: ";
        cin>>word;
        tmp.push_back(word);
        cout<<"input Name: ";
        cin>>word;
        tmp.push_back(word);
        cout<<"input Otchestvo: ";
        cin>>word;
        tmp.push_back(word);
        cout<<"input Age: ";
        cin>>word;
        tmp.push_back(word);
        cout<<"input Class: ";
        cin>>word;
        tmp.push_back(word);
        tab.push_back(tmp);
        cout<<"Added Line";
    }
    void delete_line(){
        tab.pop_back();
        cout<<"line deleted";
    }
};
int main()
{
    ifstream fin;
    fin.open("students.txt");

    int strok=4;
    const int line = 15;
    Database database;
    string a;

    vector<string> vspom;

    for(int i=0; i<strok; i++){
        for(int j=0 ;j<6; j++){
            fin>>a;
            vspom.push_back(a);
        }
        database.tab.push_back(vspom);
        vspom.clear();
    }

    while(true){
        string a;
        cin>>a;
        if(a=="help")
            cout<<"commands: tab, titul, add, delete";
        if(a=="titul")
            database.get_titul(line);
        if(a=="tab")
            database.show_tab(line, strok);
        if(a=="add"){
            database.create_new_line();
            strok++;
            cout<<strok;
        }
        if(a=="delete")
            database.delete_line();
    }

    fin.close();
    return 0;
}


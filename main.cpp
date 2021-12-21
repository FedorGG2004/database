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
    void get_titul(int line, int column){
            for(int j=0 ;j<column; j++){
                cout<<tab[0][j];
                int spaces=line-tab[0][j].length();
                    for(int k=0; k<spaces; k++){
                    cout<<" ";
                }
            }
    }
    void show_tab(int line, int strok, int column){
        for(int i=0; i<strok; i++){
            for(int j=0 ;j<column; j++){
                cout<<tab[i][j];
                int spaces=line-tab[i][j].length();
                    for(int k=0; k<spaces; k++){
                    cout<<" ";
                }
            }
        cout<<endl;
        }
    }
    void add_new_line(){
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
    void add_new_column(int strok){
        vector<string> tmp=tab[0];
        cout<<"add name of column: ";
        string word;
        cin>>word;
        tmp.push_back(word);
        tab[0]=tmp;
        for(int i=1; i<strok; i++){
            vector<string> tmp=tab[i];
            cin>>word;
            tmp.push_back(word);
            tab[i]=tmp;
        }
        cout<<"column added";
    }
    void delete_last_column(int strok){
        for(int i=0; i<strok; i++){
            vector<string> tmp=tab[i];
            tmp.pop_back();
            tab[i]=tmp;
        }
        cout<<"column deleted";
    }
};

int main()
{
    ifstream fin;
    fin.open("students.txt");

    int strok=4;
    int column=6;
    const int line = 15;
    Database database;
    string a;

    vector<string> vspom;

    for(int i=0; i<strok; i++){
        for(int j=0 ;j<column; j++){
            fin>>a;
            vspom.push_back(a);
        }
        database.tab.push_back(vspom);
        vspom.clear();
    }

    while(true){
        string a;
        cin>>a;
        if(a=="help"){
            cout<<"commands: tab, titul, add_line, delete_line, add_column, delete_last_column";
            cout<<endl;
        }
        if(a=="titul"){
            database.get_titul(line, column);
            cout<<endl;
        }
        if(a=="tab"){
            database.show_tab(line, strok, column);
            cout<<endl;
        }
        if(a=="add_line"){
            database.add_new_line();
            strok++;
            cout<<endl;
        }
        if(a=="delete_line"){
            database.delete_line();
            strok--;
            cout<<endl;
        }
        if(a=="add_column"){
            database.add_new_column(strok);
            column++;
            cout<<endl;
        }
        if(a=="delete_last_column"){
            database.delete_last_column(strok);
            column--;
            cout<<endl;
        }
    }

    fin.close();
    return 0;
}

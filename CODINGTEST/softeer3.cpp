//
//  softeer3.cpp
//  cpp
//
//  Created by Gukhee Jo on 5/30/23.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Car
{
    string name;
    int flag;
    string type;
    int num;
    int start;
    int end;
};

struct Car car[10] = {
    {"Tuscani", 1, "Coupe", 2, 196801, 198004},
    {"Porder", 1, "Truck", 3, 197702, 200405},
    {"Cortina", 1, "Sedan", 5, 196801, 198004},
    {"Elantra", 1, "Sedan", 5, 199010, 199512},
    {"Equus", 1, "Sedan", 5, 199904, 200912},
    {"Grandeur", 0, "Sedan", 5, 198607, 202305},
    {"Pony", 1, "Sedan", 5, 197512, 198201},
    {"SantaFe", 0, "RV", 7, 200006, 202305},
    {"Aerotown", 0, "Bus", 30, 199406, 202305},
    {"Universe", 0, "Bus", 45, 200612, 202305}
};
char* solution(char* param0, int param1) {
    string peri(param0);
    int period = stoi(peri.substr(0, 7));
//    cout << stoi(result);
    string res = "";
    
    for(int i=0;i<10;i++){
        if (period >= car[i].start && period <= car[i].end && param1 <= car[i].num){
            if(res!="") res+=",";
            
            res += car[i].name;
            if (car[i].flag==0) res+="*";
            res+="("+car[i].type+")";
        }
    }
    cout << res;
    char ch[1000];
    
    return strcpy(ch,res.c_str());;
}

int main() {
    char input[100];
    char num_str[100];
    cin.getline(input, 100);
    
    char separator = ',';
    
    int l = strlen(input);
//    cout << l;
        for (int i=0;i<l;i++){
        if (input[i] == ','){
            input[i] = '\n';
            strcpy(num_str, input+i+1);
            break;
        }
    }
    string str1(num_str);

    int num = stoi(str1);
//    cout << num;
    solution(input, num);


    return 0;
}


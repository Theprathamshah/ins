#include<bits/stdc++.h>
using namespace std;


string encryption(string text,string key,vector<vector<char>>arr){
    string encryptedString;
    multimap<char,char>map;
    int i = 0;
    for(int j = 0;j<text.size();j++){
        encryptedString.push_back(arr[text[j]-97][key[i]-97]);
        i = (i+1)%key.length();
    }
    return encryptedString;
}

string decryption(string text,string key,vector<vector<char>>arr){
    string normalString;
    int j = 0;
    for(int i = 0;i<text.size();i++){
        char ch = key[j];
        for(int k = 0;k<26;k++){
            if(text[i]==arr[ch-97][k]){
                normalString.push_back(k+97);
                break;
            }
        }
        j = (j+1)%key.length();
    }
    return normalString;
}

int  main(){
    vector<vector<char>>arr(26,vector<char>(26));
    string temporary = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0;i<26;i++){
        for(int j = 0;j<26;j++){
            arr[i][j] = temporary[(i+j)%26];
        }
    }
    cout<<"Enter a plain text" <<endl;
    string text;
    cin>>text;
    cout<<"Enter a key"<<endl;
    string key;
    cin>>key;
    string encryptedString = encryption(text,key,arr);
    cout<<"Encrypted String is "<<encryptedString<<endl;
    string decryptedString = decryption(encryptedString,key,arr);
    cout<<"Decrypted string is "<<decryptedString<<endl;

    if(text==decryptedString){
        cout<<"Code is correct"<<endl;
    }else{
        cout<<"There are bugs in the code"<<endl;
    }
    return 0;
}

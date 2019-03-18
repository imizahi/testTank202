#include "Fileworker.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "tank.h"
using namespace std;
/*void Fileworker::setFilename(Tank &othertank)
{
    m_filename = othertank.getName();
}*/
void Fileworker::setData()
{
    cout<<" enter TEXT "<<endl;
    cin.getline(m_data,Len);   //оператор доступу
}
//FAT-file alocation table
//NTFS-New table file system
void Fileworker::write()
{
   FILE *f = fopen(m_filename,"wt");
   int realLen = strlen(m_data);
   fwrite(m_data,sizeof(char),realLen,f);
   fclose(f);
   cout<<"file has been written!\n";

}
 void Fileworker::readFromFile()
 {
     FILE *f = fopen(m_filename,"rt");
     strcpy (m_data,"");
     fread(m_data,sizeof(char),Len,f);
     fclose(f);
     cout<<"DATA from file \n";
     cout<<m_data<<endl;
 }
 Fileworker::Fileworker(){
     strcpy(m_filename,"temp.txt");
     strcpy(m_data,"");
     cout<<"constructor"<<endl;
 }

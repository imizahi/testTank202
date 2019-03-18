#ifndef FILEWORKER_H
#define FILEWORKER_H
const int Len = 100;

class Fileworker
{
    char m_filename[Len];
    char m_data[Len];
public:
    Fileworker();
   // void setFilename(Tank &othertank);
    void write();
    void setData();
    void readFromFile();
};

#endif // FILEWORKER_H

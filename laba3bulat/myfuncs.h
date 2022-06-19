#ifndef my_func_h
#define my_func_h

double** inputFromConsole(int* sizeOfData);
double** inputFromFile(int* sizeOfData, std::ifstream& fin);
char getWay();
double getValue();
bool getNext();
void Task(double** arr, int size, std::ostream& f);
#endif 

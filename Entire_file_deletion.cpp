#include <iostream>
#include <fstream>

int main()
{
    std::ofstream obj("example.txt");
    obj << "asd";
    obj.close();
    std::string fileName = "example.txt";
    // std::remove(fileName.c_str()); // remove the entire file
    std::cout<<fileName.c_str();
    if (std::remove(fileName.c_str()) != 0)
    {
        std::cout << "Error deleting file" << std::endl;
    }
    else
    {
        std::cout << "File " << fileName << " successfully deleted" << std::endl;
    }
    return 0;
}

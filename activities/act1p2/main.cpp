/*
Nombre: Actividad 1.2 -    
        Implementación de la técnica de programación 
        "Programación dinámica" y "algoritmos avaros"
Descripción: Actividad para generar práctica de "Programación Dinámica"
                y "Algoritmos Avaros".
Autor: Jeshua Nava Avila | A01639282
Fecha de creación y modificación: 23/08/2022 - XX/08/2022
*/
#include <iostream>
#include <vector>

void readData (std::vector<int>& validCoins, int n)
{
    int data = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> data;
        validCoins.push_back(data);
    }
}

int main (int argc, char *argv[])
{
    std::vector<int> validCoins;
    int n = 0;
    // Read amount of arguments/valid coins inputs, and the values of the coins.
    std::cin >> n;
    readData(validCoins, n);
    std::cout << "Amount of valid coins: " << n << "\nValid coins: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << validCoins[i] << " ";
    }
    return 0;
}
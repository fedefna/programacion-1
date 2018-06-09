#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char buffer[4][50];
    pFile = fopen("data.csv", "r");

    if(pFile == NULL)
    {
        printf("Error al abrir el fichero\n");
        exit(1);
    }

    while(!feof(pFile))
    {
        cant = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n] \n", buffer[0], buffer[1], buffer[2], buffer[3]);

        if( cant != 4)
        {
            cant = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n] \n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(feof(f))
            {
                break;
            }
            else
            {
                printf("Problema para leer el archivo\n");

                break;
            }
        }
        id = atoi(idCad);
        anio = atoi(anioCad);

        auto1.id = id;
        auto1.anio = anio;
        strcpy(auto1.marca, marca);
        strcpy(auto1.modelo, modelo);
        strcpy(auto1.color, color);



        printf("n1=%d n2=%s n3=%s n=%d modelo:%s\n",  auto1.id,  auto1.marca,  auto1.color,  auto1.anio,  auto1.modelo);

    }

    printf("\n\n");

    fclose(f);
    return 0;
}

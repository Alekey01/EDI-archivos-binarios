#include <stdio.h>
#include <conio.h>

void capturaAlumnos(FILE *arch, int alumnos);
void alumnosArreglo(FILE *arch, int alumno, int calificaciones[25]);
float calculaPromedio(int calif[25], int alumnos);

int main()
{
    FILE *archivo, *archivo2;
    int alumnos;
    int calificaciones[25];
    int promedio;

    printf("¿Cuantos alumnos vas a capturar?");
    scanf("%d", &alumnos);

    archivo = fopen("Alumnos.dat", "wb");
    capturaAlumnos(archivo, alumnos);

    archivo2 = fopen("Alumnos.dat", "rb");
    alumnosArreglo(archivo2, alumnos, calificaciones);

    promedio = calculaPromedio(calificaciones, alumnos);

    printf("El promedios de los alumnos es: %d", promedio);

    getch();
    return 0;
}

void capturaAlumnos(FILE *arch, int alumno)
{
    char nombre[50];
    int calificacion;


    for (int i = 0; i < alumno; i++)
    {
        printf("Dame el nombre del alumno: ");
        scanf("%s", nombre);

        printf("Dame la calificación: ");
        scanf("%d", &calificacion);
        
        fwrite(nombre, sizeof(char), 1, arch);
        fwrite(&calificacion, sizeof(int), 1, arch);
    }
     
    fclose(arch);

}

void alumnosArreglo(FILE *arch, int alumno, int calificaciones[25])
{
    char nombre[50];


    for (int i = 0; i < alumno ; i++)
    {
        fread(&nombre, sizeof(char), 1, arch);
        fread(&calificaciones[i], sizeof(int), 1, arch);

    }
    
    fclose(arch);
}

float calculaPromedio(int calif[25], int alumnos)
{
    float prom = 0;

    for(int i = 0; i < alumnos; i++)
    {
        prom = prom + calif[i];

    }
    prom = prom / alumnos;

    return prom;
}

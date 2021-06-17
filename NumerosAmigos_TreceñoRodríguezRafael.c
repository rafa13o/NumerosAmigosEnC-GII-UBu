/**
 * Programa que compruebe si dos números introducidos por teclado son amigos. 
 * Dos números enteros positivos son amigos cuando la suma de los divisores del primero es igual al del segundo.
 * 
 * @author TRECEÑO RODRÍGUEZ, RAFAEL (rafa13o)
 * @version 1.0
 * @date 19-04-2021 Monday
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Funciones
int introducirDatos(int);
int sumaDivisores(int);
bool comprobarUnicos(int, int);
bool comprobarAmigos(int, int);
bool esDivisorExacto(int, int);

int main()
{
    int numero1, numero2;
    int unicos = 0; // 0 significa que es falso (son los mismos números)

    do
    {
        numero1 = introducirDatos(1);
        numero2 = introducirDatos(2);
        unicos = comprobarUnicos(numero1, numero2);
    } while (unicos == 0);

    if (comprobarAmigos(numero1, numero2))
        printf("%d y %d son amigos\n\n", numero1, numero2);
    else
        printf("%d y %d NO son amigos\n\n", numero1, numero2);

    return 0;
}

/**
 * Solicita al usuario un número, comrpueba si es un número entero positivo
 * 
 * @param numero es el número que se va a pedir (el primero=1, el segundo=2)
 * @return el dato que ha dado el usuario
 */
int introducirDatos(int numero)
{
    int entradaUsuario;
    bool esPositivo = false;

    do
    {
        if (numero == 1)
            printf("Dame el primer número --> ");
        else
            printf("Dame el segundo número --> ");

        scanf("%d", &entradaUsuario); // Leo la entrada del usuario

        if (entradaUsuario <= 0)
        {
            printf("Por favor, introduzca un número válido. El número debe ser un entero positivo\n");
            esPositivo = false;
        }
        else
            esPositivo = true;
    } while (!esPositivo);

    return entradaUsuario;
}

/**
 * Comprueba si los números que se han dado son distintos
 * 
 * @param numero1 el primer número que ha dado el usuario
 * @param numero2 el segundo número
 * @return false si los dos números son iguales, true en caso contrario
 */
bool comprobarUnicos(int numero1, int numero2)
{
    if (numero1 == numero2)
    {
        printf("Los dos números son iguales.\nPor favor, introduzca dos números distintos\n");
        return false;
    }
    else
        return true;
}

/**
 * Comprueba si dos números son amigos o no
 * 
 * @param numero1 el primer número que dio el usuario
 * @param numero2 el segundo número que dio el usuario
 * @return true si son números amigos, false en caso contrario
 */
bool comprobarAmigos(int numero1, int numero2)
{
    int sumaNumero1, sumaNumero2;

    sumaNumero1 = sumaDivisores(numero1);
    sumaNumero2 = sumaDivisores(numero2);

    if (sumaNumero1 == sumaNumero2) // Son números amigos
        return true;
    else // No son números amigos
        return false;
}

/**
 * Realiza la suma de los divisores de un número
 * 
 * @param numero el número del que se quiere hallar la suma de sus divisores
 * @return la suma de los divisores
 */
int sumaDivisores(int numero)
{
    int suma = 0;

    for (int i = numero; i >= 1; i--)
    {
        if (esDivisorExacto(numero, i))
            suma += i;
    }

    return suma;
}


/**
 * Comprueba si una división es exacta o no
 * 
 * @param dividendo el dividendo de la división
 * @param divisor el divisor de la división
 * @return true si el resto es 0 (es una división exacta), false en caso contrario
 */
bool esDivisorExacto(int dividendo, int divisor)
{
    if (dividendo % divisor == 0) // Resto 0, es divisor exacto
        return true;
    else // resto 1, no es divisor exacto
        return false;
}
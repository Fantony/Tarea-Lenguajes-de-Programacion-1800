
# Analizador Léxico

Este proyecto consiste en la creación de un analizador léxico basandonos en las reglas dadas por la *Gramatica libre de Contexto* para la *(BNF)* y los *autómatas finitos* creados y desarrollados como asignación de la clase

## Software Necesario 

- - - 

Compilador de C++ para correr el programa   
[GCC](https://gcc.gnu.org/)

- - -

# Sintaxis del lenguaje
A continuación sé mostrará las reglas, patrones y secuencias gramaticales para el correcto funcionamiento de este lenguaje de programación


## Estructura Básica de un programa
Los programas en nuestro lenguaje podrán comenzar con la palabra reservada `Programa` luego el nombre del programa, quien deberá cumplir una regla que es comenzar estrictamente con una letra Mayúscula, por ejemplo `HolaMundo` seguido de la apertura de llaves `{`, al finalizar el programa tendrá el cierre de llaves `}` para indicar que el programa ha culminado su ejecución.
```bash
Programa HolaMundo {

    Fn _Principal(){
        Mostrar "Hola Mundo";
    }

}
```
## Mi primer programa
El nombre del programa definido por el usuario como se menciona anteriormente, solo tiene la restricción que el `primer carácter` debe ser una `letra Mayúscula` y si `luego` de este el usuario ingresa más `caracteres`, estos podrán ser `alfanuméricos` (letras del alfabeto mayúsculas, minúsculas y los números), también los nombres de las funciones en este lenguaje deberán seguir la misma regla definida para el nombre del programa exceptuando que la `función base` de todos los programas creados comenzara con un guion bajo `"_"` seguido de la palabra reservada `Principal`
```bash
Programa MiPrimErprOgraMa {

    Fn Principal(){
        Mostrar "Mi primer Programa";
    }

}
```
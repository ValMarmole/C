#include <stdio.h>
int arreglo[5]; 
int cant = 5;
int i, x, m, modi, modif, va, operacion, opcOrdenar, opci, max;

void insertar(const int arreglo[], va, max) {
  if (arreglo[0] == 0) { 
    for (i = 0; i < 5; i++) {
      printf("Favor de ingresar un numero entero %d: ", i);
      scanf("%d", &arreglo[i]);
    }
  } else if (arreglo[0] !=
             0) { 
                
    for (i = 0; i < 5; i++) {
      if (arreglo[i] == 0) {
        va = va + 0;
      } else {
        va = va + 1;
      }
    }
    printf("\nva %d: ", i);
    if (va == 5) {
      printf("\nArreglo lleno \n\n");
    } else {
      for (i = 0; i < 5; i++) {
        if (arreglo[i] == 0) {
          printf("\nLlenar lugar %d ", i);
          printf("\nIngrese un numero entero: %d: ", i);
          scanf("%d", &arreglo[i]);
        }
      }
      printf("\nEl arreglo final es: ");

      for (i = 0; i <5; i++) {
        printf("\n %d ", arreglo[i]);
      }
    }
  }
}

int buscarEnArreglo(const int arreglo[], int busq, int longi) {
  for (int x = 0; x < longi; x++) {
    if (arreglo[x] == busq)
      return x;
  }
  return -1;
}

void ordenar(opcOrdenar) {
  printf("\n1.Orden ascendente");
  printf("\n2.Orden descendente");
  printf("\nElija una opcion=");
  scanf("%d", &opcOrdenar);
  switch (opcOrdenar) {
  case 1:
    for (i = 0; i < 5 - 1; i++) {
      for (m = 0; m < 5 - 1; m++) {
        if (arreglo[m] > arreglo[m + 1]) {
          max = arreglo[m];
          arreglo[m] = arreglo[m + 1];
          arreglo[m + 1] = max;
        }
      }
    }
    for (i = 0; i < 5; i++) {
      printf("\n %d ", arreglo[i]);
    }
    break;
  case 2:
    for (i = 0; i < 5 - 1; i++) {
      for (m = 0; m <5 - 1; m++) {
        if (arreglo[m] < arreglo[m + 1]) {
          max = arreglo[m];
          arreglo[m] = arreglo[m + 1];
          arreglo[m + 1] = max;
        }
      }
    }
    for (i = 0; i < 5; i++) {
      printf("\n %d ", arreglo[i]);
    }
    break;
  defalul:
    printf("\nOpcion invalida, por favor verifique\n");
  }
}


int main(void) {
  int busq;
  int existe;
  int longi = sizeof arreglo;
  max = 0;

  
  do {
    printf("\n***Menu***\n");
    printf("\n1. Agregar elementos al arreglo");
    printf("\n2. Quitar uno o todos los elementos del arreglo");
    printf("\n3. Modificar el arreglo");
    printf("\n4. Buscar dentro del arreglo");
    printf("\n5. Orden ascendente o descendente para el arreglo");
    printf("\n6. Salir del arreglo");
    printf("\n***Elija una opcion del menu ");
    scanf("%d", &operacion);
    switch (operacion) {
    case 1:
      insertar(arreglo, va, max);
      break;

    case 2:
      printf("\n 1.Eliminar un elemento");
      printf("\n 2.Eliminar todos los elementos");
      printf("\nElija un opcion: ");
      scanf("%d", &opci);
      switch (opci) {
      case 1:
        printf("Ingrese el numero que desee eliminar: ");
        scanf("%d", &opcOrdenar);
        for (m = 0; m <5; m++) {
          if (m == opcOrdenar) {
            while (m < cant - 1) {
              arreglo[m] = arreglo[m + 1];
              m++;
            }

            break;
          }
        }
        arreglo[5] = 0;
        printf("\nEl arreglo final es: ");
        for (i = 0; i < 5; i++) {
          printf("\n %d ", arreglo[i]);
        }
        break;
      case 2:
        for (i = 0; i < 5; i++) {
          if (arreglo[i] != 0) {
            arreglo[i] = 0;
          }
        }
        printf("\nLos elementos han sido eliminados\n");
        for (i = 0; i <5; i++) {
          printf("\n %d ", arreglo[i]);
        }
        break;
      }
      break;
    case 3: 
      if (arreglo[0] == 0) {
        printf("\n El arreglo esta vacio, no hay mas cambios por hacer\n");
      } else {
        printf("Ingrese el lugar a modificar: ");
        scanf("%d", &modi);
        for (i = 0; i < 5; i++) {
          if (i == modi) {
            printf("\nIngrese el valor nuevo en el arreglo: ");
            scanf("%d", &modif);
            arreglo[i] = modif;
          }
        }
        printf("\nEl arreglo final es: ");
        for (i = 0; i < 5; i++) {
          printf("\n %d ", arreglo[i]);
        }
      }
      break;

    case 4: 
      if (arreglo[0] == 0) {
        printf("\nEl lugar esta vacio, no se puede buscar nada mas\n");
      } else {
        printf("\nIngrese el valor que desea buscar: ");
        scanf("%d", &busq);
        existe = buscarEnArreglo(arreglo, busq, longi);
        if (existe == -1) {
          printf("\nValor inexistente\n");
        } else {
          printf("\n Posicion: %d que se localiza en el arreglo: %d \n", busq, existe);
        }
      }
      break;
    case 5: 
      if (arreglo[0] == 0) {
        printf("\n No existen elementos a ordenar, el arreglo se encuentra vacio \n");
      } else {
        ordenar(arreglo);
      }
      main();
      break;
    case 6:
         printf("\nUsted ha salido del arreglo\n"); 
  exit(-1);
      break;
    default:
      printf("\nIngrese un valor valido\n");
      break;
    }

  } while (operacion != 5);

}


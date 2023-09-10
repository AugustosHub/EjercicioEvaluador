/*
Una empresa ha decidido invertir en la contratación de personal informático  para que desarrolle un sistema que permita gestionar el stock.
La información a recoger  será: nombre del producto, precio y cantidad en stock. Actualmente la empresa cuenta  con 10 productos distintos.
El programa debe ser capaz de:
Dar de alta un producto nuevo.
Buscar un producto por su nombre.
Modificar el stock y precio de un producto dado.
*/

#include <stdio.h>
#include <stdlib.h>
#include<wchar.h>
#include<locale.h>
#include<time.h>
#include<unistd.h>
#include<string.h>

struct info{
    char nombre[50];
    int cantidad;
    float precio;
    int codigo;
}Productos[10];

struct infoProv{
    char nombre[50];
    char direccion[50];
    char telefono[20];
    int codigo;
}Proveedores[10];

struct infoCliente{
    char nombre[50];
    char producto[50];
    int cantidad;
    char factura[50];
    float monto;
}Clientes[100];

void InicializarPrograma(struct Productos *info,struct Proveedores *infoProv, int *lugares, int *lugaresProv, struct Clientes *infoCliente, int *lugaresCli){
        system("cls");
        for(int i=0;i<10;i++){
            strcpy(Productos[i].nombre, "-");
            Productos[i].cantidad = 0;
            Productos[i].precio = 0;
            Productos[i].codigo = 0;
            lugares[i]=0;
        }
        for(int i=0;i<10;i++){
            strcpy(Proveedores[i].nombre, "-");
            strcpy(Proveedores[i].nombre, "-");
            strcpy(Proveedores[i].nombre, "-");
            Proveedores[i].codigo = 0;
            lugaresProv[i]=0;
        }
        for(int i=0;i<10;i++){
            printf("Producto N°%d: \n",i+1);
            printf("Nombre del producto: %s\n",Productos[i].nombre);
            printf("Cantidad de %s: %d\n",Productos[i].nombre,Productos[i].cantidad);
            printf("Precio de %s: %.1f\n",Productos[i].nombre,Productos[i].precio);
            puts("---------------------------");
        }
        for(int i=0;i<10;i++){
            printf("Proveedor N°%d: \n",i+1);
            printf("Nombre del proveedor: %s\n",Proveedores[i].nombre);
            printf("Dirección del proveedor: %s\n",Proveedores[i].nombre);
            printf("Telefono del proveedor: %s\n",Proveedores[i].nombre);
            puts("---------------------------");
        }
        for(int i=0;i<100;i++){
            strcpy(Clientes[i].nombre, "-");
            strcpy(Clientes[i].factura, "-");
            strcpy(Clientes[i].producto, "-");
            Clientes[i].monto = 0;
            Clientes[i].cantidad = 0;
            lugaresCli[i] = 0;
        }
        for(int i=0;i<100;i++){
            printf("Cliente N°%d: \n",i+1);
            printf("Nombre del cliente: %s\n",Clientes[i].nombre);
            printf("Producto vendido: %s\n",Clientes[i].producto);
            printf("Cantidad vendida de %s: %i",Clientes[i].producto,Clientes[i].cantidad);
            printf("Tipo de factura: %s\n",Clientes[i].factura);
            printf("Monto de la venta: %.1f\n",Clientes[i].monto);
            puts("---------------------------");
        }
            system("cls");
            puts("¡Programa Inicializado con éxito!");
            puts("------------------------------");
            system("pause");
}

void AgregarProveedor(struct Proveedores *infoProv, int *lugaresProv){
    int op,k,j=1;
    int codigoProveedor;
    int codigoRepetido;

        puts("Lugares disponibles: \n");
        for(int i=0;i<10;i++){
            if(lugaresProv[i]==0){
                printf("%d. Lugar disponible\n",i+1);
                j = j + 1;
            }else{
                printf("%d. Lugar Ocupado\n",i+1);
                j = j + 1;
            }
        }
        printf("%d. Salir\n",j);
        puts("--------------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        if(op==j){
            system("cls");
            puts("Volviendo al menú...");
            sleep(2);
            return 0;
        }else{
            for(int i=0;i<10;i++){
                if((op-1)==i){
                    if(lugaresProv[i]==0){
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese el nombre del proveedor: ");
                        gets(Proveedores[i].nombre);
                        fflush(stdin);
                        printf("Ingrese la dirección %s: ",Proveedores[i].nombre);
                        gets(Proveedores[i].direccion);
                        fflush(stdin);
                        printf("Ingrese el telefono de %s: ",Proveedores[i].nombre);
                        gets(Proveedores[i].telefono);
                        printf("Ingrese el código del proveedor: ");
                        scanf("%d",&codigoProveedor);

                        do{
                            codigoRepetido = 0;
                            for (int k = 0; k < 10; k++) {
                                if (codigoProveedor == Proveedores[k].codigo) {
                                    puts("-----------------------------------------------------");
                                    printf("El código %d ya está en uso. Ingrese otro código.\n", codigoProveedor);
                                    puts("-----------------------------------------------------");
                                    codigoRepetido = 1;
                                    break;
                                }
                            }
                            if (codigoRepetido){
                                printf("Ingrese el código del proveedor: ");
                                scanf("%d",&codigoProveedor);
                            }
                        } while (codigoRepetido);
                        Proveedores[i].codigo = codigoProveedor;

                        lugaresProv[i]=1;
                        puts("------------------------------------");
                        system("pause");
                        system("cls");
                        puts("¡Proveedor agregado con éxito!");
                        puts("------------------------------------");
                        system("pause");
                    }else{
                        system("cls");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("El lugar está ocupado, intente con otro...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        system("pause");
                    }
                }
            }
        }
}

void AgregarProducto(struct Productos *info, int *lugares, struct Proveedores *infoProv, int *lugaresProv){
        int op,j=1;
        int codigoProveedor;

        puts("Lugares disponibles: \n");
        for(int i=0;i<10;i++){
            if(lugares[i]==0){
                printf("%d. Lugar disponible\n",i+1);
                j = j + 1;
            }else{
                printf("%d. Lugar Ocupado\n",i+1);
                j = j + 1;
            }
        }
        printf("%d. Salir\n",j);
        puts("--------------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        if(op==j){
            system("cls");
            puts("Volviendo al menú...");
            sleep(2);
            return 0;
        }else{
            for(int i=0;i<10;i++){
                if((op-1)==i){
                    if(lugares[i]==0){
                        system("cls");
                        fflush(stdin);
                        printf("Ingrese el nombre del producto: ");
                        gets(Productos[i].nombre);
                        printf("Ingrese la cantidad del producto: ");
                        scanf("%d",&Productos[i].cantidad);
                        printf("Ingrese el precio del producto: ");
                        scanf("%f",&Productos[i].precio);

                        int codigoValido = 0;
                        do{
                            printf("Ingrese el código del proveedor: ");
                            scanf("%d",&codigoProveedor);

                            for (int k = 0; k < 10; k++) {
                                if (codigoProveedor == Proveedores[k].codigo) {
                                    puts("----------------------------------------------");
                                    printf("El código es valido corresponde al proveedor: %s\n",Proveedores[k].nombre);
                                    puts("----------------------------------------------");
                                    codigoValido = 1;
                                    break;
                                }
                            }
                            if (!codigoValido){
                                puts("------------------------------------------------------");
                                puts("El código del proveedor no existe. Intente de nuevo...");
                                puts("------------------------------------------------------");
                            }
                        }while(!codigoValido);
                        Productos[i].codigo = codigoProveedor;
                        lugares[i]=1;
                        system("pause");
                        system("cls");
                        puts("¡Producto agregado con éxito!");
                        puts("-----------------------------");
                        system("pause");
                    }else{
                        system("cls");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("El lugar está ocupado, intente con otro...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        system("pause");
                    }
                }
            }
        }
}

void MostrarProveedores(struct Proveedores *infoProv, int *lugaresProv){
    int op,j=1;
        system("cls");
        puts("Proveedores disponibles:\n");
        for(int i=0;i<10;i++){
            if(lugaresProv[i]==0){
                printf("%d. Lugar disponible\n",i+1);
                j = j + 1;
            }else{
                printf("%d. %s\n",i+1,Proveedores[i].nombre);
                j = j + 1;
            }
        }
        printf("%d. Salir\n",j);
        puts("--------------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        if(op==j){
            system("cls");
            puts("Volviendo al menú...");
            sleep(2);
            return 0;
        }else{
            for(int i=0;i<10;i++){
                if((op-1)==i){
                    if(lugaresProv[i]==1){
                        system("cls");
                        printf("Proveedor N°%d:\n ",i+1);
                        printf("Nombre del proveedor: %s\n",Proveedores[i].nombre);
                        printf("Direccion de %s: %s\n",Proveedores[i].nombre,Proveedores[i].direccion);
                        printf("Telefono de %s: %s\n",Proveedores[i].nombre,Proveedores[i].telefono);
                        printf("Código del proveedor: %d\n",Proveedores[i].codigo);
                        puts("------------------------------------");
                        system("pause");
                    }else{
                        system("cls");
                        puts("Vacio, nada para mostrar...");
                        puts("------------------------------------");
                        system("pause");
                    }

                }
            }
    }
}

void MostrarProductos(struct Productos *info,int *lugares){
    int op,j=1;
        system("cls");
        puts("Productos disponibles: \n");
        for(int i=0;i<10;i++){
            if(lugares[i]==0){
                printf("%d. Lugar disponible\n",i+1);
                j = j + 1;
            }else{
                printf("%d. %s\n",i+1,Productos[i].nombre);
                j = j + 1;
            }
        }
        puts("--------------");
        printf("%d. Salir\n",j);
        puts("--------------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        if(op==j){
            system("cls");
            puts("Volviendo al menú...");
            sleep(2);
            return 0;
        }else{
            for(int i=0;i<10;i++){
                if((op-1)==i){
                    if(lugares[i]==1){
                        system("cls");
                        printf("Producto N°%d: ",i+1);
                        printf("Nombre del producto: %s\n",Productos[i].nombre);
                        printf("Cantidad del producto: %d\n",Productos[i].cantidad);
                        printf("Precio del producto: $%.1f\n",Productos[i].precio);
                        printf("Código del proveedor: %d\n\n",Productos[i].codigo);
                        puts("------------------------------------");
                        system("pause");
                    }else{
                        system("cls");
                        puts("Vacio, nada para mostrar...");
                        puts("------------------------------------");
                        system("pause");
                    }

                }
            }
        }
}

void ModificarProducto(struct Productos *info,int *lugares, struct Proveedores *infoProv, int *lugaresProv){
    int op,j=1;
    int codigoProveedor;
        system("cls");

        puts("Productos disponibles: \n");
        puts("\n¿Cuál desea modificar?\n");

        for(int i=0;i<10;i++){
            if(lugares[i]==0){
                printf("%d. Lugar disponible\n",i+1);
                j = j + 1;
            }else{
                printf("%d. %s\n",i+1,Productos[i].nombre);
                j = j + 1;
            }
        }
        puts("--------------");
        printf("%d. Salir\n",j);
        puts("--------------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        if(op==j){
            system("cls");
            puts("Volviendo al menú...");
            sleep(2);
            return 0;
        }else{
            for(int i=0;i<10;i++){
                if((op-1)==i){
                    system("cls");
                    puts("¿Desea modificarlo o eliminarlo?");
                    puts("1. Modificar");
                    puts("2. Eliminar");
                    puts("--------------");
                    puts("3. Salir");
                    puts("-----------------");
                    printf("Elegir opción: ");
                    scanf("%d",&op);

                    while(op>3 || op<1){
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("Opción invalida, intente de nuevo...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("Elegir opción: ");
                        scanf("%d",&op);
                    }

                    switch(op){
                        case 1:
                            if(lugares[i]==1){
                                system("cls");
                                fflush(stdin);
                                printf("Ingrese el nombre del producto: ");
                                gets(Productos[i].nombre);
                                printf("Ingrese la cantidad del producto: ");
                                scanf("%d",&Productos[i].cantidad);
                                printf("Ingrese el precio del producto: ");
                                scanf("%f",&Productos[i].precio);

                                int codigoValido = 0;
                                do{
                                    printf("Ingrese el código del proveedor: ");
                                    scanf("%d",&codigoProveedor);

                                    for (int k = 0; k < 10; k++) {
                                        if (codigoProveedor == Proveedores[k].codigo) {
                                            puts("----------------------------------------------");
                                            printf("El código es valido corresponde al proveedor: %s\n",Proveedores[k].nombre);
                                            puts("----------------------------------------------");
                                            codigoValido = 1;
                                            break;
                                        }
                                    }
                                    if (!codigoValido){
                                        puts("------------------------------------------------------");
                                        puts("El código del proveedor no existe. Intente de nuevo...");
                                        puts("------------------------------------------------------");
                                    }
                                }while(!codigoValido);

                                Productos[i].codigo = codigoProveedor;
                                lugares[i]=1;
                                system("pause");
                                system("cls");
                                puts("¡Producto agregado con éxito!");
                                puts("-----------------------------");
                                system("pause");
                            }else{
                                system("cls");
                                puts("El lugar se encuentra vacio");
                                puts("------------------------------------");
                                system("pause");
                            }
                            break;
                        case 2:
                            strcpy(Productos[i].nombre, "-");
                            Productos[i].cantidad = 0;
                            Productos[i].precio = 0;
                            lugares[i]=0;

                            puts("¡Producto eliminado con éxito!");
                            puts("------------------------------");
                            system("pause");
                            break;
                        case 3:
                            return 0;
                            break;
                    }

                }
            }
        }
}

void ModificarProveedores(struct Proveedores *infoProv, int *lugaresProv){
    int op,j=1;
    int codigoProveedor,codigoRepetido;

        system("cls");

        puts("Proveedores disponibles: \n");
        puts("\n¿Cuál desea modificar?\n");

        for(int i=0;i<10;i++){
            if(lugaresProv[i]==0){
                printf("%d. Lugar disponible\n",i+1);
                j = j + 1;
            }else{
                printf("%d. %s\n",i+1,Proveedores[i].nombre);
                j = j + 1;
            }
        }
        puts("--------------");
        printf("%d. Salir\n",j);
        puts("--------------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        if(op==j){
            system("cls");
            puts("Volviendo al menú...");
            sleep(2);
            return 0;
        }else{
            for(int i=0;i<10;i++){
                if((op-1)==i){
                    system("cls");
                    puts("¿Desea modificarlo o eliminarlo?");
                    puts("1. Modificar");
                    puts("2. Eliminar");
                    puts("--------------");
                    puts("3. Salir");
                    puts("-----------------");
                    printf("Elegir opción: ");
                    scanf("%d",&op);

                    while(op>3 || op<1){
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("Opción invalida, intente de nuevo...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        printf("Elegir opción: ");
                        scanf("%d",&op);
                    }

                    switch(op){
                        case 1:
                            if(lugaresProv[i]==1){
                                system("cls");
                                fflush(stdin);
                                printf("Ingrese el nombre del proveedor: ");
                                gets(Proveedores[i].nombre);
                                fflush(stdin);
                                printf("Ingrese la dirección de %s: ",Proveedores[i].nombre);
                                gets(Proveedores[i].direccion);
                                printf("Ingrese el telefono de %s: ",Proveedores[i].nombre);
                                fflush(stdin);
                                gets(Proveedores[i].telefono);
                                printf("Ingrese el código del proveedor: ");
                                scanf("%d",&codigoProveedor);

                                do{
                                    codigoRepetido = 0;
                                    for (int k = 0; k < 10; k++) {
                                        if (codigoProveedor == Proveedores[k].codigo) {
                                            puts("-----------------------------------------------------");
                                            printf("El código %d ya está en uso. Ingrese otro código.\n", codigoProveedor);
                                            puts("-----------------------------------------------------");
                                            codigoRepetido = 1;
                                            break;
                                        }
                                    }
                                    if (codigoRepetido){
                                        printf("Ingrese el código del proveedor: ");
                                        scanf("%d",&codigoProveedor);
                                    }
                                } while (codigoRepetido);
                                Proveedores[i].codigo = codigoProveedor;

                                lugaresProv[i]=1;
                                puts("------------------------------------");
                                system("pause");
                            }else{
                                system("cls");
                                puts("El lugar se encuentra vacio");
                                puts("------------------------------------");
                                system("pause");
                            }
                            break;
                        case 2:
                            strcpy(Proveedores[i].nombre, "-");
                            strcpy(Proveedores[i].direccion, "-");
                            strcpy(Proveedores[i].telefono, "-");
                            lugaresProv[i]=0;

                            puts("¡Proveedor eliminado con éxito!");
                            puts("------------------------------");
                            system("pause");
                            break;
                        case 3:
                            return 0;
                            break;
                    }

                }
            }
        }
}

void BuscarProducto(struct Productos *info, int *lugares){
    int i,intentos = 1;
    char buscador[50];

    system("cls");
    puts("*****************************************");
    fflush(stdin);
    printf("Ingrese el nombre del producto a buscar: ");
    gets(buscador);

    system("cls");
    puts("Buscando...");
    sleep(2);

    for(i=0;i<10;i++){
        if(strcmp(buscador,Productos[i].nombre)==0){
            system("cls");
            puts("¡Encontrado!");
            sleep(2);
            system("cls");
            printf("Producto N°%d: \n",i+1);
            printf("Nombre del producto: %s\n",Productos[i].nombre);
            printf("Cantidad del producto: %d\n",Productos[i].cantidad);
            printf("Precio del producto: $%.1f\n",Productos[i].precio);
            puts("------------------------------------");
            system("pause");
            break;
        }else{
            intentos = intentos + 1;
        }
    }

    if(intentos>10){
        system("cls");
        puts("No se encontró el producto ingresado...");
        puts("---------------------------------------");
        system("pause");
    }

}

void BuscarProveedor(struct Productos *info, struct Proveedores *infoProv,int *lugares, int *lugaresProv){
    int i,j,intentos = 1,intentos2 = 1;
    int buscador;

    system("cls");
    puts("*****************************************");
    fflush(stdin);
    printf("Ingrese el código del proveedor a buscar: ");
    scanf("%d",&buscador);
    system("cls");
    puts("Buscando...");
    sleep(2);

    for(i=0;i<10;i++){
        if(buscador == Proveedores[i].codigo){
            system("cls");
            puts("¡Encontrado!");
            sleep(2);
            system("cls");
            printf("Proveedor N°%d: \n",i+1);
            printf("Nombre del proveedor: %s\n",Proveedores[i].nombre);
            printf("Dirección de %s: %s\n",Proveedores[i].nombre,Proveedores[i].direccion);
            printf("Telefono de %s: %s\n",Proveedores[i].nombre,Proveedores[i].telefono);
            puts("------------------------------------");
            printf("Productos de %s\n",Proveedores[i].nombre);
            puts("------------------------------------");

                for (j = 0; j < 10; j++) {
                    if(buscador == Productos[j].codigo){
                        printf("Producto N°%d: \n", j + 1);
                        printf("Nombre del producto: %s\n", Productos[j].nombre);
                        printf("Cantidad del producto: %d\n", Productos[j].cantidad);
                        printf("Precio del producto: $%.1f\n", Productos[j].precio);
                        puts("-------------------------------------");
                    }else{
                        intentos2 = intentos2 + 1;
                    }
                }
            if(intentos2>10){
                puts("El proveedor no ha comercializado con usted");
                puts("------------------------------------------");
            }
            system("pause");
            break;
        }else{
            intentos = intentos + 1;
        }
    }

    if(intentos>10){
        system("cls");
        puts("No se encontró proveedor o código invalido");
        puts("------------------------------------------");
    }
}

void VenderProducto(struct Productos *info, int *lugares, struct Proveedores *infoProv, int *lugaresProv, struct Clientes *infoCliente, int *lugaresCli){
    int i,j,k,op,intentos = 1,cantidad;
    float monto;
    char buscador[50];

    system("cls");
    puts("*************************************************");
    fflush(stdin);
    printf("Ingrese el producto a vender: ");
    gets(buscador);

    for(i=0;i<10;i++){
        if(strcmp(buscador,Productos[i].nombre)==0){
            puts("--------------------------------------------------");
            strncpy(Clientes[i].producto,buscador, sizeof(Clientes[i].producto));
            printf("¿Cuantos %s quiere vender?\n",Productos[i].nombre);
            printf("Cantidad: ");
            scanf("%d",&cantidad);
            while(cantidad>Productos[i].cantidad){
                puts("--------------------------------------------------");
                printf("¡No hay suficientes %s!\n",Productos[i].nombre);
                puts("Intente con menos cantidad...");
                puts("--------------------------------------------------");
                printf("¿Cuantos %s quiere vender?\n",Productos[i].nombre);
                scanf("%d",&cantidad);
            }
            Productos[i].cantidad = Productos[i].cantidad - cantidad;
            Clientes[i].cantidad = cantidad;
            monto = cantidad * Productos[i].precio;
            puts("--------------------------------------------------");
            system("pause");
            break;
        }else{
            intentos = intentos + 1;
        }
    }

    if(intentos>10){
        system("cls");
        puts("No se encontró el producto ingresado...");
        puts("---------------------------------------");
        system("pause");
        return 0;
    }else{
        system("cls");
        for(j=0;j<100;j++){
            if(lugaresCli[j] == 0){
                fflush(stdin);
                printf("Ingrese el nombre de él/la cliente: ");
                gets(Clientes[j].nombre);
                printf("Ingrese el tipo de factura comercial (ej. A): ");
                gets(Clientes[j].factura);
                printf("El monto de la venta fue: %.1f",monto);
                Clientes[j].monto = monto;
                lugaresCli[j] = 1;
                puts("\n---------------------------------------");
                system("pause");
                system("cls");
                puts("¡Venta realizada con éxito!");
                puts("\n---------------------------------------");
                system("pause");
                return 0;
            }
        }
    }
}

void VerVentas(struct Productos *info, int *lugares, struct Proveedores *infoProv, int *lugaresProv, struct Clientes *infoCliente, int *lugaresCli){
    int op,j=1;
        system("cls");
        puts("Compradores recientes: \n");
        for(int i=0;i<100;i++){
            if(lugaresCli[i]==1){
                printf("%d. %s\n",i+1,Clientes[i].nombre);
                j = j + 1;
            }
        }
        puts("--------------");
        printf("%d. Salir\n",j);
        puts("--------------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>j || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        if(op==j){
            system("cls");
            puts("Volviendo al menú...");
            sleep(2);
            return 0;
        }else{
            for(int i=0;i<10;i++){
                if((op-1)==i){
                    if(lugaresCli[i]==1){
                        system("cls");
                        printf("Venta N°%d:\n",i+1);
                        printf("Nombre del cliente: %s\n",Clientes[i].nombre);
                        printf("Producto vendido a %s: %s\n",Clientes[i].nombre,Clientes[i].producto);
                        printf("Cantidad de %s vendido: %i\n",Clientes[i].producto,Clientes[i].cantidad);
                        printf("Factura realizada: %s\n",Clientes[i].factura);
                        printf("Monto de la venta: $%.1f\n",Clientes[i].monto);
                        puts("------------------------------------");
                        system("pause");
                    }
                }
            }
        }
}

int main()
{
    int op,bandera;
    int inicializacion = 0,agregarProv = 0,agregarProd = 0,Ventas = 0;
    int lugares[10];
    int lugaresProv[10];
    int lugaresCli[100];

    struct infoProv *Proveedores;
    struct infoCliente *Clientes;
    struct info *Productos;

    setlocale(LC_ALL, "");
    srand(time(NULL));

    do{
        system("cls");
        puts("////////////////////");
        puts("//////Tiendita//////");
        puts("////////////////////");
        puts("Menú: ");
        puts("1. Inicializar Programa");
        puts("--------------------");
        puts("Agregar productos/proveedores: ");
        puts("2. Agregar productos");
        puts("3. Agregar proveedores");
        puts("--------------------");
        puts("Ver productos/proveedores: ");
        puts("4. Mostrar productos");
        puts("5. Mostrar proveedores");
        puts("--------------------");
        puts("Modificar/Eliminar: ");
        puts("6. Modificar producto");
        puts("7. Modificar proveedores");
        puts("--------------------");
        puts("Buscadores: ");
        puts("8. Buscar por producto");
        puts("9. Buscar por proveedor");
        puts("--------------------");
        puts("Ventas:");
        puts("10. Vender productos");
        puts("11. Ver ventas");
        puts("--------------------");
        puts("12. Salir");
        puts("--------------------");
        printf("Elegir opción: ");
        scanf("%d",&op);

        while(op>12 || op<1){
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("Opción invalida, intente de nuevo...");
            puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            puts("--------------------");
            printf("Elegir opción: ");
            scanf("%d",&op);
        }

        switch(op){
            case 1:
                if (inicializacion == 0){
                    system("cls");
                    puts("Cargando, espere...");
                    sleep(2);
                    InicializarPrograma(Productos,Proveedores,lugaresProv,lugares,Clientes,lugaresCli);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                    inicializacion = 1;
                    agregarProv = 0;
                    agregarProd = 0;
                    Ventas = 0;
                }else if (inicializacion == 1){
                    system("cls");
                    puts("¡El programa ya está inicializado, si lo vuelve a inicializar borrará todos los registros!");
                    puts("\n¿Desea Continuar?\n");
                    puts("1. Si");
                    puts("2. No");
                    puts("-----------------");
                    printf("Elegir Opción: ");
                    scanf("%d",&op);
                    while(op>2 || op<1){
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("Opción invalida, intente de nuevo...");
                        puts("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
                        puts("--------------------");
                        printf("Elegir opción: ");
                        scanf("%d",&op);
                    }
                    switch(op){
                        case 1:
                            system("cls");
                            puts("Cargando, espere...");
                            sleep(2);
                            InicializarPrograma(Productos,Proveedores,lugaresProv,lugares,Clientes,lugaresCli);
                            system("cls");
                            puts("Volviendo al menú...");
                            sleep(2);
                            inicializacion = 1;
                            agregarProv = 0;
                            agregarProd = 0;
                            Ventas = 0;
                            break;
                        case 2:
                            system("cls");
                            puts("Volviendo al menú...");
                            sleep(2);
                            break;
                    }
                }
                break;
            case 2:
                if(agregarProv !=1 && inicializacion != 1){
                        system("cls");
                        puts("¡Debe inicializar el programa y agregar proveedores!");
                        puts("-------------------------------");
                        system("pause");
                        system("cls");
                        puts("Volviendo al menú");
                        sleep(2);
                    }else if (inicializacion!=1){
                        system("cls");
                        puts("¡Debe inicializar el programa!");
                        puts("-------------------------------");
                        system("pause");
                        system("cls");
                        puts("Volviendo al menú");
                        sleep(2);
                    }else if(agregarProv !=1){
                        system("cls");
                        puts("¡Debe agregar proveedores!");
                        puts("-------------------------------");
                        system("pause");
                        system("cls");
                        puts("Volviendo al menú");
                        sleep(2);
                    }else{
                    system("cls");
                    AgregarProducto(Productos,lugares, Proveedores, lugaresProv);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                    agregarProd = 1;
                    }
                break;
            case 3:
                if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else{
                    system("cls");
                    AgregarProveedor(Proveedores,lugaresProv);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                    agregarProv = 1;
                }
                break;
            case 4:
                if(inicializacion != 1 && agregarProd != 1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar productos!");
                    puts("--------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if(agregarProd!=1){
                    system("cls");
                    puts("¡Debe agregar productos!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else{
                    system("cls");
                    puts("Cargando, espere");
                    sleep(2);
                    MostrarProductos(Productos,lugares);
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }
                break;
            case 5:
                if (inicializacion != 1 && agregarProv !=1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar proveedores");
                    puts("----------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                }else if (agregarProv!=1){
                    system("cls");
                    puts("¡Debe agregar proveedores!");
                    puts("-------------------------------");
                    system("pause");
                }else{
                    system("cls");
                    puts("Cargando, espere");
                    sleep(2);
                    MostrarProveedores(Proveedores,lugaresProv);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }
                break;
            case 6:
                if(inicializacion != 1 && agregarProd != 1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar productos!");
                    puts("--------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if(agregarProd!=1){
                    system("cls");
                    puts("¡Debe agregar productos!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else{
                    system("cls");
                    puts("Cargando, espere...");
                    sleep(2);
                    ModificarProducto(Productos,lugares,Proveedores,lugaresProv);
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }
                break;
            case 7:
                if (inicializacion != 1 && agregarProv !=1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar proveedores");
                    puts("----------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                }else if (agregarProv!=1){
                    system("cls");
                    puts("¡Debe agregar proveedores!");
                    puts("-------------------------------");
                    system("pause");
                }else{
                    system("cls");
                    puts("Cargando, espere...");
                    sleep(2);
                    ModificarProveedores(Proveedores,lugaresProv);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }
                break;
            case 8:
                if(inicializacion != 1 && agregarProd != 1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar productos!");
                    puts("--------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if(agregarProd!=1){
                    system("cls");
                    puts("¡Debe agregar productos!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else{
                    system("cls");
                    puts("Cargando, espere...");
                    sleep(2);
                    BuscarProducto(Productos,lugares);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }
                break;
            case 9:
                if (inicializacion != 1 && agregarProv !=1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar proveedores");
                    puts("----------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                }else if (agregarProv!=1){
                    system("cls");
                    puts("¡Debe agregar proveedores!");
                    puts("-------------------------------");
                    system("pause");
                }else{
                    system("cls");
                    puts("Cargando, espere...");
                    sleep(2);
                    BuscarProveedor(Proveedores,lugaresProv,Productos,lugares);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }
                break;
            case 10:
                if(inicializacion != 1 && agregarProd != 1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar productos!");
                    puts("--------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if(agregarProd!=1){
                    system("cls");
                    puts("¡Debe agregar productos!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else{
                    system("cls");
                    puts("Cargando, espere...");
                    sleep(2);
                    VenderProducto(Productos,lugares,Proveedores,lugaresProv,Clientes,lugaresCli);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                    Ventas = 1;
                }
                break;
            case 11:
                if(inicializacion != 1 && Ventas != 1){
                    system("cls");
                    puts("¡Debe inicializar el programa y agregar productos!");
                    puts("--------------------------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if (inicializacion!=1){
                    system("cls");
                    puts("¡Debe inicializar el programa!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else if(Ventas!=1){
                    system("cls");
                    puts("¡Debe realizar una venta!");
                    puts("-------------------------------");
                    system("pause");
                    system("cls");
                    puts("Volviendo al menú");
                    sleep(2);
                }else{
                    system("cls");
                    puts("Cargando, espere...");
                    sleep(2);
                    VerVentas(Productos,lugares,Proveedores,lugaresProv,Clientes,lugaresCli);
                    system("cls");
                    puts("Volviendo al menú...");
                    sleep(2);
                }
                break;
            case 12:
                system("cls");
                puts("Saliendo del programa...");
                sleep(2);
                system("cls");
                puts("¡Adios!");
                return 0;
                break;
        }
    }while(bandera!=1);
}


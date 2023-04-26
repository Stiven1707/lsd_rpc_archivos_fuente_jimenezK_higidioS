/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "interface2.h"
#include <stdlib.h>
#include <stdio.h>


// Vector para almacenar los productos registrados
nodo_producto vectorProductos[5]= {
	{1, "Mesa", 5000.0, NO},
	{2, "Carro", 6000.0, NO},
	{3, "Plato", 7000.0, SI}
};

// Índice para llevar cuenta de cuántos productos
int posicionProductoAregistrar=0;
// Oferta actual en la subasta
oferta ofertaActual;
// Oferta actual en la subasta
oferta ofertaActual;

// Estado de la subasta
estado_subasta estadoActual = NUEVA;

bool_t *
registrar_producto_2_svc(nodo_producto *argp, struct svc_req *rqstp)
{
	static bool_t  result;
	printf("Invocando a registrar producto");
	printf("\n codigo del producto %d",argp->codigoProducto);
	if(posicionProductoAregistrar<5){
		vectorProductos[posicionProductoAregistrar]=*argp;
		result=TRUE;
		posicionProductoAregistrar++;
	}
	else{
		result=FALSE;
	}

	return &result;
}

vector_productos *
listarproductosdisponiblessubastar_2_svc(void *argp, struct svc_req *rqstp)
{
	static vector_productos result;
	int posicionResultado = 0;
    for (int i = 0; i < posicionProductoAregistrar; i++) {
        if (vectorProductos[i].estadoProd == SI) {
            result.vector_productos[posicionResultado] = vectorProductos[i];
            posicionResultado++;
        }
    }
    
    return &result;
}

bool_t *
abrircerrarsubasta_2_svc(int *argp, struct svc_req *rqstp)
{
	static bool_t result;
    printf("Invocando a abrir o cerrar una subasta\n");
    
    // Buscar el producto correspondiente y cambiar su estado de subasta
    for (int i = 0; i < posicionProductoAregistrar; i++) {
        if (vectorProductos[i].codigoProducto == *argp) {
            vectorProductos[i].estadoProd = !vectorProductos[i].estadoProd; 
            break;
        }
    }
    
    // Si se abrió la subasta, se inicializa la oferta actual
    if (vectorProductos[*argp].estadoProd == SI) {
        ofertaActual.objUsuario_comprador_actual.tipo = CLIENTE_C;
        ofertaActual.valor = vectorProductos[*argp].valor;
        estadoActual = ABIERTA;
    }
    else {
        estadoActual = CERRADA;
    }
    
    result = TRUE;
    return &result;
}


vector_productos *
listarproductostodos_2_svc(void *argp, struct svc_req *rqstp)
{
	static vector_productos result;
    printf("Invocando a listar todos los productos\n");
    
    int posicionResultado = 0;
    for (int i = 0; i < posicionProductoAregistrar; i++) {
        result.vector_productos[posicionResultado] = vectorProductos[i];
        posicionResultado++;
    }
    
    return &result;
}

nodo_producto *
consultarproducto_2_svc(int *argp, struct svc_req *rqstp)
{
	static nodo_producto result;
	printf("Invocando a consultar producto");
	// Buscar el producto correspondiente y retornarlo
	for (int i = 0; i < posicionProductoAregistrar; i++) {
		if (vectorProductos[i].codigoProducto == *argp) {
			result = vectorProductos[i];
			break;
		}
	}
	return &result;
}

nodo_subasta *
consultarproductoandvaloractualsubasta_2_svc(void *argp, struct svc_req *rqstp)
{
	static nodo_subasta result;
	printf("Invocando a consultar producto y valor actual de subasta");
	// Buscar el producto correspondiente y retornar sus datos de subasta
	for (int i = 0; i < posicionProductoAregistrar; i++) {
		if (vectorProductos[i].estadoProd == SI) {
			result.prod = vectorProductos[i];
			result.oferta_actual.objUsuario_comprador_actual.tipo = CLIENTE_C; // Se asigna un valor por defecto al usuario comprador
			result.oferta_actual.valor = vectorProductos[i].valor;
			result.estado = ABIERTA;
			break;
		}
		else {
			result.prod = vectorProductos[i];
			result.estado = CERRADA;
		}
	}
	return &result;
}

bool_t *
ofertarproductosubasta_2_svc(oferta *argp, struct svc_req *rqstp)
{
	static bool_t result;
	printf("Invocando a ofertar producto en subasta");
	// Buscar el producto correspondiente y validar la oferta realizada
	for (int i = 0; i < posicionProductoAregistrar; i++) {
		if (vectorProductos[i].estadoProd == SI) {
			if (argp->valor > vectorProductos[i].valor) {
				vectorProductos[i].valor = argp->valor;
				vectorProductos[i].estadoProd = NO; // Se cierra la subasta al aceptar la oferta
				result = TRUE;
				break;
			}
			else {
				result = FALSE;
			}
		}
		else {
			result = FALSE;
		}
	}
	return &result;
}

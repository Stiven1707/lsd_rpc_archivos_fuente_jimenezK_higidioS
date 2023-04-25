/* Declaración de datos a transferir entre el cliente y el servidor */ 

/* Declaración de constantes */
const  MAX_NOM = 20;
const  MAX_CAN_PROD = 5;
const MAXCORREO = 50;
const MAXTEL = 10;

/* Declaración de la estructura que permite almacenar los datos de un producto */
/* Enumeración para los estados de la subasta */
enum estado_subasta{
    NUEVA,
    ABIERTA,
    CERRADA
};

enum estado_producto_subasta{
    SI,
    NO
};

/* Estructura para la información de una subasta */
struct nodo_producto {
    int codigoProducto;
    char nombre[MAX_NOM];	
    float valor;
    estado_producto_subasta estadoProd;
};
enum tipo_usuario_comprador {
    ADMIN_C = 0,
    CLIENTE_C = 1
};
struct datos_completos_comprador {
    char nombres[MAX_NOM];
    char apellidos[MAX_NOM];
    char correo[MAXCORREO];
    char telefono[MAXTEL];
    char login[MAX_NOM];
    char contrasenia[MAX_NOM];
    tipo_usuario_comprador tipo;
};
struct oferta {
    datos_completos_comprador objUsuario_comprador_actual;
    float valor;
};
struct nodo_subasta {
    nodo_producto prod;
    oferta oferta_actual;
    estado_subasta estado;
};
struct vector_productos{
    nodo_producto vector_productos[MAX_CAN_PROD];
};

/* Definición de las operaciones que se pueden realizar */
program gestion_subastas {
    version gestion_subastas_version_1 {
		/*Servicio 3: Permite a los administradores registrar un producto a ofertar.*/
        bool registrar_producto(nodo_producto objProducto) = 1;

		/*Servicio 4: Permite a los administradores listar los productos a ofertar.*/
        vector_productos listarProductosDisponiblesSubastar() = 2;

		/*Servicio 5: Permite a los administradores abrir o cerrar una subasta para un producto en específico a partir
		de su id. Al cerrar una subasta se debe mostrar los datos del cliente que ganó la subasta.*/
        bool abrirCerrarSubasta(int codigoProducto) = 3;

		/*Servicio 6: Permite a los clientes listar los productos que se están subastando y los que no se están
		subastando.*/
        vector_productos listarProductosTodos() = 4;

		/*Servicio 7: Permite consultar los datos del producto en particular.*/
        nodo_producto consultarProducto(int codigoProducto) = 5;

		/*Servicio 8: Permite consultar los datos del producto que actualmente se está subastando, y el valor de la
		oferta actual. Si no hay una subasta abierta debe aparecer un mensaje indicando que no existen subastas
		abiertas*/
		nodo_subasta consultarProductoAndValorActualSubasta() = 6;

		/*Servicio 9: Permite a un cliente ofrecer una oferta para el producto que actualmente se está subastando.
		Se debe considerar que la oferta realizada sea mayor que la oferta actual.*/
        bool ofertarProductoSubasta(oferta oferta_realizada) = 7;
    } = 2;
} = 0x20000002;

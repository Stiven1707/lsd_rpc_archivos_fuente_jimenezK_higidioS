/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _INTERFACE2_H_RPCGEN
#define _INTERFACE2_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAX_NOM 20
#define MAX_CAN_PROD 5
#define MAXCORREO 50
#define MAXTEL 10

enum estado_subasta {
	NUEVA = 0,
	ABIERTA = 1,
	CERRADA = 2,
};
typedef enum estado_subasta estado_subasta;

enum estado_producto_subasta {
	SI = 0,
	NO = 1,
};
typedef enum estado_producto_subasta estado_producto_subasta;

struct nodo_producto {
	int codigoProducto;
	char nombre[MAX_NOM];
	float valor;
	estado_producto_subasta estadoProd;
};
typedef struct nodo_producto nodo_producto;

enum tipo_usuario_comprador {
	ADMIN_C = 0,
	CLIENTE_C = 1,
};
typedef enum tipo_usuario_comprador tipo_usuario_comprador;

struct datos_completos_comprador {
	char nombres[MAX_NOM];
	char apellidos[MAX_NOM];
	char correo[MAXCORREO];
	char telefono[MAXTEL];
	char login[MAX_NOM];
	char contrasenia[MAX_NOM];
	tipo_usuario_comprador tipo;
};
typedef struct datos_completos_comprador datos_completos_comprador;

struct oferta {
	datos_completos_comprador objUsuario_comprador_actual;
	float valor;
};
typedef struct oferta oferta;

struct nodo_subasta {
	nodo_producto prod;
	oferta oferta_actual;
	estado_subasta estado;
};
typedef struct nodo_subasta nodo_subasta;

struct vector_productos {
	nodo_producto vector_productos[MAX_CAN_PROD];
};
typedef struct vector_productos vector_productos;

#define gestion_subastas 0x20000002
#define gestion_subastas_version_1 2

#if defined(__STDC__) || defined(__cplusplus)
#define registrar_producto 1
extern  bool_t * registrar_producto_2(nodo_producto *, CLIENT *);
extern  bool_t * registrar_producto_2_svc(nodo_producto *, struct svc_req *);
#define listarProductosDisponiblesSubastar 2
extern  vector_productos * listarproductosdisponiblessubastar_2(void *, CLIENT *);
extern  vector_productos * listarproductosdisponiblessubastar_2_svc(void *, struct svc_req *);
#define abrirCerrarSubasta 3
extern  bool_t * abrircerrarsubasta_2(int *, CLIENT *);
extern  bool_t * abrircerrarsubasta_2_svc(int *, struct svc_req *);
#define listarProductosTodos 4
extern  vector_productos * listarproductostodos_2(void *, CLIENT *);
extern  vector_productos * listarproductostodos_2_svc(void *, struct svc_req *);
#define consultarProducto 5
extern  nodo_producto * consultarproducto_2(int *, CLIENT *);
extern  nodo_producto * consultarproducto_2_svc(int *, struct svc_req *);
#define consultarProductoAndValorActualSubasta 6
extern  nodo_subasta * consultarproductoandvaloractualsubasta_2(void *, CLIENT *);
extern  nodo_subasta * consultarproductoandvaloractualsubasta_2_svc(void *, struct svc_req *);
#define ofertarProductoSubasta 7
extern  bool_t * ofertarproductosubasta_2(oferta *, CLIENT *);
extern  bool_t * ofertarproductosubasta_2_svc(oferta *, struct svc_req *);
extern int gestion_subastas_2_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define registrar_producto 1
extern  bool_t * registrar_producto_2();
extern  bool_t * registrar_producto_2_svc();
#define listarProductosDisponiblesSubastar 2
extern  vector_productos * listarproductosdisponiblessubastar_2();
extern  vector_productos * listarproductosdisponiblessubastar_2_svc();
#define abrirCerrarSubasta 3
extern  bool_t * abrircerrarsubasta_2();
extern  bool_t * abrircerrarsubasta_2_svc();
#define listarProductosTodos 4
extern  vector_productos * listarproductostodos_2();
extern  vector_productos * listarproductostodos_2_svc();
#define consultarProducto 5
extern  nodo_producto * consultarproducto_2();
extern  nodo_producto * consultarproducto_2_svc();
#define consultarProductoAndValorActualSubasta 6
extern  nodo_subasta * consultarproductoandvaloractualsubasta_2();
extern  nodo_subasta * consultarproductoandvaloractualsubasta_2_svc();
#define ofertarProductoSubasta 7
extern  bool_t * ofertarproductosubasta_2();
extern  bool_t * ofertarproductosubasta_2_svc();
extern int gestion_subastas_2_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_estado_subasta (XDR *, estado_subasta*);
extern  bool_t xdr_estado_producto_subasta (XDR *, estado_producto_subasta*);
extern  bool_t xdr_nodo_producto (XDR *, nodo_producto*);
extern  bool_t xdr_tipo_usuario_comprador (XDR *, tipo_usuario_comprador*);
extern  bool_t xdr_datos_completos_comprador (XDR *, datos_completos_comprador*);
extern  bool_t xdr_oferta (XDR *, oferta*);
extern  bool_t xdr_nodo_subasta (XDR *, nodo_subasta*);
extern  bool_t xdr_vector_productos (XDR *, vector_productos*);

#else /* K&R C */
extern bool_t xdr_estado_subasta ();
extern bool_t xdr_estado_producto_subasta ();
extern bool_t xdr_nodo_producto ();
extern bool_t xdr_tipo_usuario_comprador ();
extern bool_t xdr_datos_completos_comprador ();
extern bool_t xdr_oferta ();
extern bool_t xdr_nodo_subasta ();
extern bool_t xdr_vector_productos ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_INTERFACE2_H_RPCGEN */

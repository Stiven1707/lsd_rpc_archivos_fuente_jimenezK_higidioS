/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "interface2.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
gestion_subastas_2(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		nodo_producto registrar_producto_2_arg;
		int abrircerrarsubasta_2_arg;
		int consultarproducto_2_arg;
		oferta ofertarproductosubasta_2_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case registrar_producto:
		_xdr_argument = (xdrproc_t) xdr_nodo_producto;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) registrar_producto_2_svc;
		break;

	case listarProductosDisponiblesSubastar:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_vector_productos;
		local = (char *(*)(char *, struct svc_req *)) listarproductosdisponiblessubastar_2_svc;
		break;

	case abrirCerrarSubasta:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) abrircerrarsubasta_2_svc;
		break;

	case listarProductosTodos:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_vector_productos;
		local = (char *(*)(char *, struct svc_req *)) listarproductostodos_2_svc;
		break;

	case consultarProducto:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_nodo_producto;
		local = (char *(*)(char *, struct svc_req *)) consultarproducto_2_svc;
		break;

	case consultarProductoAndValorActualSubasta:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_nodo_subasta;
		local = (char *(*)(char *, struct svc_req *)) consultarproductoandvaloractualsubasta_2_svc;
		break;

	case ofertarProductoSubasta:
		_xdr_argument = (xdrproc_t) xdr_oferta;
		_xdr_result = (xdrproc_t) xdr_bool;
		local = (char *(*)(char *, struct svc_req *)) ofertarproductosubasta_2_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (gestion_subastas, gestion_subastas_version_1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, gestion_subastas, gestion_subastas_version_1, gestion_subastas_2, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (gestion_subastas, gestion_subastas_version_1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, gestion_subastas, gestion_subastas_version_1, gestion_subastas_2, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (gestion_subastas, gestion_subastas_version_1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}

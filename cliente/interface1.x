/* Declaración de los datos a transferir entre el cliente y el servidor */ 

/* Declaración de constantes */
const MAXNOM = 20;
const MAXCORREO = 50;
const MAXTEL = 10;

/* Declaración de la estructura que permite almacenar los datos de un usuario */
enum tipo_usuario {
    ADMIN = 0,
    CLIENTE = 1
};

struct datos_completos {
    char nombres[MAXNOM];
    char apellidos[MAXNOM];
    char correo[MAXCORREO];
    char telefono[MAXTEL];
    char login[MAXNOM];
    char contrasenia[MAXNOM];
    tipo_usuario tipo;
};

struct datos_login {
    char login[MAXNOM];
    char contrasenia[MAXNOM];
};

struct respuesta_login {
    char mensaje[MAXNOM];
    int codigo;
    datos_completos objUsuario;
};

/* Definición de las operaciones que se pueden realizar */
program gestion_usuarios {
    version gestion_usuarios_version_1 {
        bool registrarUsuario(datos_completos objUsuario) = 1;
        respuesta_login iniciarSesion(datos_login objUsuario) = 2;
    } = 1;
} = 0x20000001;
#ifndef HANDLER_H
#define HANDLER_H
#include "worker.h"
#define OK "OK \n"
#define KO "KO"

//Overview: Supporto per la gestione delle operazioni affidate ad un thread worker


/*
     @REQUIRES: msg != null && worker != null && bytes != null
     @EFFECTS: Fa il parsing del messaggio ricevuto sul socket fd_c
*/
int handle_user_msg(char *msg,int bytes, worker *worker_client);

/*
     @REQUIRES: name != null && worker_client != null
     @EFFECTS: Registrazione utente
*/
int handle_register(char *name,worker *worker_client);

/*
     @REQUIRES: name != null && worker_client != null && lst != null 
     && bytes != null
     @EFFECTS: Gestione upload file nell'ObjectStore
*/
int handle_store(char *name,char *size,worker *worker_client,char *lst,size_t bytes);

/*
     @REQUIRES: name != null && worker_client != null
     @EFFECTS: Download di un file dall'ObjectStore
*/
int handle_retrieve(char *name,worker *worker_client);

/*
     @REQUIRES: name != null && worker_client != null
     @EFFECTS: Delete di un file 
*/
int handle_delete(char *name,worker *worker_client);
/*
     @REQUIRES: worker_client != null
     @EFFECTS: Disconnessione utente
*/
int handle_leave(worker *worker_client);



#endif /* HANDLER_H */

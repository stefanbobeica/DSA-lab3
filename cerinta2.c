#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce elimina elementele cu informatii duplicate
 * Hint:
 *      * parcurgeti lista si modificati nodurile a.i sa elimi-
 *        nati duplicatele
 *      * daca capul listei nu se modifica va trebuii 
 *        sa il returnati
 * 
 * @param list - capul listei ce trebuie sa fie procesata
 * @return node* - returneaza capul listei
 */
node *removeDuplicates(node *list)
{   node *output = list;
         node *p,*q,*aux;
          p=list;
          
          while(p!=NULL){
                   q=p;
                   while((q!=NULL)&&(q->next!=NULL)){
                       if(q->next->data==p->data){
                           aux=q->next;
                           q->next=q->next->next;
                           free(aux);
                       }
                        else q=q->next;
                   }
               p=p->next;

              }
    
   
    
    
    
    
    
    
    
    
    
    return output;
    //TODO2: metoda ce realizeaza eliminarea de noduri duplicate
}

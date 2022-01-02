#include "list.h"
#include "utils.h"



/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param number - numarul pe care il are copilul
 * @param name - numele copilului
 * @param next  - adresa urmatorului nod
 * @return childNode* - nou nod creat
 */
childNode *makeChildNode(int number, const char *name, childNode *next)
{  childNode *p;
   p=(childNode * )malloc(sizeof(childNode));
   if(p==NULL)
   return NULL;
   p->number=number;
   p->name=(char*)malloc(strlen(name)*sizeof(char));
   strcpy(p->name,name);
   p->next=next;
   return p;
   
    //TODO3.1: primul pas in implementarea cerintei 3
}




/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeChildNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return childNode* 
 */


childNode *makeCircularList(FILE *file)
{ childNode *cap_lista,*p;
      int nr;
      char aux[30];
      fscanf(file,"%d %s",&nr,aux);
      cap_lista=makeChildNode(nr,aux,NULL);
      p=cap_lista;
      while(fscanf(file,"%d %s",&nr,aux)!=EOF){
          cap_lista=makeChildNode(nr,aux,cap_lista);
      }
      p->next=cap_lista;
    //TODO2.2: al doilea pas in implementarea cerintei 3
   
  return cap_lista;
    
}


/**
 * @brief Functie ce 
 * 
 * @param head - capul listei ce reprezinta cercul de copii
 * @param p - pasul ce va fi luat pentru eliminarea copiilor
 * @return childNode* 
 */
childNode *playJosephGame(childNode *head, int p)
{
    childNode *q, *z, *cap_lista = NULL;
    q=head;
    z=head;
    while (q->next!=q){
  
        for(int i=1;i<p;i++){
        z=q;
        q=q->next;
        }
        z->next=q->next;
        cap_lista= makeChildNode(q->number,q->name,cap_lista);
        free(q->name);
        free(q);
       q=z->next;
    }
    cap_lista = makeChildNode(q->number, q->name, cap_lista);
    return cap_lista;
}
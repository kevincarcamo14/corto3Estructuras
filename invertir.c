#include<stdio.h>
#include<stdlib.h>
#define bool int

struct sNodo{
       char dato;
       struct sNodo *siguiente;
};

void push(struct sNodo** top_ref, int nuevoDato);
int pop(struct sNodo** top_ref);
bool vacio(struct sNodo* top);
void imprimir(struct sNodo* top);

//Insertar valores a la Pila
void insertar(struct sNodo** top_ref, int valor){
   if(vacio(*top_ref))
       push(top_ref, valor);
   else
       {
        int temp=pop(top_ref);
         insertar(top_ref, valor);
         push(top_ref, temp);
        }    
}
//Revierte valores a la Pila
void revertir(struct sNodo** top_ref){
   if(!vacio(*top_ref)){
     int temp=pop(top_ref);
     revertir(top_ref);
     insertar(top_ref, temp);
    }
}

bool vacio(struct sNodo* top){
    return(top==NULL)? 1:0;
}

void push(struct sNodo** top_ref,int nuevoDato){

struct sNodo* nuevoNodo= (struct sNodo*) malloc(sizeof(struct sNodo));

if(nuevoNodo==NULL)
{
    printf("stack overflow \n");
    exit(0);
}
   nuevoNodo->dato= nuevoDato;

   nuevoNodo->siguiente=(*top_ref);
   (*top_ref)= nuevoNodo;

}

int pop(struct sNodo** top_ref){
     char res;
     struct sNodo *top;
     
     if(*top_ref== NULL)
     {
       printf("stack overflow \n");
       exit(0);       
      }
      else
      {
        top= *top_ref;
        res= top->dato;
        *top_ref=top->siguiente;
        
         free(top); 
        return res; 
       }
}
//Imprime los valores de la Pila
void imprimir(struct sNodo* top){
   if(top == NULL){
       printf("\nLa pila está vacía");
   }else{
       printf("\nLa pila es:\n\n");
       while(top!=NULL){
       printf(" %d ",top->dato);
       top= top->siguiente; 
       }
   }
}

int main(){
    
    int opcion, valor;
    struct sNodo *s= NULL;
    
   do{
      printf("\n\nOPCIONES:\n\n1 - Agregar un dato a la pila: \n2 - Ver pila: \n3 - Revertir la pila: \n4 - Salir\n\nINGRESE EL NÚMERO DE LA OPCIÓN: ");
      scanf( "%d", &opcion );
 
      switch (opcion) { 
 
         case 1:      
            printf("\nIntroduzca un número entero: ");
            scanf("%d", &valor);
            push(&s, valor);
            break;
           
            
         case 2:
             imprimir(s);
             break;
             
         case 3:
             if (vacio(s)) {
                 printf( "\nLa pila está vacía");
             }else{
                 revertir(&s);
                 printf("\nPila revertida exitosamente");
             }
             break;
             
         default:
            break;

      }
   }while(opcion!=4);
}














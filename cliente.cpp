//William Arboleda Castro
//Marlyn valencias sinisterra 
//mienbros del grupo 

#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;

struct cliente  // La estrutura de datos 
{
    char nombre[30];
    int id;
    int cupo_credito;
    int cupo_usado=0;
    cliente *siguiente; 
};                      
                        

cliente *primero,*aux,*aux2; // los apuntadores donde se guardaran los espacios de memoria 

void registrar();
void consultar();
void calcular();
void usar();

int op1,op2;

int main(){
     
     do
     {
        system("cls");
        cout<<"********************************"<<"\n\n";
        cout<<"*******MENU PRINCIPAL************"<<endl;
        cout<<"1.REGISTRAR CLIENTE"<<endl;
        cout<<"2.CONSULTAR CLIENTE"<<endl;
        cout<<"3.CALCULAR CREDITOS DEL CLIENTE  "<<endl;
        cout<<"4.USAR CREDITO"<<endl;
        cout<<"5.SALIR "<<endl;
        cout<<"*********************************"<<endl;
        cout<<"->";cin>>op1;


        switch (op1)
        {
          case 1: registrar();
          break;
          case 2: consultar();
          break;
          case 3: calcular();
          break;
          case 4: usar();
          break;
          case 5: exit(0);
        }

        if(op1>3)
        {
           cout<<" LA OPCION SELECCIONADA NO EXISTE VUELVA A INTENTARLO"<<endl;
           cout<<"DESEA CONTINUAR 1.SI/2.NO -> ";cin>>op2;
        }
     }while(op2==1);
  
    return 0;
}

void registrar()
{
    system("cls");
     
     if (primero==NULL)
     {
       
        
        primero = (struct cliente *) malloc(sizeof(struct cliente));
        primero->cupo_usado=0;
        cout<<"\n";
        cout<<"INGRESE SU NOMBRE -> ";cin>>primero->nombre;
        cout<<"\n";
        cout<<"INGRESE SU DOCUMETO ->";cin>>primero->id;
        cout<<"\n";
        cout<<"INGRESE SU CREDITO -> ";cin>>primero->cupo_credito;

        primero->siguiente=NULL;

        cout<<"\n";

             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                registrar();
            }else if(op1==3)
            {
                exit(0);
            }

     }else
     {
        

        aux = (struct cliente *) malloc(sizeof(struct cliente));
        aux->cupo_usado=0;
        cout<<"\n";
        cout<<" INGRESE SU NOMBRE -> ";cin>>aux->nombre;
        cout<<"\n";
         cout<<"INGRESE SU DOCUMETO ->";cin>>aux->id;
        cout<<"\n";
        cout<<"INGRESE SU CREDITO -> ";cin>>aux->cupo_credito;

        aux->siguiente = NULL;
        aux2 = primero;

        while(aux2->siguiente!=NULL)
        
            aux2 = aux2->siguiente;
            aux2->siguiente = aux;
            aux2 = aux = NULL;

            free(aux);
            free(aux2);

            cout<<"\n";


             cout<<" DESEA CONTINUAR "<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                registrar();
            }else if(op1==3)
            {
                exit(0);
            }

     }

}

void consultar()
{
   system("cls");
   int op;
   cout<<"****CONSULTAR CLIENTES****"<<"\n"<<"\n";
   cout<<"1.CONSULTAR TODOS LOS CLIENTES "<<endl;
   cout<<"2.CONSULTAR CLIENTES CON UN CUPO USADO MAS DEL 80%"<<endl;
   cin>>op;
   if(op==1){
    system("cls");
    for(aux = primero;aux!=NULL;aux = aux->siguiente)
   {
    cout<<"****CONSULTAR A TODOS LOS CLIENTES****"<<endl;
    cout<<"*****************************************"<<endl;
    cout<<" SU NOMBRE ES -> "<<aux->nombre<<endl;
    cout<<"SU DOCUMENTO ES  ->"<<aux->id<<endl;
    cout<<" SU CREDITO ACTUAL ES DE -> "<<aux->cupo_credito<<endl;
    cout<<"SU CUPO USADO ES DE -> "<<aux->cupo_usado<<endl;
    cout<<"******************************************"<<endl;
    cout<<"\n";
    }

   }else if(op==2){
    system("cls");
    for(aux = primero;aux!=NULL;aux = aux->siguiente){
        int procentaje = (aux->cupo_usado/aux->cupo_credito)*100;
        if(procentaje>80){
            cout<<"****CONSULTAR LOS CLIENTES CON UN CUPO USADO MAYOR AL 80%"<<endl;
            cout<<"****************************************************************"<<endl;
            cout<<"SU NOMBRE ES ->"<<aux->nombre<<endl;
            cout<<"SU CUPO USADO A SOBREPASADO EL ->"<<procentaje<<"%"<<endl;
        }else{
            cout<<"\n";
            cout<<"NO SE A ENCONTRADO UN CLIENTE QUE SOBRE PASE EL CUPO USADO ";
        }
    }

    

   }
   
    
   
 
   

     cout<<"**** DESEA CONTINUAR ****"<<endl;
            cout<<"1.VOLVER AL MENU"<<endl;
            cout<<"2.CONTINUAR "<<endl;
            cout<<"3.SALIR "<<endl;
            cin>>op1;

            if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                consultar();
            }else if(op1==3)
            {
                exit(0);
            }

}

void calcular()
{
    system("cls");
    
    for(aux = primero;aux!=NULL; aux = aux->siguiente){

        
    }
}

void usar()
{
    system("cls");
    int n = 0;
    int nuevo_credito;
    int m = 0;
    cout<<"****USAR CREDITO****"<<endl<<endl;
    cout<<"INGRESE SU DOCUMETO PARA USAR SU CREDITO ->";cin>>n;

        for(aux = primero;aux!=NULL; aux = aux->siguiente){
            if (n==aux->id)
            {
                cout<<"************************************"<<endl;
                cout<<" SU NOMBRE ES -> "<<aux->nombre<<endl;
                cout<<"SU CREDITO ACTUAL ES DE ->"<<aux->cupo_credito<<" CUANTO DESEA USAR ->";cin>>m;
                while(m>aux->cupo_credito)
                {
                    cout<<"LO QUE DESEA RETIRAR NO CONCUERDA CON SU SALDO ACTUAL"<<endl;
                    cout<<"CUANTO CREDITO DESEAS USAR -> ";cin>>m;
                }
                aux->cupo_usado = m;
                nuevo_credito = aux->cupo_credito-aux->cupo_usado;
                aux->cupo_credito=nuevo_credito;

                
                
            
               
                
                
            }else{
                cout<<"CLIENTE NO ENCONTRADO ";
            }
            
        }

   
   

      if(op1==1)
            {
                main();
            }else if(op1==2)
            {
                consultar();
            }else if(op1==3)
            {
                exit(0);
            }
}

#include <cstdlib>
#include <iostream>
using namespace std;

struct nodo{
       char nro;  
       struct nodo *sgte;
};

typedef struct nodo *Tlista;

void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}

void insertarElemento(Tlista &lista, int valor, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;

    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
}


void reportarLista(Tlista lista)
{
     int i = 0;

     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->nro << endl;
          lista = lista->sgte;
          i++;
     }
}

void menu1()
{
    cout<<" 1. Agregar caracter           "<<endl;
    cout<<" 2. Mostrar lista de caracters                  "<<endl;
    cout<<"\n Ingresar una oopcion: "<<endl;
}
int main()
{
    Tlista lista = NULL;
    int op;     // opcion del menu
    char _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar
    system("pause");

    do
    {
        menu1();  cin>> op;

        switch(op)
        {
            case 1:

                 cout<< "\n Agregar caracter: "<<endl; 
				 cin>> _dato;
                 insertarInicio(lista, _dato);
            break;
            case 2:

                 cout << "Mostrar lista de caracteres"<<endl;
                 reportarLista(lista);
            break;
                    }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=2);
   system("pause");
   return 0;
}

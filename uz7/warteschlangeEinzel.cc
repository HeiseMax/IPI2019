#include <iostream>
#include <cstdlib>

// Ein Listenelement
struct IntListElem
{
  IntListElem* next;  // Zeiger auf nächstes Element
  int value;          // Daten zu diesem Element  
} ;

// Eine Liste
struct IntList
{
  int count;          // Anzahl Elemente in der Liste
  IntListElem* first; // Zeiger auf erstes Element der Liste
} ;

// Initialisiere eine Listenstruktur
void empty_list( IntList* l )
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
  l->count = 0;
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list( IntList* list, IntListElem* where, IntListElem* ins )
{
  if ( where == 0 ) // fuege am Anfang ein
  {
    ins->next = list->first;
    list->first = ins;
    list->count = list->count + 1;
  }
  else              // fuege nach where ein
  {
    ins->next = where->next;
    where->next = ins;
    list->count = list->count + 1;
  }
}

// Entferne ein Element nach einem gegebenem
// Liefere das entfernte Element zurueck
IntListElem* remove_from_list( IntList* list, IntListElem* where )
{
  IntListElem* p;  // das entfernte Element

  // where == 0 dann entferne erstes Element
  if ( where == 0 ) 
  {
    p = list->first;
    if ( p != 0 )
    {
      list->first = p->next;
      list->count = list->count - 1;
    }
    return p;
  }

  // entferne Element nach where
  p = where->next;
  if ( p != 0 )
  {
    where->next = p->next;
    list->count = list->count - 1;
  }
  return p;
}

//#######################	EIGENE_FUNKTiONEN	###########

void einreihen(IntList &list, IntListElem &elem)
{
	insert_in_list(&list, nullptr, &elem);
}

void entfernen(IntList &list)
{
	IntListElem* hilfe  = list.first;
	IntListElem* end = list.first;
	while (hilfe->next != 0)
	{
		end = hilfe;
		hilfe = hilfe->next;
	}
	remove_from_list(&list, end);
}

int main()
{
	IntList list;
	empty_list(&list);
	//IntListElem* p = list.first;

	IntListElem* elem = new IntListElem[100000];

	for (int i = 0; i < 100000; i++)
	{
		elem[i].value = rand();
		einreihen(list, elem[i]);
	}
	for (int i = 0; i < 100000; i++)
	{
		entfernen(list);
	}
	delete[] elem;
}

#include <iostream>

//Doppelt verkettete Liste

// Ein Listenelement
struct IntListElem
{
  IntListElem* next;  // Zeiger auf nächstes Element
	IntListElem* prev;
  int value;          // Daten zu diesem Element  
} ;

// Eine Liste
struct IntList
{
  int count;          // Anzahl Elemente in der Liste
  IntListElem* first; // Zeiger auf erstes Element der Liste
	IntListElem* last;
} ;

// Initialisiere eine Listenstruktur
void empty_list( IntList* l )
{
  l->first = 0;   // 0 ist keine gueltige Adresse: Liste ist leer
  l->count = 0;
	l->last = 0;
}

// Fuege ein Element nach einem gegebenem ein
void insert_in_list( IntList* list, IntListElem* where, IntListElem* ins )
{
  if ( where == 0 ) // fuege am Anfang ein
  {
    ins->next = list->first;
	ins->prev = 0;
    list->first = ins;
	if (ins->next != 0)
	{
		list->first->prev = ins;
	}
    list->count = list->count + 1;
  }

  else              // fuege nach where ein
  {
    ins->next = where->next;
	where->next->prev = ins;
    where->next = ins;
	ins->prev = where;
    list->count = list->count + 1;
  }
	IntListElem* lastElem = list->first;
	while (lastElem->next != 0)
	{
		lastElem = lastElem->next;
	}
	list->last = lastElem;
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
		if (p->next != 0)
		{
			p->next->prev = 0;
		}
		list->count = list->count - 1;
	}
	return p;
}

 	 //entferne Element nach where
	p = where->next;
	if ( p != 0 )
	{
		where->next = p->next;
		if (p->next != 0)
		{
			p->next->prev = where;
		}
	list->count = list->count - 1;
  	}
	IntListElem* lastElem;
	while (lastElem->next != 0)
	{
		lastElem = lastElem->next;
	}
	list->last = lastElem;
	return p;
}


//#######################	EIGENE_FUNKTiONEN	###########


void einreihen(IntList &list, IntListElem &elem)
{
	insert_in_list(&list, nullptr, &elem);
}

void entfernen(IntList &list)
{
	IntListElem* end = list.last->prev;
	remove_from_list(&list, end);
}

int main()
{
	IntList list;
	empty_list(&list);
	int n = 100000;

	IntListElem* elem = new IntListElem[n];

	for (int i = 0; i < n; i++)
	{
		elem[i].value = rand();
		einreihen(list, elem[i]);
	}
	for (int i = 0; i < n; i++)
	{
		entfernen(list);
	}
	delete[] elem;
}

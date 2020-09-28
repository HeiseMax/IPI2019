#include <iostream>


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


//#######################	EIGENE_FUNKTiONEN	###########


int main()
{
	int n = 0;
	std::cout << "Eingabe n: " << std::endl;
	std::cin >> n;
	int k = 0;
	std::cout << "Eingabe k: " << std::endl;
	std::cin >> k;

	IntList listN;
	IntList listK;
	empty_list(&listN);
	empty_list(&listK);

	IntListElem* p = listN.first;
	IntListElem* f = listK.first;

	IntListElem elemN[n];
	IntListElem elemK[k];

	

	for (int i = 0; i < n; i++)
	{
		insert_in_list(&listN, p, &elemN[i]);
		elemN[i].value = i+100;
	}
	elemN[0].next = listN.first; //Letztes Element von N zeigt auf erstes Element von N

	for (int i = 0; i < k; i++)
	{
		insert_in_list(&listK, f, &elemK[i]);
		elemK[i].value = i;		
	}
	elemK[0].next = listN.first; //letztes Element von Liste K wird mit Zyklus N verbunden

	if (n == 0) 
	{
		elemK[0].next = &elemK[0];
	}
	if (k == 0)
	{
		listK.first = listN.first;
	}

//igel und Hase

	IntListElem* igel = listK.first;
	igel = igel->next;
	IntListElem* hase = listK.first;
	hase = hase->next;
	hase = hase->next;

	while (igel->next != hase->next) //Igel und Hase finden sich
	{
		igel = igel->next;
		hase = hase->next;
		hase = hase->next;
	}

	int j = 0;
	if (elemK[0].next == &elemK[0])
	{
		std::cout << "Laenge Zyklus = " << j << std::endl;
		return 0;
	}		
	igel = igel->next;
	j++;
	while (igel->next != hase->next)//Igel prüft wie lang der Zyklus ist
	{
		igel = igel->next;
		j++;
	}
	std::cout << "Laenge Zyklus = " << j << std::endl;
	return 0;
}

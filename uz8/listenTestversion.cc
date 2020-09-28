#include <iostream>

class IntList
{
	public:
		// Konstruktor, erzeugt eine leere Liste
		IntList();
		// Destruktor, loescht gesamten Listeninhalt
		~IntList();
		// CopyKonstruktor
		IntList(const IntList& list);
		// Zuweisung
		IntList& operator= (const IntList& list);
		// Gibt Anzahl der Elemente zurueck
		int getCount();
		// Gibt zurueck, ob die Liste leer ist
		bool isEmpty();
		// Gibt die Liste aus
		void print();
		// Fuegt die Zahl 'element' an der (beliebigen) Position 'position' ein			
		void insert(int element,int position);
		void insert(int element); //üerberladene insert funktion, die immer vorne einfügt
		// Loescht das Element an der Position 'position'
		void remove(int position);
		// Gibt den Wert des Elements an der Position 'position' zurueck
		int getElement(int position);
	private:
		// ... (hier folgen private Member der Klasse)
		int _count;
		struct IntListElem
		{
 			IntListElem* next;
			int value; 
		};
		IntListElem* _first;
};

IntList::IntList()
{
	_first = nullptr;
	_count = 0;
}

IntList::~IntList()
{
	IntListElem* posi;
	posi = _first;
	for (int i = 0; i < _count; i++)
	{
		for (int j = 1; j < (_count - i); i++)
		{
			posi =	 posi->next;
		}
	delete posi;
	}
}

IntList::IntList(const IntList& list)
{
	_first = nullptr;
	_count = 0;
	IntListElem* elem = new IntListElem[list._count];
	IntListElem* posi;
	posi = list._first;
	for (int i = 0; i < list._count; i++)
	{
		elem[list._count - i -1].value = posi->value;
		posi = posi->next;
		elem[i].next = _first;
		_first = &elem[i];
		_count = _count + 1;
	}
}

IntList& IntList::operator= (const IntList& list)
{
	if (this != &list)
	{

		IntListElem* posi;
		for (int i = 0; i < _count; i++)
		{
			posi = _first;
			for (int j = 1; j < (_count - i); i++)
			{
				posi =	 posi->next;
			}
		delete posi;
		}
		_first = nullptr;
		_count = 0;

		IntListElem* elem = new IntListElem[list._count];
		posi = list._first;
		for (int i = 0; i < list._count; i++)
		{
			elem[list._count - i -1].value = posi->value;
			posi = posi->next;
			elem[i].next = _first;
			_first = &elem[i];
			_count = _count + 1;
		}
	}
	return *this;
}

int IntList::getCount()
{
	return _count;
}

bool IntList::isEmpty()
{
	return (_count == 0);
}

void IntList::print()
{

	IntListElem* posi;
	posi = _first;

	for (int i = 0; i < _count; i++)
	{
		std::cout << posi->value << " ";
		posi = posi->next;
	}
	std::cout << std::endl;
}

void IntList::insert(int element,int position)
{
	IntListElem* elem = new IntListElem;
	elem->value = element;

	IntListElem* posi;
	posi = _first;
	for (int i = 1; i < position; i++)
	{
		posi =	 posi->next;
	}

	if ( position == 0 )
	{
		elem->next = _first;
		_first = elem;
		_count = _count + 1;
	}
	else
	{
		elem->next = posi->next;
		posi->next = elem;
		_count = _count + 1;
	}	
}

void IntList::insert(int element)
{
	IntListElem* elem = new IntListElem;
	elem->value = element;
	elem->next = _first;
	_first = elem;
	_count = _count + 1;
}

void IntList::remove(int position)
{
	IntListElem* posi;
	posi =_first;
	for (int i = 1; i < position; i++)
	{
		posi =	 posi->next;
	}
	if ( position == 0 ) 
  	{
		IntListElem* remover;
		remover = _first;
		_first = _first->next;
		_count = _count - 1;
		
		delete remover;
	}
	else
	{
		IntListElem* remover;
		remover = posi-> next;
		posi->next = posi->next->next;
		_count = _count - 1;
		delete remover;
	}
}

int IntList::getElement(int position)
{
	IntListElem* posi;
	posi =_first;
	for (int i = 0; i < position; i++)
	{
		posi =	 posi->next;
	}
	return posi->value;
}

int main()
{
	IntList list;
	list.insert(30);
	list.insert(20);
	list.insert(10);
	list.print();
	list.remove(0);
	list.print();
	list.insert(30,2);
	list.print();
	list.insert(40,3);
	list.print();
	IntList copy(list);
	copy.print();
	copy.remove(2);
	copy.print();
	list.print();
	copy = list;
	copy.print();
	return 0;
}

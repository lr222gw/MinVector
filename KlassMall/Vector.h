#ifndef VECTOR_H
#define VECTOR_H

template<typename T> //H�r deklarerar vi att denna klass inte �r en vanlig klass utan en klassmall! 
class Vector {

private:
	T * items;				//Enkelpekare blir smidigare h�r... en array av typen T...
	int capacity;			//hur stor arrayen �r
	int capacityIncrement;	//huur mycket arrayen ska expandera n�r den ska expandera
	int nrOfItems;			//aktuellt antal element i arrayen
	void expand();

public:
	//* konstruktorer(default, med parameter f�r kapacitet, med parameter f�r kapacitet och inkrement)	
	Vector(int capacity = 10, int capacityIncrement=5); // defaultargumenten g�r att vi inte beh�ver en defaultkonstrruktor.. d� denna agerar som en s�dan...

	//* destruktor
	virtual ~Vector(); //destruktorer ska ALLTID vara virtuella, ifall denna vector n�gon g�ng kommer agera som basklass... (t�nker p� framtiden, lixom)
	
	//* copy - konstruktor

	//* tilldelningsoperator 1
	void addLast(T item);

	void addFirst(T item);
																		//Varje g�ng Throw anv�nds s� b�r man anropa den funktionen med "try"-satsen
	void addAt(int index, T item) throw(...);			//"throw(...)" <- betyder att denna funktion kan kasta ett "exception"!
	T getFirst() const		throw(...);
	T getLast() const		throw(...);
	T getAt(int index) const throw(...);
	T removeFirst()			throw(...);							//genom att ha returtypen "T" s� f�r man elementet som man tar bort, 
	T removeLast()			throw(...);							//d� det kanske ska anv�ndas n�gon annanstanns (b�ttre �n void...)
	T removeAt(int index)	throw(...);
	void removeBetween(int start, int end) throw(...); //Denna �r void, d� vi inte har lust att returnera en hel array (med v�rderna mellan start och end...)
	//void clear();
	//* +operatorn
	//*[]operatorn <- �verlagra denna 
		//^ kan anv�ndas s�h�r allts� myVector[1] <- det betyder att den ska g�ra s�h�r myVector.getAt(1);
		// ^d� m�ste returtypen vara T, se den h�r:
	T operator[](int index) const throw(...);
};

template<typename T>
void Vector<T>::expand() {
	//1. �ka p� v�rdet p� capacity
	this->capacity += this->capacityIncrement; //enligt v�r capacity increment...

	//2. G�ra en T pekare 
	T* temp = new T[this->capacity];

	//3. loopa igenom
	for (int i = 0; i < this->nrOfItems; i++) {
		temp[i] = this->items[i]
	}

	delete[] this->items;

	//st�ller om pekaren (obs, ytlige kopiering, bara pekarna... adresserna)
	this->items = temp; 
}


template <typename T> //S�h�r g�r vi definitionen f�r v�r konstruktor p� v�r klassmall! Notera att vi forrtfarande �r I h-filen! 
Vector<T>::Vector(int capacity, int capacityIncrement) {
	// se till att alla medlems varibler blir initierade... som vanligt
	this->nrOFITems = 0;

	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->items = new T[this->capacity];
}

template<typename T>
Vector<T>::~Vector()	//inline Vector<T>::~Vector() <- vad betyder inline? den kom med n�r jag kopierade... svar: PLOCKA BORT INLINE! 
{
	delete[] this->items;  // vi beh�ver inte ta bort elementen i items, d� de inte �r dynamiska! (de �r inte skapta med "new")...
}

template<typename T>
void Vector<T>::addLast(T item) {
	if (this->capacity == this->nrOfItems) {

		this->expand();
	}

	this->items[this->nrOfItems] = item;
	this->nrOfItems++;
}

template<typename T>
void Vector<T>::addFirst(T item) {
	if (this->nrOfItems == this->capacity) {
		this->expand();
	}
	
	this->items[this->nrOfItems] = this->items[0]; //Byter plats, den f�rsta elementet s�tts l�ngst bak
	this->items[0] = item; //det nya elementet s�tts l�ngst fram


}

template<typename T>
void Vector<T>::addAt(int index, T item) throw(...){	//h�r ska "throw(...)" st� f�r att ber�tta att anv�ndaren 
														//kan anv�nda en try sats f�r denna funktion
	if (index<0 || index > this->nrOfItems) {
		throw "index is not allowed"; // vi kastar ett undantag om ogiltig inmatning
		// efter throw har k�rts s� kommer vi avbryta funktionen... 
		// OBS vi beh�ver en "Try" n�r funktionen anv�nds ... typ 
		// try{
		//		myVector.addAt(72, "blomma"); //vi har inte 72 platser, d�rf�r blir det fel... (ogiltigt index)
	
		//}catch{
		//		//Denna sats k�rs om "throw" utf�rdes av funktionen som var "inramad" av "try"-satsen...
		//	cout << "Error meddelande";
		//}
	}



	if (this->capacity == this->nrOfItems) {

		this->expand();
	}

	this->items[this->nrOfItems] = this->items[index];
	this->nrOfItems++;
	this->items[index] = item;

}

template<typename T>
T Vector<T>::getFirst() const {

}

template<typename T>
T Vector<T>::getLast() const {

}

template<typename T>
T Vector<T>::getLast() const {

}

template<typename T>
T Vector<T>::getAt(int index) const {

}

template<typename T>
T Vector<T>::removeFirst() {

}
template<typename T>
T Vector<T>::removeLast() {

}

template<typename T>
T Vector<T>::removeAt(int index) {
	
}

template<typename T>
void Vector<T>::removeBetween(int start, int end) {

}
#endif // !VECTOR_H

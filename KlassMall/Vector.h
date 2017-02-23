#ifndef VECTOR_H
#define VECTOR_H

template<typename T> //Här deklarerar vi att denna klass inte är en vanlig klass utan en klassmall! 
class Vector {

private:
	T * items;				//Enkelpekare blir smidigare här... en array av typen T...
	int capacity;			//hur stor arrayen är
	int capacityIncrement;	//huur mycket arrayen ska expandera när den ska expandera
	int nrOfItems;			//aktuellt antal element i arrayen
	void expand();

public:
	//* konstruktorer(default, med parameter för kapacitet, med parameter för kapacitet och inkrement)	
	Vector(int capacity = 10, int capacityIncrement=5); // defaultargumenten gör att vi inte behöver en defaultkonstrruktor.. då denna agerar som en sådan...

	//* destruktor
	virtual ~Vector(); //destruktorer ska ALLTID vara virtuella, ifall denna vector någon gång kommer agera som basklass... (tänker på framtiden, lixom)
	
	//* copy - konstruktor

	//* tilldelningsoperator 1
	void addLast(T item);

	void addFirst(T item);
																		//Varje gång Throw används så bör man anropa den funktionen med "try"-satsen
	void addAt(int index, T item) throw(...);			//"throw(...)" <- betyder att denna funktion kan kasta ett "exception"!
	T getFirst() const		throw(...);
	T getLast() const		throw(...);
	T getAt(int index) const throw(...);
	T removeFirst()			throw(...);							//genom att ha returtypen "T" så får man elementet som man tar bort, 
	T removeLast()			throw(...);							//då det kanske ska användas någon annanstanns (bättre än void...)
	T removeAt(int index)	throw(...);
	void removeBetween(int start, int end) throw(...); //Denna är void, då vi inte har lust att returnera en hel array (med värderna mellan start och end...)
	//void clear();
	//* +operatorn
	//*[]operatorn <- överlagra denna 
		//^ kan användas såhär alltså myVector[1] <- det betyder att den ska göra såhär myVector.getAt(1);
		// ^då måste returtypen vara T, se den här:
	T operator[](int index) const throw(...);
};

template<typename T>
void Vector<T>::expand() {
	//1. öka på värdet på capacity
	this->capacity += this->capacityIncrement; //enligt vår capacity increment...

	//2. Göra en T pekare 
	T* temp = new T[this->capacity];

	//3. loopa igenom
	for (int i = 0; i < this->nrOfItems; i++) {
		temp[i] = this->items[i]
	}

	delete[] this->items;

	//ställer om pekaren (obs, ytlige kopiering, bara pekarna... adresserna)
	this->items = temp; 
}


template <typename T> //Såhär gör vi definitionen för vår konstruktor på vår klassmall! Notera att vi forrtfarande är I h-filen! 
Vector<T>::Vector(int capacity, int capacityIncrement) {
	// se till att alla medlems varibler blir initierade... som vanligt
	this->nrOFITems = 0;

	this->capacity = capacity;
	this->capacityIncrement = capacityIncrement;
	this->items = new T[this->capacity];
}

template<typename T>
Vector<T>::~Vector()	//inline Vector<T>::~Vector() <- vad betyder inline? den kom med när jag kopierade... svar: PLOCKA BORT INLINE! 
{
	delete[] this->items;  // vi behöver inte ta bort elementen i items, då de inte är dynamiska! (de är inte skapta med "new")...
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
	
	this->items[this->nrOfItems] = this->items[0]; //Byter plats, den första elementet sätts längst bak
	this->items[0] = item; //det nya elementet sätts längst fram


}

template<typename T>
void Vector<T>::addAt(int index, T item) throw(...){	//här ska "throw(...)" stå för att berätta att användaren 
														//kan använda en try sats för denna funktion
	if (index<0 || index > this->nrOfItems) {
		throw "index is not allowed"; // vi kastar ett undantag om ogiltig inmatning
		// efter throw har körts så kommer vi avbryta funktionen... 
		// OBS vi behöver en "Try" när funktionen används ... typ 
		// try{
		//		myVector.addAt(72, "blomma"); //vi har inte 72 platser, därför blir det fel... (ogiltigt index)
	
		//}catch{
		//		//Denna sats körs om "throw" utfördes av funktionen som var "inramad" av "try"-satsen...
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

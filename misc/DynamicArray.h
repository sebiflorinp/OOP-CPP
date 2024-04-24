#ifndef CPPLAB_DYNAMICARRAY_H
#define CPPLAB_DYNAMICARRAY_H

template <typename Element>
class DynamicArrayIterator;

template <typename Element>
class DynamicArray
{
public:
	// Default constructor
	DynamicArray();

	/*
	 * Copy constructor.
	 * Preconditions: arrayToBeCopied: an instance of the DynamicArray class.
	 * Post-conditions: -
	 */
	DynamicArray(const DynamicArray& arrayToBeCopied);

	// Destructor
	~DynamicArray();

	/*
	 * Assignment operator.
	 * Preconditions: arrayToBeAssigned: an instance of the DynamicArray class.
	 * Post-conditions: an instance of the DynamicArray class.
	 */
	DynamicArray& operator=(const DynamicArray& arrayToBeAssigned);

    /*
     * Move constructor.
     * Preconditions: arrayToBeMoved: an instance of the DynamicArray class.
     * Post-conditions: -
     */
	DynamicArray(DynamicArray&& arrayToBeMoved);

	/*
	 * Move assignment.
	 * Preconditions: arrayToBeMoved: an instance of the DynamicArray class.
	 * Post-conditions: an instance of the DynamicArray class.
	 */
	DynamicArray& operator=(DynamicArray&& arrayToBeMoved);

    /*
     * Adds a new element in the array.
     * Preconditions: newElement: an Element
     * Post-conditions: -
     */
	void add(const Element& newElement);

    /*
     * Returns the element at a given position.
     * Preconditions: position: a positive integer
     * Post-conditions: an Element
     */
	Element& get(int position) const;


    /*
     * Changes the value of the element at the given position to match the given value
     * Preconditions: position: a positive integer
     *                newValue: an Element
     * Post-conditions: -
     */
	void set(int position, const Element& newValue);

    /*
     * Returns the size of the Array.
     * Preconditions: -
     * Post-conditions: an integer
     */
	int size() const noexcept;

    /*
     * Deletes an element at the given position
     * Preconditions: position: a positive integer
     * Post-conditions: -
     */
    void erase(int position);

	friend class DynamicArrayIterator<Element>;

    /*
     * Returns a DynamicArrayIterator at the first position of the Array.
     * Preconditions: -
     * Post-conditions: DynamicArrayIterator
     */
	DynamicArrayIterator<Element> begin() const;

    /*
     * Returns a DynamicArrayIterator at the last position of the Array.
     * Preconditions: -
     * Post-conditions: DynamicArrayIterator
     */
	DynamicArrayIterator<Element> end() const;


private:
	int length;
	int capacity;
	Element* elements;

	void ensureCapacity();
};

template<typename ElementT>
void DynamicArray<ElementT>::erase(int position) {
    for (int i = position; i < length - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    length--;
}

template<typename Element>
DynamicArray<Element>::DynamicArray() :elements{ new Element[2] }, capacity{ 2 }, length{ 0 } {}

template<typename Element>
DynamicArray<Element>::DynamicArray(const DynamicArray<Element>& arrayToBeCopied) {
	elements = new Element[arrayToBeCopied.capacity];

    // Copy the elements in the copy.
	for (int i = 0; i < arrayToBeCopied.length; i++) {
		elements[i] = arrayToBeCopied.elements[i];
	}
	length = arrayToBeCopied.length;
	capacity = arrayToBeCopied.capacity;
}

template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(const DynamicArray<Element>& arrayToBeAssigned) {
    // Create a new array and put the elements of the given on in it.
	delete[] elements;
	elements = new Element[arrayToBeAssigned.capacity];
	for (int i = 0; i < arrayToBeAssigned.length; i++) {
		elements[i] = arrayToBeAssigned.elements[i];
	}
	length = arrayToBeAssigned.length;
	capacity = arrayToBeAssigned.capacity;
	return *this;
}

template<typename Element>
DynamicArray<Element>::~DynamicArray() {
	delete[] elements;
}

template<typename Element>
DynamicArray<Element>::DynamicArray(DynamicArray&& arrayToBeMoved) {
	// Copy the data from the given array.
	elements = arrayToBeMoved.elements;
	length = arrayToBeMoved.length;
	capacity = arrayToBeMoved.capacity;

	// Free the given array so the data doesn't get deleted twice.
	arrayToBeMoved.elements = nullptr;
	arrayToBeMoved.length = 0;
	arrayToBeMoved.capacity = 0;
}

template<typename Element>
DynamicArray<Element>& DynamicArray<Element>::operator=(DynamicArray<Element>&& arrayToBeMoved) {
	// Check if to given array is the same as the current one.
	if (this == &arrayToBeMoved) {
		return *this;
	}
	delete[] elements;
	// Copy the data from the given array to the current one
	elements = arrayToBeMoved.elements;
	length = arrayToBeMoved.length;
	capacity = arrayToBeMoved.capacity;

	// Free the data from the given array so the data isn't deleted twice
	arrayToBeMoved.elements = nullptr;
	arrayToBeMoved.length = 0;
	arrayToBeMoved.capacity = 0;
	return *this;
}

template<typename Element>
void DynamicArray<Element>::add(const Element& newElement) {
	ensureCapacity();
	elements[length++] = newElement;
}

template<typename Element>
Element& DynamicArray<Element>::get(int position) const {
	return elements[position];
}

template<typename Element>
void DynamicArray<Element>::set(int position, const Element& newValue) {
	elements[position] = newValue;
}

template<typename Element>
int DynamicArray<Element>::size() const noexcept {
	return length;
}

template<typename Element>
void DynamicArray<Element>::ensureCapacity() {
	// Check if there is enough space for a new element
	if (length < capacity) {
		return;
	}

	// increase the space if it isn't the case
	capacity *= 2;
	Element* aux = new Element[capacity];
	for (int i = 0; i < length; i++) {
		aux[i] = elements[i];
	}
	delete[] elements;
	elements = aux;
}

template<typename Element>
DynamicArrayIterator<Element> DynamicArray<Element>::begin() const
{
	return DynamicArrayIterator<Element>(*this);
}

template<typename Element>
DynamicArrayIterator<Element> DynamicArray<Element>::end() const
{
	return DynamicArrayIterator<Element>(*this, length);
}

template<typename Element>
class DynamicArrayIterator {
private:
	const DynamicArray<Element>& array;
	int position = 0;
public:
	/*
	 * Constructor of the DynamicArrayIterator.
	 * Preconditions: array: a reference to an instance of the DynamicArray class.
	 * Post-conditions: -
	 */
	DynamicArrayIterator(const DynamicArray<Element>& array) noexcept;

	/*
	 * Constructor of the DynamicArrayIterator.
	 * Preconditions: array: a reference to an instance of the DynamicArray class. 
	 * 				  position: a positive integer
	 * Post-conditions: -
	 */
	DynamicArrayIterator(const DynamicArray<Element>& array, int position)noexcept;

	/*
	 * Checks if the iterator is on a valid position.
	 * Preconditions: -
	 * Post-conditions: a boolean
	 */
	bool valid()const;

	/*
	 * Returns the element at the position the iterator is at.
	 * Preconditions: -
	 * Post-conditions: an Element
	 */
	Element& element() const;

    /*
     * Moves the iterator one position forward.
     * Preconditions: -
     * Post-conditions: -
     */
	void next();

    /*
     * Returns the element the iterator is currently pointing at.
     * Preconditions: -
     * Post-conditions: an Element
     */
	Element& operator*();

    /*
     * Moves the iterator one position forward.
     * Preconditions: -
     * Post-conditions: -
     */
	DynamicArrayIterator& operator++();

    /*
     * Checks if two iterators are at the same position.
     * Preconditions: anotherDynamicArrayIterator: an instance of the DynamicArrayIterator class.
     * Post-conditions: a boolean
     */
	bool operator==(const DynamicArrayIterator& anotherDynamicArrayIterator)noexcept;

    /*
     * Checks if two iterators are on different positions.
     * Preconditions: anotherDynamicArrayIterator: an instance of the DynamicArrayIterator class.
     * Post-conditions: a boolean.
     */
	bool operator!=(const DynamicArrayIterator& anotherDynamicArrayIterator)noexcept;
};

template<typename Element>
DynamicArrayIterator<Element>::DynamicArrayIterator(const DynamicArray<Element>& v) noexcept:array{ v } {}

template<typename Element>
DynamicArrayIterator<Element>::DynamicArrayIterator(const DynamicArray<Element>& array, int position)noexcept :
array{ array }, position{ position } {}

template<typename Element>
bool DynamicArrayIterator<Element>::valid()const {
	return position < array.length;
}

template<typename Element>
Element& DynamicArrayIterator<Element>::element() const {
	return array.elements[position];
}

template<typename Element>
void DynamicArrayIterator<Element>::next() {
	position++;
}

template<typename Element>
Element& DynamicArrayIterator<Element>::operator*() {
	return element();
}

template<typename Element>
DynamicArrayIterator<Element>& DynamicArrayIterator<Element>::operator++() {
	next();
	return *this;
}

template<typename Element>
bool DynamicArrayIterator<Element>::operator==(const DynamicArrayIterator<Element>& anotherDynamicArrayIterator) noexcept {
	return position == anotherDynamicArrayIterator.position;
}

template<typename Element>
bool DynamicArrayIterator<Element>::operator!=(const DynamicArrayIterator<Element>& anotherDynamicArrayIterator)noexcept {
	return !(*this == anotherDynamicArrayIterator);
}

#endif //CPPLAB_DYNAMICARRAY_H

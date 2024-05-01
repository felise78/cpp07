#ifndef ARRAY_HPP
 #define ARRAY_HPP

	#include <cstddef>
	#include <stdexcept>
	#include <sstream>
	
	// Template Class

	template <typename T>
	class Array {

		private:
		T* 				_elements;
		unsigned int 	_size;

		public:
		// Constructor
		Array() : _elements(NULL), _size(0) {}

		// Constructor with param
		Array(unsigned int n) : _size(n) {
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; ++i) { // pb de conditional jumps if this is not set
				_elements[i] = T();
			}
		}

		// Copy constructor
		Array(const Array& copy) { this->_elements = NULL; *this = copy; }

		// Assignment operator
		Array<T>& operator=(const Array<T>& src) {
			if (this != &src) {
				if ( this->_elements != NULL ) 
					delete [] this->_elements;
				this->_size = src._size;
				this->_elements = new T[ this->_size ];
				for (unsigned int i = 0; i < this->_size; ++i) {
					this->_elements[i] = src._elements[i];
				}
			}
			return *this;
		}

		// Destructor
		~Array() { delete[] this->_elements; }

		// Subscript operator
		T& operator[] ( unsigned int index ) {
			if (index >= this->_size) {
				std::stringstream buffer;
            	buffer << "Index [" << index << "] is out of bounds";
				throw std::out_of_range( buffer.str() );
			}
			return this->_elements[ index ];
		}

		// Subscript const operator
		const T& operator[] ( unsigned int index ) const {
			if (index >= this->_size) {
				std::stringstream buffer;
            	buffer << "Index [" << index << "] is out of bounds";
				throw std::out_of_range( buffer.str() );
			}
			return this->_elements[ index ];
		}

		// Size function 
		unsigned int size() const { return this->_size; }
	};

	template <typename T>
	std::ostream & operator<<( std::ostream & os, const Array<T> & array ) {
    os << "[";
    size_t size = array.size();
    for( size_t position = 0; position < size; ++position ) {
        os << array[position];
        if ( position < size - 1 ) os << ", ";
    }
    return os << "]";
}

#endif
 
// https://koor.fr/Cpp/Templates/TemplatedClass.wp

/*
	implémenter les méthodes génériques (templates) directement dans le corps de la classe : 
	Attention, dans ce cas, les méthodes produites seront aussi considérées comme inline. 
*/
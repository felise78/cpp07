// Templates MUST be defined in the header file

#ifndef WHATEVER_HPP
 #define WHATEVER_HPP

	template <typename T>
	static void swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <typename T>
	static T min(const T& a, const T& b)
	{
		if(a < b)
			return a;
		else
			return b;
	}

	template <typename T>
	static T max(const T& a, const T& b)
	{
		if(a > b)
			return a;
		else
			return b;
	}

#endif

// static : car dans le main il n'y a pas d'instances 

/* templates - 
vous ne connaissez pas à l'avance la taille des types de données qui seront utilisés. 
Il en résulte qu'il est important de passer les paramètres de méthodes par références : 
ainsi on limitera le nombre d'octets qui seront empile sur la pile d'exécution (la stack)
durant l'appel.
*/
#ifndef ITER_HPP
 #define ITER_HPP

	template <typename T, typename Fonc>
	static void iter(T* arr, int len, Fonc func)
	{
		for (int i = 0; i < len; ++i) {
			func(arr[i]);
		}
	}

	template <typename T>
	void print(const T& value) {
		std::cout << value << " ";
	}

#endif
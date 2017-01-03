void swap(int & a , int & b){
	int temp = a;
	a = b;
	b = temp;
}

void swap(float & a , float & b){
	float temp = a;
	a = b;
	b = temp;
}

template<T>
void swap(T & a , T & b){
	T temp = a;
	a = b;
	b = temp;
}


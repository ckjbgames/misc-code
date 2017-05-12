template<class T>
bool in(T val, T* arr, int arrlen) {
	/*
	 * Test if a value is in an array.
	 */
	int count;
	bool retval;
	for(count = 0;count < arrlen;count++) {
		if(arr[count]==val) {
			retval=true;
			break;
		}
	}
	if(!retval) retval=false;
	return retval;
}


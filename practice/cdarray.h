#ifndef CDARRAY
#define CDARRAY


template <typename TType>
class CDArray
{
private:
	TType *mArray;
	size_t mArraySize;
	size_t mCapacity;
	const int mDefaultCapacity;
	const float mSizeMultiplier;

public:
	CDArray();
	CDArray(const size_t& mArraySize);
	CDArray(const CDArray &obj);
	~CDArray();

	TType& operator[](const size_t& i);
	void reserve(const size_t& newCapacity);
	void resize(const size_t& newSize);
	void push_back(const TType& object);
	TType& pop_back();
	size_t size() const;
	size_t max_size() const;
	bool empty() const;
	void clear();
	void erase(const size_t& index);
	void swap(const size_t& firstObjIndex, const size_t& secondObjIndex);
	void compress();
	size_t capacity() const;


	class iterator {
	private:
		TType *ptr;
	public:
		iterator(TType* ptr_ = 0) : ptr(ptr_) {}
		TType* getPtr() const;
		void setPtr(TType* p);
		iterator& operator=(iterator& right);
		TType& operator*();
		TType* operator->();
		TType* operator++();
		TType* operator+(int i);
		TType* operator-(int i);
		TType* operator--();
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
	};


	void erase(iterator index);
	void erase(iterator startIndex, iterator endIndex);
	void swap(iterator firstObj, iterator secondObj);
	iterator begin();
	iterator end();
	iterator find(TType& obj);
	iterator find_back(TType& obj);
};


//------------------------------------------------------------------------------
//		Iterator class implementation
//------------------------------------------------------------------------------

template <typename TType>
TType* CDArray<TType>::iterator::getPtr() const
{
	return ptr;
}

template <typename TType>
void CDArray<TType>::iterator::setPtr(TType* p)
{
	ptr = p;
}

template <typename TType>
typename CDArray<TType>::iterator& CDArray<TType>::iterator::operator=(iterator& right) // 0_0
{
	if (this == &right)
	{
		return *this;
	}
	ptr = right.ptr;
	return *this;
}

template <typename TType>
TType& CDArray<TType>::iterator::operator*()
{
	return *ptr;
}

template <typename TType>
TType* CDArray<TType>::iterator::operator->()
{
	return ptr;
}

template <typename TType>
TType* CDArray<TType>::iterator::operator++()
{
	return ++ptr;
}

template <typename TType>
TType* CDArray<TType>::iterator::operator+(int i)
{
	ptr = ptr + i;
	return ptr;
}

template <typename TType>
TType* CDArray<TType>::iterator::operator-(int i)
{
	ptr = ptr - i;
	return --ptr;
}

template <typename TType>
TType* CDArray<TType>::iterator::operator--()
{
	return --ptr;
}

template <typename TType>
bool CDArray<TType>::iterator::operator==(const iterator& other) const
{
	return ptr == other.ptr;
}

template <typename TType>
bool CDArray<TType>::iterator::operator!=(const iterator& other) const
{
	return !(*this == other);
}


//------------------------------------------------------------------------------
//		CDArray class implementation
//------------------------------------------------------------------------------

template <typename TType>
CDArray<TType>::CDArray() : mDefaultCapacity(10), mSizeMultiplier(1.1f)
{
	mCapacity = mDefaultCapacity;
	mArray = new TType[mCapacity];
	mArraySize = 0;
}

template <typename TType>
CDArray<TType>::CDArray(const size_t &mArraySize) : mDefaultCapacity(10), mSizeMultiplier(1.1f)
{
	mCapacity = mArraySize * 2;
	mArray = new TType[mCapacity];
	this->mArraySize = mArraySize;
}

template <typename TType>
CDArray<TType>::CDArray(const CDArray& obj)
{
	//TODO
	this->mCapacity = obj.mCapacity;
	this->mArraySize = obj.mArraySize;
	
	this->mArray = new TType[obj.mCapacity];
	for (size_t i = 0; i < obj.mArraySize; i++)
	{
		this->mArray[i] = obj[i];
	}
}

template <typename TType>
CDArray<TType>::~CDArray()
{
	delete[] mArray;
}


template <typename TType>
TType &CDArray<TType>::operator[](const size_t &i)
{
	/*
	if (i < 0 || i >= mArraySize)
	{
		throw std::out_of_range("Out of range!");
	}
	*/
	return mArray[i];
}

template <typename TType>
void CDArray<TType>::reserve(const size_t &newCapacity)
{
	TType *tempPointer;
	mCapacity = newCapacity;
	tempPointer = new TType[mCapacity];
	if (0 != mArraySize)
	{
		for (size_t i = 0; i < mArraySize; i++)
		{
			tempPointer[i] = mArray[i];
		}
	}
	delete[] mArray;
	mArray = tempPointer;
}

template <typename TType>
void CDArray<TType>::resize(const size_t& newSize)
{
	TType *tempPointer;
	mArraySize = newSize;
	mCapacity = newSize * mSizeMultiplier;
	tempPointer = new TType[mCapacity];
	if (0 != mArraySize)
	{
		for (size_t i = 0; i < mArraySize; i++)
		{
			tempPointer[i] = mArray[i];
		}
	}
	delete[] mArray;
	mArray = tempPointer;
}

template <typename TType>
void CDArray<TType>::push_back(const TType& object)
{
	if (mArraySize >= mCapacity)
	{
		reserve(mCapacity*mSizeMultiplier);
		mArray[mArraySize] = object;
		mArraySize++;
	}
	else
	{
		mArray[mArraySize] = object;
		mArraySize++;
	}
}

template <typename TType>
TType &CDArray<TType>::pop_back()
{
	TType temp = mArray[mArraySize - 1];
	erase(mArraySize - 1);
	return temp;
}

template <typename TType>
size_t CDArray<TType>::size() const
{
	return mArraySize;
}

template <typename TType>
size_t CDArray<TType>::max_size() const
{
	size_t i = 0;
	return ~i;
}

template <typename TType>
bool CDArray<TType>::empty() const
{
	return 0 == mArraySize;
}

template <typename TType>
void CDArray<TType>::clear()
{
	delete[] mArray;
	mArray = new TType[mDefaultCapacity];
	mCapacity = mDefaultCapacity;
	mArraySize = 0;
}

template <typename TType>
void CDArray<TType>::erase(const size_t &index)
{
	if (0 != mArraySize && index < mArraySize)
	{
		TType *tempPointer = new TType[mCapacity - 1];
		for (size_t i = 0; i < index; i++)
		{
			tempPointer[i] = mArray[i];
		}
		for (size_t i = index + 1; i < mArraySize; i++)
		{
			tempPointer[i - 1] = mArray[i];
		}
		delete[] mArray;
		mCapacity--;
		mArraySize--;
		mArray = tempPointer;
	}
}

template <typename TType>
void CDArray<TType>::erase(iterator index)
{
	TType *tempPointer = new TType[mCapacity - 1];
	size_t tempIndex = 0;
	for (size_t i = 0; i < mArraySize; i++)
	{
		if (&mArray[i] == index.getPtr() + 1)
		{
			break;
		}
		tempPointer[i] = mArray[i];
		tempIndex = i;
	}
	for (size_t i = tempIndex + 1; i < mArraySize; i++)
	{
		tempPointer[i - 1] = mArray[i];
	}
	delete[] mArray;
	mCapacity--;
	mArraySize--;
	mArray = tempPointer;
}

template <typename TType>
void CDArray<TType>::erase(iterator startIndex, iterator endIndex)
{
	TType *tempPointer = new TType[mArraySize];
	size_t tempIndex = 0;
	size_t tempOuterIndex = 0;

	for (size_t i = 0; i < mArraySize; i++)
	{
		if (&mArray[i] == startIndex.getPtr())
		{
			break;
		}
		tempPointer[i] = mArray[i];
		tempIndex = i;
		tempOuterIndex = i;
	}
	for (size_t i = tempIndex + 1; i < mArraySize; i++)
	{
		if (&mArray[i] == endIndex.getPtr() + 1)
		{
			break;
		}
		tempIndex = i;
	}
	for (size_t i = tempIndex; i < mArraySize; i++)
	{
		tempPointer[tempOuterIndex + 1] = mArray[i];
		tempOuterIndex++;
	}

	delete[] mArray;

	mArray = new TType[tempOuterIndex*mSizeMultiplier];
	mArray = tempPointer;
	mArraySize = tempOuterIndex + 1;
}

template <typename TType>
void CDArray<TType>::swap(iterator firstObj, iterator secondObj)
{
	// TODO doesn't work =(
	TType *first = firstObj.getPtr();
	TType *second = secondObj.getPtr();
	TType temp = *first;
	*first = *second;
	*first = temp;
}

template <typename TType>
void CDArray<TType>::swap(const size_t &firstObjIndex, const size_t &secondObjIndex)
{
	if (firstObjIndex < mArraySize && secondObjIndex < mArraySize)
	{
		TType tempObj = mArray[firstObjIndex];
		mArray[firstObjIndex] = mArray[secondObjIndex];
		mArray[secondObjIndex] = tempObj;
	}
}

template<typename TType>
void CDArray<TType>::compress()
{
	mCapacity = mArraySize;
	reserve(mCapacity);
}

template<typename TType>
size_t CDArray<TType>::capacity() const
{
	return mCapacity;
}


template <typename TType>
typename CDArray<TType>::iterator CDArray<TType>::begin()
{
	iterator it;
	it.setPtr(mArray);
	return it;
}

template <typename TType>
typename CDArray<TType>::iterator CDArray<TType>::end()
{
	iterator it;
	it.setPtr(mArray + mArraySize);
	return it;
}

template<typename TType>
typename CDArray<TType>::iterator CDArray<TType>::find(TType& obj)
{
	iterator it;
	it.setPtr(0);
	for (size_t i = 0; i < mArraySize; i++)
	{
		if (obj == mArray[i])
		{
			it.setPtr(&mArray[i]);
			break;
		}
	}
	return it;
}

template<typename TType>
typename CDArray<TType>::iterator CDArray<TType>::find_back(TType& obj)
{
	iterator it;
	it.setPtr(0);
	for (size_t i = mArraySize; i >= 0; i--)
	{
		if (obj == mArray[i])
		{
			it.setPtr(&mArray[i]);
			break;
		}
	}
	return it;
}


#endif CDARRAY

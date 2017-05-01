#ifndef _CMYVECTOR_HPP
#define _CMYVECTOR_HPP

template <typename T>
struct SElement
{
	T mData;
	SElement<T>* next;
};

template <typename T>
class CMyVector
{
public:
	CMyVector();
	~CMyVector();
	void push_back(const T& object);
	void clear();
	SElement<T>* _current();
	SElement<T>* _begin();
private:
	SElement<T>* begin, * current;
};

template <typename T>
CMyVector<T>::CMyVector()
{
	begin = 0;
	current = 0;
}

template <typename T>
CMyVector<T>::~CMyVector()
{
   while(current)
   {
      SElement<T>* temp = current->next;
      delete current;
      current = temp;
   }
}

template <typename T>
void CMyVector<T>::push_back(const T& object)
{
	SElement<T>* temp = new SElement<T>;
   temp->mData = object;
   temp->next = begin;
   begin = temp;
}

template <typename T>
void CMyVector<T>::clear()
{
   while(current)
   {
      SElement<T>* temp = current->next;
      delete current;
      current = temp;
   }
}

template <typename T>
SElement<T>* CMyVector<T>::_begin()
{
	return begin;
}

template <typename T>
SElement<T>* CMyVector<T>::_current()
{
	return current;
}

#endif
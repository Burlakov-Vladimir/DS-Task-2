// DynamicStack.h : This file contains the "DynamicStack" Class.

#pragma once

template <typename T>
class DynamicStack
{
public:
   DynamicStack();

   ~DynamicStack();

   DynamicStack(const DynamicStack &) = delete;

   DynamicStack &operator=(const DynamicStack &) = delete;

   T &operator[](size_t index);

   size_t size(DynamicStack &stack) const;

   void extendCapacity();
   void reduceCapacity();
   void pushBack(T data);
   void popBack();

   bool empty() const;
   void printEmpty(std::ostream &output);
	void printPopError(std::ostream &output);
   void print(std::ostream &output);

private:
   T *data_;
   size_t size_;
   size_t capacity_;
};


template <typename T>
DynamicStack<T>::DynamicStack()
{
	data_ = static_cast<T *>(malloc(1 * sizeof(T)));
	size_ = 0;
	capacity_ = 0;
}


template <typename T>
DynamicStack<T>::~DynamicStack()
{
	free(data_);
}


template<typename T>
inline T &DynamicStack<T>::operator[](size_t index)
{
	return data_[index];
}


template<typename T>
inline size_t DynamicStack<T>::size(DynamicStack &stack) const
{
	return size_;
}


template<typename T>
void DynamicStack<T>::extendCapacity()
{
	if (capacity_ == 0)
	{
		capacity_++;
	}

	capacity_ *= 2;
	data_ = static_cast<T *>(realloc(data_, (capacity_) * sizeof(T)));
}


template<typename T>
void DynamicStack<T>::reduceCapacity()
{
	capacity_ = size_;
	data_ = static_cast<T *>(realloc(data_, (capacity_) * sizeof(T)));
}


template<typename T>
void DynamicStack<T>::pushBack(T data)
{
	if (size_ >= capacity_)
	{
		extendCapacity();
	}

	data_[size_] = data;
	size_++;
}


template<typename T>
void DynamicStack<T>::popBack()
{
	if (size_ != 0)
	{
		size_--;
	}
	else
	{
		printPopError(std::cout);
	}

	if (size_ < capacity_ / 4)
	{
		reduceCapacity();
	}
}


template<typename T>
inline bool DynamicStack<T>::empty() const
{
	return size_ == 0;
}


template<typename t>
inline void DynamicStack<t>::printEmpty(std::ostream &output)
{
	if (empty())
		output << "Stack is empty." << std::endl;
	else
		output << "Stack is not empty." << std::endl;
}

template<typename T>
inline void DynamicStack<T>::printPopError(std::ostream &output)
{
	output << "ERROR: Stack is empty. Pop Back cannot be done." << std::endl;
}


template<typename t>
void DynamicStack<t>::print(std::ostream &output)
{
	if (empty())
	{
		printEmpty(output);
	}
	else
	{
		output << "Stack = {";
		for (size_t i = 0; i < size_ - 1; i++)
		{
			output << data_[i] << ", ";
		}
		output << data_[size_ - 1] << '}'<< std::endl;
	}
}

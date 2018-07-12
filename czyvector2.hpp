#ifndef VECTOR_H
#define VECTOR_H
#define SPACE_CAPACITY 2 
namespace stl
{
  template<typename Object>
  class Vector
  {
	public:
	class reverse_iterator
	{
		private:
			Pointer t;
		public:
			reverse_iterator(Pointer _t=nullptr):t(_t){
			}
			bool operator !=( const reverse_iterator & other) const
			{
				return t != other.t;
			}
			bool operator == (const reverse_iterator & other) const
			{
				return t == other.t;
			}
			T operator *()
			{
				return *t;
			}
			reverse_iterator operator ++()
			{
				return --t;
			}
			void operator ++(int)
			{
				 Pointer tmp = t;
				 --t;
				 return tmp;
			}
			reverse_iterator operator --()
			{
				return ++t;
			}
			void operator --(int)
			{
				iterator tmp = t;
				++t;
				return tmp;
			}
			reverse_iterator operator -=(size_type it)
        	{
            	return t+=it;
        	}
        	reverse_iterator operator +=(size_type it)
        	{
            	return t-=it;
        	}
			
		};
				 
  private:
      size_t theSize;
      size_t theCapacity;
      Object* Objects;
  public:
    explicit Vector(int initsize = 0)
	:theSize(initsize)
    ,theCapacity(initsize + SPACE_CAPACITY)
    {
      Objects = new Object[theCapacity];
    }
    Vector(const Vector& V)
    :theSize(0)
    ,theCapacity(0)
    ,Objects(0)
    {
      *this = V;
    }
	~Vector()
    {
      delete[ ] Objects;
    }
    Vector &operator = (const Vector& ths)
    {
      if(this !=ths)
      {
        delete[] Objects;
        theSize = ths.theSize;
        theCapacity = ths.theCapacity;

        for(int i=0;i<ths.theSize;++i)
        {
          Objects[i] = ths.Objects;
        }
      }
      return *this;
    }
    void resize(int newSize)
    {
      if(newSize <= theSize)
      {
      	theSize = newSize;
        return;
	  } 
      if(newSize>theCapacity)
        resize(2*newSize +1);
      theSize = newSize;
    }
    void reserve(int newCapacity)
    {
      if(newCapacity < theSize)
      {
        return ;
      }
      Object * temp=Objects;
      Objects = new Object[newCapacity];
      for(int i=0;i< theSize;++i)
      {
        Objects[i] = temp[i];
      }
      delete[] temp;
    }
    
    Object & operator [] (int index)
    {
      return Objects[index];
    }
    
    const Object& operator[](int index) const
    {
      return Objects[index];
    }
    bool isEmpty() const
    {
      return size() == 0;
    }
    int size() const
    {
      return theSize;
    }
    int capacity() const
    {
      return theCapacity;
    }
    void push_back(Object obj)
    {
      if(theSize == theCapacity)
      {
        reserve(2*theCapacity+1);
      }
      Objects[theSize++] = obj;
    }
    void pop_back()
    {
      --theSize;
    }
    const Object & back() const
    {
      return Objects[size()-1];
    }
    typedef Object* iterator;
    typedef const Object* const_iterator;

    iterator begin()
    {
      return &Objects[0];
    }

    iterator end()
    {
      return &Objects[size()];
    }
    const_iterator cbegin() const
    {
      return &Objects[0];
    }
	iterator insert(iterator pos,const_reference value)
    {
        theSize++;
        if(theSize==theCapacity)
        	reserve(2*theCapacity+1);
        for(auto i=end()-1;i!=pos;i--)
            *i=*(i-1);
        *pos=value;
        return pos;
    }
    void clear()
   	{
		theSize=0;
    }
   	iterator erase( const_iterator pos )
   	{
   		if(theSize==0)
        {
        	printf("There is nothing in the vector!\n");
        	exit(1);	
		}	
        else
        {
        	--theSize;
        	for(size_type i=pos;i<theSize;i++)
            	Objects[i]=Objects[i+1];
        	return begin()+pos;
		}
        	
			
	}
	iterator erase( const_iterator first, const_iterator last )
	{
		if(theSize==0)
        {
        	printf("There is nothing in the vector!\n");
        	exit(1);	
		}	
        else
        {
        	--theSize;
        	for(size_type i=first;i<last;i++)
            	Objects[i]=Objects[i+last];
        	return begin();
		}
        	
	}
	void swap(vector & s)
    {
        pointer tmp=Objects;
        Objects=s.Objects;
        s.Objects=tmp;
        size_type tmp=theSize;
        theSize=s.theSize;
        s.theSize=tmp;
        size_type tmp=theCapacity;
        theCapacity=s.theCapacity;
        s.theCapacity=tmp;
    }
    void shrink_to_fit()
    {
        theCapacity=theSize+1;
        pointer tmp=Objects;
        pointer Object=new value_type[theCapacity];
        for(size_type i=0;i<theSize;i++)
            Object[i]=Objects[i];
        Objects=Object;
        delete[] tmp;
    }
	}
}
#endif

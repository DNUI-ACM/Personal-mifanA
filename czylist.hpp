#ifndef LIST_H
#define LIST_H

namespace stl
{
    template<typename Object>
    class List
    {
        private:
            struct Node
            {
                Object data;
                Node*prev;
                Node*next;
                Node(Object obj=object(),Node*p=NULL,Node*n=NULL)
                :data(obj),prev(p),next(n){ }
            };
            Node*head;
            Node*tail;
            size_t theSize;
        public:
            List():theSize(0),head(NULL),tail(NULL)
            {   }

            List(const List&L)
            {
                init();
                *this = L;
            }

            const List & operator = (const List &L)
            {
                if(this == &L)
                {
                    return *this;
                }

                clear();

                for(iterator from = L.begin();from !=L.cend();++from)
                {
                    push_back(*from);
                }
                return *this;
            }

            bool operator == (const List &L)
            {
                return head == L.head && tail == L.tail&&theSize == L.theSize;
            }

            bool operator < ( const std::list<T,Alloc>& lhs,const std::list<T,Alloc>& rhs );
            {
                Node*temp1 = lhs.head->next;
                Node*temp2 = rhs.head->next;

                while (temp1!=lhs.tail&&temp2!=rhs.tail)
                {
                    Node*tempNext1 = temp1->next;
                    Node*tempNext2 = temp2->next;
                    if(temp1->data >= temp2->data)
                        return 0;
                    temp1 = tempNext1;
                    temp2 = tempNext2;
                }
                return 1;
            }

            bool operator <= ( const std::list<T,Alloc>& lhs,const std::list<T,Alloc>& rhs );
            {
                Node*temp1 = lhs.head->next;
                Node*temp2 = rhs.head->next;

                while (temp1!=lhs.tail&&temp2!=rhs.tail)
                {
                    Node*tempNext1 = temp1->next;
                    Node*tempNext2 = temp2->next;
                    if(temp1->data > temp2->data)
                        return 0;
                    temp1 = tempNext1;
                    temp2 = tempNext2;
                }
                return 1;
            }

            bool operator > ( const std::list<T,Alloc>& lhs,const std::list<T,Alloc>& rhs );
            {
                Node*temp1 = lhs.head->next;
                Node*temp2 = rhs.head->next;

                while (temp1!=lhs.tail&&temp2!=rhs.tail)
                {
                    Node*tempNext1 = temp1->next;
                    Node*tempNext2 = temp2->next;
                    if(temp1->data <= temp2->data)
                        return 0;
                    temp1 = tempNext1;
                    temp2 = tempNext2;
                }
                return 1;
            }

            bool operator >= ( const std::list<T,Alloc>& lhs,const std::list<T,Alloc>& rhs );
            {
                Node*temp1 = lhs.head->next;
                Node*temp2 = rhs.head->next;

                while (temp1!=lhs.tail&&temp2!=rhs.tail)
                {
                    Node*tempNext1 = temp1->next;
                    Node*tempNext2 = temp2->next;
                    if(temp1->data < temp2->data)
                        return 0;
                    temp1 = tempNext1;
                    temp2 = tempNext2;
                }
                return 1;
            }

            ~List()
            {
                Node*temp = head->next;

            while (temp!=tail)
            {
            	Node*tempNext = temp->next;
                delete temp;
                temp = tempNext;
            }
            delete head;
            delete tail;
            }

            void init()
            {
            head = new Node;
            tail = new Node;
            head->next = tail;
            tail->prev =head;
            }

        public://??????Ķ??
            class const_iterator
            {
            public:
            const_iterator(Node *n=NULL)
            :current(n){}

            const Object& operator *() const
            {
                retrieve();
            }

            const_iterator & operator ++()
            {
                current = current->next;
                return * this;
            }

            const_iterator & operator ++(int)
            {
                const_iterator*p = *this;
                ++(*this);
                return p;
            }

            const_iterator & operator --()
            {
                current = current-> prev;
                return *this;
            }

            const_iterator & operator --(int)
            {
                const_iterator* p = *this;
                p=p->prev;
                return p;
            }

            bool operator != (const const_iterator & iter) const
            {
                return ! (this->operator == (iter));
            }

            protected:
                Node* current;

                const Object & retrieve() const
                {
                    return current->data;
                }

                const_iterator(Node*p):current(p) { }

                friend class List<Object>;
        };

        class iterator : public const_iterator
        {
        public:
            iterator();
            ~iterator();

            Object& operator*() const
            {
                retrieve();
            }

            iterator & operator ++()
            {
                current = current->next;
                return * this;
            }

            iterator & operator ++(int)
            {
                const_iterator ret = *this;
                ++*this;
                return ret;
            }
            protected:
                iterator(Node*p): const_iterator(p){}
        	};

            iterator begin()
            {
                return iterator(head->next);
            }

            iterator begin() noexcept
            {
                return iterator(head->next);
            }

            const_iterator begin() const noexcept
            {
                return const_iterator(head->next);
            }

            const_iterator cbegin() const noexcept
            {
                return const_iterator(head->next);
            }

			iterator end() noexcept
			{
				return iterator(tail);
			}

            const_iterator end() const noexcept
            {
                return const_iterator(tail);
            }

            const_iterator cend() const noexcept
            {
                return const_iterator(tail);
            }

            const_iterator cbegin() const noexcept
            {
                return const_iterator(head->next);
            }

            const_iterator cend() const noexcept
            {
                return const_iterator(tail);
            }


            reverse_iterator rbegin() noexcept
            {
                 return iterator(tail);
            }

            void assign( size_type count, const Object & value )
            {
                clear();
                for(size_t i=0;i<count;++i)
                {
                    push_back(*value);
                }
            }

            // void sort()
            // {
            //     // int n = theSize,len=1;
            //     // while(len<n)
            //     // {
            //     //      ist &p;
            //     //      pass(this.current,p,n,len);
            //     //      len*=2;
            //     //      pass(p,this,n,len);
            //     //      len*=2;
            //     // }

            //     // for(iterator from = first;from != last;++from)
            //     // {
            //     //
            //     // }
            // }

            // void pass(iterator a,iterator t,int n,int len)
            // {
            //     iterator i,j;
            //     for( i=begin();i<=end()-2;i+=2*len)
            //         // merge(a,t,i+len,i+2*len);
            //     if(i+len<n)
            //         // merage(a,t,i,i+len,n);
            //     else

            // }

            void merge( list&& other )
            {
                List & L
                List(L);
                iterator h1=*this.head->next,h2=*(*other).head->next,h3=*L.head->next;
                while(h1!=*this.tail&&h2!=*(*other).tail)
                {
                    if(h1->data < h2->data)
                    {
                        *L.push_back(h1->data);
                        h1=h1->next;
                    }
                    else
                    {
                        *L.push_back(h2->data);
                        h2=h2->next;
                    }
                }
                while(h1!=*this.tail)
                {
                    *L.push_back(h1->data);
                     h1=h1->next;
                }
                while(h2!=*(*other).tail)
                {
                    *L.push_back(h2->data);
                     h2=h2->next;
                }
                other = &L;
            }

            const_reverse_iterator rbegin() const noexcept
            {
                 return const_iterator(tail);
            }

            const_reverse_iterator crbegin() const noexcept
            {
                 return const_iterator(tail);
            }

            reverse_iterator rend() noexcept
            {
                return iterator(head-1);
            }

            const_reverse_iterator  rend() const noexcept
            {
                return const_iterator(head-1);
            }

            const_reverse_iterator  crend() const noexcept
            {
                return const_iterator(head-1);
            }

            size_t Size() const
            {
                return theSize;
            }

            bool Empty()const
            {
                return Size()==0;
            }

            void push_back(const Object& obj)
            {
                insert(end(),obj);
            }

            void push_front(Object obj)
            {
                insert(begin(),obj);
            }

            void resize(size_type count,const value_type & value)
            {
                if(theSize>count)
                {
                    while(theSize!=count)
                    {
                        pop_back();
                    }
                }
                else
                {
                    while(theSize!=count)
                    {
                        push_back(value);
                    }
                }
            }

            void resize(size_type count)
            {
                if(theSize>count)
                {
                    while(theSize!=count)
                    {
                        pop_back();
                        --theSize;
                    }
                }
                else
                {
                    while(theSize!=count)
                    {
                        push_back(0);
                        ++theSize;
                    }
                }
            }

            /*??*/void swap( list& other ) noexcept(std::allocator_traits<Allocator>::is_always_equal::value)
            {

            }

            void remove(const Object& value)
            {
                Node*temp = head->next;
                while (temp!=tail)
                {
                    Node*tempNext = temp->next;
                    if(temp->data==value)
                        erase(temp);
                    temp = tempNext;
                }
            }

            void reverse() noexcept
            {
                Node*temp,*newhead=NULL;
                while(head)
                {
                    temp=head;
                    head=head->next;
                    temp->next = newhead;
                    newhead=temp;
                }
            }

            size_type unique()
            {
                Node*temp = head->next->next;
                int num=0;
                while (temp!=tail)
                {
                    Node*tempNext = temp->next;
                    if(temp->data==temp->prev->data)
                        {
                            erase(temp);
                            ++num;
                        }
                    temp = tempNext;
                }
                return num;
            }

            void splice(const_iterator pos,list&& other)
            {
                //Node* head2=*other.head;
                // Node*p= pos.current;
                while(!other.Empty())
                {
                    insert(pos,*other.front());
                    pop_front();
                    ++pos;
                }
            }

            void splice( const_iterator pos, list&& other, const_iterator it )
            {
                insert(pos,*it);
                list.erase(it);
            }

            void splice( const_iterator pos, list&& other, const_iterator first, const_iterator last )
            {
                Node*p= pos.current;
                for(iterator from = first;from != last;++from)
                {
                    insert(pos,*from);
                    ++pos;
                }
            }

            iterator insert(iterator it,const Object & obj)
            {
                Node*p= it.current;
                Node*node=new Node(obj,p->prev,p);
                p->prev->next = node;
				p->prev = node;
				++theSize;
				return iterator(node);
            }

            const Object &front() const
            {
            	return head->next->data;
			}

			Object &back() const
			{
				return tail->prev->data;
			}

			void pop_front()
			{
				Node*temp = head->next;
				temp->next->prev = head;
				head->next = temp->next;
				delete temp;
				theSize--;
			}

            void pop_back()
            {
                erase(--end());
            }

            void clear()
            {
                while(!Empty())
                    pop_front();
            }

			iterator erase(iterator itr)
			{
				Node*temp=itr.current;
				iterator ret = ++itr;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				theSize--;
				return ret;
			}

			iterator erase(iterator itr1,iterator itr2)
			{
				iterator to = ++itr2;
				for(iterator i = itr1;i!=to;)
					i=erase(i);
			}
			return i;

    }
}
#endif

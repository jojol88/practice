template <typename T>
struct Data
 {
     T x;
     Data<T> *Next,*Prev;
 };
 
template <typename T> 
class List 
 {
     Data<T> *Head,*Tail;
 public:
     List<T>():Head(NULL),Tail(NULL){};
     ~List();
     void Show();
     void Add(T x);
 };

template <typename T> 
List<T>::~List()
 {   
     while (Head)
     {
         Tail=Head->Next;
         delete Head;
         Head=Tail;
     }
 }

template <typename T> 
 void List<T>::Add(T x)
 {
   Data<T> *temp=new Node;
   temp->Next=NULL;
   temp->x=x;
   if (Head!=NULL)
   {
       temp->Prev=Tail;
       Tail->Next=temp;
       Tail=temp;
   }
   else
   {
       temp->Prev=NULL;
       Head=Tail=temp;
   }
 }

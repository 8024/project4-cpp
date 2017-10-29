//#include<iostream>
//
//
//using namespace std;
//extern int error_exist;		//	标志错误是否存在，为1时存在，否则不存在
//class QUEUE {
//	int *const elems;		//申请内存用于存储
//	const int max;			//队列能存放的最大元素个数
//	int head, tail;			//队列的头和尾，当队列为空时，head=tail
//public:
//	QUEUE(int m);						//初始化m个元素空间大小的队列
//	QUEUE(const QUEUE&s);				//用s队列初始化队列 
//	virtual operator int() const;		//返回队列的实际元素个数	//常成员函数
//	virtual QUEUE& operator<< (int e);	//将e入列，并返回队列
//	virtual QUEUE& operator>> (int& e);//出队列到e，并返回队列
//	virtual QUEUE& operator= (const QUEUE& s);	//赋s给队列，并返回队列
//	virtual void print() const;					//打印队列
//	virtual ~QUEUE();							//销毁队列
//};
//
//
//
//QUEUE::QUEUE(int m) :
//	elems(new int[m + 1]),
//	max(m + 1),			//	此处用m+1用于便于判断队列实际元素个数是否达到最大值，最大值为m，预留一个空间
//	head(0),
//	tail(0) {
//	if (elems == nullptr) {
//		cout << "NO enough memory for a new queue" << endl;
//		error_exist = 1;
//		return;
//	}
//	error_exist = 0;
//}
//QUEUE::QUEUE(const QUEUE&s) :
//	elems(new int[s.max]),
//	max(s.max),
//	head(s.head),
//	tail(s.tail) {
//	if (elems == nullptr) {
//		cout << "NO enough memory for a new QUEUE" << endl;
//		error_exist = 1;
//		return;
//	}
//	error_exist = 0;
//}
//QUEUE::~QUEUE(void) {
//	if (elems != nullptr) {
//		delete[] elems;
//		cout << "the deletion done" << endl;
//	}
//}
//QUEUE::operator int(void) const {		//	此函数没有判断队列的元素个数是否超出范围和队列为空
//	if (tail > head) {
//		return (tail - head);
//	}
//	else return (tail + max - head);
//}
//QUEUE& QUEUE::operator<<(int e) {		//	将e入列，返回队列
//	if ((head - tail == (max - 1)) || (head - tail == 1)) {		//	此两个判断情况为队列已满
//		error_exist = 1;
//		return *this;
//	}
//	error_exist = 0;
//	tail = (tail + 1) % max;
//	elems[tail] = e;
//	return *this;
//}
//QUEUE& QUEUE::operator >> (int &e) {
//	if (head == tail) {
//		error_exist = 1;
//		e = 0;
//		return *this;
//	}
//	head = (head + 1) % max;
//	e = elems[head];
//	return *this;
//}
//QUEUE& QUEUE::operator= (const QUEUE&s) {
//	if (s.max != max) {
//		*(int**)elems = new int[s.max];		//强制转换
//		if (elems == nullptr) {
//			cout << "NO enough memory for the queue" << endl;
//			error_exist = 1;
//			return *this;
//		}
//		*(int*)max = s.max;		//	强制转换
//	}
//	error_exist = 0;
//	head = s.head;
//	tail = s.tail;
//	int cnt = head;
//	while (cnt != tail) {
//		cnt = (cnt + 1) % max;
//		elems[cnt] = s.elems[cnt];
//	}
//	return *this;
//}
//void QUEUE::print(void) const{
//
//}

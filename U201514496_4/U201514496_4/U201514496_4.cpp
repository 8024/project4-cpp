//#include<iostream>
//
//
//using namespace std;
//extern int error_exist;		//	��־�����Ƿ���ڣ�Ϊ1ʱ���ڣ����򲻴���
//class QUEUE {
//	int *const elems;		//�����ڴ����ڴ洢
//	const int max;			//�����ܴ�ŵ����Ԫ�ظ���
//	int head, tail;			//���е�ͷ��β��������Ϊ��ʱ��head=tail
//public:
//	QUEUE(int m);						//��ʼ��m��Ԫ�ؿռ��С�Ķ���
//	QUEUE(const QUEUE&s);				//��s���г�ʼ������ 
//	virtual operator int() const;		//���ض��е�ʵ��Ԫ�ظ���	//����Ա����
//	virtual QUEUE& operator<< (int e);	//��e���У������ض���
//	virtual QUEUE& operator>> (int& e);//�����е�e�������ض���
//	virtual QUEUE& operator= (const QUEUE& s);	//��s�����У������ض���
//	virtual void print() const;					//��ӡ����
//	virtual ~QUEUE();							//���ٶ���
//};
//
//
//
//QUEUE::QUEUE(int m) :
//	elems(new int[m + 1]),
//	max(m + 1),			//	�˴���m+1���ڱ����ж϶���ʵ��Ԫ�ظ����Ƿ�ﵽ���ֵ�����ֵΪm��Ԥ��һ���ռ�
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
//QUEUE::operator int(void) const {		//	�˺���û���ж϶��е�Ԫ�ظ����Ƿ񳬳���Χ�Ͷ���Ϊ��
//	if (tail > head) {
//		return (tail - head);
//	}
//	else return (tail + max - head);
//}
//QUEUE& QUEUE::operator<<(int e) {		//	��e���У����ض���
//	if ((head - tail == (max - 1)) || (head - tail == 1)) {		//	�������ж����Ϊ��������
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
//		*(int**)elems = new int[s.max];		//ǿ��ת��
//		if (elems == nullptr) {
//			cout << "NO enough memory for the queue" << endl;
//			error_exist = 1;
//			return *this;
//		}
//		*(int*)max = s.max;		//	ǿ��ת��
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

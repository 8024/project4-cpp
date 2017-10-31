#include<stdio.h>
class QUEUE {
public:
	QUEUE(int m);						//初始化队列：最多m个元素
	QUEUE(const QUEUE& s);				//用队列s拷贝初始化队列
	virtual operator int() const;		//返回队列的实际元素个数
	virtual int full()const;	//判断队列是否已满
	virtual int operator[](int x)const;		//	取下标为x的
	virtual QUEUE& operator<<(int e);	//将e入队列，并返回队列
	virtual QUEUE& operator >> (int& e);//出队列到e，并返回队列
	virtual QUEUE& operator=(const QUEUE& s);	//赋s给队列，并返回队列
	virtual void print(FILE *fp) const;			//打印队列
	virtual ~QUEUE();					//销毁队列

	bool m_bError_exist;				//判断队列是否存在错误
	virtual int gethead();
	virtual int gettail();
private:
	int *const m_iElems;				//申请内存用于存放队列的元素
	const int m_iMax;					//队列能存放的最大元素个数
	int m_iHead, m_iTail;				//队列的头和尾，当head=tail时，则队列为空
};

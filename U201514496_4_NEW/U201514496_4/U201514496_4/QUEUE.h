#include<stdio.h>
class QUEUE {
public:
	QUEUE(int m);						//��ʼ�����У����m��Ԫ��
	QUEUE(const QUEUE& s);				//�ö���s������ʼ������
	virtual operator int() const;		//���ض��е�ʵ��Ԫ�ظ���
	virtual int full()const;	//�ж϶����Ƿ�����
	virtual int operator[](int x)const;		//	ȡ�±�Ϊx��
	virtual QUEUE& operator<<(int e);	//��e����У������ض���
	virtual QUEUE& operator >> (int& e);//�����е�e�������ض���
	virtual QUEUE& operator=(const QUEUE& s);	//��s�����У������ض���
	virtual void print(FILE *fp) const;			//��ӡ����
	virtual ~QUEUE();					//���ٶ���

	bool m_bError_exist;				//�ж϶����Ƿ���ڴ���
	virtual int gethead();
	virtual int gettail();
private:
	int *const m_iElems;				//�����ڴ����ڴ�Ŷ��е�Ԫ��
	const int m_iMax;					//�����ܴ�ŵ����Ԫ�ظ���
	int m_iHead, m_iTail;				//���е�ͷ��β����head=tailʱ�������Ϊ��
};

#include "QUEUE.h"
#include<iostream>
#include<stdio.h>

using namespace std;
QUEUE::QUEUE(int m) :
	m_iElems(new int[m + 1]),
	m_iMax(m + 1),			//	此处用m+1用于便于判断队列实际元素个数是否达到最大值，最大值为m，预留一个空间
	m_iHead(0),
	m_iTail(0) {
	if (m_iElems == nullptr) {
		cout << "NO enough memory for a new queue" << endl;
		m_bError_exist = true;
		return;
	}
	m_bError_exist = false;
}
QUEUE::QUEUE(const QUEUE&s) :
	m_iElems(new int[s.m_iMax]),
	m_iMax(s.m_iMax),
	m_iHead(s.m_iHead),
	m_iTail(s.m_iTail) {
	if (m_iElems == nullptr) {
		cout << "NO enough memory for a new QUEUE" << endl;
		m_bError_exist = true;
		return;
	}
	m_bError_exist = false;
	int cnt_assi = m_iHead;			//	转换的重点
	while (cnt_assi != m_iTail) {
		cnt_assi = (cnt_assi + 1) % m_iMax;
		m_iElems[cnt_assi] = s.m_iElems[cnt_assi];
	}
}
QUEUE::~QUEUE(void) {
	if (m_iElems != nullptr) {
		delete[] m_iElems;
		cout << "the deletion done" << endl;
	}
}
QUEUE::operator int(void) const {		//	此函数没有判断队列的元素个数是否超出范围和队列为空
	if (m_iTail > m_iHead) {
		return (m_iTail - m_iHead);
	}
	else return (m_iTail + m_iMax - m_iHead);
}
int QUEUE::full() const{
	if ((m_iHead + m_iTail == (m_iMax - 1)) || (m_iHead - m_iTail == 1)) {
		return true;
	}
	else return false;
}
int QUEUE::operator[](int x)const{
	int get_elem;
	get_elem = m_iElems[x];
	return get_elem;
}
QUEUE& QUEUE::operator<<(int e) {		//	将e入列，返回队列
	if ((m_iHead + m_iTail == (m_iMax - 1)) || (m_iHead - m_iTail == 1)) {		//	此两个判断情况为队列已满
		m_bError_exist = true;
		return *this;
	}
	m_bError_exist = false;
	m_iTail = (m_iTail + 1) % m_iMax;
	m_iElems[m_iTail] = e;
	return *this;
}
QUEUE& QUEUE::operator>>(int &e) {
	if (m_iHead == m_iTail) {
		m_bError_exist = true;
		e = 0;
		return *this;
	}
	m_bError_exist = false;
	m_iHead = (m_iHead + 1) % m_iMax;
	e = m_iElems[m_iHead];
	return *this;
}
QUEUE& QUEUE::operator=(const QUEUE&s) {
	delete[] m_iElems;
	int**p_m_iElems = (int**)&m_iElems;
	int* p_m_iMax = (int*)&m_iMax;
	*p_m_iElems = new int[s.m_iMax];
	if (*p_m_iElems == nullptr) {
		m_bError_exist = true;
		return *this;
	}
	*p_m_iMax = s.m_iMax;
	m_bError_exist = 0;
	m_iHead = s.m_iHead;
	m_iTail = s.m_iTail;
	int cnt_assi = m_iHead;			//	转换的重点
	while (cnt_assi != m_iTail) {
		cnt_assi = (cnt_assi + 1) % m_iMax;
		m_iElems[cnt_assi] = s.m_iElems[cnt_assi];
	}
	return *this;
}
void QUEUE::print(FILE *fp) const{
	const int *p_m_iHead = &m_iHead;
	const int *p_m_iTail = &m_iTail;
	const int *p_m_iElems=m_iElems;
	int cnt_pri = *p_m_iHead;
	while (cnt_pri != *p_m_iTail) {
		cnt_pri = (cnt_pri + 1) % m_iMax;
		fprintf(fp, "%d  ", p_m_iElems[cnt_pri]);
	}
}

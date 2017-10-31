#include<iostream>
#include"QUEUE.h"
#include<stdio.h>

using namespace std;

int main(int agrc,char* agrv[]) {
	int get_num = NULL;
	int num_cnt = 3;
	int lost_num = NULL;
	int sign_tran = 0;
	int sign_max = NULL;

	char filename[20] = "U201514496_4.txt";
	FILE *fp = fopen(filename, "w+");

	get_num = atoi(agrv[2]);
	fprintf(fp, "%c  %d  ", 'S', get_num);
	if (!get_num) {
		fprintf(fp, "%c", 'E');
		fclose(fp);
		cout << "the length of queue is 0,input error!" << endl;
		return 0;
	}
	sign_max = get_num;
	get_num--;
	QUEUE queue(get_num);		//创建新的队列
	QUEUE *pqueue = &queue;
	if (queue.m_bError_exist == true) {
		cout << "Errors!" << endl;
		fprintf(fp, "%c", 'E');
		fclose(fp);
		return 0;
	}

	while (num_cnt < agrc) {
		if (!strcmp("-I", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'I');
			++num_cnt;
			while ((strcmp("-I", agrv[num_cnt]) && strcmp("-O", agrv[num_cnt]) && strcmp("-A", agrv[num_cnt]) && strcmp("-C", agrv[num_cnt]) && strcmp("-N", agrv[num_cnt]) && strcmp("-G", agrv[num_cnt])) && (num_cnt < agrc - 1)) {
				get_num = atoi(agrv[num_cnt]);
				pqueue->operator<<(get_num);
				if (pqueue->m_bError_exist == true) {
					cout << "Error!" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
				++num_cnt;
			}
			if (num_cnt == agrc - 1) {
				get_num = atoi(agrv[num_cnt]);
				pqueue->operator<<(get_num);
				if (pqueue->m_bError_exist == true) {
					cout << "Error!" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
				++num_cnt;
			}
			pqueue->print(fp);
		}
		else if (!strcmp("-A", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'A');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			get_num--;
			QUEUE *pqueue_new_A = new QUEUE(get_num);
			pqueue_new_A->operator=(*pqueue);
			if (sign_tran) { delete pqueue; }
			if (pqueue_new_A->m_bError_exist == true) {
				cout << "Error!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			pqueue = pqueue_new_A;
			pqueue->print(fp);
			sign_tran = 1;
			++num_cnt;
		}
		else if (!strcmp("-C", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'C');
			QUEUE* pqueue_new_C = new QUEUE(*pqueue);
			if (sign_tran) { delete pqueue; }
			if (true == pqueue_new_C->m_bError_exist) {
				cout << "Error!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			pqueue = pqueue_new_C;
			pqueue->print(fp);
			sign_tran = 1;

			++num_cnt;
		}
		else if (!strcmp("-N", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'N');
			fprintf(fp, "%d  ", pqueue->operator int());
			++num_cnt;
		}
		else if (!strcmp("-G", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'G');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			if (get_num >=sign_max) {
				cout << "Errors!" << endl;
				fprintf(fp, "%c", 'E');
				fclose(fp);
				return 0;
			}
			get_num = (get_num + 1) % sign_max;		//	将下标转换，方便于接下来的判断
			if (pqueue->gethead() <= pqueue->gettail()) {
				if ((get_num <= pqueue->gettail()) && (get_num > pqueue->gethead())) {		//	下标在范围内
					fprintf(fp, "%d  ", pqueue->operator[](get_num));
				}
				else {
					cout << "Errors!" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
			}
			else {
				if (((get_num >= 0) && (get_num <= pqueue->gettail())) || ((get_num > pqueue->gethead()) && (get_num <= (sign_max - 1)))) {	//下标在范围内
					fprintf(fp, "%d  ", pqueue->operator[](get_num));
				}
				else {
					cout << "Errors!" << endl;
					fprintf(fp, "%c", 'E');
					fclose(fp);
					return 0;
				}
			}
			++num_cnt;
		}
		else if (!strcmp("-O", agrv[num_cnt])) {
			fprintf(fp, "%c  ", 'O');
			++num_cnt;
			get_num = atoi(agrv[num_cnt]);
			for (; get_num > 0; get_num--) {
				pqueue->operator >> (lost_num);
				if (true == pqueue->m_bError_exist) {
					cout << "Errors" << endl;
					fprintf(fp, "%c  ", 'E');
					fclose(fp);
					return 0;
				}
			}
			pqueue->print(fp);
			++num_cnt;
		}
		else {
			cout << "the input is wrong!" << endl;
			fclose(fp);
			return 0;
		}
	}
	if (sign_tran) { delete pqueue; }
	cout << "the operations are done!" << endl;
	fclose(fp);

	return 0;
}

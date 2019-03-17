template<class ElemType>
Status SeqList<ElemType >::DeleteElem(int i, ElemType &e)
{
	ElemType e;
	if (length = MAXSIZE)
		cout << "over_flow" << endl;
	else
		if (i < 1 || i>length) {
			cout << "RANGE_ERROR" << endl;
			e.numb = -1;
		}
		else
		{
			e = elem[i - 1];
			for (int j = i; j < length; j++)
				elem[j - 1] = elem[j];
			length--;
		}
	return e;
}
template<class ElemType>
Status SeqList<ElemType >::InserElem(int i, ElemType &e) 
{
	if (length = MAXSIZE)
		cout << "over_flow" << endl;
	else
		if (i < 1 || i>100)
			cout << "RANGE_ERROR" << endl;
		else {
			for (int j = length; j >= i; j--) {
				elem[j] = elem[i - 1];
				elem[i - 1] = e;
				length++;
				cout << "SUCCESS" << endl;
			}
		}
}

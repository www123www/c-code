template<class ElemType>
Status OrdSeqList<ElemType>::InsertElem(const ElemType &e)
{
	int i = length;
	if (length == maxlength)
		retrun OVER_FLOW;
	else {
		while (i > 0 && elems[i - 1] > e) {
			elems[i] = elema[i - 1];
			i--;
		}
		elems[i] = e;
		length++;
		return SUCCESS;
	}
}
template<class ElemType>
void OrdSeqList<ElemType>::DeleteElem(ElemType e)
{
	int i = 0, j;
	while (i <= length - 1 && elems[i] < e)
		i++;
	if (i <= length - 1 && elems[i] == e) {
		j = i + 1;
		while (j <= length - 1 && elems[j] == e)
			j++;
		while (j <= length)
		{
			elems[i++] = elems[j++];
		}
		length = length + i - j;
	}
}
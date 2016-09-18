struct Node         // �߶���
{
	int left;
	int right;
	int counter;
}segTree[4*BORDER]; 

/* �����߶��� ���ڵ㿪ʼ��������[lef,rig]���߶���*/
void construct(int index, int lef, int rig)
{
	segTree[index].left = lef;
	segTree[index].right = rig;
	if(lef == rig)   // Ҷ�ڵ�
	{
		segTree[index].counter = 0;
		return;
	}
	int mid = (lef+rig) >> 1;
	construct((index<<1)+1, lef, mid);
	construct((index<<1)+2, mid+1, rig);
	segTree[index].counter = 0;
}

/* �����߶�[start,end]���߶���, ͬʱ����������� */
void insert(int index, int start, int end)
{
	if(segTree[index].left == start && segTree[index].right == end)
	{
		++segTree[index].counter;
		return;
	}
	int mid = (segTree[index].left + segTree[index].right) >> 1;
	if(end <= mid)//������ 
	{
		insert((index<<1)+1, start, end);
	}else if(start > mid)//������ 
	{
		insert((index<<1)+2, start, end);
	}else//�ֿ����� 
	{
		insert((index<<1)+1, start, mid);
		insert((index<<1)+2, mid+1, end);
	}
}

/* ��ѯ��x�ĳ��ִ��� 
 * �Ӹ��ڵ㿪ʼ��[x,x]Ҷ�ӵ�����·�������е������ӷ�Ϊx���ִ���
 */
int query(int index, int x)
{
	if(segTree[index].left == segTree[index].right) // �ߵ�Ҷ�ӣ�����
	{
		return segTree[index].counter;
	}
	int mid = (segTree[index].left+segTree[index].right) >> 1;
	if(x <= mid)
	{
		return segTree[index].counter + query((index<<1)+1,x);
	}
	return segTree[index].counter + query((index<<1)+2,x);
}

void  delete_ (int c , int  d, int index)
{
       if(c <= segTree[index].left && d >= segTree[index].right) 
           segTree[index].counter--;
       else 
       {
          if(c < (segTree[index].left + segTree[index].right)/2 ) delete_( c,d, segTree[index].left);
          if(d > (segTree[index].left + segTree[index].right)/2 ) delete_( c,d, segTree[index].right);
       }
} 
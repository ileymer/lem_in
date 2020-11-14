//
//#include "lem_in.h"
//
//
//
////-----work list
//
//void add_element_end_queue(int data, t_queue *head) {
//	t_queue *tmp;
//	t_queue *p = head;
//	int o;
//
//	tmp = (t_queue *) malloc(sizeof(t_queue));
//	tmp->v = data;
//	tmp->next = NULL;
//	tmp->f = p->v;
//	while (p->next != NULL)
//	{
//		p = p->next;
//	}
//	p->next = tmp;
//}
//
//
//int check_queue(int data, t_queue *head)
//{
//	t_queue *p = head;
//
//	while (p != NULL)
//	{
//		if (p->v == data)
//			return (0);
//		p = p->next;
//	}
//	return (1);
//}
//
//t_queue *remove_element(t_queue *head)
//{
//	t_queue *tmp = head->next;
//	if (head == NULL)
//		return NULL;
//	free(head);
//	return tmp;
//}
//
//int remove_element_c(t_queue *head)
//{
//	t_queue *tmp = head;
//
//	if (tmp->next != NULL)
//		return (0);
//
//	while (tmp->next->next != NULL)
//	{
//		tmp = tmp->next;
//	}
//
//	free(tmp->next->next);
//	tmp->next = NULL;
//	return 0;
//}
//
//void add_element_end_par(int a, int b, t_par *head)
//{
//// Выделение памяти под корень списка
//	t_par *tmp = (t_par*)malloc(sizeof(t_par));
//// Присваивание значения узлу
//	tmp->previous = a;
//	tmp->current = b;
//// Присваивание указателю на следующий элемент значения NULL
//	tmp -> next = NULL;
//// Присваивание новому указателю указателя head.
//// Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
//	if(head == NULL)
//		head = tmp;
//	t_par *p = head;
//// Сдвиг указателя p в самый конец первоначального списка
//
//	while (p && p->next != NULL)
//		p = p->next;
//// Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
//	p->next = tmp;
//}
//
//void remove_element_par(t_par *head)
//{
//	int retval = 0;
//	int r = 0;
//
//	/* if there is only one item in the list, remove it */
//	if (head->next == NULL) {
//		free(head);
//		r = 1;
//	}
//
//	/* get to the last node in the list */
//	t_par * current = head;
//
//	while (current->next->next != NULL) {
//		retval++;
//		current = current->next;
//	}
//
//	/* now current points to the last item of the list, so let's remove current->next */
//
//	free(current->next);
//	current->next = NULL;
//
//}
//
//
////*********************work list
//void	init_alg(t_map *p)
//{
//	int i;
//
//	i = 0;
//	p->room = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->s = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->bl = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->bl_s = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->pow_room = (int **)malloc(sizeof(int *) * p->q_rooms);
//	while (i < p->q_rooms)
//	{
//		p->bl[i] = 0;
//		p->bl_s[i] = 0;
//		p->room[i++] = 0;
//	}
//}
//
//void	add_pow(int i, t_map *p)
//{
//	int j;
//	int q;
//
//	j = 0;
//	q = 1;
//	while (j < p->q_rooms)
//	{
//		if (p->tab[i][j] == 1)
//			p->pow_room[i][q++] = j;
//		j++;
//	}
//}
//
//void 	init_pow_rooms(t_map *p)
//{
//	int i;
//	int k;
//	int j;
//
//	i = 0;
//	k = 0;
//	j = 0;
//	while (i < p->q_rooms)
//	{
//		j = 0;
//		k = 0;
//		while (j < p->q_rooms)
//			if (p->tab[i][j++] == 1)
//				k++;
//		if (k != 0)
//		{
//			p->pow_room[i] = (int *)malloc(sizeof(int) * (k + 1));
//			j = 0;
//			p->pow_room[i][0] = k;
//			add_pow(i, p);
//		}
//		i++;
//	}
//}
//
//void init_bfs(t_queue *q, t_map *p)
//{
//	int		i;
//
//	i = 0;
//	q->v = 0;
//	q->f = 0;
//	q->next = NULL;
//	while (i < p->q_rooms)
//	{
//		p->s[i] = 0;
//		p->room[i] = -1;
//		i++;
//	}
//}
//
//
//
////---------------------------alg
//void	bfs(t_map *p)
//{
//	int		i;
//	t_queue	*q;
//
//	q = (t_queue *)malloc(sizeof(t_queue));
//	i = 1;
//	init_bfs(q, p);
//	p->room[0] = 0;
//	while (q != 0)
//	{
//		i = 1;
//		while (i <= p->pow_room[q->v][0])
//		{
//			if (p->room[p->pow_room[q->v][i]] == -1 && p->tab[q->v][p->pow_room[q->v][i]] < 1 && check_queue(p->pow_room[q->v][i], q) == 1)
//			{
//				if (p->bl_s[q->v] == 1 && p->pow_room[q->v][i] != p->q_rooms) {
//					if (p->s[p->pow_room[q->v][i]] == 0 && p->tab[q->v][p->pow_room[q->v][i]] == -1)
//						p->s[p->pow_room[q->v][i]] = p->s[q->v] + 1;
//				}
//				else
//				if (p->s[p->pow_room[q->v][i]] == 0)
//					p->s[p->pow_room[q->v][i]] = p->s[q->v] + 1;
//				if (p->s[p->pow_room[q->v][i]] == p->q_rooms - 1)
//					p->ants = q->v;
//				if ((p->s[p->q_rooms - 1] != 0 && p->s[p->pow_room[q->v][i]] > p->s[p->q_rooms - 1]) || p->pow_room[q->v][i] == p->q_rooms - 1)
//					break;
//				p->room[p->pow_room[q->v][i]] = q->v;
//				if (p->bl_s[p->pow_room[q->v][i]])
//				add_element_end_queue(p->pow_room[q->v][i], q);
//			}
//			i++;
//		}
//		q = remove_element(q);
//	}
//
//}
//
//int dfs_one(int e, t_map *p);
//
//int dfs(t_map *p)
//{
//	int i;
//
//	i = 0;
//	while (i < p->q_rooms)
//		p->bl[i++] = 0;
//	i = 0;
//	while (i <= p->pow_room[p->q_rooms - 1][0])
//	{
//		dfs_one(p->q_rooms - 1,  p);
//		i++;
//	}
//}
//
//int dfs_one(int e, t_map *p)
//{
//	int i;
//
//	i = 1;
//	while (i <= p->pow_room[e][0])
//	{
//		if (p->bl[p->pow_room[e][i]] == 0 && p->s[e] - 1 == p->s[p->pow_room[e][i]] && ((p->tab[e][p->pow_room[e][i]] >= 0 && e != p->q_rooms - 1) || (p->tab[e][p->pow_room[e][i]] == 0 && e == p->q_rooms - 1)))
//		{
//			//add_element_end_par(e, p->pow_room[e][i], par);
//			if (!(p->pow_room[e][i] == 0 && p->tab[e][p->pow_room[e][i]] != 0)) {
//				p->tab[e][p->pow_room[e][i]] = p->tab[e][p->pow_room[e][i]] - 1;
//				p->tab[p->pow_room[e][i]][e] = p->tab[p->pow_room[e][i]][e] + 1;
//				p->bl_s[p->pow_room[e][i]] = 1;
//				if (p->pow_room[e][i] != 0)
//					p->bl[p->pow_room[e][i]] = 1;
//			}
//			if (p->pow_room[e][i] == 0)
//				return (1);
//			if (dfs_one(p->pow_room[e][i],  p) == 0)
//			{
//				p->tab[e][p->pow_room[e][i]] = p->tab[e][p->pow_room[e][i]] + 1;
//				p->tab[p->pow_room[e][i]][e]= p->tab[p->pow_room[e][i]][e] - 1;
//				p->bl[p->pow_room[e][i]] = 0;
//				p->bl_s[p->pow_room[e][i]] = 0;
//			}
//			else
//				return (1);
//		}
//		i++;
//	}
//	return (0);
//}
//
//
//int  vivod(int i, t_map *p)
//{
//	int j;
//
//	j = 0;
//	while (j < p->q_rooms)
//	{
//		if (p->tab[i][j] == 1)
//		{
//			printf("%d--->", i);
//			vivod(j, p);
//			return (1);
//		}
//		j++;
//	}
//}
//void vivi(t_map *p)
//		{
//	int i;
//	i = 0;
//				while (i < p->q_rooms)
//				{
//					if (p->tab[0][i] == 1)
//					{
//						printf("%d--->", 0);
//						vivod(i, p);
//						printf("%d\n\n", p->q_rooms - 1);
//					}
//					i++;
//				}
//		};
//
//void	starts_alg(t_map *p)
//{
//	int f;
//
//	f = 0;
//	int i = 0;
//	int j;
//	init_alg(p);
//	init_pow_rooms(p);
//
//	while (i < p->q_rooms)
//	{
//		j = 0;
//		while (j < p->q_rooms)
//		{
//			p->tab[i][j++] = 0;
//		}
//		i++;
//	}
//
//	while (p->s[p->q_rooms - 1] != 0 && f == 0)
//	{
//		bfs(p);
//		if (p->s[p->q_rooms - 1] == 0)
//			break;
//
//		dfs(p);
//		vivi(p);
//		printf("\n-*****************\n");
//	}
//	i = 0;
//	while (i < p->q_rooms)
//	{
//		if (p->tab[0][i] == 1)
//		{
//			printf("%d--->", 0);
//			vivod(i, p);
//			printf("%d\n\n", p->q_rooms - 1);
//		}
//		i++;
//	}
//
//	//print_matrix(p);
//	//test***vivod
//	i = 0;
////	while (i < p->q_rooms)
////	{
////		j = 1;
////		while (j <= p->pow_room[i][0])
////		{
////			printf ("%7d", p->pow_room[i][j]);
////			j++;
////		}
////
////		printf ("\nsloi %d  -  %d", i, p->s[i]);
////		printf("\n");
////		i++;
////	}
//	print_matrix(p);
//};
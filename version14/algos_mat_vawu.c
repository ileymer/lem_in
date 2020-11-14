//
//#include "lem_in.h"
//
////work list
//
//int dfs_one(int e, t_par *par, t_map *p);
//
//void carpov(t_map *pMap);
//
//void add_element_end_queue(int data, t_queue *head) {
//	t_queue *tmp;
//	t_queue *p = head;
//	int o;
//
//	tmp = (t_queue *) malloc(sizeof(t_queue));
//	tmp->v = data;
//	tmp->next = NULL;
//	tmp->p = p->v;
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
//
////***work list
////init
//void	init_alg(t_map *p)
//{
//	int i;
//
//	i = 0;
//	p->room = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->s = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->st = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->sl = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->bl = (int *)malloc (sizeof(int) * p->q_rooms);
//	p->pow_room = (int **)malloc(sizeof(int *) * p->q_rooms);
//	while (i < p->q_rooms)
//	{
//		p->bl[i] = 0;
//		p->room[i++] = 0;
//	}
//
//}
//
//int		sort_pow(t_map *p, int q)
//{
//	int i;
//	int f;
//	int s;
//
//	i = 1;
//	f = 1;
//	s = 0;
//	if (p->room[q] == 0)
//		return (0);
//	if (p->pow_room[q][0] < 2)
//		return (0);
//	while (f == 1)
//	{
//		i = 1;
//		f = 0;
//		while (i <= p->pow_room[q][0] - 1)
//		{
//			if (p->pow_room[p->pow_room[q][i]][0] > p->pow_room[p->pow_room[q][i + 1]][0])
//			{
//				f = 1;
//				s = p->pow_room[q][i];
//				p->pow_room[q][i] = p->pow_room[q][i + 1];
//				p->pow_room[q][i + 1] = s;
//			}
//			i++;
//		}
//	}
//	return (0);
//}
//
//
//void sorting(t_map *p)
//{
//	int i;
//
//	i = 0;
//	while (i < p->q_rooms)
//	{
//		sort_pow(p, i);
//		i++;
//	}
//}
//
//
//int 	search_q_replay(int n, t_map *p, int i)
//{
//	int r;
//
//	r = 0;
//	while (i < p->q_links)
//	{
//		if (p->tab[i][0] == n || p->tab[i][1] == n)
//			r++;
//		i++;
//	}
//	return (r);
//}
//
//void	add_pow(t_map *p, int r, int n, int i)
//{
//	int j;
//
//	j = 1;
//	p->pow_room[n][0] = r;
//	while (i < p->q_links)
//	{
//		if (p->tab[i][0] == n)
//		{
//			p->pow_room[n][j++] = p->tab[i][1];
//		}
//		else if (p->tab[i][1] == n)
//		{
//			p->pow_room[n][j++] = p->tab[i][0];
//		}
//		i++;
//	}
//}
//
//void 	init_pow_rooms(t_map *p)
//{
//	int i;
//	int repeat;
//
//	i = 0;
//	repeat = 0;
//	while (i < p->q_links)
//	{
//		if (p->room[p->tab[i][0]] == 0)
//		{
//			repeat = search_q_replay(p->tab[i][0], p, i);
//			p->pow_room[p->tab[i][0]] = (int *)malloc(sizeof(int) * (repeat + 1));
//			p->sl[p->tab[i][0]] = (int *)malloc(sizeof(int) * (repeat + 1));
//			add_pow(p, repeat, p->tab[i][0], i);
//			p->room[p->tab[i][0]] = 1;
//		}
//		if (p->room[p->tab[i][1]] == 0)
//		{
//			repeat = search_q_replay(p->tab[i][1], p, i);
//			p->pow_room[p->tab[i][1]] = (int *)malloc(sizeof(int) * (repeat + 1));
//			add_pow(p, repeat, p->tab[i][1], i);
//			p->room[p->tab[i][1]] = 1;
//		}
//		i++;
//	}
//	//sorting(p);
//}
////**init
//
////alg
//
//void init_bfs(t_queue *q, t_map *p)
//{
//	int		i;
//
//	i = 0;
//	q->v = 0;
//	q->p = 0;
//	q->next = NULL;
//	while (i < p->q_rooms)
//	{
//		p->s[i] = 0;
//		p->st[i] = 0;
//		if (p->bl[i] == 0)
//			p->room[i] = -1;
//		else
//			p->room[i] = 1;
//		i++;
//	}
//}
//
//void layer_override(int *s, int q)
//{
//	int i;
//
//	i = 0;
//	while (i < q - 1)
//	{
//		if (s[i] == s[q - 1])
//			s[i]--;
//		if (s[i] > s[q - 1])
//			s[i] = -1;
//		i++;
//	}
//}
//
//void bfs(t_map *p)
//{
//	int 	i;
//	t_queue *q;
//	int 	f;
//
//	f = 0;
//	q = (t_queue *)malloc(sizeof(t_queue));
//	init_bfs(q, p);
//	i = 1;
//	p->room[0] = 0;
//	while (q != 0)
//	{
//		i = 1;
//		while(i <= p->pow_room[q->v][0] && f == 0)
//		{
//			if (p->room[p->pow_room[q->v][i]] == -1 && check_queue(p->pow_room[q->v][i], q) == 1)
//			{
//				if (p->s[p->pow_room[q->v][i]] == 0)
//					p->s[p->pow_room[q->v][i]] = p->s[q->v] + 1;
////				if ((p->s[p->q_rooms - 1] != 0 && p->s[p->pow_room[q->v][i]] > p->s[p->q_rooms - 1]) || p->pow_room[q->v][i] == p->q_rooms - 1)
////					break;
//				if (p->pow_room[q->v][i] != p->q_rooms - 1)
//				{
//					p->room[p->pow_room[q->v][i]] = q->v;
//					add_element_end_queue(p->pow_room[q->v][i], q);
//				}
//			}
//			i++;
//		}
//		q = remove_element(q);
//	}
//	//layer_override(p->s, p->q_rooms);
//}
//
//int dfs(t_map *p, t_par *par)
//{
//	int i;
//	t_way	*cw;
//	t_way	*ccw;
//
//	i = 0;
//	while (i <= p->pow_room[p->q_rooms - 1][0])
//	{
//		dfs_one(p->q_rooms - 1, par, p);
//		i++;
//	}
//}
//
//int sorte_slois(t_map *p, int e, int rk)
//{
//	int i;
//	int k;
//
//	i = 1;
//	k = 0;
//	while (i <= p->pow_room[e][0])
//	{
//		if (p->s[e] + 1 == p->s[p->pow_room[e][i]])
//			k++;
//		i++;
//	}
//	if (k == 0)
//		return (100000);
//	return (k);
//}
//
//void	sorte_sloi(t_map *p, int e)
//{
//	int i;
//	int f;
//	int s;
//
//	i = 1;
//	f = 1;
//	s = 0;
//	while (i <= p->pow_room[e][0])
//	{
//		p->st[p->pow_room[e][i]] =sorte_slois(p, p->pow_room[e][i], e);
//		i++;
//	}
//	while (f == 1)
//	{
//		i = 1;
//		f = 0;
//		while (i <= p->pow_room[e][0] - 1)
//		{
//			if (p->st[p->pow_room[e][i]] > p->st[p->pow_room[e][i+ 1]])
//			{
//				f = 1;
//				s = p->pow_room[e][i];
//				p->pow_room[e][i] = p->pow_room[e][i + 1];
//				p->pow_room[e][i + 1] = s;
//			}
//			i++;
//		}
//	}
//
//}
//
//
//
//
//
//int dfs_one(int e, t_par *par, t_map *p)
//{
//	int i;
//
//	i = 1;
//	sorte_sloi(p, e);
//	while (i <= p->pow_room[e][0])
//	{
//			if (p->s[e] - 1 == p->s[p->pow_room[e][i]] && p->bl[p->pow_room[e][i]] == 0)
//			{
//				add_element_end_par(e, p->pow_room[e][i], par);
//				if (p->pow_room[e][i] != 0)
//					p->bl[p->pow_room[e][i]] = 1;
//				if (p->pow_room[e][i] == 0)
//					return (1);
//				if (dfs_one(p->pow_room[e][i], par, p) == 0)
//				{
//					p->bl[p->pow_room[e][i]] = 0;
//					remove_element_par(par);
//				}
//				else
//					return (1);
//			}
//		i++;
//	}
//	return (0);
//}
//
////void	alg(t_map *p)
////{
////
////}
//
//void result_show(t_par *par, t_map *p)
//{
//	int i;
//	int r  = 0;
//	t_par *a;
//
//	i = 0;
//	while (i < p->ants)
//	{
//		a = par;
//		while (a != NULL)
//		{
//			if (a->previous == p->q_rooms - 1 && p->s[a->current] != 0)
//			{
//				printf("L%d-%s ", p->s[a->current],  p->rooms[a->previous]);
//				p->s[a->current] = 0;
//				i++;
//			}
//			else if (a->current == 0 && p->s[0] > 0)
//			{
//				p->s[0] = p->s[0]  - 1;
//				p->s[a->previous] = p->ants - p->s[0];
//				printf("L%d-%s ", p->s[a->previous], p->rooms[a->previous]);
//			}
//			else if(p->s[a->current] != 0 && p->s[a->previous] == 0)
//			{
//				printf("L%d-%s ", p->s[a->current],  p->rooms[a->previous]);
//				p->s[a->previous] = p->s[a->current];
//				p->s[a->current] = 0;
//			}
//			a = a->next;
//		}
//		printf("\n");
//		r++;
//	}
//	printf("\n----(()()%d()()------\n", r);
//}
//
//
//int start_alg(t_map *p)
//{
//	int		i;
//	t_par	*par;
//	int 	f;
//
//	f = 0;
//	i = 0;
//	par = (t_par *)malloc(sizeof(t_par) * 1);
//	p->m = (int **)malloc(sizeof(int *) * p->q_rooms);
//	while (i < p->q_rooms)
//		p->m[i++] = (int *)malloc(sizeof(int) * p->q_rooms);
//	i = 0;
//	int j = 0;
//
//
//
//	while (i < p->q_rooms)
//	{
//		j = 0;
//		while (j < p->q_rooms)
//		{
//			p->m[i][j++] = 0;
//		}
//		i++;
//	}
//	i = 0;
//
//	par->next = NULL;
//	init_alg(p);
//	init_pow_rooms(p);
//	p->sl = 0;
//	while (p->s[p->q_rooms - 1] != 0 && f == 0)
//	{
//		bfs(p);
//		if (p->s[p->q_rooms - 1] == 0)
//			break;
//		p->sl = p->s[p->q_rooms - 1] - 1;
//		dfs(p, par);
//	}
//	while (i < p->q_rooms)
//		p->s[i++] = 0;
//	i = 1;
//	while (i <= p->pow_room[p->q_rooms - 1][0])
//		printf("\n---%d---\n", p->pow_room[p->q_rooms - 1][i++]);
//	p->s[0] = p->ants;
//	par = par->next;
//	t_par *u;
//	u = par;
//	while (u != NULL)
//	{
//		printf ("<-----%d <------%d" , u->previous, u->current);
//		if (u->current == 0)
//			printf("\n");
//		p->m[u->previous][u->current] = -1;
//		p->m[u->current][u->previous] = 1;
//		u = u->next;
//	}
//	printf("\n");
//	i = 0;
////	while (i < p->q_rooms)
////	{
////		j = 0;
////		while (j < p->q_rooms)
////		{
////			printf("%4d", p->m[i][j++]);
////		}
////		printf(" end\n");
////		i++;
////	}
//	result_show(par, p);
//	return (0);
//}
//
//
////int carpov_one(t_map *p, t_queue *q, int e);
////
////void carpov(t_map *p)
////{
////	int i;
////	t_queue *q;
////
////	i = 1;
////	q = (t_queue *)malloc(sizeof(t_queue));
////	q->v = 0;
////	q->next = NULL;
////	while (i <= p->pow_room[0][0])
////	{
////		if (p->bl[p->pow_room[0][i]] == 0)
////		{
////			if (carpov_one(p, q, p->pow_room[0][i]) == 1) {
////				p->m[0][p->pow_room[0][i]] = 1;
////				p->m[p->pow_room[0][i]][0] = -1;
////			}
////		}i++;
////	}
////}
////
////
////int carpov_one(t_map *p, t_queue *q, int e)
////{
////	int i;
////	int f;
////
////	i = 1;
////	f = 0;
////	if (e != p->q_rooms - 1)
////		add_element_end_queue(e, q);
////	else
////		return (1);
////	while (i <= p->pow_room[e][0])
////	{
////		if (check_queue(p->pow_room[e][i], q) == 1)
////		{
////			if (p->m[e][p->pow_room[e][i]] == -1)
////			{
////				p->m[e][p->pow_room[e][i]] = 0;
////				p->m[p->pow_room[e][i]][e]= 0;
////				f = 1;
////			}
////			else if (p->m[e][p->pow_room[e][i]] == 0)
////			{
////				p->m[e][p->pow_room[e][i]] = 1;
////				p->m[p->pow_room[e][i]] [e]= -1;
////				f = 2;
////			}
////			if (carpov_one(p, q, p->pow_room[e][i]) == 0)
////			{
////				if (f == 1)
////				{
////					p->m[e][p->pow_room[e][i]] = 1;
////					p->m[p->pow_room[e][i]][e]= -1;
////				}
////				if (f == 2)
////				{
////					p->m[e][p->pow_room[e][i]] = 0;
////					p->m[p->pow_room[e][i]][e]= 0;
////				}
////				if (q->next != NULL)
////				remove_element_c(q);
////			}
////			else
////				return (1);
////		}
////		i++;
////	}
////	return (0);
////}
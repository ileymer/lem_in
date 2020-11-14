
#include "lem_in.h"



//-----work list

void add_element_end_queue(int data, t_queue *head, int f) {
	t_queue *tmp;
	t_queue *p = head;

	tmp = (t_queue *) malloc(sizeof(t_queue));
	tmp->v = data;
	tmp->next = NULL;
	tmp->f = f;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = tmp;
}


int check_queue(int data, t_queue *head)
{
	t_queue *p = head;

	while (p != NULL)
	{
		if (p->v == data)
			return (0);
		p = p->next;
	}
	return (1);
}

t_queue *remove_element(t_queue *head)
{
	t_queue *tmp = head->next;
	if (head == NULL)
		return NULL;
	free(head);
	return tmp;
}

int remove_element_c(t_queue *head)
{
	t_queue *tmp = head;

	if (tmp->next != NULL)
		return (0);

	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}

	free(tmp->next->next);
	tmp->next = NULL;
	return 0;
}

void add_element_end_par(int a, int b, t_par *head)
{
	t_par *tmp = (t_par*)malloc(sizeof(t_par));
// Присваивание значения узлу
	tmp->previous = a;
	tmp->current = b;
// Присваивание указателю на следующий элемент значения NULL
	tmp -> next = NULL;
// Присваивание новому указателю указателя head.
// Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
	if(head == NULL)
		head = tmp;
	t_par *p = head;
// Сдвиг указателя p в самый конец первоначального списка

	while (p && p->next != NULL)
		p = p->next;
// Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
	p->next = tmp;
}

void remove_element_par(t_par *head)
{
	int retval = 0;
	int r = 0;

	/* if there is only one item in the list, remove it */
	if (head->next == NULL) {
		free(head);
		r = 1;
	}

	/* get to the last node in the list */
	t_par * current = head;

	while (current->next->next != NULL) {
		retval++;
		current = current->next;
	}

	/* now current points to the last item of the list, so let's remove current->next */

	free(current->next);
	current->next = NULL;

}


//*********************work list
void	init_alg(t_map *p)
{
	int i;

	i = 0;
	p->room = (int *)malloc (sizeof(int) * p->q_rooms);
	p->s = (int *)malloc (sizeof(int) * p->q_rooms);
	p->bl = (int *)malloc (sizeof(int) * p->q_rooms);
	p->bl_s = (int *)malloc (sizeof(int) * p->q_rooms);
	p->pow_room = (int **)malloc(sizeof(int *) * p->q_rooms);
	p->tab_final = (int **)malloc(sizeof(int *) * p->q_rooms);
	while (i < p->q_rooms)
	{
		p->bl[i] = 0;
		p->tab_final[i] = (int *)malloc(sizeof(int) * p->q_rooms);
		p->bl_s[i] = 0;
		p->room[i++] = 0;
	}
}

void	add_pow(int i, t_map *p)
{
	int j;
	int q;

	j = 0;
	q = 1;
	while (j < p->q_rooms)
	{
		if (p->tab[i][j] == 1)
			p->pow_room[i][q++] = j;
		j++;
	}
}

void 	init_pow_rooms(t_map *p)
{
	int i;
	int k;
	int j;

	i = 0;
	while (i < p->q_rooms)
	{
		j = 0;
		k = 0;
		while (j < p->q_rooms)
			if (p->tab[i][j++] == 1)
				k++;
		if (k != 0)
		{
			p->pow_room[i] = (int *)malloc(sizeof(int) * (k + 1));
			j = 0;
			p->pow_room[i][0] = k;
			add_pow(i, p);
		}
		i++;
	}
}

void init_bfs(t_queue *q, t_map *p)
{
	int		i;

	i = 0;
	q = (t_queue *)malloc(sizeof(t_queue));
	q->v = 0;
	q->f = 0;
	q->next = NULL;
	while (i < p->q_rooms)
	{
		p->s[i] = 0;
		p->room[i] = -1;
		i++;
	}
}



//---------------------------alg
void	bfs(t_map *p)
{
	int		i;
	t_queue	*q;
	int f;

	init_bfs(q, p);
	p->room[0] = 0;
	while (q != 0)
	{
		i = 1;
		while (i <= p->pow_room[q->v][0])
		{
			f = 0;
			if (p->room[p->pow_room[q->v][i]] == -1 && p->tab[q->v][p->pow_room[q->v][i]] < 1 && check_queue(p->pow_room[q->v][i], q) == 1)
			{
				if (p->s[p->pow_room[q->v][i]] == 0)
				{
					if (q->f == 1)
					{
						if ( p->tab[q->v][p->pow_room[q->v][i]] == -1) {
							p->s[p->pow_room[q->v][i]] = p->s[q->v] + 1;
							f = 1;
						}
					}
					else {
						f = 1;
						p->s[p->pow_room[q->v][i]] = p->s[q->v] + 1;
					}
				}
				if ((p->s[p->q_rooms - 1] != 0 && p->s[p->pow_room[q->v][i]] > p->s[p->q_rooms - 1]) || p->pow_room[q->v][i] == p->q_rooms - 1)
					break;
				if (f == 1) {
					p->room[p->pow_room[q->v][i]] = q->v;
					if (p->bl_s[p->pow_room[q->v][i]] == 1 && q->f == 0)
						add_element_end_queue(p->pow_room[q->v][i], q, 1);
					else
						add_element_end_queue(p->pow_room[q->v][i], q, 0);
				}
			}
			i++;
		}
		q = remove_element(q);
	}

}

int dfs_one(int e, t_map *p);

int dfs(t_map *p)
{
	int i;

	i = 0;
	while (i < p->q_rooms)
		p->bl[i++] = 0;
	i = 0;
	while (i <= p->pow_room[p->q_rooms - 1][0])
	{
		dfs_one(p->q_rooms - 1,  p);
		i++;
	}
	return (0);
}

int dfs_one(int e, t_map *p)
{
	int i;

	i = 1;
	while (i <= p->pow_room[e][0])
	{
		if (p->bl[p->pow_room[e][i]] == 0 && p->s[e] - 1 == p->s[p->pow_room[e][i]] && ((p->tab[e][p->pow_room[e][i]] >= 0 && e != p->q_rooms - 1) || (p->tab[e][p->pow_room[e][i]] == 0 && e == p->q_rooms - 1)))
		{
			if (!(p->pow_room[e][i] == 0 && p->tab[e][p->pow_room[e][i]] != 0)) {
				p->tab[e][p->pow_room[e][i]] = p->tab[e][p->pow_room[e][i]] - 1;
				p->tab[p->pow_room[e][i]][e] = p->tab[p->pow_room[e][i]][e] + 1;
				p->bl_s[p->pow_room[e][i]] = 1;
				if (p->pow_room[e][i] != 0)
					p->bl[p->pow_room[e][i]] = 1;
			}
			if (p->pow_room[e][i] == 0)
				return (1);
			if (dfs_one(p->pow_room[e][i],  p) == 0)
			{
				p->tab[e][p->pow_room[e][i]] = p->tab[e][p->pow_room[e][i]] + 1;
				p->tab[p->pow_room[e][i]][e]= p->tab[p->pow_room[e][i]][e] - 1;
				p->bl[p->pow_room[e][i]] = 0;
				p->bl_s[p->pow_room[e][i]] = 0;
			}
			else
				return (1);
		}
		i++;
	}
	return (0);
}


int  vivod(int i, t_map *p)
{
	int j;

	j = 0;
	while (j < p->q_rooms)
	{
		if (p->tab[i][j] == 1)
		{
			printf("%d--->", i);
			vivod(j, p);
			return (1);
		}
		j++;
	}
	return (1);
}
void vivi(t_map *p)
{
	int i;
	i = 0;
	while (i < p->q_rooms)
	{
		if (p->tab[0][i] == 1)
		{
			printf("%d--->", 0);
			vivod(i, p);
			printf("%d\n\n", p->q_rooms - 1);
		}
		i++;
	}
};


int size_ways(t_map *p)
{
	int i;
	int k;

	i = 1;
	k = 0;
	while (i < p->q_rooms)
	{
		if (p->tab[0][i] == 1)
			k++;
		i++;
	}
	p->ways = (int **) malloc(sizeof(int *) * k);
	p->w_a = (int **) malloc(sizeof(int *) * k);
	p->k_w = k;
	return (0);
}


int 	count_way(t_map *p, int i)
{
	int j;

	j = 0;
	while (j < p->q_rooms)
	{
		if (p->tab[i][j] == 1)
		{
			p->n++;
			return (count_way(p, j));
		}
		j++;
	}
	return (0);
}


int		add_way(t_map *p, int i, int l, int j)
{
	int q;

	q = 0;
	while (q < p->q_rooms)
	{
		if (p->tab[i][q] == 1)
		{
			p->ways[l][j] = i;
			add_way(p, q, l, ++j);
			return (0);
		}
		q++;
	}
	return (0);
}

void add_ways(t_map *p)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < p->q_rooms)
	{
		p->n = 1;
		if (p->tab[0][i] == 1)
		{
			count_way(p, i);
			p->ways[j] = (int *) malloc(sizeof(int) * (p->n + 1));
			p->w_a[j] = (int *) malloc(sizeof(int) * (3));
			p->w_a[j][1] = j;
			p->w_a[j++][0] = p->n + 1;
			//printf ("<<<----%d---->>>\n", p->n);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < p->q_rooms)
	{
		if (p->tab[0][i] == 1)
		{
			p->ways[j][0] = 0;
			add_way(p, i, j, 1);
			p->ways[j][p->w_a[j][0] - 1] = p->q_rooms - 1;
			j++;
		}
		i++;
	}
}

void	sort_ways(int **w_a, int n)
{
	int i;
	int f;
	int k;
	int b;

	i = 0;
	f = 1;
	while (f == 1)
	{
		f = 0;
		i = 0;
		while (i < n - 1)
		{
			if (w_a[i][0] > w_a[i + 1][0])
			{
				f = 1;
				b = w_a[i][1];
				k = w_a[i][0];
				w_a[i][0] = w_a[i + 1][0];
				w_a[i][1] = w_a[i + 1][1];
				w_a[i + 1][0] = k;
				w_a[i + 1][1] = b;
			}
			i++;
		}
	}
}

void 	distrib_ants(t_map *p)
{
	int i;
	int a;
	int f;

	i = 0;
	f = 1;
	a = p->ants;
	while (a > 0)
	{
		i = 0;
		f = 1;
		while (i < p->k_w - 1)
		{
			if (i == p->k_w - 1 - 1)
			{
				if ((p->w_a[i][0] + p->w_a[i][2] + 1) >= (p->w_a[i + 1][0] + p->w_a[i + 1][2] + 1)) {
					p->w_a[i + 1][2] = p->w_a[i + 1][2] + 1;
					a--;
					break;
				}
			}
			if ((p->w_a[i][0] + p->w_a[i][2] + 1) < (p->w_a[i + 1][0] + p->w_a[i + 1][2] + 1) && f == 1)
			{
				p->w_a[i][2] = p->w_a[i][2] + 1;
				a--;
				break;
			}
			i++;
		}

	}

}

void nool_w_a(int **w_a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		w_a[i++][2] = 0;
	}
}

int mins(int **w, int n)
{
	int i;
	int m;

	i = 0;
	m = 10000000;
	while (i < n)
	{
		if (w[i][0] + w[i][2] < m)
			m = w[i][0] + w[i][2];
		i++;
	}
	return (m);
}



void tabtotab(int **t, int **t2, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			t2[i][j] = t[i][j];
			j++;
		}
		i++;
	}
}


void start_end(t_map *p)
{
	int a;

	a = 1;
	while (a <= p-> ants)
	{
		ft_printf("L%d-%s ", a, p->rooms[p->q_rooms - 1]);
		a++;
	}
	ft_printf("\n");
}

int 	check_start_end(t_map *p)
{
	int i;

	i = 1;
	while (i <= p->pow_room[0][0])
	{
		if (p->pow_room[0][i] == p->q_rooms - 1)
			return (1);
		i++;
	}
	return (0);
}

void	result_show(t_map *p)
{
	int i;
	int n;
	int a;
	int r;


	a = 1;
	i = 0;
	r = 0;
	int k = 0;
	while (i < p->q_rooms)
	{
		p->s[i++] = 0;
	}
	i = 0;
	while (r != p->ants)
	{
		i = 0;
		while (i < p->k_w)
		{
			n = p->w_a[i][0] - 1;
			while (n > 1)
			{
				if (p->s[p->ways[p->w_a[i][1]][n - 1]] != 0)
				{
					ft_printf ("L%d-%s ", p->s[p->ways[p->w_a[i][1]][n - 1]], p->rooms[p->ways[p->w_a[i][1]][n]]);
					p->s[p->ways[p->w_a[i][1]][n]] = p->s[p->ways[p->w_a[i][1]][n - 1]];
					p->s[p->ways[p->w_a[i][1]][n - 1]] = 0;
					if (p->ways[p->w_a[i][1]][n] == p->q_rooms - 1)
						r++;
				}
				n--;
			}
			if ( n == 1 && p->w_a[i][2] > 0)
			{
				ft_printf ("L%d-%s ", a, p->rooms[p->ways[p->w_a[i][1]][n]]);
				p->s[p->ways[p->w_a[i][1]][n]] = a++;
				p->w_a[i][2]--;
			}
			i++;
		}
		ft_printf ("\n");
		k++;
	}
	ft_printf ("%d", k);
}
int	start_alg(t_map *p)
{
	int f;

	f = 0;
	int i = 0;
	int r;
	int j;
	int m = 1000000;
	init_alg(p);
	init_pow_rooms(p);

	while (i < p->q_rooms)
	{
		j = 0;
		while (j < p->q_rooms)
		{
			p->tab[i][j++] = 0;
		}
		i++;
	}

	if (check_start_end(p) == 1)
	{
		start_end(p);
		return (1);
	}

	while (p->s[p->q_rooms - 1] != 0 || f == 0)
	{
		f = 1;
		bfs(p);
		if (p->s[p->q_rooms - 1] == 0)
			break;
		dfs(p);
		size_ways(p);
		add_ways(p);
		nool_w_a(p->w_a, p->k_w);
		sort_ways(p->w_a, p->k_w);
		if (p->k_w > 1)
			distrib_ants(p);
		else
			p->w_a[0][2] = p->ants;
		r = mins(p->w_a, p->k_w);
		if (r < m)
		{
			m = r;
			tabtotab(p->tab, p->tab_final, p->q_rooms);
		}
	}
	i = 0;
	i = 0;
	tabtotab(p->tab_final, p->tab, p->q_rooms);
	size_ways(p);
	add_ways(p);
	nool_w_a(p->w_a, p->k_w);
	sort_ways(p->w_a, p->k_w);
	if (p->k_w > 1)
	distrib_ants(p);
	else
	p->w_a[0][2] = p->ants;
	result_show(p);
	i = 0;
	j = 0;
//	while (i < p->k_w)
//	{
//		j = 0;
//		while (j < p->w_a[i][0])
//		{
//			printf ("%d-->", p->ways[p->w_a[i][1]][j++]);
//		}
//		printf("(((%d -- %d    mur - %d))\n", p->w_a[i][1], p->w_a[i][0], p->w_a[i][2]);
//		i++;
//	}

	//print_matrix(p);
	//test***vivod
	i = 0;
//	while (i < p->q_rooms)
//	{
//		j = 1;
//		while (j <= p->pow_room[i][0])
//		{
//			printf ("%7d", p->pow_room[i][j]);
//			j++;
//		}
//
//		printf ("\nsloi %d  -  %d", i, p->s[i]);
//		printf("\n");
//		i++;
//	}
	//print_matrix(p);
	return (0);
};
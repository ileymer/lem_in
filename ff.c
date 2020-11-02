

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

void nol(int n, int *a)
{
	int i;

	i = 0;
	while (i < n)
		a[i++] = 0;
}




typedef struct s_par
{
	int previous;
	int current;
	struct s_par *next;
} t_par;

typedef struct s_way
{
	int value;
	int k;
	struct s_way *next;
	t_par *t_way;
} t_way;

typedef struct s_mas
{
	int *a;
	int *bl;
	int *s;
	int k_a;
	int **b;
	int k_b;
	int k_v;
} t_mas;


typedef struct s_queue
{
	int v;
	int p;
	struct s_queue *next;
} queue;

void nol(int n, int *a);
void add_element_end_queue(int data, queue *head);
void add_element_end_par(int a, int b, t_par *head);
queue *remove_element(queue *head);
int bfs(t_par *p, queue *q, t_mas *m, int **ms);
int edmans_carpov(t_par *p, queue *q, t_mas *m, int **ms);
int		check_matr(int **ms, int i, int jj, int ii, int n);
int valone(int **a, int n, int q);
int ebashim_nax(t_par *p, queue *q, t_mas *m, int **ms);
int check_queue(int data, queue *head);
bfs2(t_par *p, queue *q, t_mas *m, int **ms);
void remove_element_par(t_par *head);
int dfs_one(int e, t_par *p, t_mas *m);
int check_way(t_mas *m);
int dfs(t_par *p, t_mas *m);

int main() {
	t_way *p;
	queue *q;
	t_par *w;
	t_par *e;
	t_mas *m;
	int i;
	int **ms;


	p = (t_way *)malloc(sizeof(t_way));

	w = (t_par *)malloc(sizeof(t_par));
        e = (t_par *)malloc(sizeof(t_par));
	m = (t_mas *)malloc(sizeof(t_mas));

	m->k_b = 3359;
	m->k_a = 2569;
	m->b = (int **) malloc(sizeof(int) * m->k_b);
	ms = (int **) malloc(sizeof(int) * m->k_a);
	m->a = (int *)malloc(sizeof(int) * m->k_a);
	m->bl = (int *)malloc(sizeof(int) * m->k_a);
	m->s = (int *)malloc(sizeof(int) * m->k_a);
	i = 0;
	while (i < m->k_b)
		m->b[i++] = (int *) malloc(sizeof(int) * 2);
	i = 0;
	while (i < m->k_a)
		ms[i++] = (int *) malloc(sizeof(int) * m->k_a);

	i = 0;
	while (i < m->k_b) {
		scanf("%i", &m->b[i][0]);
		scanf("%i", &m->b[i][1]);
		i++;
	}
	i = 0;
	while (i < m->k_b) {
		printf("%i-%i\n", m->b[i][0], m->b[i][1]);

		i++;
	}

	nol(m->k_a, m->a);
	m->a[0] = 1;
	p->next = NULL;
	p->t_way = w;
	w->next = NULL;
        e->next = NULL;

	m->k_v = 1;

	int j;
	i = 0;
	while (i < m->k_a)
	{
		j = 0;
		while (j < m->k_a)
			ms[i][j++] = 0;
		m->bl[i] = 0;
		i++;
	}
	bfs2(w, q, m, ms);
	 i = 0;
	while (i < m->k_a)
        {
	  m->s[i] = 0;
	  m->a[i++] = 0;
        }
	//m->a[0] = 1;
         w = w->next;
	while (w != NULL)
	{

		printf ("%d - %d\n", w->previous, w->current);
		if (w->current == m->k_a - 1)
		  add_element_end_par(w->previous, w->current, e);

		if (w->current != m->k_a - 1)
                {
		  m->a[w->current] = w->previous;
                }
              w = w->next;
	}
        e = e->next;
	i = 0;
	int rs = 0;
	int rf = 0;
	int  f= 0;
	t_par *c = e;
	int mur = 425;
	m->s[i] = mur;
	int qq = 0;
	int mrS = 0;
        while (qq < mur)
 {
	    c = e;
	    while (c != NULL) {
              f = 0;
              rs = c->previous;
              rf = c->current;
              while (f == 0) {
                if (rs != 0) {
                if (m->s[rs] != 0) {
                    m->s[rf] = m->s[rs];
                    m->s[rs] = 0;
                    if (rf == m->k_a - 1)
                      qq++;
                    printf("L%d-%d ", m->s[rf], rf);
                  }
                    rf = rs;
                    rs = m->a[rs];
                  } else {
                  if (m->s[rs] != 0) {
                      m->s[rs] = m->s[rs] - 1;
                      m->s[rf] = mur - m->s[rs];
                    if (rf == m->k_a - 1)
                      qq++;
                      printf("L%d-%d ", m->s[rf], rf);
                    }
                    f = 1;
                  }
                }
              c = c->next;
              }
	    printf("\n");
		mrS++;
            }
    //    }
//          /*while (i < m->k_a)
//          {
//                  j = 0;
//                  while (j < m->k_a)
//                          printf ("%4d", ms[i][j++]);
//                  printf ("\n");
//                  i++;
//          }*/

printf("\n\n\n----------<<<%d>>>>------------\n\n\n", mrS);


	return 0;

}

void vivod(int **ms, int n)
{
	int i = 0;
	int j;
	while (i < n)
	{
		j = 0;
		while (j < n)
			printf ("%4d", ms[i][j++]);
		printf ("\n");
		i++;
	}
}

void vivod2(t_par *p, int a)
{
	while (p != NULL)
	{
		printf("%d ---> ", p->current);
		if (p->current == a)
			printf("\n");
		p = p->next;
	}
}

bfs2(t_par *p, queue *q, t_mas *m, int **ms) {
  int i = 0;

  m->s[0] = 0;

  while (check_way(m)) {
  q = (queue *)malloc(sizeof(queue));
    q->v = 0;
    q->p = 0;
    q->next = NULL;

  i = 0;
    while (i < m->k_a) {
      m->s[i] = 0;
      m->a[i] = m->bl[i];
      i++;
    }

    while (q != NULL) {
      i = 0;
      while (i < m->k_b) {
        if (q->v == m->b[i][0] || q->v == m->b[i][1]) {
          if (q->v != m->b[i][0] && m->a[m->b[i][0]] == 0 &&
              check_queue(m->b[i][0], q) == 1) {
            if (m->s[m->b[i][0]] == 0)
              m->s[m->b[i][0]] = m->s[q->v] + 1;
            if (m->b[i][0] != m->k_a - 1) {
              m->a[m->b[i][0]] = 1;
              add_element_end_queue(m->b[i][0], q);
            }
          } else if (q->v != m->b[i][1] && m->a[m->b[i][1]] == 0 &&
                     check_queue(m->b[i][1], q) == 1) {
            if (m->s[m->b[i][1]] == 0)
              m->s[m->b[i][1]] = m->s[q->v] + 1;
            if (m->b[i][1] != m->k_a - 1) {
              m->a[m->b[i][1]] = 1;
              add_element_end_queue(m->b[i][1], q);
            }
          }
        }
        i++;
      }
      m->a[q->v] = 1;
      q = remove_element(q);
    }
    i = 0;
    while (i < m->k_a - 1) {
      if (m->s[i] == m->s[m->k_a - 1])
        m->s[i]--;
      if (m->s[i] > m->s[m->k_a - 1])
        m->s[i] = -1;
      m->a[i] = 0;
      printf("sloi  %-4d %d\n", i, m->s[i]);
      i++;
    }
    printf("%-4d %d\n", i, m->s[i]);
    m->a[i] = 0;
    dfs(p, m);
    vivod2(p, m->k_a - 1);
  }
}

int dfs(t_par *p, t_mas *m)
{
  int i = 0;
  	while (i < m->k_b)
	{
          if (m->b[i][0] == 0 || m->b[i][1] == 0) {
            dfs_one(0, p, m);
          }
          i++;

	}
}

int dfs_one(int e, t_par *p, t_mas *m)
{
  int i;

  i = 0;
  while (i < m->k_b)
  {
    if (m->b[i][0] == e || m->b[i][1] == e)
    {
      if (m->b[i][0] != e && m->s[m->b[i][0]] - 1 == m->s[m->b[i][1]] && m->bl[m->b[i][0]] == 0)
      {
        add_element_end_par(m->b[i][1], m->b[i][0], p);
        if (m->b[i][0] != m->k_a - 1)
          m->bl[m->b[i][0]] = 1;
        if (m->b[i][0] == m->k_a - 1)
          return (1);
        if (dfs_one(m->b[i][0], p, m) == 0) {  m->bl[m->b[i][0]] = 0;
          m->bl[m->b[i][0]] = 0;
          remove_element_par(p);

        }
        else
          return (1);
      }
      else if ((m->b[i][1] != e && m->s[m->b[i][1]] - 1 == m->s[m->b[i][0]] && m->bl[m->b[i][1]] == 0))
      {
        add_element_end_par(m->b[i][0], m->b[i][1], p);
        if (m->b[i][1] != m->k_a - 1)
          m->bl[m->b[i][1]] = 1;
        if (m->b[i][1] == m->k_a - 1)
          return (1);
        if (dfs_one(m->b[i][1], p, m) == 0) {
          m->bl[m->b[i][1]] = 0;
          remove_element_par(p);
        }
        else
          return (1);
      }
    }
    i++;
  }

  return (0);
}

int check_way(t_mas *m)
{
  int i;

  i = 0;
  while (i < m->k_a - 1)
  {
    if (m->s[i] != -1)
    {
    return (1);
    }
    i++;
  }
  return (0);
}































int edmans_carpov(t_par *p, queue *q, t_mas *m, int **ms)
{
	int i;
	int f = 0;
	int fm = 1;
	int r;


	while (fm == 1) {
		q = (queue *) malloc(sizeof(queue));
		q->next = NULL;
		q->v = 0;
		q->p = 0;
		fm = 0;
		while (q != NULL) {
			i = 0;
			while (i < m->k_b) {
				if (q->v == m->b[i][0] || q->v == m->b[i][1]) {
					if (q->v != m->b[i][0] && q->p != m->b[i][0] && check_queue(m->b[i][0], q) == 1) {
						if (ms[q->v][m->b[i][0]] == 0) {
							ms[q->v][m->b[i][0]] = 1;
							ms[m->b[i][0]][q->v] = -1;
							add_element_end_queue(m->b[i][1], q);
						} else if (ms[q->v][m->b[i][0]] == -1) {
							ms[m->b[i][0]][q->v] = 0;
							ms[q->v][m->b[i][0]] = 0;
							add_element_end_queue(m->b[i][1], q);
						}
						if (m->b[i][0] == m->k_a - 1) {
							fm = 1;
							break;
						}
					}
					if (q->v != m->b[i][1] && q->p != m->b[i][1]  && check_queue(m->b[i][1], q) == 1) {
						if (ms[q->v][m->b[i][1]] == 0) {
							ms[m->b[i][1]][q->v] = -1;
							ms[q->v][m->b[i][1]] = 1;
							add_element_end_queue(m->b[i][1], q);
						} else if (ms[q->v][m->b[i][1]] == -1) {
							ms[m->b[i][1]][q->v] = 0;
							ms[q->v][m->b[i][1]] = 0;
							add_element_end_queue(m->b[i][1], q);
						}
						if (m->b[i][1] == m->k_a - 1) {
							fm = 1;
							break;
						}

					}

				}
				i++;

			}
			q = remove_element(q);
			if (fm == 1)
			{
				while (q != NULL)
					q = remove_element(q);
			}


		}
		i = 0;
	int j;
		j = 0;
		vivod(ms, m->k_a);
		printf("\n----------------\n");
		while (j < m->k_a)
		{
			if (ms[i][j] != 0)
				check_matr(ms, j, j, i, m->k_a);
			j++;
		}
		vivod(ms, m->k_a);
		printf("\n\n\n");
	}
}

int ebashim_nax(t_par *p, queue *q, t_mas *m, int **ms)
{
	int i;
	int f = 0;
	int fm = 0;
	int r;

	while (fm < 3)
	{
		if (q != NULL)
		q->v = 0;
		f = 0;
		while (q != NULL && f == 0)
		{
			i = 0;
			while (i < m->k_b)
			{
				if (q->v == m->b[i][0] || q->v == m->b[i][1])
				{
					if (q->v != m->b[i][0] && m->b[i][0] != 0)
					{
						if ((valone(ms, m->k_a, m->b[i][0]) < 1) || m->b[i][0] == m->k_a - 1)
						{
							if (ms[m->b[i][0]][m->b[i][1]] == 0)
							{
								ms[m->b[i][0]][m->b[i][1]] = -1;
								ms[m->b[i][1]][m->b[i][0]] = 1;
							}
							else if (ms[m->b[i][0]][m->b[i][1]] == -1)
							{
								ms[m->b[i][0]][m->b[i][1]] = 0;
								ms[m->b[i][1]][m->b[i][0]] = 0;
							}
							add_element_end_queue(m->b[i][0], q);
							if (m->b[i][0] == m->k_a - 1)
								f = 1;
						}
					}
					if (q->v != m->b[i][1] && m->b[i][1] != 0)
					{
						if ((valone(ms, m->k_a, m->b[i][1]) < 1) || m->b[i][1] == m->k_a - 1)
						{
							if (ms[m->b[i][1]][m->b[i][0]] == 0)
							{
								ms[m->b[i][1]][m->b[i][0]] = -1;
								ms[m->b[i][0]][m->b[i][1]] = 1;
							}
							else if (ms[m->b[i][1]][m->b[i][0]] == -1)
							{
								ms[m->b[i][1]][m->b[i][0]] = 0;
								ms[m->b[i][0]][m->b[i][1]] = 0;
							}
							add_element_end_queue(m->b[i][1], q);
							if (m->b[i][1] == m->k_a - 1)
								f = 1;
						}
					}
				}
			i++;
			}
			if (q->v != m->k_a - 1)
				q = remove_element(q);
		}
		i = 0;

		int j = 0;
		while (j < m->k_a)
		{
			if (ms[i][j] != 0)
				check_matr(ms, j, j, i, m->k_a);
			j++;
		}
		fm++;
		if (q != NULL)
		while (q->next != NULL)
		{
			q = remove_element(q);
		}

	}
}

int bfs(t_par *p, queue *q, t_mas *m, int **ms)
{
	int i;
	int f = 0;


	i = 0;

	while (q != NULL && f == 0)
	{
		i = 0;
		while (i < m->k_b)
		{

			if (q->v == m->b[i][0] || q->v == m->b[i][1])
			{
				if (q->v != m->b[i][0])
				{

					if (m->a[m->b[i][0]] == 0)
					{
						if (m->b[i][0] != m->k_a - 1)
						add_element_end_queue(m->b[i][0], q);

						add_element_end_par(q->v, m->b[i][0], p);
						if (m->b[i][0] != m->k_a - 1)
						m->a[m->b[i][0]] = 1;
						if (ms[m->b[i][0]][m->b[i][1]] == 0)
						{
							ms[m->b[i][0]][m->b[i][1]] = -1;
							ms[m->b[i][1]][m->b[i][0]] = 1;
						}

					}
				}
				else
				{

					if (m->a[m->b[i][1]] == 0)
					{
						if (m->b[i][1] != m->k_a - 1)
						add_element_end_queue(m->b[i][1], q);

						add_element_end_par(q->v, m->b[i][1], p);
						if (m->b[i][1] != m->k_a - 1)
						m->a[m->b[i][1]] = 1;
						if (ms[m->b[i][0]][m->b[i][1]] == 0)
						{
						ms[m->b[i][0]][m->b[i][1]] = 1;
						ms[m->b[i][1]][m->b[i][0]] = -1;


						}
					}
				}
			}


			i++;

		}
		m->a[q->v] = 1;
		q = remove_element(q);
	}
	int j;
	i = 0;
	while (i < m->k_a)
	{
		j = 0;
		while (j < m->k_a)
			printf ("%4d", ms[i][j++]);
		printf ("\n");
		i++;
	}
	i = 0;

		j = 0;
		while (j < m->k_a)
		{
			if (ms[i][j] != 0)
			check_matr(ms, j, j, i, m->k_a);
			j++;
		}

	//check_matr(ms, 0, 0, 0, m->k_a);

}




int		check_matr(int **ms, int i, int jj, int ii, int n)
{
	int f;
	int j;

	f = 0;
	j = 0;

		while (j < n && f == 0)
		{
			if (ms[i][j] == 1)
				f = check_matr(ms, j, j, i, n);
			if (ms[i][8] == 1)
				f = 1;
			j++;
		}

	if (f == 0) {
		ms[ii][jj] = 0;
		ms[jj][ii] = 0;

	}
	return f;


}

int valone(int **a, int n, int q)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < n)
	{
		if (a[i][q] == 1)
		{
			k++;
		}
		i++;
	}
	return (k);
}
check_queue(int data, queue *head)
{
	queue *p = head;

	while (p != NULL)
	{
		if (p->v == data)
			return (0);
		p = p->next;
	}
	return (1);
}
void add_element_end_queue(int data, queue *head) {
// Выделение памяти под корень списка
	queue *tmp = (queue *) malloc(sizeof(queue));
	int o;
// Присваивание значения узлу
	tmp->v = data;

// Присваивание указателю на следующий элемент значения NULL
	tmp->next = NULL;
// Присваивание новому указателю указателя head.
// Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
	queue *p = head;
	tmp->p = p->v;
// Сдвиг указателя p в самый конец первоначального списка
	while (p->next != NULL) {
	p = p->next;
}

// Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
	p->next = tmp;
}

void add_element_end(int data, t_way *head)
{
// Выделение памяти под корень списка
	t_par *tmpw = (t_par*)malloc(sizeof(t_par));
	t_way *tmp = (t_way*)malloc(sizeof(t_way));
// Присваивание значения узлу
	tmp->value = data;
// Присваивание указателю на следующий элемент значения NULL
	tmp -> next = NULL;
// Присваивание новому указателю указателя head.
// Присваивание выполняется для того, чтобы не потерять указатель на «голову» списка
	t_way *p = head;
// Сдвиг указателя p в самый конец первоначального списка
	while (p->next != NULL)
		p = p->next;
// Присваивание указателю p -> next значения указателя tmp (созданный новый узел)
	p->next = tmp;
	p->t_way = tmpw;
}



void add_element_end_par(int a, int b, t_par *head)
{
// Выделение памяти под корень списка
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


queue *remove_element(queue *head)
{
// Присваивание новому указателю  tmp указателя head, p - NULL
	queue *tmp = head->next;
// Проверка списка на пустоту
	if (head == NULL)
		return NULL;

		free(head);
		return tmp;


}

void remove_element_par(t_par *head)
{
	int retval = 0;

	/* if there is only one item in the list, remove it */
	if (head->next == NULL) {
		free(head);
	}

	/* get to the last node in the list */
	t_par * current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* now current points to the last item of the list, so let's remove current->next */

	free(current->next);
	current->next = NULL;

}




/*
 * while (i < r)
		printf("%d-%d\n", b[i][0], b[i++][1]);
	printf("dada");
 */

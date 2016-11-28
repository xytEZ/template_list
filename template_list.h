#ifndef TEMPLATE_LIST_H_
# define TEMPLATE_LIST_H_

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "x_print_format.h"

# define List(type)		t_list_##type
# define FrameList(type)					\
								\
  typedef struct s_node_##type	t_node_##type;			\
  typedef struct s_list_##type	t_list_##type;			\
								\
  struct s_node_##type						\
  {								\
    type		data;					\
    t_node_##type	*next;					\
      t_node_##type	*prev;					\
  };								\
								\
  struct s_list_##type						\
  {								\
    size_t		length;					\
    t_node_##type	*head;					\
      t_node_##type	*tail;					\
  };								\
  								\
  t_list_##type							\
  list_##type##_new()						\
  {								\
    t_list_##type	list = {0, NULL, NULL};			\
      								\
      return list;						\
  }								\
  								\
  void								\
  list_##type##_clear(t_list_##type *list)			\
  {								\
    if (list->head)						\
      {								\
	while (list->head)					\
	  {							\
	    t_node_##type	*tmp = list->head;		\
	      							\
	      list->head = list->head->next;			\
	      free(tmp);					\
	  }							\
	list->tail = NULL;					\
	list->length = 0;					\
      }								\
  }								\
  								\
  void								\
  list_##type##_dump(const t_list_##type *list)			\
  {								\
    if (list->head)						\
      {								\
	const t_node_##type	*tmp = list->head;		\
	  							\
	  while (tmp)						\
	    {							\
	      printf("data -> " X_PRINT_FORMAT_##type		\
		     "\n", tmp->data);				\
	      tmp = tmp->next;					\
	    }							\
      }								\
  }								\
								\
  void								\
  list_##type##_dump_reverse(const t_list_##type *list)		\
  {								\
    if (list->tail)						\
      {								\
	const t_node_##type	*tmp = list->tail;		\
								\
	  while (tmp)						\
	    {							\
	      printf("data -> " X_PRINT_FORMAT_##type		\
		     "\n", tmp->data);				\
	      tmp = tmp->prev;					\
	    }							\
      }								\
  }								\
								\
  bool								\
  list_##type##_push_front(t_list_##type *list, type data)	\
  {								\
    t_node_##type	*node = malloc(sizeof(*node));		\
								\
      if (!node)						\
	return false;						\
      node->data = data;					\
      node->next = list->head;					\
      if (list->head)						\
	list->head->prev = node;				\
      node->prev = NULL;					\
      list->head = node;					\
      if (!list->tail)						\
	list->tail = node;					\
      ++list->length;						\
      return true;						\
  }								\
								\
  bool								\
  list_##type##_push_back(t_list_##type *list, type data)	\
  {								\
   t_node_##type	*node = malloc(sizeof(*node));		\
								\
     if (!node)							\
       return false;						\
     node->data = data;						\
     node->next = NULL;						\
     if (!list->tail)						\
       {							\
	node->prev = NULL;					\
	list->head = node;					\
       }							\
     else							\
       {							\
	 list->tail->next = node;				\
	 node->prev = list->tail;				\
       }							\
     list->tail = node;						\
     ++list->length;						\
     return true;						\
  }								\
  								\
  t_node_##type*						\
  list_##type##_pop_front(t_list_##type *list)			\
  {								\
    if (!list->head)						\
      return NULL;						\
    								\
    t_node_##type	*node = list->head;			\
      								\
      if (list->head->next)					\
	{							\
	  list->head = list->head->next;			\
	  list->head->prev = NULL;				\
	}							\
      else							\
	{							\
	  list->head = NULL;					\
	  list->tail = NULL;					\
	}							\
      --list->length;						\
      return node;						\
  }								\
  								\
  t_node_##type*						\
  list_##type##_pop_back(t_list_##type *list)			\
  {								\
    if (!list->tail)						\
      return NULL;						\
    								\
    t_node_##type	*node = list->tail;			\
      								\
      if (list->tail->prev)					\
	{							\
	  list->tail = list->tail->prev;			\
	  list->tail->next = NULL;				\
	}							\
      else							\
	{							\
	  list->head = NULL;					\
	  list->tail = NULL;					\
	}							\
      --list->length;						\
      return node;						\
  }								\
  								\
  size_t							\
  list_##type##_size(const t_list_##type *list)			\
  {								\
    return list->length;					\
  }								\

# define list_new(type) list_##type##_new()
# define list_clear(type, list) list_##type##_clear(&list)
# define list_dump(type, list) list_##type##_dump(&list)
# define list_dump_reverse(type, list) list_##type##_dump_reverse(&list)
# define list_push_front(type, list, data) list_##type##_push_front(&list, data)
# define list_push_back(type, list, data) list_##type##_push_back(&list, data)
# define list_pop_front(type, list) list_##type##_pop_front(&list)
# define list_pop_back(type, list) list_##type##_pop_back(&list)
# define list_size(type, list) list_##type##_size(&list)

#endif	/* !TEMPLATE_LIST_H_ */

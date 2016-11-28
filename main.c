#include "template_list.h"

FrameList(float);
FrameList(char);

int
main()
{
  printf("( ( ( ( List float ) ) ) )\n\n");

  List(float)	list = list_new(float);

  list_push_front(float, list, 42);
  list_push_front(float, list, 84);
  list_push_back(float, list, 21);
  list_push_back(float, list, 10.5); 
  
  printf("---- dump list ----\n");

  list_dump(float, list);

  printf("\n\n");

  printf("---- dump reverse list ----\n");

  list_dump_reverse(float, list);

  printf("\n\n");
  
  printf("List's size => %zd\n\n", list_size(float, list));

  printf("!!!!-- pop_front and pop_back --!!!!\n\n\n");

  free(list_pop_front(float, list));
  free(list_pop_back(float, list));

  printf("---- dump list ----\n");

  list_dump(float, list);

  printf("\n\n");

  printf("---- dump reverse list ----\n");

  list_dump_reverse(float, list);

  printf("\n\n");
  
  printf("List's size => %zd\n\n", list_size(float, list));

  list_clear(float, list);


  

  printf("( ( ( ( List char ) ) ) )\n\n");

  List(char)	list2 = list_new(char);

  list_push_front(char, list2, 'b');
  list_push_front(char, list2, 'a');
  list_push_back(char, list2, 'c');
  list_push_back(char, list2, 'd'); 
  
  printf("---- dump list ----\n");

  list_dump(char, list2);
  
  list_clear(char, list2);

  return 1;
}

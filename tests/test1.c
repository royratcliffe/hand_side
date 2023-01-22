#include <assert.h>
#include <string.h>

#include "hand_side.h"

int main() {
  struct hand_side *address_by_name = NULL;
  push_hand_side(&address_by_name, "main", &main);
  assert(right_for_left_stricmp_hand_side(&address_by_name, "main") == &main);
  free_hand_side(&address_by_name);
  return 0;
}

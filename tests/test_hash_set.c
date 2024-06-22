#include "../include/rsv_containers.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test_hash_set(void) {
  int test_int;
  int* test_key;
  rsv_hash_set_t hash_set;

  /* Test: Create hash set */
  hash_set = rsv_hash_set_create(2, sizeof(int), NULL, NULL);
  assert(hash_set.amount == 0);
  assert(hash_set.capacity == 2);

  /* Test: Insert keys */
  test_int = 100;
  test_key = &test_int;
  rsv_hash_set_add(&hash_set, test_key);
  assert(hash_set.amount == 1);

  test_int = 200;
  test_key = &test_int;
  rsv_hash_set_add(&hash_set, test_key);
  assert(hash_set.amount == 2);

  /* Test: Check keys presence */
  test_int = 100;
  test_key = &test_int;
  assert(rsv_hash_set_contains(&hash_set, test_key) == 1);

  test_int = 200;
  test_key = &test_int;
  assert(rsv_hash_set_contains(&hash_set, test_key) == 1);

  test_int = 300;
  test_key = &test_int;
  assert(rsv_hash_set_contains(&hash_set, test_key) == 0);

  /* Test: Insert with key collision (same hash index) */
  test_int = 300;
  test_key = &test_int;
  rsv_hash_set_add(&hash_set, test_key);
  assert(hash_set.amount == 3);
  assert(rsv_hash_set_contains(&hash_set, test_key) == 1);

  /* Test: Remove keys from hash set */
  test_int = 200;
  test_key = &test_int;
  rsv_hash_set_remove(&hash_set, test_key);
  assert(hash_set.amount == 2);
  assert(rsv_hash_set_contains(&hash_set, test_key) == 0);

  test_int = 100;
  test_key = &test_int;
  rsv_hash_set_remove(&hash_set, test_key);
  assert(hash_set.amount == 1);
  assert(rsv_hash_set_contains(&hash_set, test_key) == 0);

  rsv_hash_set_destroy(&hash_set);
  printf("All hash set tests passed!\n");
}

int main(void) {
  test_hash_set();
  exit(EXIT_SUCCESS);
}

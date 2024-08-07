#ifndef solution_TEST
#define solution_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define solution_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/solution.h"
solution_t* instantiate_solution(int include_optional);



solution_t* instantiate_solution(int include_optional) {
  solution_t* solution = NULL;
  if (include_optional) {
    solution = solution_create(
      "5d7fc778-3e59-4128-a797-2e423c0aa461",
      opthub_rest_api_solution__"User",
      "912f548d-2bbe-48ab-90ce-e96dae38377d",
      4,
      0,
      "2024-08-06T10:11:45.789Z",
      "1e892e70-47ba-4c8e-8563-6aea9019e334"
    );
  } else {
    solution = solution_create(
      "5d7fc778-3e59-4128-a797-2e423c0aa461",
      opthub_rest_api_solution__"User",
      "912f548d-2bbe-48ab-90ce-e96dae38377d",
      4,
      0,
      "2024-08-06T10:11:45.789Z",
      "1e892e70-47ba-4c8e-8563-6aea9019e334"
    );
  }

  return solution;
}


#ifdef solution_MAIN

void test_solution(int include_optional) {
    solution_t* solution_1 = instantiate_solution(include_optional);

	cJSON* jsonsolution_1 = solution_convertToJSON(solution_1);
	printf("solution :\n%s\n", cJSON_Print(jsonsolution_1));
	solution_t* solution_2 = solution_parseFromJSON(jsonsolution_1);
	cJSON* jsonsolution_2 = solution_convertToJSON(solution_2);
	printf("repeating solution:\n%s\n", cJSON_Print(jsonsolution_2));
}

int main() {
  test_solution(1);
  test_solution(0);

  printf("Hello world \n");
  return 0;
}

#endif // solution_MAIN
#endif // solution_TEST

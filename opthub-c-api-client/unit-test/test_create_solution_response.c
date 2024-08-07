#ifndef create_solution_response_TEST
#define create_solution_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define create_solution_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/create_solution_response.h"
create_solution_response_t* instantiate_create_solution_response(int include_optional);



create_solution_response_t* instantiate_create_solution_response(int include_optional) {
  create_solution_response_t* create_solution_response = NULL;
  if (include_optional) {
    create_solution_response = create_solution_response_create(
      "5d7fc778-3e59-4128-a797-2e423c0aa461",
      opthub_rest_api_create_solution_response__"User",
      "912f548d-2bbe-48ab-90ce-e96dae38377d",
      4
    );
  } else {
    create_solution_response = create_solution_response_create(
      "5d7fc778-3e59-4128-a797-2e423c0aa461",
      opthub_rest_api_create_solution_response__"User",
      "912f548d-2bbe-48ab-90ce-e96dae38377d",
      4
    );
  }

  return create_solution_response;
}


#ifdef create_solution_response_MAIN

void test_create_solution_response(int include_optional) {
    create_solution_response_t* create_solution_response_1 = instantiate_create_solution_response(include_optional);

	cJSON* jsoncreate_solution_response_1 = create_solution_response_convertToJSON(create_solution_response_1);
	printf("create_solution_response :\n%s\n", cJSON_Print(jsoncreate_solution_response_1));
	create_solution_response_t* create_solution_response_2 = create_solution_response_parseFromJSON(jsoncreate_solution_response_1);
	cJSON* jsoncreate_solution_response_2 = create_solution_response_convertToJSON(create_solution_response_2);
	printf("repeating create_solution_response:\n%s\n", cJSON_Print(jsoncreate_solution_response_2));
}

int main() {
  test_create_solution_response(1);
  test_create_solution_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // create_solution_response_MAIN
#endif // create_solution_response_TEST

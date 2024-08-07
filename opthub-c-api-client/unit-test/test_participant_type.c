#ifndef participant_type_TEST
#define participant_type_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define participant_type_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/participant_type.h"
participant_type_t* instantiate_participant_type(int include_optional);



participant_type_t* instantiate_participant_type(int include_optional) {
  participant_type_t* participant_type = NULL;
  if (include_optional) {
    participant_type = participant_type_create(
    );
  } else {
    participant_type = participant_type_create(
    );
  }

  return participant_type;
}


#ifdef participant_type_MAIN

void test_participant_type(int include_optional) {
    participant_type_t* participant_type_1 = instantiate_participant_type(include_optional);

	cJSON* jsonparticipant_type_1 = participant_type_convertToJSON(participant_type_1);
	printf("participant_type :\n%s\n", cJSON_Print(jsonparticipant_type_1));
	participant_type_t* participant_type_2 = participant_type_parseFromJSON(jsonparticipant_type_1);
	cJSON* jsonparticipant_type_2 = participant_type_convertToJSON(participant_type_2);
	printf("repeating participant_type:\n%s\n", cJSON_Print(jsonparticipant_type_2));
}

int main() {
  test_participant_type(1);
  test_participant_type(0);

  printf("Hello world \n");
  return 0;
}

#endif // participant_type_MAIN
#endif // participant_type_TEST

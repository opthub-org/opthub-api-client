/*
 * create_solution_response.h
 *
 * 解の作成リクエストの結果
 */

#ifndef _create_solution_response_H_
#define _create_solution_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct create_solution_response_t create_solution_response_t;

#include "participant_type.h"

// Enum  for create_solution_response

typedef enum  { opthub_rest_api_create_solution_response__NULL = 0, opthub_rest_api_create_solution_response__User, opthub_rest_api_create_solution_response__Team } opthub_rest_api_create_solution_response__e;

char* create_solution_response_participant_type_ToString(opthub_rest_api_create_solution_response__e participant_type);

opthub_rest_api_create_solution_response__e create_solution_response_participant_type_FromString(char* participant_type);



typedef struct create_solution_response_t {
    char *match_id; // string
    participant_type_t *participant_type; // custom
    char *participant_id; // string
    int trial_no; //numeric

} create_solution_response_t;

create_solution_response_t *create_solution_response_create(
    char *match_id,
    participant_type_t *participant_type,
    char *participant_id,
    int trial_no
);

void create_solution_response_free(create_solution_response_t *create_solution_response);

create_solution_response_t *create_solution_response_parseFromJSON(cJSON *create_solution_responseJSON);

cJSON *create_solution_response_convertToJSON(create_solution_response_t *create_solution_response);

#endif /* _create_solution_response_H_ */


/*
 * solution.h
 *
 * 解
 */

#ifndef _solution_H_
#define _solution_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct solution_t solution_t;

#include "object.h"
#include "participant_type.h"

// Enum  for solution

typedef enum  { opthub_rest_api_solution__NULL = 0, opthub_rest_api_solution__User, opthub_rest_api_solution__Team } opthub_rest_api_solution__e;

char* solution_participant_type_ToString(opthub_rest_api_solution__e participant_type);

opthub_rest_api_solution__e solution_participant_type_FromString(char* participant_type);



typedef struct solution_t {
    char *match_id; // string
    participant_type_t *participant_type; // custom
    char *participant_id; // string
    int trial_no; //numeric
    object_t *variable; //object
    char *created_at; //date time
    char *user_id; // string

} solution_t;

solution_t *solution_create(
    char *match_id,
    participant_type_t *participant_type,
    char *participant_id,
    int trial_no,
    object_t *variable,
    char *created_at,
    char *user_id
);

void solution_free(solution_t *solution);

solution_t *solution_parseFromJSON(cJSON *solutionJSON);

cJSON *solution_convertToJSON(solution_t *solution);

#endif /* _solution_H_ */


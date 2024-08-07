/*
 * participant_type.h
 *
 * 参加者の種別
 */

#ifndef _participant_type_H_
#define _participant_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct participant_type_t participant_type_t;


// Enum  for participant_type

typedef enum { opthub_rest_api_participant_type__NULL = 0, opthub_rest_api_participant_type__User, opthub_rest_api_participant_type__Team } opthub_rest_api_participant_type__e;

char* participant_type_participant_type_ToString(opthub_rest_api_participant_type__e participant_type);

opthub_rest_api_participant_type__e participant_type_participant_type_FromString(char* participant_type);

//cJSON *participant_type_participant_type_convertToJSON(opthub_rest_api_participant_type__e participant_type);

//opthub_rest_api_participant_type__e participant_type_participant_type_parseFromJSON(cJSON *participant_typeJSON);

#endif /* _participant_type_H_ */


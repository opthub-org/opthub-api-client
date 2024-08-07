#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "participant_type.h"


char* participant_type_participant_type_ToString(opthub_rest_api_participant_type__e participant_type) {
    char *participant_typeArray[] =  { "NULL", "User", "Team" };
    return participant_typeArray[participant_type];
}

opthub_rest_api_participant_type__e participant_type_participant_type_FromString(char* participant_type) {
    int stringToReturn = 0;
    char *participant_typeArray[] =  { "NULL", "User", "Team" };
    size_t sizeofArray = sizeof(participant_typeArray) / sizeof(participant_typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(participant_type, participant_typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *participant_type_participant_type_convertToJSON(opthub_rest_api_participant_type__e participant_type) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "participant_type", participant_type_participant_type_ToString(participant_type)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

opthub_rest_api_participant_type__e participant_type_participant_type_parseFromJSON(cJSON *participant_typeJSON) {
    opthub_rest_api_participant_type__e *participant_type = NULL;
    opthub_rest_api_participant_type__e participant_typeVariable;
    cJSON *participant_typeVar = cJSON_GetObjectItemCaseSensitive(participant_typeJSON, "participant_type");
    if(!cJSON_IsString(participant_typeVar) || (participant_typeVar->valuestring == NULL)){
        goto end;
    }
    participant_typeVariable = participant_type_participant_type_FromString(participant_typeVar->valuestring);
    return participant_typeVariable;
end:
    return 0;
}

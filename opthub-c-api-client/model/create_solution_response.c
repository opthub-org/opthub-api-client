#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "create_solution_response.h"


char* create_solution_response_participant_type_ToString(opthub_rest_api_create_solution_response__e participant_type) {
    char* participant_typeArray[] =  { "NULL", "User", "Team" };
    return participant_typeArray[participant_type];
}

opthub_rest_api_create_solution_response__e create_solution_response_participant_type_FromString(char* participant_type){
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

create_solution_response_t *create_solution_response_create(
    char *match_id,
    participant_type_t *participant_type,
    char *participant_id,
    int trial_no
    ) {
    create_solution_response_t *create_solution_response_local_var = malloc(sizeof(create_solution_response_t));
    if (!create_solution_response_local_var) {
        return NULL;
    }
    create_solution_response_local_var->match_id = match_id;
    create_solution_response_local_var->participant_type = participant_type;
    create_solution_response_local_var->participant_id = participant_id;
    create_solution_response_local_var->trial_no = trial_no;

    return create_solution_response_local_var;
}


void create_solution_response_free(create_solution_response_t *create_solution_response) {
    if(NULL == create_solution_response){
        return ;
    }
    listEntry_t *listEntry;
    if (create_solution_response->match_id) {
        free(create_solution_response->match_id);
        create_solution_response->match_id = NULL;
    }
    if (create_solution_response->participant_type) {
        participant_type_free(create_solution_response->participant_type);
        create_solution_response->participant_type = NULL;
    }
    if (create_solution_response->participant_id) {
        free(create_solution_response->participant_id);
        create_solution_response->participant_id = NULL;
    }
    free(create_solution_response);
}

cJSON *create_solution_response_convertToJSON(create_solution_response_t *create_solution_response) {
    cJSON *item = cJSON_CreateObject();

    // create_solution_response->match_id
    if (!create_solution_response->match_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "matchId", create_solution_response->match_id) == NULL) {
    goto fail; //String
    }


    // create_solution_response->participant_type
    if (opthub_rest_api_create_solution_response__NULL == create_solution_response->participant_type) {
        goto fail;
    }
    cJSON *participant_type_local_JSON = participant_type_convertToJSON(create_solution_response->participant_type);
    if(participant_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "participantType", participant_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // create_solution_response->participant_id
    if (!create_solution_response->participant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "participantId", create_solution_response->participant_id) == NULL) {
    goto fail; //String
    }


    // create_solution_response->trial_no
    if (!create_solution_response->trial_no) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "trialNo", create_solution_response->trial_no) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

create_solution_response_t *create_solution_response_parseFromJSON(cJSON *create_solution_responseJSON){

    create_solution_response_t *create_solution_response_local_var = NULL;

    // define the local variable for create_solution_response->participant_type
    participant_type_t *participant_type_local_nonprim = NULL;

    // create_solution_response->match_id
    cJSON *match_id = cJSON_GetObjectItemCaseSensitive(create_solution_responseJSON, "matchId");
    if (!match_id) {
        goto end;
    }

    
    if(!cJSON_IsString(match_id))
    {
    goto end; //String
    }

    // create_solution_response->participant_type
    cJSON *participant_type = cJSON_GetObjectItemCaseSensitive(create_solution_responseJSON, "participantType");
    if (!participant_type) {
        goto end;
    }

    
    participant_type_local_nonprim = participant_type_parseFromJSON(participant_type); //custom

    // create_solution_response->participant_id
    cJSON *participant_id = cJSON_GetObjectItemCaseSensitive(create_solution_responseJSON, "participantId");
    if (!participant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(participant_id))
    {
    goto end; //String
    }

    // create_solution_response->trial_no
    cJSON *trial_no = cJSON_GetObjectItemCaseSensitive(create_solution_responseJSON, "trialNo");
    if (!trial_no) {
        goto end;
    }

    
    if(!cJSON_IsNumber(trial_no))
    {
    goto end; //Numeric
    }


    create_solution_response_local_var = create_solution_response_create (
        strdup(match_id->valuestring),
        participant_type_local_nonprim,
        strdup(participant_id->valuestring),
        trial_no->valuedouble
        );

    return create_solution_response_local_var;
end:
    if (participant_type_local_nonprim) {
        participant_type_free(participant_type_local_nonprim);
        participant_type_local_nonprim = NULL;
    }
    return NULL;

}

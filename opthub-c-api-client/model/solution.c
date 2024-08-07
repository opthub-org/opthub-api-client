#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "solution.h"


char* solution_participant_type_ToString(opthub_rest_api_solution__e participant_type) {
    char* participant_typeArray[] =  { "NULL", "User", "Team" };
    return participant_typeArray[participant_type];
}

opthub_rest_api_solution__e solution_participant_type_FromString(char* participant_type){
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

solution_t *solution_create(
    char *match_id,
    participant_type_t *participant_type,
    char *participant_id,
    int trial_no,
    object_t *variable,
    char *created_at,
    char *user_id
    ) {
    solution_t *solution_local_var = malloc(sizeof(solution_t));
    if (!solution_local_var) {
        return NULL;
    }
    solution_local_var->match_id = match_id;
    solution_local_var->participant_type = participant_type;
    solution_local_var->participant_id = participant_id;
    solution_local_var->trial_no = trial_no;
    solution_local_var->variable = variable;
    solution_local_var->created_at = created_at;
    solution_local_var->user_id = user_id;

    return solution_local_var;
}


void solution_free(solution_t *solution) {
    if(NULL == solution){
        return ;
    }
    listEntry_t *listEntry;
    if (solution->match_id) {
        free(solution->match_id);
        solution->match_id = NULL;
    }
    if (solution->participant_type) {
        participant_type_free(solution->participant_type);
        solution->participant_type = NULL;
    }
    if (solution->participant_id) {
        free(solution->participant_id);
        solution->participant_id = NULL;
    }
    if (solution->variable) {
        object_free(solution->variable);
        solution->variable = NULL;
    }
    if (solution->created_at) {
        free(solution->created_at);
        solution->created_at = NULL;
    }
    if (solution->user_id) {
        free(solution->user_id);
        solution->user_id = NULL;
    }
    free(solution);
}

cJSON *solution_convertToJSON(solution_t *solution) {
    cJSON *item = cJSON_CreateObject();

    // solution->match_id
    if (!solution->match_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "matchId", solution->match_id) == NULL) {
    goto fail; //String
    }


    // solution->participant_type
    if (opthub_rest_api_solution__NULL == solution->participant_type) {
        goto fail;
    }
    cJSON *participant_type_local_JSON = participant_type_convertToJSON(solution->participant_type);
    if(participant_type_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "participantType", participant_type_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }


    // solution->participant_id
    if (!solution->participant_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "participantId", solution->participant_id) == NULL) {
    goto fail; //String
    }


    // solution->trial_no
    if (!solution->trial_no) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "trialNo", solution->trial_no) == NULL) {
    goto fail; //Numeric
    }


    // solution->variable
    if (!solution->variable) {
        goto fail;
    }
    cJSON *variable_object = object_convertToJSON(solution->variable);
    if(variable_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "variable", variable_object);
    if(item->child == NULL) {
    goto fail;
    }


    // solution->created_at
    if (!solution->created_at) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "createdAt", solution->created_at) == NULL) {
    goto fail; //Date-Time
    }


    // solution->user_id
    if(solution->user_id) {
    if(cJSON_AddStringToObject(item, "userId", solution->user_id) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

solution_t *solution_parseFromJSON(cJSON *solutionJSON){

    solution_t *solution_local_var = NULL;

    // define the local variable for solution->participant_type
    participant_type_t *participant_type_local_nonprim = NULL;

    // solution->match_id
    cJSON *match_id = cJSON_GetObjectItemCaseSensitive(solutionJSON, "matchId");
    if (!match_id) {
        goto end;
    }

    
    if(!cJSON_IsString(match_id))
    {
    goto end; //String
    }

    // solution->participant_type
    cJSON *participant_type = cJSON_GetObjectItemCaseSensitive(solutionJSON, "participantType");
    if (!participant_type) {
        goto end;
    }

    
    participant_type_local_nonprim = participant_type_parseFromJSON(participant_type); //custom

    // solution->participant_id
    cJSON *participant_id = cJSON_GetObjectItemCaseSensitive(solutionJSON, "participantId");
    if (!participant_id) {
        goto end;
    }

    
    if(!cJSON_IsString(participant_id))
    {
    goto end; //String
    }

    // solution->trial_no
    cJSON *trial_no = cJSON_GetObjectItemCaseSensitive(solutionJSON, "trialNo");
    if (!trial_no) {
        goto end;
    }

    
    if(!cJSON_IsNumber(trial_no))
    {
    goto end; //Numeric
    }

    // solution->variable
    cJSON *variable = cJSON_GetObjectItemCaseSensitive(solutionJSON, "variable");
    if (!variable) {
        goto end;
    }

    object_t *variable_local_object = NULL;
    
    variable_local_object = object_parseFromJSON(variable); //object

    // solution->created_at
    cJSON *created_at = cJSON_GetObjectItemCaseSensitive(solutionJSON, "createdAt");
    if (!created_at) {
        goto end;
    }

    
    if(!cJSON_IsString(created_at) && !cJSON_IsNull(created_at))
    {
    goto end; //DateTime
    }

    // solution->user_id
    cJSON *user_id = cJSON_GetObjectItemCaseSensitive(solutionJSON, "userId");
    if (user_id) { 
    if(!cJSON_IsString(user_id) && !cJSON_IsNull(user_id))
    {
    goto end; //String
    }
    }


    solution_local_var = solution_create (
        strdup(match_id->valuestring),
        participant_type_local_nonprim,
        strdup(participant_id->valuestring),
        trial_no->valuedouble,
        variable_local_object,
        strdup(created_at->valuestring),
        user_id && !cJSON_IsNull(user_id) ? strdup(user_id->valuestring) : NULL
        );

    return solution_local_var;
end:
    if (participant_type_local_nonprim) {
        participant_type_free(participant_type_local_nonprim);
        participant_type_local_nonprim = NULL;
    }
    return NULL;

}

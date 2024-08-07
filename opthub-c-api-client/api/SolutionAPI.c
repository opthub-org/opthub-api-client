#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "SolutionAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// 解の作成
//
create_solution_response_t*
SolutionAPI_createSolution(apiClient_t *apiClient, char *matchId, variable)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/solution")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/solution");




    // query parameters
    char *keyQuery_matchId = NULL;
    char * valueQuery_matchId = NULL;
    keyValuePair_t *keyPairQuery_matchId = 0;
    if (matchId)
    {
        keyQuery_matchId = strdup("matchId");
        valueQuery_matchId = strdup((matchId));
        keyPairQuery_matchId = keyValuePair_create(keyQuery_matchId, valueQuery_matchId);
        list_addElement(localVarQueryParameters,keyPairQuery_matchId);
    }

    // query parameters
    char *keyQuery_variable = NULL;
     valueQuery_variable ;
    keyValuePair_t *keyPairQuery_variable = 0;
    if (variable)
    {
        keyQuery_variable = strdup("variable");
        valueQuery_variable = (variable);
        keyPairQuery_variable = keyValuePair_create(keyQuery_variable, &valueQuery_variable);
        list_addElement(localVarQueryParameters,keyPairQuery_variable);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful operation");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","successful operation");
    //}
    //nonprimitive not container
    cJSON *SolutionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    create_solution_response_t *elementToReturn = create_solution_response_parseFromJSON(SolutionAPIlocalVarJSON);
    cJSON_Delete(SolutionAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_matchId){
        free(keyQuery_matchId);
        keyQuery_matchId = NULL;
    }
    if(valueQuery_matchId){
        free(valueQuery_matchId);
        valueQuery_matchId = NULL;
    }
    if(keyPairQuery_matchId){
        keyValuePair_free(keyPairQuery_matchId);
        keyPairQuery_matchId = NULL;
    }
    if(keyQuery_variable){
        free(keyQuery_variable);
        keyQuery_variable = NULL;
    }
    if(keyPairQuery_variable){
        keyValuePair_free(keyPairQuery_variable);
        keyPairQuery_variable = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// 解の取得
//
solution_t*
SolutionAPI_getSolution(apiClient_t *apiClient, char *matchId, char *participantId, int *trialNo)
{
    list_t    *localVarQueryParameters = list_createList();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/solution")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/solution");




    // query parameters
    char *keyQuery_matchId = NULL;
    char * valueQuery_matchId = NULL;
    keyValuePair_t *keyPairQuery_matchId = 0;
    if (matchId)
    {
        keyQuery_matchId = strdup("matchId");
        valueQuery_matchId = strdup((matchId));
        keyPairQuery_matchId = keyValuePair_create(keyQuery_matchId, valueQuery_matchId);
        list_addElement(localVarQueryParameters,keyPairQuery_matchId);
    }

    // query parameters
    char *keyQuery_participantId = NULL;
    char * valueQuery_participantId = NULL;
    keyValuePair_t *keyPairQuery_participantId = 0;
    if (participantId)
    {
        keyQuery_participantId = strdup("participantId");
        valueQuery_participantId = strdup((participantId));
        keyPairQuery_participantId = keyValuePair_create(keyQuery_participantId, valueQuery_participantId);
        list_addElement(localVarQueryParameters,keyPairQuery_participantId);
    }

    // query parameters
    char *keyQuery_trialNo = NULL;
    char * valueQuery_trialNo = NULL;
    keyValuePair_t *keyPairQuery_trialNo = 0;
    if (trialNo)
    {
        keyQuery_trialNo = strdup("trialNo");
        valueQuery_trialNo = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_trialNo, MAX_NUMBER_LENGTH, "%d", *trialNo);
        keyPairQuery_trialNo = keyValuePair_create(keyQuery_trialNo, valueQuery_trialNo);
        list_addElement(localVarQueryParameters,keyPairQuery_trialNo);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","Successful operation");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 0) {
    //    printf("%s\n","successful operation");
    //}
    //nonprimitive not container
    cJSON *SolutionAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    solution_t *elementToReturn = solution_parseFromJSON(SolutionAPIlocalVarJSON);
    cJSON_Delete(SolutionAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_freeList(localVarQueryParameters);
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    if(keyQuery_matchId){
        free(keyQuery_matchId);
        keyQuery_matchId = NULL;
    }
    if(valueQuery_matchId){
        free(valueQuery_matchId);
        valueQuery_matchId = NULL;
    }
    if(keyPairQuery_matchId){
        keyValuePair_free(keyPairQuery_matchId);
        keyPairQuery_matchId = NULL;
    }
    if(keyQuery_participantId){
        free(keyQuery_participantId);
        keyQuery_participantId = NULL;
    }
    if(valueQuery_participantId){
        free(valueQuery_participantId);
        valueQuery_participantId = NULL;
    }
    if(keyPairQuery_participantId){
        keyValuePair_free(keyPairQuery_participantId);
        keyPairQuery_participantId = NULL;
    }
    if(keyQuery_trialNo){
        free(keyQuery_trialNo);
        keyQuery_trialNo = NULL;
    }
    if(valueQuery_trialNo){
        free(valueQuery_trialNo);
        valueQuery_trialNo = NULL;
    }
    if(keyPairQuery_trialNo){
        keyValuePair_free(keyPairQuery_trialNo);
        keyPairQuery_trialNo = NULL;
    }
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

